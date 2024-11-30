#include <bits/stdc++.h>  // Includes all standard libraries (use specific headers for clarity and efficiency).
#define Tahtoh ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)  // Macro for fast input/output.
#define ll long long  // Alias for long long data type.
#define el "\n"  // Alias for newline character.
#define sp " "  // Alias for a space character.
using namespace std;

// StackV01 class demonstrates stack implementation with static array allocation.
class StackV01 {
    int Tos, stk[5];  // Tos: Top of stack, stk: static array for stack storage.
public:
    // Constructor to initialize stack and set Tos to 0.
    StackV01() {
        cout << "Ctor .." << el;  // Print message when constructor is called.
        Tos = 0;
    }

    // Function to check if the stack is full.
    bool ISFull() {
        return (Tos == 5);  // Stack is full when Tos reaches the size limit (5 in this case).
    }

    // Function to check if the stack is empty.
    bool ISEmpty() {
        return (Tos == 0);  // Stack is empty when Tos is 0.
    }

    // Function to push an element to the stack.
    void push(int N) {
        if (!ISFull())  // Only push if stack is not full.
            stk[Tos++] = N;
    }

    // Function to pop an element from the stack.
    int pop() {
        if (!ISEmpty())  // Only pop if stack is not empty.
            return stk[--Tos];  // Decrement Tos before returning value.
        return 0;  // Return 0 if stack is empty.
    }
};

// StackV02 class demonstrates stack implementation with dynamic memory allocation.
class StackV02 {
    int Tos, Size;  // Tos: Top of stack, Size: Stack size, stk: dynamic array for stack storage.
    int* stk;  // Pointer to dynamically allocated memory for stack.

public:
    // Constructor to initialize stack with dynamic memory allocation.
    StackV02(int L) {
        cout << "Ctor .." << el;  // Print message when constructor is called.
        Tos = 0;
        Size = L;
        stk = new int[Size];  // Dynamically allocate memory for stack based on size parameter.
    }

    // Function to check if the stack is full.
    bool ISFull() {
        return (Tos == Size);  // Stack is full when Tos reaches the dynamic size.
    }

    // Function to check if the stack is empty.
    bool ISEmpty() {
        return (Tos == 0);  // Stack is empty when Tos is 0.
    }

    // Function to push an element to the stack.
    void push(int N);

    // Function to pop an element from the stack.
    int pop();

    // Destructor to clean up dynamic memory allocation.
    ~StackV02() {
        cout << "Des ...." << el;  // Print message when destructor is called.
        delete[] stk;  // Deallocate dynamically allocated memory for the stack.
    }
};

// Member function definitions for StackV02 class using the scope operator `::`.
// These functions were declared inside the class but defined outside.
void StackV02::push(int N) {
    if (!ISFull())  // Only push if stack is not full.
        stk[Tos++] = N;
}

int StackV02::pop() {
    if (!ISEmpty())  // Only pop if stack is not empty.
        return stk[--Tos];  // Decrement Tos before returning value.
    return 0;  // Return 0 if stack is empty.
}

int main() {
    Tahtoh;  // Activates fast input/output .

    // With Static Allocation (currently commented out).
    // StackV01 S1;  // Static allocation for the StackV01 class.
    // S1.push(3);
    // S1.push(4);
    // S1.push(5);
    // cout << S1.pop() << el;
    // cout << S1.pop() << el;
    // cout << S1.pop() << el;
    // cout << S1.pop() << el;

    // With Dynamic Allocation using StackV02.
    StackV02 S2(5);  // Create a stack with dynamic size (5).
    S2.push(3);  // Push 3 to the stack.
    S2.push(4);  // Push 4 to the stack.
    S2.push(5);  // Push 5 to the stack.

    cout << S2.pop() << el;  // Pop and print top value (5).
    cout << S2.pop() << el;  // Pop and print next value (4).

    return 0;
}
