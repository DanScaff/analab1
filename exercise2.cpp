#include <iostream>
#include <math.h>

#define N_LENGTH 5
#define X_LENGTH 4

double factorial(double);
double taylor(double, double);
double absErrCalc(double, double);
double relErrCalc(double, double);

int main(int argc, char * argv[]) {

    const int N[N_LENGTH] = {3, 10, 50, 100, 150};
    const double x[X_LENGTH] = {0.5, 30, -0.5, -30};
    
    double rStandard[X_LENGTH]; //array contente i risultati ottenuti con la funzione exp(x) di cmath
    double rTaylor[N_LENGTH][X_LENGTH];

    double absErr[N_LENGTH][X_LENGTH];
    double relErr[N_LENGTH][X_LENGTH];

    for(int i = 0 ; i < X_LENGTH; i++) {
        rStandard[i] = exp(x[i]);
        for(int j = 0 ; j < N_LENGTH ; j++) {
            rTaylor[j][i] = taylor(N[j], x[i]);
        }
    }

    for(int i = 0 ; i < X_LENGTH ; i++) {
        for(int j = 0 ; j < N_LENGTH ; j++) {
            absErr[j][i] = absErrCalc(rTaylor[j][i], rStandard[i]);
            relErr[j][i] = relErrCalc(rTaylor[j][i], rStandard[i]);
        }
    }

    std::cout << "Standard result: " << std::endl;
    for(int i = 0 ; i < X_LENGTH ; i++) {
        std::cout << "x = " << x[i] << " -> " << rStandard[i] << std::endl;
    }
    std::cout << "Taylor result: " << std::endl;
    for(int i = 0 ; i < X_LENGTH ; i++) {
        std::cout << "x = " << x[i] << std::endl;
        for(int j = 0 ; j < N_LENGTH ; j++) {
            std::cout << "  -N = " << N[j] << " -> " << rTaylor[j][i] << "; ";
            std::cout << "absErr = " << absErr[j][i] << "; ";
            std::cout << "relErr = " << relErr[j][i] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "Algoritmo 2: " << std::endl;
    for(int i = 0 ; i < 2 ; i++) {
        std::cout << "x = " << x[i + 2] << std::endl;
        for(int j = 0 ; j < N_LENGTH ; j++) {
            std::cout << "  -N = " << N[j] << " -> " << 1 / rTaylor[j][i] << "; ";
            std::cout << "absErr = " << absErrCalc(1 / rTaylor[j][i], rStandard[i + 2]) << "; ";
            std::cout << "relErr = " << relErrCalc(1 / rTaylor[j][i], rStandard[i + 2]) << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}

double factorial(double n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double taylor(double N, double x) {
    double res = 0;
    for(int n = 0 ; n <= N ; n++) {
        res += pow(x, n) / factorial(n);
    }
    return res;
}

double absErrCalc(double obtained, double expected){
    return abs(obtained - expected);
}

double relErrCalc(double obtained, double expected){
    return abs(absErrCalc(obtained, expected) / expected);
}
