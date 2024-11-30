#include <bits/stdc++.h>
#define Taha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define el "\n"
#define sp " "
using namespace std;

class Complex
{
    int real, img;  // Real and imaginary parts of the complex number.

public:
    // Default constructor: Initializes real and imaginary parts to 0.
    Complex()
    {
        cout << "Default Ctor ..." << el;
        real = img = 0;
    }

    // Parameterized constructor: Initializes real and imaginary parts with given values.
    Complex(int r, int l)
    {
        cout << "Ctor ..." << el;
        real = r;
        img = l;
    }

    // Copy constructor: Copies values from another Complex object.
    Complex(const Complex &OldC)
    {
        cout << "Copy Ctor ..." << el;
        real = OldC.real;
        img = OldC.img;
    }

    // Destructor: Cleans up when the object goes out of scope.
    ~Complex()
    {
        cout << "Dest ..." << el;
    }

    // Getter for the real part.
    int GetReal()
    {
        return real;
    }

    // Getter for the imaginary part.
    int GetImg()
    {
        return img;
    }

    // Method to print the complex number in the form "real + img*i".
    void Print()
    {
        cout << "Complex Number is " << real << " +" << img << "i" << el;
    }

    // Sum function: Adds two Complex objects and returns the result.
    Complex Sum(const Complex &right)
    {
        Complex result(right.real + real, right.img + img);
        return result;
    }

    // Overloaded + operator for adding two Complex objects.
    Complex operator + (const Complex &right)
    {
        Complex result(right.real + real, right.img + img);
        return result;
    }

    // Overloaded + operator for adding an integer to a Complex object.
    Complex operator + (int right)
    {
        Complex result(right + real, img);
        return result;
    }

    // Overloaded += operator for adding a Complex object to the current one.
    Complex& operator += (const Complex &right)
    {
       real += right.real;
       img += right.img;
       return *this;
    }

    // Prefix increment operator: Increases the real part by 1.
    Complex & operator++ ()
    {
       real++;
       return *this;
    }

    // Postfix increment operator: Increases the real part by 1 and returns the old value.
    Complex operator ++(int)
    {
        Complex temp(*this);
        real++;
        return temp;
    }

    // Conversion operator to convert Complex to int (returns real part).
    operator int()
    {
        return real;
    }
};

// Friend function to add an integer to a Complex object.
Complex operator + (int l, Complex &right)
{
    Complex result(right.GetReal() + l, right.GetImg());
    return result;
}

int main()
{
    Taha;  // Enables faster I/O.

    // Creating Complex objects.
    Complex c1(3, 2), c2(4, 5), c3, c4;

    // Using the += operator to add c1 and c2, and assign the result to c3.
    c3 = c1 += c2;

    // Using the postfix increment operator to increment c1 and assign the result to c3.
    c3 = c1++;  // Post-increment: c3 gets the old value of c1.

    // Using the prefix increment operator to increment c2 and assign the result to c4.
    c4 = ++c2;  // Pre-increment: c2 is incremented before assignment.

    // Using the conversion operator to get the real part of c1 as an integer.
    int x = (int)c1;
    cout << x << el;

    // Printing the complex numbers after operations.
    c3.Print();
    c4.Print();

    return 0;
}
