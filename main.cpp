#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    /*
     * Initialize ifstream object named file. This new variable will allow us to use ifstream's methods:
     * open(string file) -> void function that updates ifstream object with file info
     * is_open() -> returns boolean if file has been open successfully
     * ignore() -> skips character, more info will be explained when I use it later
     * Whenever we use an object's methods, you need to do <named_variable>.<method_name>
     * Think of it as only the ifstream are allowed to use these functions (methods)
    */
    ifstream file;
    file.open("/Users/hankim/CLionProjects/hannah/sample.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file." << endl;
        return 1;
    }

    // Initialize variables we want to read for each record
    int id;
    string name;
    double gpa;
    string course;

    // Every new record starts with an ID so this while loop will keep running until we can't read more records or more
    // specifically when there is a blank character that is not a valid integer.
    while (file >> id)
    {
        /*
         * The data is organized as follows:
         * 1111
         * s1First s2Last
         *
         * When the expression file >> id is run, think of the file as a pointer and after reading the integer its
         * pointing to the end of 1111
         *                            ^
         *                            |
         *                           file
         * We need to use ignore to tell the file pointer to go to the next line with ignore()
         */
        file.ignore();

        /*
         * getline(file, name) is different though from file >> name
         * This basically reads the whole line and stores it into name and moves the file pointer over the next line
         * so we don't have to call ignore()
         *
         * Just use getline() anytime you want to read a string
         */
        getline(file, name);

        // Same logic as before with the ID
        file >> gpa;
        file.ignore();
        cout << "ID: " << id << "  Name: " << name << "  Courses: ";

        /*
         * This one is a bit tricky but don't be scared <3
         * Since the lab says there can be any number of courses we must use a while loop. We would use a for loop
         * if we knew the amount of courses each person takes.
         *
         * A nice simulation will help understand the logic of this while loop
         * Data:
         * 1111
         * s1First s1Last
         * 3.92
    file-->CS1
         * CS7
         * CS2
         * #
         * First iteration:
         * file is pointing to beginning of CS1
         * getline(file, course) is called
         * course = "CS1"
         * the compiler reads the code from left to right, so we can use course and check if it does NOT equal "#"
         * Since we have a valid course "CS1" we now want to print it out
         *
         * Second iteration:
         * CS1
    file-->CS7
         * #
         * getline(file, course) is called
         * course = "CS7"
         * We have a valid course "CS7" we now want to print it out
         *
         * Third Iteration:
         * CS1
         * CS7
  file--> #
         * getline(file, course) is called
         * course = "#"
         * The expression course != "#" will return false as stop the while loop
         */
        while (getline(file, course) && course != "#")
        {
            cout << course << ", ";
        }
        cout << endl;
    }
    file.close();
    return 0;
}
