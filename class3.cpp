#include<iostream>
#include<string>
using namespace std;

class Money {
    /* private:
        int num;
        double tax; */
    protected:
        int num;
        double tax;
    public:
    //オーバーロード
        Money(int n, double t);
        Money();
        void show();
        static void show_static();
        
};

//継承
class humanMoney : public Money {
    private:
        string name;
    public:
        humanMoney(string name);
        humanMoney(int n,double t, string s);
        void human_show();
        void show_all();
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

humanMoney::humanMoney(string n) {
    name = n;
    cout << "コンストラクタ　継承先" << endl;
}

humanMoney::humanMoney(int n,double t, string s):Money(n,t) { 
    name = s;
    cout << "コンストラクタ　継承先２ "<< endl;
}

void humanMoney::human_show() {
    cout << name << " さん" << endl;
}

void humanMoney::show_all() {
    cout << num << " " << tax << " " << name << endl;
}


int main() {
    humanMoney hm("tanaka");
    hm.human_show();
    hm.show();

    humanMoney hm2(243,432.0,"morio");
    hm2.show();
    //privateだとアクセスできんので
    //cout << hm2.name << " " << hm2.tax << endl;
    hm2.show_all();
    return 0;
}
