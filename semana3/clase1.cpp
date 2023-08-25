#include <iostream>

using namespace std;

int main()
{
    // heap
    int* ptrScore = new int(5);
    cout << *ptrScore << endl;
    cout << ptrScore << endl;
    delete ptrScore;
}