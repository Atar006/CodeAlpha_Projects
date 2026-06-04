// CodeAlpha Internship - Task 1: CGPA Calculator
// Intern: Atar Ali
// Description: Takes course grades and credit hours, calculates GPA and CGPA

#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "============================" << endl;
    cout << "   CGPA Calculator" << endl;
    cout << "============================" << endl;

    int numCourses;
    cout << "\nEnter number of courses: ";
    cin >> numCourses;

    string courseNames[20];
    float  creditHours[20];
    float  gradePoints[20];

    float totalCredits    = 0;
    float totalGradePoints = 0;

    cout << "\nGrade points scale:" << endl;
    cout << "A = 4.0 | B = 3.0 | C = 2.0 | D = 1.0 | F = 0.0" << endl;
    cout << endl;

    for (int i = 0; i < numCourses; i++) {
        cout << "--- Course " << i + 1 << " ---" << endl;

        cout << "Course name   : ";
        cin.ignore();
        getline(cin, courseNames[i]);

        cout << "Credit hours  : ";
        cin >> creditHours[i];

        cout << "Grade points  : ";
        cin >> gradePoints[i];

        totalCredits     += creditHours[i];
        totalGradePoints += gradePoints[i] * creditHours[i];

        cout << endl;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "============================" << endl;
    cout << "        RESULTS" << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Course Summary:" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < numCourses; i++) {
        cout << courseNames[i] << " -> " << gradePoints[i] << " grade points, "
             << creditHours[i] << " credits" << endl;
    }

    cout << "----------------------------" << endl;
    cout << "Total Credits    : " << totalCredits    << endl;
    cout << "Total Grade Pts  : " << totalGradePoints << endl;
    cout << "----------------------------" << endl;
    cout << "Your CGPA        : " << cgpa << endl;
    cout << "============================" << endl;

    return 0;
}
