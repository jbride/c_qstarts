#include <iostream>
#include <string>
using namespace std;

class Person {

    int age;

    public:
        Person(int a) : age(a) {
            std::cout << "Person age = " << age << endl;
        }
        ~Person() {
            std::cout << "destroying Person with age = " << age << endl;
        }

};
int main() {

    int *pI = nullptr;

    // create dynamic variable
    pI = new int{51};
    std::cout << "mem address " << pI << ", value = " << *pI << endl;

    // create a local variable from dynamic variable
    int i = *pI;
    std::cout << "mem address " << &i << ", value = " << i << endl;

    delete pI;

    // Create dynamic variable of Person
    Person *pPerson = new Person(51);
    delete pPerson;

    // Create a local object and observe that it gets auto destroyed
    Person pObj = Person(52);
    return 0;
}