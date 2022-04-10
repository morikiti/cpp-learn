#include <iostream>
using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        Point(int a=0,int b=0 ) {x = a; y = b;}
        void show(){cout << "x : " << x << " y: " << y << endl;}
        void setX(int a) {x = a;}
        void setY(int b) {y = b;}
        Point operator+ (Point p);
        friend Point operator+ (int a, Point p);
};

Point Point::operator+ (Point p) { 
    Point tmp;
    tmp.x = x + p.x;
    tmp.y = y + p.y;
    return tmp;

}

Point operator+(int a, Point p) { 
    Point tmp;
    tmp.x = a + p.x;
    tmp.y = a + p.y;
    return tmp;
}

int  main() { 
    Point p1 = Point(2,3);
    Point p2 = Point(10,10);
    p1.show();
    p1 = p1 + p2;
    p2.show();
    p2 = 5 + p1;
    p1.show();
    p2.show();
}