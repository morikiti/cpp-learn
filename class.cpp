#include<iostream>
#include<string>
using namespace std;

class Person {
    public:
        int num;
        string name;
        void show();
};

void Person::show() {
    cout << name << "さん " << num << "歳"<< endl;
}

int main() {
    Person p;
    cin >> p.num >> p.name;
    p.show();

    Person* pa;
    pa = new Person;
    cin >> pa->num >> pa->name;
    pa->show();
    delete pa;

   return 0;
}