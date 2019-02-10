/*
 * From: http://www.modernescpp.com/index.php/condition-variables
 */
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;

void doTheWork(){
    std::cout << "Processing Shared Data." << std::endl;
}

void waitingForWork(){
    std::cout << "Worker: Waiting for work." << std::endl;

    // unique_lock `lck` is created, locking `mutex_`
    std::unique_lock<std::mutex> lck(mutex_);
    // block execution of locked thread until both:
    // - `condVar` is notified by `notify_one()`
    // - `dataReady` evaluates to `true`.
    condVar.wait(lck, []{return dataReady;});
    doTheWork();
    std::cout << "Work Done." << std::endl;
}

void setDataReady(){
    // Thread 2, created after thread one,
    // takes ownership of the mutex, used to create a lock_guard.
    std::lock_guard<std::mutex> lck_guard(mutex_);
    // Simulate notifications that don't unblock `waitingForWork()`
    // because `dataReady` is still `false`
    for(auto i = 0; i < 5; i++)
    {
        dataReady=false;
        std::cout << "Sender: Data is not Ready." << std::endl;
        condVar.notify_one(); // notify waiting thread in `waitingForWork`
    }
    dataReady=true;
    std::cout << "Sender: Data is Ready." << std::endl;
    condVar.notify_one(); // unblocks `waitingForWork`
    // existing function scope, lock_guard `lck_guard`
    // is destroyed and the mutex is released.
}

int main(){
    std::cout << std::endl;

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();

    std::cout << std::endl;
}