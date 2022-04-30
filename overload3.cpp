#include <iostream>
#include <vector>
using namespace std;

int add(int a, int b) { 
    return a+b;
}

double add(double a, double b) { 
    return a+b;
}




int  main() { 
    double q,w;
    int a,s;
    cin >> q >> w;
    cin >> a >> s;
    cout << add(q,w) << endl;
    cout << add(a,s) << endl;
    }