#include <iostream>
using namespace std;

int globalInt = 51;
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

    delete pDynamicInt;

    // throw seg fault at runtime
    std::cout << "invalidRef = " << invalidRef() << endl;
    return 0;
}