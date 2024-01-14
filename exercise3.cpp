#include <iostream>
#include <math.h>

int main(int argc, char * argv[]) {
    double dEps;
    float sEps;
    int dd = 0;
    int sd = 0;
    while (1 + pow(2, -dd) > 1) {
        dd++;
    }
    while (1 + powf(2, -sd) > 1) {
        sd++;
    }
    dEps = pow(2, -dd);
    sEps = powf(2, -sd);
    std::cout << "precisione di maccchina eps in doppia precisione = " << dEps << std::endl;
    std::cout << "precisione di maccchina eps in singola precisione = " << sEps << std::endl;
    
    return 0;
}