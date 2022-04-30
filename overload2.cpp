#include <iostream>
#include <vector>
using namespace std;

class P { 
    public:
        //int add(vector<int> a, vector<int> b);
        int add(int a, int b);
        double add(double a, double b);
};

int P::add(int a, int b) { 
    return a+b;
}

double P::add(double a, double b) { 
    return a+b;
}

int operator+(vector<int> a, vector<int> b) { 
    int res = 0;
    for(int i = 0; i < a.size(); ++i) { 
        res += a[i]*b[i];
    }
    return res;
}


int  main() { 
    double q,w;
    int a,s;
    P p;
    cin >> q >> w >> a >> s; 
    cout << p.add(q,w) << endl;
    cout << p.add(a,s) << endl;
    vector<int> va = {1,2,3,4,5,6};
    vector<int> vb = {3,4,5,6,6,8};
    cout << va + vb << endl;
    cout << a + s << endl;
}