#include <iostream>

using namespace std;

// Abstract Base Class for Geometric Shapes
class GeoShapes {
protected:
    int D1, D2; // Dimensions of the shape

public:
    // Constructor with default values
    GeoShapes(int _D1 = 0, int _D2 = 0) {
        D1 = _D1;
        D2 = _D2;
        cout << "GeoShapes Constructor...\n";
    }

    // Getter for the first dimension
    int GetDim1() {
        return D1;
    }

    // Getter for the second dimension
    int GetDim2() {
        return D2;
    }

    // Setter for the first dimension
    void setDim1(int _D1) {
        D1 = _D1;
    }

    // Setter for the second dimension
    void setDim2(int _D2) {
        D2 = _D2;
    }

    // Pure virtual function to calculate the area of the shape
    virtual float Carea() = 0;
    /*
        Optionally, you could provide a default implementation:
        virtual float Carea() {
            return 0;
        }
    */
};

// Rectangle class derived from GeoShapes
class Rect : public GeoShapes {
public:
    // Constructor initializing the dimensions of the rectangle
    Rect(int W, int H) : GeoShapes(W, H) {}

    // Override to calculate the area of the rectangle
    float Carea() override {
        return D1 * D2;
    }
};

// Square class derived from Rect
class square : public Rect {
public:
    // Constructor initializing the side length of the square
    square(int L) : Rect(L, L) {}

    // Override to calculate the area of the square
    float Carea() override {
        return D1 * D2; // Square area = side^2
    }

    // Setter for dimension 1 with constraints specific to a square
    void setDim1(int _D1) {
        D1 = D2 = _D1;
    }

    // Setter for dimension 2 with constraints specific to a square
    void setDim2(int _D2) {
        D2 = D1 = _D2;
    }
};

// Triangle class derived from GeoShapes
class triangle : public GeoShapes {
public:
    // Constructor initializing the base and height of the triangle
    triangle(int W, int H) : GeoShapes(W, H) {}

    // Override to calculate the area of the triangle
    float Carea() override {
        return 0.5 * D1 * D2;
    }
};

// Function to calculate the sum of areas for all shapes using polymorphism
float SumOfGeoAreas(GeoShapes *Gptr[], int N) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += Gptr[i]->Carea(); // Dynamically bind Carea based on object type
    }
    return sum;
}

/*
    Function to calculate the sum of areas for shapes based on type.
    This function is less flexible than using polymorphism.
*/
float SumOfAreas(Rect *Rarr, int R, square *Sarr, int S, triangle *Tarr, int T) {
    float RSum = 0;
    for (int i = 0; i < R; i++) {
        RSum += Rarr[i].Carea();
    }

    float SSum = 0;
    for (int i = 0; i < S; i++) {
        SSum += Sarr[i].Carea();
    }

    float TSum = 0;
    for (int i = 0; i < T; i++) {
        TSum += Tarr[i].Carea();
    }

    return RSum + SSum + TSum; // Total sum of areas
}

int main() {
    // Declare and initialize arrays of specific shapes
    Rect Rarr[2] = {Rect(10, 20), Rect(15, 5)};
    square Sarr[3] = {square(10), square(5), square(8)};
    triangle tarr[2] = {triangle(10, 2), triangle(5, 10)};

    // Calculate and print the sum of areas using the type-specific function
    cout << "Sum of Areas (Type-Specific): " << SumOfAreas(Rarr, 2, Sarr, 3, tarr, 2) << endl;

    // Create a polymorphic array of pointers to GeoShapes
    GeoShapes *Garr[7] = {Rarr, &Rarr[1], Sarr, &Sarr[1], &Sarr[2], tarr, &tarr[1]};

    // Calculate and print the sum of areas using polymorphism
    cout << "Sum of Areas (Polymorphic): " << SumOfGeoAreas(Garr, 7) << endl;

    return 0;
}
