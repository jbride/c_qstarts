#include <iostream>
using namespace std;

class Person {

    int age;

    public:

        // Use a "constructor initializer" 
        Person(int a) : age(a) {
            std::cout << "Person age = " << age << endl;
        }
        ~Person() {
            std::cout << "destroying Person with age = " << age << endl;
        }

};

class PointerManager {


    /*     
     * One of the most powerful ways to manage ownership of a dynamic variable is to make the owned pointer to a dynamic variable a class member variable.
     * The dynamic member variable is then deleted when the class instance is destroyed.
    */
    Person *pPerson = nullptr;

    public :

        PointerManager(int i) {
            pPerson = new Person(52);
        }
        ~PointerManager() {
            delete pPerson;
        }

};

int main() {

    int *pI = nullptr;

    // create dynamic variable
    // Dynamic variables are not known by name but are instead known by a pointer to the dynamic variable
    pI = new int{51};
    std::cout << "mem address " << pI << ", value = " << *pI << endl;

    // create a local variable from a dynamic variable
    int i = *pI;
    std::cout << "mem address " << &i << ", value = " << i << endl;

    delete pI;

    // Create dynamic variable of Person
    Person *pPerson = new Person(51);
    delete pPerson;

    // Create a local object and observe that it gets auto destroyed
    Person pObj = Person(52);

    /*
     * Declare a global, function-local or block-local instance of the class.
     * Subsequently, the dynamic variable contained in the class instance will have the same lifetime as the class instance.
     * This technique makes the lifetime of dynamic variables as easy to understand as the lifetime of other kinds of variables
    */
    PointerManager pManager(52);

    return 0;
}