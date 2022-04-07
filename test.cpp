#include<iostream>
#include<string>
using namespace std;

void text(const string &aa) { 
    cout << aa << endl;
}

int main() {
    string a;
    cin >> a;
    text(a);
    return 0;
}
