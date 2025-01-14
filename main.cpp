#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string grade;
};

Student arr[100];
int studentCount = 0;

void AddStudent()
{
    if (studentCount >= 100)
    {
        cout << "Cannot add more students.Database is full.";
    }
    cout << "\033[2;94mEnter the student ID: ";
    cin >> arr[studentCount].id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, arr[studentCount].name);
    cout << "Enter the Student Age: ";
    cin >> arr[studentCount].age;
    cout << "Enter Student Grade: ";
    cin >> arr[studentCount].grade;
    studentCount++;
    cout << "Student added successfully" << endl;
}

void displayStudent()
{
    if (studentCount == 0)
    {
        cout << "No students to display." << endl;
        return;
    }
    cout << "\033[2;94mID\tName\t\tAge\tGrade\033[0m" << endl;
    for (int i = 0; i < studentCount; i++)
    {
        cout << arr[i].id << "\t" << arr[i].name << "\t\t" << arr[i].age << "\t" << arr[i].grade << endl;
    }
}

void searchStudent()
{
    int searchID;
    cout << "\033[1;94mEnter the Student ID to search: \033[0m";
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < studentCount; i++)
    {
        if (arr[i].id == searchID)
        {
            found = true;
            cout << "\033[2;94mStudent found\033[0m  " << endl;
            cout << "Student ID: " << arr[i].id << endl;
            cout << "Student Name: " << arr[i].name << endl;
            cout << "Student Age: " << arr[i].age << endl;
            cout << "Student Grade: " << arr[i].grade << endl;
        }
    }
    if (!found)
    {
        cout << "\033[2;94mStudent with ID " << searchID << " not found." << endl;
    }
}

void UpdateStudent()
{
    int studentId;
    cout << "\033[1;94mEnter the student ID to update:";
    cin >> studentId;
    bool found = false;
    for (int i = 0; i < studentCount; i++)
    {
        if (arr[i].id == studentId)
        {
            found = true;
            cout << "\033[2;94mEnter the new Name: ";
            cin >> arr[i].name;
            cout << "Enter the Age: ";
            cin >> arr[i].age;
            cout << "Enter the Grade: ";
            cin >> arr[i].grade;
        }
    }
    if (!found)
    {
        cout << "\033[2;94mStudent with ID " << studentId << " not found." << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\033[4;31mStudent Managment System\033[0m  " << endl;
        cout << "\033[1;34m1. Add Student" << endl;
        cout << "2. Display Student\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit System\033[0m" << endl;
        cout << "\033[1;36mEnter the choice: \033[0m";

        cin >> choice;

        switch (choice)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            UpdateStudent();
            break;
        case 5:
            cout << "Exiting the System." << endl;
            break;
        default:
            cout << "Invalid choice.Please try again." << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}