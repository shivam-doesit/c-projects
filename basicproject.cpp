#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to hold student records
struct Student {
    int rollNo;
    string name;
    string fatherName;
    string dob;  // Date of birth in string format (e.g., "DD/MM/YYYY")
    string branch;
    int yearOfAdmission;
    int tentativeYearOfPassing;
    string state;
    string pin;
    string country;
};

// Function to add a new student record
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter Roll No: ";
    cin >> newStudent.rollNo;
    cin.ignore(); // Ignore the newline character left by the last input
    cout << "Enter Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Father's Name: ";
    getline(cin, newStudent.fatherName);
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, newStudent.dob);
    cout << "Enter Branch: ";
    getline(cin, newStudent.branch);
    cout << "Enter Year of Admission: ";
    cin >> newStudent.yearOfAdmission;
    cout << "Enter Tentative Year of Passing: ";
    cin >> newStudent.tentativeYearOfPassing;
    cin.ignore(); // Ignore the newline character left by the last input
    cout << "Enter State: ";
    getline(cin, newStudent.state);
    cout << "Enter PIN: ";
    getline(cin, newStudent.pin);
    cout << "Enter Country: ";
    getline(cin, newStudent.country);

    students.push_back(newStudent);
}

// Function to update a student's record
void updateStudent(vector<Student>& students, int rollNo) {
    bool found = false;
    for (auto& student : students) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "Updating record for Roll No: " << rollNo << endl;
            cout << "Enter new Name: ";
            getline(cin, student.name);
            cout << "Enter new Father's Name: ";
            getline(cin, student.fatherName);
            cout << "Enter new Date of Birth (DD/MM/YYYY): ";
            getline(cin, student.dob);
            cout << "Enter new Branch: ";
            getline(cin, student.branch);
            cout << "Enter new Year of Admission: ";
            cin >> student.yearOfAdmission;
            cout << "Enter new Tentative Year of Passing: ";
            cin >> student.tentativeYearOfPassing;
            cin.ignore(); // Ignore the newline character left by the last input
            cout << "Enter new State: ";
            getline(cin, student.state);
            cout << "Enter new PIN: ";
            getline(cin, student.pin);
            cout << "Enter new Country: ";
            getline(cin, student.country);
            break;
        }
    }
    if (!found) {
        cout << "Record with Roll No: " << rollNo << " not found!" << endl;
    }
}

// Function to delete a student's record
void deleteStudent(vector<Student>& students, int rollNo) {
    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == rollNo) {
            students.erase(it);
            found = true;
            cout << "Record with Roll No: " << rollNo << " deleted successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Record with Roll No: " << rollNo << " not found!" << endl;
    }
}

// Function to generate a report based on the common name
void reportByName(const vector<Student>& students, const string& name) {
    cout << "Students with name '" << name << "':" << endl;
    bool found = false;
    for (const auto& student : students) {
        if (student.name == name) {
            cout << "Roll No: " << student.rollNo << ", Father's Name: " << student.fatherName << ", DOB: " << student.dob
                 << ", Branch: " << student.branch << ", Year of Admission: " << student.yearOfAdmission
                 << ", Tentative Year of Passing: " << student.tentativeYearOfPassing << ", State: " << student.state
                 << ", PIN: " << student.pin << ", Country: " << student.country << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with the name '" << name << "'!" << endl;
    }
}

// Function to generate a report based on the common state
void reportByState(const vector<Student>& students, const string& state) {
    cout << "Students from state '" << state << "':" << endl;
    bool found = false;
    for (const auto& student : students) {
        if (student.state == state) {
            cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", Father's Name: " << student.fatherName
                 << ", DOB: " << student.dob << ", Branch: " << student.branch << ", Year of Admission: " << student.yearOfAdmission
                 << ", Tentative Year of Passing: " << student.tentativeYearOfPassing << ", State: " << student.state
                 << ", PIN: " << student.pin << ", Country: " << student.country << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found from the state '" << state << "'!" << endl;
    }
}

// Function to generate a report based on the common district (PIN code)
void reportByPIN(const vector<Student>& students, const string& pin) {
    cout << "Students with PIN code '" << pin << "':" << endl;
    bool found = false;
    for (const auto& student : students) {
        if (student.pin == pin) {
            cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", Father's Name: " << student.fatherName
                 << ", DOB: " << student.dob << ", Branch: " << student.branch << ", Year of Admission: " << student.yearOfAdmission
                 << ", Tentative Year of Passing: " << student.tentativeYearOfPassing << ", State: " << student.state
                 << ", PIN: " << student.pin << ", Country: " << student.country << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with the PIN code '" << pin << "'!" << endl;
    }
}

int main() {
    vector<Student> students;  // Using a vector to store student records
    int choice;

    while (true) {
        cout << "\nClass Records Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Report by Name\n";
        cout << "5. Report by State\n";
        cout << "6. Report by PIN\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after integer input

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2: {
                int rollNo;
                cout << "Enter Roll No to update: ";
                cin >> rollNo;
                cin.ignore();
                updateStudent(students, rollNo);
                break;
            }
            case 3: {
                int rollNo;
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                cin.ignore();
                deleteStudent(students, rollNo);
                break;
            }
            case 4: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                reportByName(students, name);
                break;
            }
            case 5: {
                string state;
                cout << "Enter state to search: ";
                getline(cin, state);
                reportByState(students, state);
                break;
            }
            case 6: {
                string pin;
                cout << "Enter PIN to search: ";
                getline(cin, pin);
                reportByPIN(students, pin);
                break;
            }
            case 7:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
