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
    Person(string personName, int personAge, int personID) : name(personName), age(personAge), id(personID) {}

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

    // Calculate GPA
    double calculateGPA() {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (double grade : grades) sum += grade;
        return sum / grades.size();
    }

    // Display Student Information
    void displayStudentInfo() {
        cout << "\n--- Student Information ---" << endl;
        displayPersonInfo();
        cout << "Courses and Grades:" << endl;
        for (size_t i = 0; i < courses.size(); ++i) {
            cout << "  " << courses[i] << ": " << grades[i] << endl;
        }
        cout << "GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
    }
};

// Derived Class: Teacher (inherits from Person)
class Teacher : public Person {
private:
    string subject;
    double salary;
    vector<string> coursesTaught;

public:
    // Constructor
    Teacher(string teacherName, int teacherAge, int teacherID, string teacherSubject, double teacherSalary)
        : Person(teacherName, teacherAge, teacherID), subject(teacherSubject), salary(teacherSalary) {}

    // Assign Course to Teacher
    void assignCourse(string courseName) {
        coursesTaught.push_back(courseName);
    }

    // Display Teacher Information
    void displayTeacherInfo() {
        cout << "\n--- Teacher Information ---" << endl;
        displayPersonInfo();
        cout << "Subject: " << subject << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
        cout << "Courses Taught:" << endl;
        for (const string &course : coursesTaught) cout << "  " << course << endl;
    }
};

// School Management System
class SchoolManagementSystem {
private:
    vector<Student> students;
    vector<Teacher> teachers;

public:
    // Add a student
    void addStudent(Student student) {
        students.push_back(student);
    }

    // Add a teacher
    void addTeacher(Teacher teacher) {
        teachers.push_back(teacher);
    }

    // Display all students
    void displayAllStudents() {
        cout << "\n========== All Students ==========" << endl;
        for (Student &student : students) student.displayStudentInfo();
    }

    // Display all teachers
    void displayAllTeachers() {
        cout << "\n========== All Teachers ==========" << endl;
        for (Teacher &teacher : teachers) teacher.displayTeacherInfo();
    }
};

// Main Function
int main() {
    SchoolManagementSystem system;

    // Create Students
    Student student1("Alice Johnson", 20, 1001);
    student1.addCourse("Mathematics", 90.5);
    student1.addCourse("Physics", 85.0);
    student1.addCourse("Computer Science", 95.0);

    Student student2("Bob Smith", 22, 1002);
    student2.addCourse("Mathematics", 78.0);
    student2.addCourse("English", 88.5);
    student2.addCourse("History", 82.0);

    // Create Teachers
    Teacher teacher1("Mr. Smith", 45, 2001, "Physics", 5000.0);
    teacher1.assignCourse("Physics");
    teacher1.assignCourse("Mathematics");

    Teacher teacher2("Ms. Davis", 39, 2002, "English", 4800.0);
    teacher2.assignCourse("English");

    // Add students and teachers to the system
    system.addStudent(student1);
    system.addStudent(student2);
    system.addTeacher(teacher1);
    system.addTeacher(teacher2);

    // Display information
    system.displayAllStudents();
    system.displayAllTeachers();

    return 0;
}
