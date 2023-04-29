#include <iostream>
#include <array>

template<typename T>
void printArray(T inArray){

    int c = 1;
    for(auto x : inArray){
        std::cout << x;
        if(c != inArray.size() ){
            std::cout << " , ";
            c++;
        }
    }
    std::cout << "\n";
}

int main() {

    std::array<int, 3> intArray = {1,2,3};
    printArray(intArray);

    std::array<float, 3> floatArray = {1.1f,2.2f,3.3f};
    printArray(floatArray);

    return 0;
}