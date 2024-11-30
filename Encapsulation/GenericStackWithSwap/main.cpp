#include <bits/stdc++.h>
#define Tahtoh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define el "\n"
#define sp " "
using namespace std;

/*
    Overloaded Swap functions for different types:
    This is commented out because we now use a templated version of Swap.

void Swap(int &x, int &Y)
{
    int temp = x;
    x = Y;
    Y = temp;
}

void Swap(double &x, double &Y)
{
    double temp = x;
    x = Y;
    Y = temp;
}

void Swap(string &x, string &Y)
{
    string temp = x;
    x = Y;
    Y = temp;
}
*/

template <class T>
// Template function to swap two values of any data type
void Swap(T &x, T &Y)
{
    T temp = x;  // Temporary variable to hold one value
    x = Y;        // Swap the values
    Y = temp;
}
// End of template function scope

template <class T1>
class Stack
{
    int Tos, Size;      // Tos = Top of stack, Size = Stack size
    T1 *stk;            // Pointer to dynamically allocated array to hold stack elements
    static int SNum;    // Static variable to keep track of the number of stack instances

public:
    // Constructor to initialize the stack with a specified size
    Stack(int _size)
    {
        cout << "Ctor .." << el;
        Tos = 0;               // Stack is empty initially
        Size = _size;          // Set stack size
        stk = new T1[Size];    // Dynamically allocate memory for the stack
        SNum++;                // Increment the number of Stack instances
    }

    // Copy constructor to create a copy of an existing stack
    Stack(const Stack &S)
    {
        cout << "Copy Ctor .." << el;
        Tos = S.Tos;           // Copy the top of the stack
        Size = S.Size;         // Copy the size of the stack
        stk = new T1[Size];    // Allocate new memory for the stack
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = S.stk[i];  // Copy the values from the old stack
        }
        SNum++;                 // Increment the number of Stack instances
    }

    // Destructor to clean up the memory when the stack is destroyed
    ~Stack()
    {
        cout << "Dest .." << el;
        delete[] stk;  // Release the dynamically allocated memory
        SNum--;         // Decrement the number of Stack instances
    }

    // Static function to get the current number of stack objects
    static int GetSNum()
    {
        return SNum;
    }

    // Function to get the current top of the stack (Tos)
    int GetTos()
    {
        return Tos;
    }

    // Function to get the value at a specific index in the stack
    T1 GetValuebyIndex(int i)
    {
        return stk[i];
    }

    // Function to check if the stack is full
    bool ISFull()
    {
        return (Tos == Size);  // Stack is full when Tos == Size
    }

    // Function to check if the stack is empty
    bool ISEmpty()
    {
        return (Tos == 0);  // Stack is empty when Tos == 0
    }

    // Function to push an element onto the stack if it's not full
    void push(T1 N)
    {
        if (!ISFull())
            stk[Tos++] = N;  // Push the element onto the stack and increment Tos
    }

    // Function to pop an element from the stack if it's not empty
    T1 pop()
    {
        if (!ISEmpty())
            return stk[--Tos];  // Return the popped element and decrement Tos
        return 0;  // Return 0 if the stack is empty
    }
};

// Initialize static member variable SNum to 0
template <class T1>
int Stack<T1>::SNum = 0;

int main()
{
    Tahtoh;  // Fast I/O

    int A = 5, B = 3;
    Swap(A, B);  // Swap values of A and B using type inference
    cout << "A is: " << A << el;
    cout << "B is: " << B << el;

    double D1 = 5.65, D2 = 3.258;
    Swap<double>(D1, D2);  // Explicitly specify the type for Swap
    cout << "D1 is: " << D1 << el;
    cout << "D2 is: " << D2 << el;

    string S1 = "Omar", S2 = "Ezz";
    Swap(S1, S2);  // Swap strings S1 and S2
    cout << "S1 is: " << S1 << el;
    cout << "S2 is: " << S2 << el;

    // Create a Stack of integers with size 5
    Stack<int> S(5);
    S.push(5);
    S.push(6);
    S.push(7);

    // Pop an element from the stack
    cout << S.pop() << el;

    return 0;
}
