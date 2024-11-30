#include <bits/stdc++.h> // Includes all standard libraries (use specific headers in real projects for better clarity and efficiency).
#define Tahtoh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) // Macro for fast input/output.
#define ll long long // Alias for long long data type.
#define el "\n" // Alias for newline character.
#define sp " " // Alias for a space character.
using namespace std;

// Encapsulation: Use private members to hide implementation details and control access via public methods.
// In C++, the default access modifier for a class is `private`, but in `struct` it's `public`.
// Explicitly set private members to enforce encapsulation.
struct Complex {
private:
    int real; // Represents the real part of a complex number.
    int img;  // Represents the imaginary part of a complex number.

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

    // Prints the complex number in the format "real+imgi".
    void Print() {
        cout << real << "+" << img << "i" << el;
    }
};

int main() {
    Tahtoh; // Activates fast input/output (optional for competitive programming).

    // Creating instances of `Complex` (allocated on the stack).
    Complex C1; // In C++, `struct` is a value type, not a reference type (like in .NET).
    Complex C2;

    // Old way (C-style): Directly accessing struct members.
    // Uncommenting these lines would show that accessing private members is not allowed.
    // C1.real = 7;
    // C1.img = 8;
    // cout << C1.real << "+" << C1.img << "i" << el;

    // New way (C++-style): Using encapsulation principles with getters and setters.
    C1.SetReal(7);
    C1.SetImag(3);

    C2.SetReal(6);
    C2.SetImag(2);

    // Using member functions to print values.
    // Member functions belong to the object and must be called on the object.
    C1.Print(); // Output: "7+3i"
    C2.Print(); // Output: "6+2i"

    return 0;
}
