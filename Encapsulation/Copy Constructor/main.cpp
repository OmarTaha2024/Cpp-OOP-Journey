#include <bits/stdc++.h>  // Includes all standard libraries (better to include only necessary headers).
#define Taha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)  // Macro for fast input/output.
#define ll long long  // Alias for long long data type.
#define el "\n"  // Alias for newline character.
#define sp " "  // Alias for a space character.
using namespace std;

// Stack class demonstrates constructor overloading, copy constructor, encapsulation, and friend functions.
class Stack {
    int Tos, Size;  // Tos tracks the top of the stack, Size is the maximum capacity.
    int *stk;  // Pointer to dynamically allocated array for the stack elements.
public:
    // Constructor to initialize the stack with a given size (default is 5).
    Stack(int L = 5) {
        cout << "Ctor .." << el;  // Output message when the constructor is called.
        Tos = 0;  // Stack is initially empty.
        Size = L;  // Initialize the size of the stack.
        stk = new int[Size];  // Dynamically allocate memory for the stack.
    }

    // Copy Constructor to perform deep copy (creating a new array for the stack elements).
    Stack(Stack &OldS) {
        Size = OldS.Size;  // Copy the size of the stack.
        Tos = OldS.Tos;  // Copy the current top of the stack.
        stk = new int[Size];  // Allocate new memory for the stack array.
        for (int i = 0; i < Tos; i++) {  // Copy each element from the old stack.
            stk[i] = OldS.stk[i];
        }
        cout << "copy Ctor .." << el;  // Output message when the copy constructor is called.
    }

    // Check if the stack is full (i.e., if the top has reached the maximum size).
    bool ISFull() {
        return (Tos == Size);
    }

    // Check if the stack is empty (i.e., no elements have been added).
    bool ISEmpty() {
        return (Tos == 0);
    }

    // Push a value onto the stack.
    void push(int N);

    // Pop a value from the stack.
    int pop();

    // Friend function to view the contents of the stack (can access private members).
    friend void viewcontent(Stack s);

    // Destructor to clean up the dynamically allocated memory when the object is destroyed.
    ~Stack() {
        cout << "Des ...." << el;  // Output message when the destructor is called.
        for (int i = 0; i < 5; i++)  // Clean up the stack by setting its elements to -1 (optional).
            stk[i] = -1;
        delete[] stk;  // Deallocate the dynamically allocated memory.
    }
};

// Push a value onto the stack (member function).
void Stack::push(int N) {
    if (!ISFull())  // If the stack is not full, add the new element.
        stk[Tos++] = N;
}

// Pop a value from the stack (member function).
int Stack::pop() {
    if (!ISEmpty())  // If the stack is not empty, return the top element and decrement Tos.
        return stk[--Tos];
    return 0;  // If the stack is empty, return 0 as a placeholder (could handle error more gracefully).
}

// Friend function to view the stack's contents (accesses private members of the stack).
void viewcontent(Stack s) {  // Pass by reference to avoid unnecessary copying.
    cout << "stack content .." << sp;

    // Print all elements of the stack from the bottom to the top.
    for (int i = 0; i < s.Tos; i++) {
        cout << s.stk[i] << sp;
    }
    cout << el;

    // You can modify the stack's contents because friend functions can access private members.
    s.stk[2] = 15;  // This directly modifies the stack's third element (not a good practice).
}

int main() {
    Taha;  // Fast input/output setup.

    // Create a stack of size 5 and push some values onto it.
    Stack S1(5);
    S1.push(3);
    S1.push(4);
    S1.push(5);

    // View the contents of the stack using the friend function.
    viewcontent(S1);

    // Pop values from the stack and display them.
    cout << S1.pop() << el;
    return 0;
}
