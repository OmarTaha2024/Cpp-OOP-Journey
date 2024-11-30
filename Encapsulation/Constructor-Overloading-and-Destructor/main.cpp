#include <bits/stdc++.h>  // Includes all standard libraries (use specific headers for clarity and efficiency).
#define Tahtoh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) // Macro for fast input/output.
#define ll long long  // Alias for long long data type.
#define el "\n"  // Alias for newline character.
#define sp " "  // Alias for a space character.
using namespace std;

// Point2D class with no constructor explicitly defined.
// The compiler automatically generates a default constructor if not provided.
class Point2D {
    int x, y;
    // Default constructor generated by the compiler:
    // Point2D() {}  // Does nothing and does not initialize any values.
};

// Complex class that demonstrates constructor overloading and destructors.
class Complex {
    int real;  // Real part of the complex number.
    int img;   // Imaginary part of the complex number.

public:
    // Getter for the real part.
    int GetReal() {
        return real;
    }

    // Getter for the imaginary part.
    int GetImag() {
        return img;
    }

    // Setter for the real part.
    void SetReal(int r) {
        real = r;
    }

    // Setter for the imaginary part.
    void SetImag(int i) {
        img = i;
    }

    // Constructor with two parameters to initialize the complex number.
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    // Constructor with one parameter, sets both real and imaginary parts to the same value.
    Complex(int l) {
        real = img = l;
    }

    // Default constructor with no parameters, sets both parts to zero.
    Complex() {
        real = img = 0;
    }

    // Destructor, used to clean up if any dynamic memory allocation was used.
    // Here, no dynamic memory is used, so the destructor only prints a message when the object is destroyed.
    ~Complex() {
        cout << "Dest" << el;  // Print "Dest" when the object is destroyed.
    }

    // Print the complex number in the format "real+img i".
    void Print() {
        cout << real << "+" << img << "i" << el;
    }
};

int main() {
    Tahtoh;  // Activates fast input/output

    // Creating instances of Complex with different constructors.
    Complex C1(3, 4);  // Uses the constructor with two parameters.
    Complex C2(2);     // Uses the constructor with one parameter.

    // C3 would use the default constructor (but it's commented out for now).
    // Complex C3;  // Parameterless constructor with initialization to 0.

    // Point2D P1;  // Default constructor for Point2D, automatically created by the compiler.

    // Calling the Print method to display the complex numbers.
    C1.Print();  // Output: "3+4i"
    C2.Print();  // Output: "2+2i"

    return 0;
}
