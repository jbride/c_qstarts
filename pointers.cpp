#include <string>
#include <iostream>
#include <array>
using namespace std;

class ArrayTest {


    int fiveA[5] = {1,2,3,4,5};
    int *p1 = nullptr;

    public:

        // Arrays and pointers are almost indistinguishable from each other in C++.
        // A pointer to the beginning of an array, the address of the first element & the bare array name all mean the same thing
        void testArray() {
            p1 = &fiveA[2];
            std::cout << "\n" << &fiveA << "\t" << p1 << endl;

            std::cout << "\n" << fiveA[4] << "\t" << p1[2] << endl;
        }

};

int main() {
    int i = 12345;

    // create a pointer to the address of the variable
    int *p = &i;

    std::cout << "p = " << p << ", &i = " << &i << endl;

    // add 2 to the de-referenced pointer (the actual variable, i)
    int j = *p + 3;

    // increment the variable i to 2
    *p = *p +2;

    std::cout <<  "i = " << i << ", p = " << p << endl;

    ArrayTest aTest;
    aTest.testArray();

    return 0;
}