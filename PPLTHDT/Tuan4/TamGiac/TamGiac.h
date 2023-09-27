#pragma once
#include "Diem.h"
struct TamGiac
{
    Diem A;
    Diem B;
    Diem C;
};

void nhaptamgiac(TamGiac& tamgiac);
void xuattamgiac(TamGiac tamgiac);
float dientichtamgiac(TamGiac tamgiac);
Diem trongtamtamgiac(TamGiac tamgiac);
