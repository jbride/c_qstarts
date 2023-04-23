#include <iostream>
#include <array>

int main() {
    int intVar = 10;
    double doubleVar0 = 3.3;
    double doubleVar1 = 5.0;
    std::array<double,2> myArray = {doubleVar0,doubleVar1};
    //myArray.fill(2.0);
    std::cout << "hello\t" << (double)(myArray[0] / myArray[1]) << "\n";
    return 0;
}
