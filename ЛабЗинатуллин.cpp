#include <iostream>
#include <cstdint>
#include <cstring>
#include "bits.h"

using namespace std;

int main() {
    cout << "РАЗМЕРЫ ТИПОВ (байт)" << endl;
    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "short int: " << sizeof(short int) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long int: " << sizeof(long int) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;

    cout << "\nЦЕЛЫЕ ЧИСЛА: 32 БИТА" << endl;
    cout << "+3: "; printIntBits(static_cast<uint32_t>(3));
    cout << "-3: "; printIntBits(static_cast<uint32_t>(-3));
    cout << "0: "; printIntBits(static_cast<uint32_t>(0));

    cout << "\nFLOAT: знак, порядок, мантисса" << endl;
    float f1 = 3.14f;
    float f2 = -2.5f;
    float f3 = 0.0f;
    float f4 = 1.0e-40f;
    uint32_t bitsF;

    memcpy(&bitsF, &f1, sizeof(f1));
    cout << "3.14: "; printFloatBits(bitsF);
    memcpy(&bitsF, &f2, sizeof(f2));
    cout << "-2.5: "; printFloatBits(bitsF);
    memcpy(&bitsF, &f3, sizeof(f3));
    cout << "0: "; printFloatBits(bitsF);
    memcpy(&bitsF, &f4, sizeof(f4));
    cout << "Денормализованное число: "; printFloatBits(bitsF);

    uint32_t infFloat = 0xFFu << 23;
    cout << "+inf: "; printFloatBits(infFloat);

    cout << "\nDOUBLE: знак, порядок, мантисса" << endl;
    double d1 = 3.14;
    double d2 = -2.5;
    double d3 = 0.0;
    double d4 = 1.0e-310;
    uint64_t bitsD;

    memcpy(&bitsD, &d1, sizeof(d1));
    cout << "3.14: "; printDoubleBits(bitsD);
    memcpy(&bitsD, &d2, sizeof(d2));
    cout << "-2.5: "; printDoubleBits(bitsD);
    memcpy(&bitsD, &d3, sizeof(d3));
    cout << "0: "; printDoubleBits(bitsD);
    memcpy(&bitsD, &d4, sizeof(d4));
    cout << "Денормализованное число: "; printDoubleBits(bitsD);

    uint64_t infDouble = 0x7FFULL << 52;
    cout << "+inf: "; printDoubleBits(infDouble);

    cout << "\nИЗМЕНЕНИЕ БИТА" << endl;
    uint32_t intBits = 12;
    cout << "Число 12 до изменения: "; printIntBits(intBits);
    intBits = static_cast<uint32_t>(changeBit(intBits, 0, '1'));
    cout << "Установили бит 0: "; printIntBits(intBits);
    intBits = static_cast<uint32_t>(changeBit(intBits, 2, '0'));
    cout << "Сбросили бит 2: "; printIntBits(intBits);
    intBits = static_cast<uint32_t>(changeBit(intBits, 0, '^'));
    cout << "Инвертировали бит 0: "; printIntBits(intBits);

    memcpy(&bitsF, &f1, sizeof(f1));
    cout << "Биты float до изменения: "; printFloatBits(bitsF);
    bitsF = static_cast<uint32_t>(changeBit(bitsF, 2, '1'));
    cout << "Биты float после установки бита 2: "; printFloatBits(bitsF);

    memcpy(&bitsD, &d1, sizeof(d1));
    cout << "Биты double до изменения: "; printDoubleBits(bitsD);
    bitsD = changeBit(bitsD, 0, '0');
    cout << "Биты double после сброса бита 0: "; printDoubleBits(bitsD);

    cout << "\nСДЕЛАТЬ ЧИСЛО НЕЧЁТНЫМ" << endl;
    int number = 12;
    cout << "До: " << number << endl;
    number |= 1;
    cout << "После number |= 1: " << number << endl;

    return 0;
}
