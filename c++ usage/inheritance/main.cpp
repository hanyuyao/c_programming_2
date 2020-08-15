#include <iostream>

using namespace std;

class Point
{
protected:
    double x, y;
public:
    Point(){
        x = y = 0;
    }
    Point(double x, double y):x(x), y(y){}
    void showPoint(){
        cout << "x:" << x << ' ' << "y:" << y << endl;
    }
};

class Point2D:public Point
{
private:
    double x1, y1;
public:
    Point2D():Point(){
        x1 = y1 = 0;
    }
    Point2D(double x, double y, double x1, double y1):Point(x, y){
        this->x1 = x1;
        this->y1 = y1;
    }
    void showPoint2(){
        cout << "x:" << x << ' ' << "y:" << y << ' ';
        cout << "x1:" << x1 << ' ' << "y1:" << y1 << endl;
    }
};

int main()
{
    Point a(5, 8);
    a.showPoint();
    Point2D b(1, 2, 3, 4);
    b.showPoint();
}
