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
    int *pI = &i;

    std::cout << "pI = " << pI << ", &i = " << &i << endl;

    // add 3 to the de-referenced pointer (the actual variable, i)
    int j = *pI + 3;

    // increment the variable i to 2
    *pI = *pI +2;

    std::cout <<  "i = " << i << ", pI = " << pI << endl;

    ArrayTest aTest;
    aTest.testArray();

    return 0;
}