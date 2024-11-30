#include <bits/stdc++.h>  // Includes all standard libraries (use specific headers for clarity and efficiency).
#define Tahtoh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)  // Macro for fast input/output.
#define ll long long  // Alias for long long data type.
#define el "\n"  // Alias for newline character.
#define sp " "  // Alias for a space character.
using namespace std;

// Complex class demonstrates constructor overloading, encapsulation, and operator optimization.
class Complex {
    int real;  // Real part of the complex number.
    int img;   // Imaginary part of the complex number.
public:
    // Getter and Setter functions for real and imaginary parts of complex number.
    int GetReal() {
        return real;
    }

    int GetImag() {
        return img;
    }

    void SetReal(int r) {
        real = r;
    }

    void SetImag(int i) {
        img = i;
    }

    // Constructor to initialize with real and imaginary parts.
    Complex(int r, int i) {
        cout << "Ctor01 ... " << el;  // Output message when this constructor is called.
        real = r;
        img = i;
    }

    // Constructor to initialize with a single value for both real and imaginary parts.
    Complex(int l) {
        cout << "Ctor02 ... " << el;  // Output message when this constructor is called.
        real = img = l;
    }

    // Default constructor to initialize both real and imaginary parts to 0.
    Complex() {
        cout << "Ctor03 ... " << el;  // Output message when this constructor is called.
        real = img = 0;
    }

    // Sum function that creates a new object, adds the real and imaginary parts of the current and passed object,
    // and returns the result.
    Complex SumV1(Complex C) {
        Complex result;  // Local result object, default constructor called.
        result.real = real + C.real;
        result.img = img + C.img;
        return result;  // Return result, calling the copy constructor.
    }

    // Sum function using pass-by-reference to avoid creating unnecessary copies.
    // Using const to ensure the passed object is not modified.
    Complex SumV2(const Complex& C) {
        Complex result(real + C.real, img + C.img);  // Initialize result directly with sum of real and imaginary parts.
        // C.real = 0;  // This would result in compilation error because C is const.
        return result;  // Return result by value.
    }

    // Print function to display the complex number in "real + imagi" format.
    void Print() {
        cout << real << "+" << img << "i" << el;
    }

    // Destructor to print message when object is destroyed.
    ~Complex() {
        cout << "Dest ... " << el;  // Output message when this destructor is called.
    }
};

int main() {
    Tahtoh;  // Activates fast input/output

    // Create three complex numbers: C1 (3+4i), C2 (5+5i), and C3 (default constructor, 0+0i).
    Complex C1(3, 4), C2(5), C3;

    // Calling SumV1, which will use a temporary object and copy data.
    // After returning, the temporary object (result) will be destroyed.
    // Uncomment the following line to see the constructor/destructor calls:
    // C3 = C1.SumV1(C2);  // SumV1 is called, but the temporary object destructor may not be visible due to return value optimization (RVO).

    // Calling SumV2, which uses pass-by-reference and avoids unnecessary copying.
    C3 = C1.SumV2(C2);  // SumV2 is called, and result is stored in C3.

    return 0;
}
