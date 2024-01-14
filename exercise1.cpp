#include <iostream>
#include <cmath>

int main(int argc, char * argv[]) {
    double d0 = 4, d1 = 7;

    double a = 0, b, c;
    double r1, r2;

    for(int i = 0 ; i < 7 ; i++)
        a += (d0 + 1) * pow(10, i);

    b = (d1 + 1) * pow(10, 20);
    c = -b;

    r1 = (a + b) + c;
    r2 = a + (b + c);

    std::cout << "r1 = " << r1 << std::endl << "r2 = " << r2 << std::endl;

    return 0;
}