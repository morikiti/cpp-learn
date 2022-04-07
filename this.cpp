#include<iostream>
#include<string>
using namespace std;

class Product {
    private:
        int price;
        int tax;
    public:
        Product(int a, int b);
        void show();
};

//thisは、メンバ関数を呼び出したクラスオブジェクトへのポインタ
Product::Product(int a, int b) {
    this->price = a;
    this->tax = b;
}

void Product::show() {
    cout << this->price << " " << this->tax << endl;
}

int main() {
    Product kome(321,8);
    kome.show();
    return 0;
}
