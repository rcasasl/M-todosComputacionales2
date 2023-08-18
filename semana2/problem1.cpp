#include <iostream>

int main(){
    int b = 5;
    int* ptrB = &b;
    std::cout << ptrB << std::endl;
    std::cout << *ptrB << std::endl;
    return 0;
}
