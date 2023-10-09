#include "matran.h"
#include <iostream>
using namespace std;

int main()
{
    matran A, B, C, D, E;
    A.nhap();
    cout << "Ma tran A: " << endl;
    A.xuat();
    cout << endl;
    B.nhap();
    cout << "Ma tran B: " << endl;
    B.xuat();
    cout << endl;
    cout << "Tong 2 ma tran" << endl;
    C = A + B;
    C.xuat();
    cout << endl;
    cout << "Hieu 2 ma tran" << endl;
    D = A - B;
    D.xuat();
    cout << endl;
    cout << "Tich 2 ma tran" << endl;
    E = A * B;
    E.xuat();
    cout << endl;
    cout << "Gan ma tran A = ma tran B" << endl;
    A = B;
    cout << "Ma tran A sau khi gan: " << endl;
    A.xuat();
    cout << endl;

    return 0;
}
