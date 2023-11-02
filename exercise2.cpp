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
    
    double rStandard[X_LENGTH];
    double rTaylor[N_LENGTH][X_LENGTH];

    double absErr[N_LENGTH][X_LENGTH];
    double relErr[N_LENGTH][X_LENGTH];

    for(int i = 0 ; i < X_LENGTH; i++) {
        rStandard[i] = exp(x[i]);
        for(int j = 0 ; j < N_LENGTH ; j++) {
            rTaylor[j][i] = taylor(N[j], x[i]);
        }
    }

    
    
    return 0;
}

double factorial(double n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double taylor(double N, double x) {
    double res = 0;
    for(int n = 0 ; n < N ; n++) {
        res += pow(x, n) / factorial(n);
    }
    return res;
}

double absErrCalc(double obtained, double expected){
    return obtained - expected;
}
double relErrCalc(double, double){
    
}
