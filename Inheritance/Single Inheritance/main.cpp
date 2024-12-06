/**                         Documentation section
_________________________________________________________________________________________________________________
-----------------------------------------------------------------------------------------------------------------
@name :   Single Inheritance
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
single inheritance :
class which contain only one base class and only
one derive class
**/
// Base class
class Vehicle
{
protected:
    string brand;
    string model;

public:
    Vehicle(string b, string m) : brand(b), model(m) {}

    void displayInfo() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

// Derived class
class Car : public Vehicle
{
private:
    int doors;

public:
    Car(string b, string m, int d) : Vehicle(b, m), doors(d) {}

    void displayInfo() const
    {
        // Call the base class method
        Vehicle::displayInfo();
        cout << "Number of Doors: " << doors << endl;
    }
};

int main()
{
    Taha ; // Faster I/O
    Car myCar("Toyota", "Corolla", 4);
    myCar.displayInfo();



    return 0;
}
