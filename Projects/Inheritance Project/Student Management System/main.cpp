#include <bits/stdc++.h>

using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    int age;
    int id;

public:
    // Constructor
    Person(string personName, int personAge, int personID) {
        name = personName;
        age = personAge;
        id = personID;
    }

    // Display Person Information
    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

// Derived Class: Student (inherits from Person)
class Student : public Person {
private:
    vector<string> courses;
    vector<double> grades;

public:
    // Constructor
    Student(string studentName, int studentAge, int studentID) : Person(studentName, studentAge, studentID) {}

    // Add Course and Grade
    void addCourse(string courseName, double grade) {
        courses.push_back(courseName);
        grades.push_back(grade);
    }

    // Display Student Information
    void displayStudentInfo() {
        cout << "\n--- Student Information ---" << endl;
       displayPersonInfo();
        cout << "Courses and Grades:" << endl;
        for (size_t i = 0; i < courses.size(); ++i) {
            cout << courses[i] << ": " << grades[i] << endl;
        }
    }
};

// Derived Class: Teacher (inherits from Person)
class Teacher : public Person {
private:
    string subject;
    double salary;

public:
    // Constructor
    Teacher(string teacherName, int teacherAge, int teacherID, string teacherSubject, double teacherSalary)
        : Person(teacherName, teacherAge, teacherID), subject(teacherSubject), salary(teacherSalary) {}

    // Display Teacher Information
    void displayTeacherInfo() {
        cout << "\n--- Teacher Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Main Function
int main() {
    // Creating Student Object
    Student student1("Alice Johnson", 20, 1001);
    student1.addCourse("Mathematics", 89.5);
    student1.addCourse("Physics", 92.0);
    student1.addCourse("Computer Science", 95.5);

    // Creating Teacher Object
    Teacher teacher1("Mr. Smith", 45, 2001, "Physics", 5000.0);

    // Displaying Information
    student1.displayStudentInfo();
    teacher1.displayTeacherInfo();

    return 0;
}
