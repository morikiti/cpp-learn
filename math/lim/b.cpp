#include <iostream>
#include <vector>
using namespace std;
using ld = long double;


int  main() {  
    int a,b;
    cin >> a >> b;
    if( -1 <(a/b) && a <= b ) { 
        cout << 1 << endl;
    } else if(a>b) { 
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;   
}