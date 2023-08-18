#include <iostream>
using namespace std;

void cycle(int* ptrA, int* ptrB, int* ptrC, int* ptrD, string direction)
{
    if (direction == "Left"){
        int a_temp = *ptrA;
        *ptrA = *ptrB;
        *ptrB = *ptrC;
        *ptrC = *ptrD;
        *ptrD = a_temp;
    }
    if (direction == "Right"){
        int d_temp = *ptrD;
        *ptrD = *ptrC;
        *ptrC = *ptrB;
        *ptrB = *ptrA;
        *ptrA = d_temp;
    }    
}
int main(){
    int a = 2;
    int b = 3;
    int c = 4;
    int d = 6;    
    int *ptrA = &a;
    int *ptrB = &b;
    int *ptrC = &c;
    int *ptrD = &d;
    cout << "Initial Numbers:" << "\n";
    cout << a << " " << b << " " << c << " " << d << "\n";
    cout << "One cycle to the right:" << "\n";
    cycle(ptrA, ptrB, ptrC, ptrD, "Right");
    cout << a << " " << b << " " << c << " " << d <<"\n";
    cout << "Two cycles to the left:" << "\n";
    cycle(ptrA, ptrB, ptrC, ptrD, "Left");
    cycle(ptrA, ptrB, ptrC, ptrD, "Left");
    cout << a << " " << b << " " << c << " " << d << "\n";
    cout << "Adresses:" << "\n";
    cout << ptrA << " " << ptrB << " " << ptrC << " " << ptrD;
    return 0;
}
