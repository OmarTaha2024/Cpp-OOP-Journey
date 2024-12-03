#include <iostream>

using namespace std;
class Base
{
protected :
    int x ;
public :
    /// Constructor
    Base(int _x=0)
    {
        x=_x;
        cout<<"Base Ctor"<<endl;
    }
    /// Virtual destructor to ensure proper cleanup
    virtual ~Base()
    {
        cout << "Base Dtor" << endl;
    }
    /// Non-virtual method
    void Show()
    {
        cout<<"I am Base "<<endl;
    }
    /// Dynamically binded Method , should be public method
    virtual void DyShow()
    {
        cout<<"Base "<<endl;
    }

};
class Derived : public Base
{
protected:
    int y ;
public :
    Derived(int _x=0,int _y = 0):Base(_x)
    {
        y = _y;
        cout<<"Derived Ctor"<<endl;
    }

    /// Destructor
    ~Derived()
    {
        cout << "Derived Dtor" << endl;
    }
    void Show()
    {
        cout<<"I am Derived "<<endl;
    }
/// with public inheritance , and override with public method
    void DyShow()
    {
        cout<<"Derived "<<endl;
    }

};

class DerivedL02 : public Derived
{
protected:
    int z ;
public :
    DerivedL02(int _x=0,int _y =0,int _z = 0):Derived(_x,_y)
    {
        z = _z;
        cout<<"Derived L02 Ctor"<<endl;
    }
    ~DerivedL02()
    {
        cout << "Derived L02 Dtor" << endl;
    }
    void Show()
    {
        cout<<"I am Derived L02 "<<endl;
    }
/// with public inheritance , and override with public method
    void DyShow()
    {
        cout<<"Derived L02 "<<endl;
    }

};
int main()
{
    /* Base B(1);
     B.Show();///Base

     Derived D(2,3);
     D.Show(); ///Derived


     Base *BPtr = new Base(4); /// Base
     BPtr->Show();


     Derived *DPtr = new Derived(2,3); /// Derived
     DPtr->Show();

     BPtr = new Derived(7,8);/// valid
     BPtr->Show();///Base
     /// statically Binded method (Early Binding)
     ///Compiler Bind function call statement with function definetion
     /// by compiler @ compilation based on pointer type


     BPtr->DyShow();///Base
     /// Dynamiclly Binded method (lated Binding)
     ///OS (Run Time) Bind function call to function body
     /// at Run Time (not compilation time) based on object type (not pointer type)
     */
 // Create a Base pointer pointing to a DerivedL02 object
    Base *BPtr = new DerivedL02(2, 3, 4);
    BPtr->DyShow(); /// Output: Derived L02

    // Deleting the pointer to invoke destructors
    delete BPtr; /// Ensures DerivedL02, Derived, and Base destructors are called

    // Create a Derived pointer pointing to a DerivedL02 object
    Derived *Dptr = new DerivedL02(5, 6, 7);
    Dptr->DyShow(); /// Output: Derived L02

    // Deleting the pointer to invoke destructors
    delete Dptr; /// Ensures DerivedL02 and Derived destructors are called
    return 0;
}
