/**                         Documentation section
_________________________________________________________________________________________________________________
-----------------------------------------------------------------------------------------------------------------
@name :  Hybrid  Inheritance
@author : Omar Mohamed El Sayed Taha
@Link : ...........................



__________________________________________________________________________________________________________________
------------------------------------------------------------------------------------------------------------------
**/
#include <bits/stdc++.h>
#define Taha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define el "\n"
#define sp " "



using namespace std;




/**
Hybrid inheritance :
combines two or more types of inheritance

  hierarchal inheritance
           Shape
          /     \
     Circle   Rectangle


  multiple inheritance

      Circle    Rectangle
          \      /
          Cylinder


**/


// Base class
class Shape
{
protected:
    string color;

public:
    Shape(string c) : color(c) {}

    void displayColor() const
    {
        cout << "Color: " << color << endl;
    }
};

// First derived class
class Circle : public Shape
{
protected:
    double radius;

public:
    Circle(string c, double r) : Shape(c), radius(r) {}

    void displayCircleInfo() const
    {
        displayColor();
        cout << "Radius: " << radius << endl;
    }
};

// Second derived class
class Rectangle : public Shape
{
protected:
    double length, width;

public:
    Rectangle(string c, double l, double w) : Shape(c), length(l), width(w) {}

    void displayRectangleInfo() const
    {
        displayColor();
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }
};

// Derived class from Circle and Rectangle (Multiple inheritance)
class Cylinder : public Circle, public Rectangle
{
private:
    double height;

public:
    Cylinder(string c, double r, double h, double l, double w)
        : Circle(c, r), Rectangle(c, l, w), height(h) {}

    void displayCylinderInfo() const
    {
        Circle::displayCircleInfo();
        cout << "Height: " << height << endl;
        cout << "Base Area: " << (3.14159 * radius * radius) << endl;
        cout << "Surface Area: " << (2 * 3.14159 * radius * (radius + height)) << endl;
        cout << "Volume: " << (3.14159 * radius * radius * height) << endl;
    }
};
int main()
{
    Taha ; //Faster I/O
    Cylinder myCylinder("Blue", 5.0, 10.0, 0.0, 0.0); // Circle attributes are relevant
    cout << "Cylinder Details:" << endl;
    myCylinder.displayCylinderInfo();
    return 0;
}
