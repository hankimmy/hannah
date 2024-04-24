#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_COURSES = 10;

int main() {
    ifstream file("/Users/hankim/CLionProjects/hannah/sample.txt"); // Adjust the path as necessary
    if (!file.is_open()) {
        cerr << "Failed to open file." << std::endl;
        return 1;
    }
    int id;
    string name;
    double gpa;
    string course;
    string line;
    while (file >> id) {
        file.ignore();
        getline(file, name);
        file >> gpa;
        file.ignore();
        cout << "ID: " << id << "  Name: " << name << "  Courses: ";
        while (getline(file, line) && line != "#") {
            file >> course;
            cout << course << ", ";
        }
        cout << endl;
    }
    file.close();
    return 0;
}
