#include <iostream>
using namespace std;

class ArrayTest {

    int globalIntArray[5] = {1,2,3,4,5};
    int* pA = nullptr;

    public:

        // Arrays and pointers are almost indistinguishable from each other in C++.
        // A pointer to the beginning of an array, the address of the first element & the bare array name all mean the same thing
        void testArray() {

            // C++ 17 provides std::size()
            std::cout << "testArray() array size = " << std::size(globalIntArray) << endl;

            // set pointer to address-of 3rd element of array
            pA = &globalIntArray[2];
            std::cout << "testArray() " << &globalIntArray << "\t" << pA << endl;

            // The following are equivalent expressions
            // int fifthE = pA[2];
            int fifthE = *(pA + 2);

            // print the value 2 elements beyond the pointer currently points to
            std::cout << "testArray(): " << globalIntArray[4] << "\t" << fifthE << "\t" << pA << endl;
        }
};

int main() {
    std:cout << "main() size of int = " << sizeof(int) << endl;

    int i = 12345;

    // create a pointer to the address of the variable
    int* pI = &i;

    std::cout << "main() pI = " << pI << ", &i = " << &i << endl;

    // add 3 to the de-referenced pointer (the actual variable, i)
    int j = *pI + 3;

    // increment the variable i by 2
    *pI = *pI +2;

    std::cout <<  "main() i = " << i << ", pI = " << pI << ", j = " << j << endl;

    ArrayTest aTest;
    aTest.testArray();

    return 0;
}