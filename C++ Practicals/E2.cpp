#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float area() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }
    float area()
    {
        return length * breadth;
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }
    float area()
    {
        return 0.5 * base * height;
    }
};

void runTest(int testNo, float r, float l, float b, float base, float h)
{
    cout << "===== Test Case " << testNo << " =====" << endl;

    Circle c(r);
    Rectangle rect(l, b);
    Triangle t(base, h);

    Shape *ptr;

    ptr = &c;
    cout << "Area of Circle: " << ptr->area() << endl;

    ptr = &rect;
    cout << "Area of Rectangle: " << ptr->area() << endl;

    ptr = &t;
    cout << "Area of Triangle: " << ptr->area() << endl;

    cout << endl;
}

int main()
{
    runTest(1, 7, 5, 10, 9, 12);
    runTest(2, 2, 4, 6, 5, 6);

    cout << "Program completed successfully." << endl;
    return 0;
}