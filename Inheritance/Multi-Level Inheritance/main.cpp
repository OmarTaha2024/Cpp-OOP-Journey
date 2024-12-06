/**                         Documentation section
_________________________________________________________________________________________________________________
-----------------------------------------------------------------------------------------------------------------
@name :  Multi-Level Inheritance
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
Multi-Level inheritance :
class which contain only one base class and multiple derive class
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

// Another derived class (inherits from Car) but can't access doors because it is private attributes
class ElectricCar : public Car
{
private:
    int batteryCapacity; // in kWh
public:
    ElectricCar(string b, string m, int d, int bc)
        : Car(b, m, d), batteryCapacity(bc) {}
    void displayInfo() const
    {
        // Call the parent class method
        Car::displayInfo();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

int main()
{
    Taha ; // Faster I/O
    ElectricCar myElectricCar("Tesla", "Model S", 4, 100);
    myElectricCar.displayInfo();


    return 0;
}
