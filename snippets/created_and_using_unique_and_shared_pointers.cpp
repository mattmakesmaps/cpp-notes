#include <iostream>
#include <memory>

struct People {
    std::string m_name;
    int m_age;
    std::string m_default_species = "Human";

    People(std::string name, int age) : m_name(name), m_age(age) {
        std::cout << "Calling Regular CTOR: " << name << std::endl;
    }

    People(const People& people) : m_name(people.m_name), m_age(people.m_age) {
        std::cout << "Calling Copy CTOR: " << people.m_name << std::endl;
    }
};

void shared_pointer_experiment(){
    // Create a People instance, using the regular ctor.
    People matt("Matt Kenny", 32);

    // Create a shared pointer, using the regular ctor.
    std::shared_ptr<People> ptrPeople;
    ptrPeople = std::make_shared<People>("Steve", 82);

    // Create a shared pointer, using the copy ctor.
    std::shared_ptr<People> ptr2People;
    ptr2People = std::make_shared<People>(matt);

    //ptr2People is still separate from matt and ptrPeople
    ptr2People->m_name = "Updated Name";

    // Create a shared pointer from ptr2People
    // ptr2People and ptr3People refer to the same resource.
    auto ptr3People = ptr2People;
    ptr2People->m_name = "Updated again";
    // prints 2 confirming ptr2People and ptr3People reference same resource.
    std::cout << ptr3People.use_count() << std::endl;
}

void unique_pointer_experiment() {
    // Create a People instance, using the regular ctor.
    People matt("Matt Kenny", 32);
    // Make a unique pointer using the copy constructor.
    auto ptr2People = std::make_unique<People>(matt);

    //ptr2People is still separate from matt and ptrPeople
    ptr2People->m_name = "Updated Name";

    // ptr3People will point to same address as ptr2People did,
    // ptr2People is now null;
    auto ptr3People = std::move(ptr2People);
    if(ptr2People == nullptr) {
       std::cout << "ptr2People is destroyed" << std::endl;
    }

    /*** compile errors ***/
    // trying to make a pointer from a pointer, bad syntax.
    //auto ptr4People = std::make_unique<People>(ptr3People);
    // assignment constructor not allowed for unique pointer
    //auto ptr4People = ptr3People;

    // Use regular CTOR.
    auto ptr4People = std::make_unique<People>("Nora", 63);
}

int main() {
    //shared_pointer_experiment();
    unique_pointer_experiment();
    return 0;
}