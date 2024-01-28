#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 40;
const int MAX_COURSES = 5;  // Assuming each student can have up to 5 courses

// Define the Course structure
struct Course {
    string course_code;
    string course_name;
};

// Define the Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student structure
struct Student {
    string reg_number;
    string name;
    int age;
    Course courses[MAX_COURSES];
    Grade grades[MAX_COURSES];
};

// Function to calculate grade based on the mark
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

// Function to add a student
void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        cout << "Enter registration number: ";
        cin >> students[numStudents].reg_number;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, students[numStudents].name);

        cout << "Enter age: ";
        cin >> students[numStudents].age;

        // Assume each student has 3 courses for simplicity
        for (int i = 0; i < 3; ++i) {
            cout << "Enter course code for Course " << i + 1 << ": ";
            cin >> students[numStudents].courses[i].course_code;

            cout << "Enter course name for Course " << i + 1 << ": ";
            cin.ignore();
            getline(cin, students[numStudents].courses[i].course_name);
        }

        numStudents++;
        cout << "Student added successfully." << endl;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

// Function to edit a student's details
void editStudent(Student students[], int numStudents) {
    string regNumber;
    cout << "Enter registration number of the student to edit: ";
    cin >> regNumber;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_number == regNumber) {
            cout << "Enter new registration number: ";
            cin >> students[i].reg_number;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, students[i].name);

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Student details updated successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

// Function to add marks and calculate grades
void addMarksAndCalculateGrades(Student students[], int numStudents) {
    string regNumber;
    cout << "Enter registration number of the student to add marks: ";
    cin >> regNumber;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_number == regNumber) {
            // Assume each student has 3 courses for simplicity
            for (int j = 0; j < 3; ++j) {
                cout << "Enter mark for Course " << j + 1 << ": ";
                cin >> students[i].grades[j].mark;

                // Calculate grade based on the mark
                students[i].grades[j].the_grade = calculateGrade(students[i].grades[j].mark);
            }

            cout << "Marks and grades added successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

// Function to display student details
void displayStudentDetails(Student students[], int numStudents) {
    cout << "Student Details:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Registration Number: " << students[i].reg_number << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;

        // Display course details
        cout << "Courses:" << endl;
        for (int j = 0; j < 3; ++j) {
            cout << "  Course " << j + 1 << ": " << students[i].courses[j].course_code
                 << " - " << students[i].courses[j].course_name << endl;
        }

        // Display grades
        cout << "Grades:" << endl;
        for (int j = 0; j < 3; ++j) {
            cout << "  Course " << j + 1 << ": Mark = " << students[i].grades[j].mark
                 << ", Grade = " << students[i].grades[j].the_grade << endl;
        }

        cout << "-----------------------------------" << endl;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
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
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                editStudent(students, numStudents);
                break;
            case 3:
                addMarksAndCalculateGrades(students, numStudents);
                break;
            case 4:
                displayStudentDetails(students, numStudents);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
