#include <bits/stdc++.h>
using namespace std;

// Base Class: Person (Demonstrates Inheritance and Polymorphism)
class Person
{
protected:
    string name;
    int age;
    int id;

public:
    // Constructor
    Person(string personName, int personAge, int personID) : name(personName), age(personAge), id(personID) {}

    // Virtual Method (for Polymorphism)
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }

    // Virtual Destructor
    virtual ~Person() {}
};

// Derived Class: Student (Demonstrates Function Overriding)
class Student : public Person
{
private:
    vector<string> courses;
    vector<double> grades;

public:
    // Constructor
    Student(string studentName, int studentAge, int studentID) : Person(studentName, studentAge, studentID) {}
    // Function Overloading: Add Course with or without Grade
    void addCourse(string courseName)
    {
        courses.push_back(courseName);
        grades.push_back(0.0); // Default grade
    }

    void addCourse(string courseName, double grade)
    {
        courses.push_back(courseName);
        grades.push_back(grade);
    }
    // Calculate GPA
    double calculateGPA()
    {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (double grade : grades) sum += grade;
        return sum / grades.size();
    }

    // Overridden displayInfo Method
    void displayInfo() override
    {
        cout << "\n--- Student Information ---" << endl;
        Person::displayInfo();
        cout << "Courses and Grades:" << endl;
        for (size_t i = 0; i < courses.size(); ++i)
        {
            cout << "  " << courses[i] << ": " << grades[i] << endl;
        }
        cout << "GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
    }
};

// Derived Class: Teacher (Demonstrates Function Overriding)
class Teacher : public Person
{
private:
    string subject;
    double salary;

public:
    // Constructor
    Teacher(string teacherName, int teacherAge, int teacherID, string teacherSubject, double teacherSalary)
        : Person(teacherName, teacherAge, teacherID), subject(teacherSubject), salary(teacherSalary) {}

    // Overridden displayInfo Method
    //We can remove override keyword but if we write wrong of name for function compiler will think this is new method with new name
    void displayInfo()
    {
        cout << "\n--- Teacher Information ---" << endl;
        Person::displayInfo();
        cout << "Subject: " << subject << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};

// Derived Class: Administrator (Demonstrates Polymorphism with another role)
class Administrator : public Person
{
private:
    string department;

public:
    // Constructor
    Administrator(string adminName, int adminAge, int adminID, string dept)
        : Person(adminName, adminAge, adminID), department(dept) {}

    // Overridden displayInfo Method
    void displayInfo() override
    {
        cout << "\n--- Administrator Information ---" << endl;
        Person::displayInfo();
        cout << "Department: " << department << endl;
    }
};

// Function to demonstrate Polymorphism
void displayPersonDetails(Person *person)
{
    person->displayInfo(); // Calls the appropriate overridden method based on the object type
}

// Main Function
int main()
{
    // Creating objects of derived classes
    Student student("Alice Johnson", 20, 1001);
    student.addCourse("Mathematics", 90.5);
    student.addCourse("Physics", 85.0);

    Teacher teacher("Mr. Smith", 45, 2001, "Physics", 5000.0);
    Administrator admin("Laura Brown", 38, 3001, "Human Resources");

    // Demonstrating Polymorphism using base class pointers
    vector<Person*> people;
    people.push_back(&student);
    people.push_back(&teacher);
    people.push_back(&admin);

    cout << "\n========== Person Details (Polymorphism Demonstration) ==========" << endl;
    for (Person* person : people)
    {
        displayPersonDetails(person); // Polymorphism in action
    }

    return 0;
}
