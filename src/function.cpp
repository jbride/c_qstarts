#include <iostream>
using namespace std;

int globalInt = 51;

# A pointer variable is designated to own a dynamic variable during its lifetime
# The pointer is called an "owned" pointer
int* pDynamicInt = new int(52);

int simpleInt() {
    return 1;
}

int& validGlobalRef() {
    return globalInt;
}

int& validDynamicRef() {
    return *pDynamicInt;
}

// g++ 12.2.1 :   will log a warning at compile time
int& invalidRef() {
    int functionScopeInt = 2;
    return functionScopeInt;
}

int main() {
    std::cout << "int = " << simpleInt() << endl;
    std::cout << "validGlobalRef = " << validGlobalRef() << endl;
    std::cout << "validDynamicRef = " << validDynamicRef() << endl;

    # Dynamic variables live from the time they are created by an executable statement until they are destroyed by another executable statement.
    # The app can explicitly control the lifetime of data structures built from dynamic variables
    # Responsibility for destroying dynamic variables is shared by the entire program.
    # C++ is generous in permitting any line of the program to create or destroy additional pointers to a dynamic variable
    # However, C++ exacts a harsh penalty if the developer forgets to delete or double-deletes a dynamic variable: a memory leak or an error trap from the OS that halts the program
    delete pDynamicInt;

    // throw seg fault at runtime
    std::cout << "invalidRef = " << invalidRef << endl;
    return 0;
}
