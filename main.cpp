#include <iostream>
#include <fstream>

using namespace std;

double computeAverage(int grade1, int grade2, int grade3);

int main() {
    ifstream file;
    file.open("/Users/hannah/grades.txt");
    if (!file)
    {
        cout << "Failed to open file." << endl;
        return 1;
    }
    int studentID;
    int grade1;
    int grade2;
    int grade3;

    cout << fixed << setprecision(2);
    cout << "Student ID\tAverage" << endl;
    while(file >> studentID >> grade1 >> grade2 >> grade3)
    {
        cout << studentID << "\t\t" << computeAverage(grade1, grade2, grade3) << endl;
    }
    file.close();
    return 0;
}

double computeAverage(int grade1, int grade2, int grade3)
{
    double sum = 0;
    if (grade1 < grade2 && grade1 < grade3)
    {
        sum = grade2 + grade3;
    }
    else if (grade2 < grade1 && grade2 < grade3)
    {
        sum = grade1 + grade3;
    }
    else if (grade3 < grade1 && grade3 < grade2)
    {
        sum = grade1 + grade2;
    }
    return sum / 2.0;
}