#include <bits/stdc++.h>
using namespace std;

class Product {
    private:
        int price;
        int tax;
    public:
        Product(int a, int b);
        void show();
};


int main() {
    Product kome(321,8);
    kome.show();
    return 0;
}
