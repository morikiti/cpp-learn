#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

std::vector<double> operator+(const std::vector<double>& x, const std::vector<double>& y) {
	std::vector<double> z(x.size());
	for (size_t d = 0; d < x.size(); d++) z[d] = x[d] + y[d];
	return z;
}
std::vector<double> operator-(const std::vector<double>& x, double y) {
	std::vector<double> z(x.size());
	for (size_t d = 0; d < x.size(); d++)
		z[d] = x[d] - y;
	return z;
}

std::vector<double> operator-(const std::vector<double>& x) {
	std::vector<double> z(x.size());
	for (size_t d = 0; d < x.size(); d++) z[d] = -x[d];
	return z;
}

std::vector<double> operator-(const std::vector<double>& x, const std::vector<double>& y) {
	return x + (-y);
}
std::vector<double> operator*(double a, const std::vector<double>& x) {
	std::vector<double> z(x.size());
	for (size_t d = 0; d < z.size(); d++) z[d] = a * x[d];
	return z;
}
std::vector<double> operator*(const std::vector<double>& x, const std::vector<double>& y) {
	std::vector<double> z(x.size());
	for (size_t d = 0; d < x.size(); d++) z[d] = x[d] * y[d];
	return z;
}
std::vector<double> operator/(const std::vector<double>& x, double a) {
	std::vector<double> z(x.size());
	for (size_t d = 0; d < x.size(); d++) z[d] = x[d] / a;
	return z;
}
std::vector<double> operator+(const std::vector<double>& x, double a) {
    std::vector<double> z(x.size());
    for (size_t d = 0; d < x.size(); d++) z[d] = x[d] + a;
    return z;
}
std::vector<double> operator/(const std::vector<double>& x, const std::vector<double>& y) {
    std::vector<double> z(x.size());
    for (size_t d = 0; d < x.size(); d++) z[d] = x[d] / y[d];
    return z;
}
double Sum(const std::vector<double>& x) { 
    double z = 0.;
    for(size_t d = 0; d < x.size(); ++d) z += x[d];
    return z;
}
double Dot(const std::vector<double>& x, const std::vector<double>& y) { 
    return Sum(x * y);
}


std::vector<std::string> split(std::string& input, char delimiter)
{
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

int main() {
    std::vector<std::vector<double>> xt ={{1,1,1,1},{1,2,3,2},{1,1,2,3}};
    std::vector<std::vector<double>> x ={{1,1,1},{1,2,1},{1,3,2},{1,2,3}};
    
    std::vector<double> y = {6,7,10,11};

    std::vector<std::vector<double>> xtx(xt.size()),xty(xt.size());
    
    for(int i = 0; i < xt.size(); ++i) { 
        for(int j = 0; j < 1; ++j) { 
            xty[i].push_back(Dot(xt[i],y));
        }
    }

    for(int i = 0; i < xt.size(); ++i) { 
        for(int j = 0; j < xt.size(); ++j) { 
            xtx[i].push_back(Dot(xt[i],xt[j]));
        }
    }



    for(int i = 0; i < xtx.size(); ++i) { 
        for(auto a : xtx[i]) { 
            cout << a << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < xtx.size(); ++i) { 
        for(auto a : xty[i]) { 
            cout << a << " ";
        }
        cout << endl;
    }

}