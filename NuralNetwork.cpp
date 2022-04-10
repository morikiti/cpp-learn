#include <iostream>
#include<cmath>
#include<vector>
#include<random>
#include <limits>
using namespace std;

vector<double> operator+(const vector<double>& x, const vector<double>& y) { 
    vector<double> z(x.size());
    for(size_t d = 0; d < x.size(); ++d ) z[d] = x[d] + y[d];
    return z;
}

vector<double> operator-(const vector<double>& x, double y) { 
    vector<double> z(x.size());
    for(size_t d = 0; d < x.size(); ++d) { 
        z[d] = x[d] - y;
    }
    return z;
}

vector<double> operator-(const vector<double>& x) {
    vector<double> z(x.size());
    for (size_t d = 0; d < x.size(); ++d) z[d] = -x[d];
    return z;
}

vector<double> operator-(const vector<double>& x, const vector<double>& y) { 
    return x +(-y);
}

vector<double> operator*(double a, const vector<double>& x) { 
    vector<double> z(x.size());
    for(size_t d = 0; d < z.size(); ++d) z[d] = a * z[d];
    return z;
}

vector<double> operator*(const vector<double>& x, const vector<double>& y) { 
    vector<double> z(x.size());
    for(size_t d = 0; d < x.size(); ++d) z[d] = x[d] * y[d];
    return z;
}

vector<double> operator /(const vector<double>& x, double a) { 
    vector<double> z(x.size());
    for(size_t d = 0; d < x.size(); ++d) z[d] = x[d] / a;
    return z;
}

double Sum(const vector<double>& x) { 
    double z = 0;
    for(size_t d = 0; d < x.size(); ++d) z += x[i];
    return z;
}

double Dot(const vector<double>& x, const vector<double>& y) { 
    return Sum(x * y);
}

class Activation { 
    public:
        virtual double f(double x) const { return x; }
        virtual double df(double x) const {return 1.;}
        virtual double operator()(double x) const {return f(x);} 
};