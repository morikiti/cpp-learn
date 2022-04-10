#include <iostream>
#include <vector>
using namespace std;

vector<double> operator*(vector<double>& x, vector<double>& y) { 
    vector<double> z(x.size());
    for(int i = 0; i < x.size(); ++i) z[i] = x[i]*y[i];
    return z;
}

vector<double> operator-(vector<double>& x, vector<double>& y) { 
    vector<double> z(x.size());
    for(int i = 0; i < x.size(); ++i) z[i] = x[i]-y[i];
    return z;
}

vector<double> operator+(vector<double>& x, vector<double>& y) { 
    vector<double> z(x.size());
    for(int i = 0; i < x.size(); ++i) z[i] = x[i]+y[i];
    return z;
}


int  main() { 
    vector<double> a = {2,2,2,2,2};
    vector<double> b = {1,2,3,4,5};
    vector<double> c;

    c=a+b;
    for(auto aa : c) { 
        cout << aa << " ";
    }
    cout << endl;
    for(auto aa : a) { 
        cout << aa << " ";
    }
    cout << endl;
    for(auto aa : b) { 
        cout << aa << " ";
    }
    cout << endl;
    c = a*b;
    for(auto aa : c) { 
        cout << aa << " ";
    }
    cout << endl;
    c = a-b;
    for(auto aa : c) { 
        cout << aa << " ";
    }
    cout << endl;
    c = b-a;
    for(auto aa : c) { 
        cout << aa << " ";
    }

}