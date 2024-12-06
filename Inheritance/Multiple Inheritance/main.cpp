/**                         Documentation section
_________________________________________________________________________________________________________________
-----------------------------------------------------------------------------------------------------------------
@name :   Multiple Inheritance
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
Multiple inheritance :
class which contain more base class and only
one derive class
**/

// First base class
class Engine
{
protected:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    void displayEngineInfo() const
    {
        cout << "Horsepower: " << horsepower << " HP" << endl;
    }
};

// Second base class
class Transmission
{
protected:
    string type;

public:
    Transmission(string t) : type(t) {}

    void displayTransmissionInfo() const
    {
        cout << "Transmission Type: " << type << endl;
    }
};

// Derived class
class Car : public Engine, public Transmission
{
private:
    string brand;
    string model;

public:
    Car(string b, string m, int hp, string t)
        : Engine(hp), Transmission(t), brand(b), model(m) {}

    void displayCarInfo() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        displayEngineInfo();
        displayTransmissionInfo();
    }
};
int main()
{
    Taha; //Faster I/O
    Car myCar("Tesla", "Model S", 670, "Automatic");
    myCar.displayCarInfo();
    return 0;
}
