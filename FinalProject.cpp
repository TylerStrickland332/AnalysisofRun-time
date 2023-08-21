//============================================================================
// Name        : CourseManagement.cpp
// Author      : Your Name
// Version     : 1.0
// Description : Course Management Program in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Define a class to hold course information
class Course {
public:
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
    
    Course(string number, string title) : courseNumber(number), courseTitle(title) {}
};

// HashTable class definition
class HashTable {
private:
    const unsigned int DEFAULT_SIZE = 179;
    vector<vector<Course>> table;
//Creation of hash table
public:
    HashTable() {
        table.resize(DEFAULT_SIZE);
    }
//Insert function to add courses to hash table
    void Insert(Course course) {
        unsigned int key = hash(course.courseNumber);
        table[key].push_back(course);
    }
//Search function to search courses by ID
    Course Search(string courseNumber) {
        unsigned int key = hash(courseNumber);
        for (const Course& course : table[key]) {
            if (course.courseNumber == courseNumber) {
                return course;
            }
        }
        return Course("", ""); // Return an empty course if not found
    }

private:
    unsigned int hash(string courseNumber) {
        unsigned int sum = 0;
        for (char c : courseNumber) {
            sum += static_cast<unsigned int>(c);
        }
        return sum % DEFAULT_SIZE;
    }

public:
//Prints all courses in hash table
public:
    void PrintAllCourses() {
        vector<Course> allCourses;

        // Collect all courses into the allCourses vector
        for (const vector<Course>& courseList : table) {
            for (const Course& course : courseList) {
                allCourses.push_back(course);
            }
        }

        // Sort the courses alphanumerically by course number
        sort(allCourses.begin(), allCourses.end(), [](const Course& a, const Course& b) {
            return a.courseNumber < b.courseNumber;
            });

        // Print the sorted courses
        for (const Course& course : allCourses) {
            cout << "Course Number: " << course.courseNumber << endl;
            cout << "Course Title: " << course.courseTitle << endl;
            cout << "Prerequisites: ";
            for (const string& prereq : course.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl << "-------------------------" << endl;
        }
    }
};

//Main function
int main() {
    cout << "Welcome to your course planner!" << endl;
    HashTable courseTable;
    string filename;
    int done = 0;
    int isLoaded = 0;

    int choice;
 //Menu
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Load File" << endl;
        cout << "2. Print Course List Alphanumerically" << endl;
        cout << "3. Print Course Information" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if (choice == 1) {
            isLoaded = 1;
//Prompts user to input the name of the file



// Read course data from the file and insert into the hash table

            while (done != 1) {
                //Prompts user to input file name
                cout << "Enter the course data file name: ";
                cin >> filename;
                //Checks if file name is currently accesssible within files
                ifstream inputFile(filename);
                if (inputFile.is_open()) {
                    string line;
                    while (getline(inputFile, line)) {
                        //Reads each line for the course ID, name, and prerequisites course IDs
                        stringstream ss(line);
                        string courseNumber, courseTitle, prerequisite;
                        getline(ss, courseNumber, ',');
                        getline(ss, courseTitle, ',');
                        //Assigns course and attached information to a holder value
                        Course course(courseNumber, courseTitle);
                        //Inserts holder value into the hash table and starts again until a blank line is read
                        while (getline(ss, prerequisite, ',')) {
                            course.prerequisites.push_back(prerequisite);
                        }
                        courseTable.Insert(course);
                    }
                    inputFile.close();
                    //If course data loads successfully, outputs 
                    cout << "Course data loaded successfully." << endl;
                    done = 1;
                }
                else {
                    //If any error occurs opening the file, outputs
                    cout << "Error: Could not open the file." << endl;
                }
            }
        }
//Option one prints all the course values
        if (choice == 2) {
            if (isLoaded != 1) {
                cout << "File not yet loaded, please select menu option 1" << endl;
            }
            else {
                cout << "Here's all your selected courses so far!" << endl;
                courseTable.PrintAllCourses();
            }
        } else if (choice == 3) {
            if (isLoaded != 1) {
                cout << "File not yet loaded, please select menu option 1" << endl;
            }
            else {
                //Option two searches for a course using a  user input course ID
                string courseNumber;
                cout << "Enter the course number: ";
                cin >> courseNumber;

                // Search for the course and print its information
                Course course = courseTable.Search(courseNumber);
                //If course not found, outputs
                if (course.courseNumber.empty()) {
                    cout << "Course not found." << endl;
                }
                else {
                    cout << "Course Number: " << course.courseNumber << endl;
                    cout << "Course Title: " << course.courseTitle << endl;
                    cout << "Prerequisites: ";
                    for (const string& prereq : course.prerequisites) {
                        cout << prereq << " ";
                    }
                    cout << endl;
                }
            }
//Option 9 exits program
        } else if (choice == 9) {
            cout << "Thank you for using the cours planner!" << endl;
            break;
        }
        else if (choice == 1000) {
        
        } else {
//If choice invalid then prompts user of so and goes back to the menu
            cout << "Invalid choice. Please enter a valid option." << endl;
           
        }
    }

    return 0;
}
