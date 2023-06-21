#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
using std::string, std::cout;

double fun(double x){
    return 1./(1.+10.*x*x*x*x*x*x);
}

double* calcC(int n, double * xi, double *fxi){
    auto *c = new double [n];

    for (int i = 0; i < n; i++) {
        c[i] = fxi[i];
    }
    for (int k = 1; k < n; k++) {
        for (int i = n - 1; i >= k; i--) {
            c[i] = (c[i] - c[i - 1]) / (xi[i] - xi[i - k]);
        }
    }

    return c;

}

double calculatePolunomial(double * xi, double *c, int n, double x){
    double result = c[0];
    double term = 1.0;
    for (int k = 1; k < n; k++) {
        term *= (x - xi[k - 1]);
        result += c[k] * term;
    }
    return result;
}

double* generateChebyshev(int n) {
    auto *nodes = new double[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = std::cos((2.0 * i + 1.0) * M_PI / (2.0 * n));
    }

    return nodes;
}


int main() {
    double h = 0.1;
    int n = static_cast<int>(2./h)+1;
    auto *xi = new double [n];
    auto *fxi = new double [n];
    double x = -1;
    for (int i = 0; i < n; ++i) {
        xi[i] = x;
        fxi[i] = fun(x);
        x+=h;
    }

    double *c = calcC(n, xi, fxi);
    double h2 = 0.001;
    std::ofstream plik("wynik.txt");
    x = -1;
    while(x<=1){
        plik << x << " " << calculatePolunomial(xi, c, n, x) << '\n';
        x+=h2;
    }
    plik.close();


    xi = generateChebyshev(n);
    for (int i = 0; i < n; ++i) {
        fxi[i] = fun(xi[i]);
    }
    c = calcC(n, xi, fxi);

    plik.open("czebyszew.txt");
    x = -1;
    while(x<=1){
        plik << x << " " << calculatePolunomial(xi, c, n, x) << '\n';
        x+=h2;
    }
    plik.close();



    delete[] xi;
    delete[] fxi;
    delete[] c;

    return 0;


}
