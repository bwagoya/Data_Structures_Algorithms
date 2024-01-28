#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Course {
public:
    string course_code;
    string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;

    // Constructor to calculate grade based on the mark
    Grade(int mark) : mark(mark) {
        if (mark > 69)
            the_grade = 'A';
        else if (mark > 59)
            the_grade = 'B';
        else if (mark > 49)
            the_grade = 'C';
        else if (mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }
};

class Student {
public:
    string reg_number;
    string name;
    int age;
    vector<Course> courses;
    vector<Grade> grades;

    // Member function to add a course
    void addCourse(const string& course_code, const string& course_name) {
        Course newCourse = {course_code, course_name};
        courses.push_back(newCourse);
    }

    // Member function to add a grade
    void addGrade(int mark) {
        Grade newGrade = Grade(mark);
        grades.push_back(newGrade);
    }

    // Member function to display student details
    void displayDetails() const {
        cout << "Registration Number: " << reg_number << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;

        // Display course details
        cout << "Courses:" << endl;
        for (const Course& course : courses) {
            cout << "  Course: " << course.course_code << " - " << course.course_name << endl;
        }

        // Display grades
        cout << "Grades:" << endl;
        for (const Grade& grade : grades) {
            cout << "  Mark = " << grade.mark << ", Grade = " << grade.the_grade << endl;
        }

        cout << "-----------------------------------" << endl;
    }
};

int main() {
    unordered_map<string, Student> studentMap;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Edit a student's details" << endl;
        cout << "3. Add marks and calculate grades" << endl;
        cout << "4. Display student details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent;
                cout << "Enter registration number: ";
                cin >> newStudent.reg_number;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, newStudent.name);

                cout << "Enter age: ";
                cin >> newStudent.age;

                // Assume each student has 3 courses for simplicity
                for (int i = 0; i < 3; ++i) {
                    string courseCode, courseName;
                    cout << "Enter course code for Course " << i + 1 << ": ";
                    cin >> courseCode;

                    cout << "Enter course name for Course " << i + 1 << ": ";
                    cin.ignore();
                    getline(cin, courseName);

                    newStudent.addCourse(courseCode, courseName);
                }

                studentMap[newStudent.reg_number] = newStudent;
                cout << "Student added successfully." << endl;
                break;
            }
            case 2: {
                string regNumber;
                cout << "Enter registration number of the student to edit: ";
                cin >> regNumber;

                auto it = studentMap.find(regNumber);
                if (it != studentMap.end()) {
                    cout << "Enter new registration number: ";
                    cin >> it->second.reg_number;

                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, it->second.name);

                    cout << "Enter new age: ";
                    cin >> it->second.age;

                    cout << "Student details updated successfully." << endl;
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 3: {
                string regNumber;
                cout << "Enter registration number of the student to add marks: ";
                cin >> regNumber;

                auto it = studentMap.find(regNumber);
                if (it != studentMap.end()) {
                    // Assume each student has 3 courses for simplicity
                    for (int j = 0; j < 3; ++j) {
                        int mark;
                        cout << "Enter mark for Course " << j + 1 << ": ";
                        cin >> mark;

                        it->second.addGrade(mark);
                    }

                    cout << "Marks and grades added successfully." << endl;
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Student Details:" << endl;
                for (const auto& entry : studentMap) {
                    const Student& student = entry.second;
                    student.displayDetails();
                }
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

