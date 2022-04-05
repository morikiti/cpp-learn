#include<iostream>
#include<string>
using namespace std;

class Money {
    private:
        int num;
        double tax;
    public:
    //オーバーロード
        Money(int n, double t);
        Money();
        void show();
        static void show_static();
        
};
//コンストラクタ
Money::Money() {
    num = 0;
    tax = 5;
    cout << "OK" << endl;
}

Money::Money(int n, double t) {
    num = n;
    tax = t;
    cout << "ok " << endl;
}

void Money::show() {
    cout << num << " " << tax << endl;
}

void Money::show_static() {
    cout << "静的関数"<< endl;
}

int main() {
    Money m;
    Money m2(132,4.0);
    m.show();
    m2.show();

    //インスタンス化しなくとも実行可能
    Money::show_static();

    Money marray[10];//デフォルトコンストラクタが１０個実行

    return 0;
}
