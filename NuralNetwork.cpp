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
    for(size_t d = 0; d < x.size(); ++d) z += x[d];
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

class Linear : public Activation{};
class Sigmoid : public Activation { 
    public:
        virtual double f(double x) const override { 
            return 1. / (1. + exp(-x));
        }
        virtual double f(double x) const override { 
            double p = f(x);
            return p * (1. - p);
        }
};

class Error {
public:
	virtual double f(double y, double p) const {
		double error = y - p;
		return error * error / 2.;
	}
	virtual double df(double y, double p) const {
		return p - y;
	}
	double f(const vector<double>& Y, const vector<double>& P) const {
		double error = 0.;
		for (size_t n = 0; n < Y.size(); n++) error += f(Y[n], P[n]);
		return error / ((double)Y.size());
	}
	double operator()(const vector<double>& Y, const vector<double>& P) const {
		return f(Y, P);
	}
};