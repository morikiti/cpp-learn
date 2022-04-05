#include<iostream>
#include<string>
using namespace std;

class Money {
    private:
        int num;
        double tax;
    public:
        //インライン関数
        int getNum() {return num;}
        double getTax() {return tax;}


        void show();
        void setNumber(int n, double t);
        double calc();

};

void Money::show() {
    cout << num << " " << tax << endl;
}

void Money::setNumber(int n, double t) {
    if(n > 0 && t > 0) { 
        num = n;
        tax = t;
    } else {
        cout << "Error !! "<< endl;
    }
}

double Money::calc() {
    return num*(1 + tax/100);
}

//引数としてのオブジェクト関数定義
void buy(Money m);
//大きなクラスの場合、メンバごとのコピーを行うと重くなるかもしれんので、
void pbuy(Money* pm);
//参照でも同じ
void buys(Money& m);

int main() {
    Money m;
    m.setNumber(1233,5);
    m.show();
    cout << m.calc() << endl;

    buy(m);
    pbuy(&m);
    buys(m);
   return 0;
}

void buy(Money m) {
    int n = m.getNum();
    double g = m.getTax();
    cout << "購入金額 " <<n * (1+g/100) << endl;
    cout << "税金 " << n*g/100 << endl;
}

void pbuy(Money* pm) { 
    int n = pm->getNum();
    double g = pm->getTax();
    cout << "購入金額 " <<n * (1+g/100) << endl;
    cout << "税金 " << n*g/100 << endl;
}
void buys(Money& m) { 
    int n = m.getNum();
    double g = m.getTax();
    cout << "購入金額 " <<n * (1+g/100) << endl;
    cout << "税金 " << n*g/100 << endl;
}