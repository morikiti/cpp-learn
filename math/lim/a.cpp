#include <iostream>
#include <vector>
using namespace std;
using ld = long double;


int  main() {  
    int x,d;
    cin >> x >> d;
    if(d == 0) { 
        cout << 1 << endl;
    } else if(d >= 1) { 
        cout << 2 << endl;
    } else if(d < 0) { 
        cout << 3 << endl;
    }
}