#include <bits/stdc++.h>
#define Tahtoh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define el "\n"
#define sp " "
using namespace std;

class Stack
{
    int Tos, Size;      // Tos = Top of Stack, Size = Maximum size of the stack
    int *stk;           // Pointer to dynamically allocated array for stack storage
    static int SNum;    // Static member to keep track of the number of Stack objects

public:
    // Constructor to initialize the stack with a given size
    Stack(int _size)
    {
        cout << "Ctor .." << el;
        Tos = 0;                 // Initially the stack is empty
        Size = _size;           // Set stack size
        stk = new int[Size];    // Dynamically allocate memory for the stack
        SNum++;                 // Increment the count of Stack objects
    }

    // Copy Constructor: Creates a new Stack as a copy of an existing one
    Stack(const Stack &S)
    {
        cout << "Copy Ctor .." << el;
        Tos = S.Tos;              // Copy top of stack
        Size = S.Size;            // Copy size
        stk = new int[Size];      // Allocate new memory for stack
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = S.stk[i];    // Copy the values from the old stack
        }
        SNum++;                   // Increment the count of Stack objects
    }

    // Destructor: Cleans up the allocated memory when the object is destroyed
    ~Stack()
    {
        cout << "Dest .." << el;
        delete[] stk;  // Release memory used by the stack
        SNum--;         // Decrement the count of Stack objects
    }

    // Static function to get the current number of Stack objects
    static int GetSNum()
    {
        return SNum;
    }

    // Function to get the current top of the stack (Tos)
    int GetTos()
    {
        return Tos;
    }

    // Function to get the value at a specific index of the stack
    int GetValuebyIndex(int i)
    {
        return stk[i];
    }

    // Function to check if the stack is full
    bool ISFull()
    {
        return (Tos == Size);  // Returns true if stack is full
    }

    // Function to check if the stack is empty
    bool ISEmpty()
    {
        return (Tos == 0);  // Returns true if stack is empty
    }

    // Pushes an element onto the stack if it's not full
    void push(int N)
    {
        if (!ISFull())
            stk[Tos++] = N;
    }

    // Pops an element from the stack if it's not empty
    int pop()
    {
        if (!ISEmpty())
            return stk[--Tos];
        return 0;  // Return 0 if the stack is empty
    }
};

// Initialize the static member SNum to 0
int Stack::SNum = 0;

// Function to display the contents of a stack
void ViewContent(Stack &S)
{
    for (int i = 0; i < S.GetTos(); i++)
    {
        cout << S.GetValuebyIndex(i) << sp;  // Print each element in the stack
    }
    cout << el;
}

int main()
{
    Tahtoh;  // Faster I/O

    // Display initial stack count (before any stacks are created)
    cout << "Initial Stack Count: " << Stack::GetSNum() << el;

    // Create stack S1 with size 5 and push elements
    Stack S1(5);
    S1.push(5);
    S1.push(6);
    S1.push(7);

    // Display the stack count after creating S1
    cout << "Stack Count After S1: " << Stack::GetSNum() << el;

    // Create stack S2 with size 3 and push elements
    Stack S2(3);
    S2.push(1);
    S2.push(2);

    // Display the stack count after creating S2
    cout << "Stack Count After S2: " << Stack::GetSNum() << el;

    // Display the contents of S1
    ViewContent(S1);

    return 0;
}
