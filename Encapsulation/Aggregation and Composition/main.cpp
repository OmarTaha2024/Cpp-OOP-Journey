#include <bits/stdc++.h>
#define Taha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define el "\n"
#define sp " "

using namespace std;

// Point Class: Represents a point in 2D space
class Point
{
    int X, Y;  // Coordinates of the point
public:
    // Default Constructor
    Point()
    {
        X = Y = 0;
        cout << "Default Ctor" << el;
    }

    // Constructor that initializes both X and Y with the same value
    Point(int _N)
    {
        X = Y = _N;
        cout << "Ctor 01" << el;
    }

    // Constructor that initializes X and Y with different values
    Point(int _x, int _y)
    {
        X = _x;
        Y = _y;
        cout << "Ctor 02" << el;
    }

    // Destructor
    ~Point()
    {
        cout << "Dest" << el;
    }

    // Getter for X
    int GetX()
    {
        return X;
    }

    // Getter for Y
    int GetY()
    {
        return Y;
    }

    // Setter for X
    void SetX(int _x)
    {
        X = _x;
    }

    // Setter for Y
    void SetY(int _y)
    {
        Y = _y;
    }

    // Display the point as (X, Y)
    void Show()
    {
        cout << "(" << X << "," << Y << ")" << el;
    }
};

/// Rectangle Class: Example of Composition (Point objects as members)
class Rectangle
{
    Point UL, LR;  // Upper-left and lower-right corners of the rectangle
    int color;     // Color of the rectangle

public:
    // Default Constructor
    Rectangle()
    {
        cout << "Parameterless of Rect.." << el;
        color = 0;
    }

    // Parameterized Constructor (Uses Constructor Chaining for Points)
    Rectangle(int x1, int y1, int x2, int y2, int c) : UL(x1, y1), LR(x2, y2)
    {
        cout << "Ctor of Rect.." << el;
        color = c;
    }

    // Destructor
    ~Rectangle()
    {
        cout << "Dest of Rect.." << el;
    }

    // Draw Method: Simulates drawing the rectangle
    void Draw()
    {
        // For now, just print rectangle information
        cout << "Drawing Rectangle from ";
        UL.Show();
        cout << " to ";
        LR.Show();
        cout << " with color " << color << el;
    }
};

/// Picture Class: Example of Aggregation (Manages an array of Rectangle objects)
class Picture
{
    int Rnum;            // Number of rectangles in the picture
    Rectangle *Rarr;     // Dynamic array of rectangles

public:
    // Default Constructor
    Picture()
    {
        cout << "Parameterless Picture Ctor..." << el;
        Rarr = NULL;
        Rnum = 0;
    }

    // Parameterized Constructor
    Picture(Rectangle *Prect, int R)
    {
        cout << "Pict Ctor..." << el;
        Rarr = Prect;
        Rnum = R;
    }

    // Destructor
    ~Picture()
    {
        cout << "Pict Dest..." << el;
    }

    // Setter for Rectangles
    void SetRect(Rectangle *Prect, int R)
    {
        Rarr = Prect;
        Rnum = R;
    }

    // Method to draw all rectangles in the picture
    void PicturePaint()
    {
        for (int i = 0; i < Rnum; i++)
        {
            Rarr[i].Draw();
        }
    }
};

int main()
{
    Taha;  // Faster I/O
    /* Example Usage
       Rectangle R1(20, 30, 15, 25, 2);
       R1.Draw(); // Call the Draw method to see the output
    */

    // Dynamically create an array of rectangles
    Rectangle *Prect;
    Prect = new Rectangle[2]{
        Rectangle(10, 10, 200, 200, 3),  // Rectangle 1
        Rectangle(20, 30, 350, 320, 2)  // Rectangle 2
    };

    // Create a Picture object
    Picture p1;
    p1.SetRect(Prect, 2);  // Set the rectangles for the picture
    p1.PicturePaint();     // Draw the picture

    // Clean up dynamically allocated memory
    delete[] Prect;
    p1.SetRect(NULL, 0);  // Reset the picture

    return 0;
}
