#include <iostream>
#include <array>
using namespace std;

class ArrayTest {

    int objectIntArray[5] = {1,2,3,4,5};
    int* pA = nullptr;
    std::array<double,2> objectStdArray = {2.5,5.0};

    public:

        std::array<double, 2>  getObjectStdArray() {
            return objectStdArray;
        }

        void testStdArray(int arrayIndex) {

            std::cout << "testStdArray() division = " << (double)( objectStdArray[0] / objectStdArray[1] ) << endl;

            objectStdArray.fill(5.0);
            std::cout << "testStdArray() array element value = " << objectStdArray.at(arrayIndex) << endl;

        }

        // Arrays and pointers are almost indistinguishable from each other in C++.
        // A pointer to the beginning of an array, the address of the first element & the bare array name all mean the same thing
        void testArray() {

            // C++ 17 provides std::size()
            std::cout << "testArray() array size = " << std::size(objectIntArray) << endl;

            // set pointer to address-of 3rd element of array
            pA = &objectIntArray[2];
            std::cout << "testArray() " << &objectIntArray << "\t" << pA << endl;

            // The following are equivalent expressions
            // int fifthE = pA[2];
            int fifthE = *(pA + 2);

            // print the value 2 elements beyond the pointer currently points to
            std::cout << "testArray(): " << objectIntArray[4] << "\t" << fifthE << "\t" << pA << endl;
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

    std::cout << "Size of globalStdArray = " << aTest.getObjectStdArray().size() << "\nEnter index of array element to print: " << endl;
    int index = 0;
    std::cin >> index;
    aTest.testStdArray( index );

    return 0;
}