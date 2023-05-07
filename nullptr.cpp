#include <iostream>
using namespace std;

int main() {
    int *p = nullptr;

    // Force a segfault
    // Segfaults are caused by a program trying to read or write an illegal memory location
    // Note that where the segfault occurs is generally only a clue as to where "the mistake which causes" it is in the code.
    // An important clue, but it's not necessarily where the problem resides
    std::cout << "deferenced pointer p = " << *p << endl;

    return 0;
}