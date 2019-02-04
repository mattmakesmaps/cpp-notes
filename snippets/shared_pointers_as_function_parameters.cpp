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

void in_shared_pointer(std::shared_ptr<People> person){
    // Ref count is 2, since pMatt and person reference the same object.
    std::cout << "In in_shared_pointer(): " << person->m_name << std::endl;
    std::cout << "use_count: " << person.use_count() << std::endl;
}

void in_shared_pointer_reference(std::shared_ptr<People>& person) {
    // Ref count is 1, since person is a reference to pMatt!
    std::cout << "In in_shared_pointer_reference(): " << person->m_name << std::endl;
    std::cout << "use_count: " << person.use_count() << std::endl;
}

int main() {
    /***
     * In the following example, pMatt and the shared pointers in
     * both methods all point to the same memory address. The two
     * methods differ in their ref counts, where one creates a new
     * shared pointer and another accepts a reference to a shared
     * pointer.
     ***/
    auto pMatt = std::make_shared<People>("Matt", 32);
    in_shared_pointer(pMatt);
    in_shared_pointer_reference(pMatt);
    return 0;
}