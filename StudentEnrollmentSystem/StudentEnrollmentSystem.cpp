#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Course
{
private:
    string name;
    int credit;

public:
    Course(string _name = "", int _credit = 1) : name(_name), credit(_credit) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    int getCredit() const { return credit; }
    void setCredit(int value) { credit = value; }
    void print() const
    {
        cout << "Course: " << name << "   Credit=" << credit << endl;
    }
};


class Student
{
private:
    string name, matric;
    vector<Course*> courses;

public:
    Student(string _name = "", string _matric = "") : name(_name), matric(_matric) {}
    string getName() const { return name; }
    string getMatric() const { return matric; }
    void setName(string value) { name = value; }
    void setMatric(string value) { matric = value; }


    void enrollToCourse(Course* c) {
        courses.push_back(c);
    }

    int getEnrolledCount() const {
        return courses.size();
    }

    int getTotalCredit() const {
        int totalCredit = 0;
        for (int i = 0; i < courses.size(); i++)
        {
            totalCredit = totalCredit + courses[i]->getCredit();
        }
        return totalCredit;
    }

    void printCourses() const {
        for (int i = 0; i < courses.size(); i++)
        {
            courses[i]->print();
        }
    }
    void printSummary() const
    {
        cout << "Name:" << name << endl;
        cout << "Matric:" << matric << endl;
        cout << "Number of courses enrolled:" << getEnrolledCount() << endl;
        cout << "Total credit carried:" << getTotalCredit() << endl;
    }
};

int main()
{

    vector<Course> allcourses;

    allcourses.push_back(Course("Programming Technique I", 3));
    allcourses.push_back(Course("Programming Technique II", 3));
    allcourses.push_back(Course("Operating Systems", 3));
    allcourses.push_back(Course("Web Programming", 3));
    allcourses.push_back(Course("Digital Logic", 3));
    allcourses.push_back(Course("Object-Oriented Programming", 4));
    allcourses.push_back(Course("Application Development", 4));
    allcourses.push_back(Course("Final Year Project I", 2));
    allcourses.push_back(Course("Software Engineering", 3));
    allcourses.push_back(Course("Graduate Success Attributes", 2));


    Student s1("Anna Mull", "A19EC4002");
    s1.enrollToCourse(&allcourses[0]);
    s1.enrollToCourse(&allcourses[3]);
    s1.enrollToCourse(&allcourses[6]);

    Student s2("Mario Max", "A16EC4001");
    s2.enrollToCourse(&allcourses[1]);
    s2.enrollToCourse(&allcourses[2]);
    s2.enrollToCourse(&allcourses[4]);

    Student s3("Wilma Mumduya", "A16EC4045");
    s3.enrollToCourse(&allcourses[6]);
    s3.enrollToCourse(&allcourses[7]);
    s3.enrollToCourse(&allcourses[8]);

    Student s4("Maliha Tasnim", "A18EC4056");
    s4.enrollToCourse(&allcourses[0]);
    s4.enrollToCourse(&allcourses[2]);
    s4.enrollToCourse(&allcourses[6]);

    Student s5("Paul Molive", "A16EC9043");
    s5.enrollToCourse(&allcourses[1]);
    s5.enrollToCourse(&allcourses[2]);
    s5.enrollToCourse(&allcourses[9]);
    Student s6("Gail Forcewind", "A16EC4032");
    Student s7("Paige Turner", "A16EC3002");
    Student s8("Bob Frapples", "A17EC3003");
    Student s9("Robin Banks", "A17EC4043");
    Student s10("Jimmy Changa", "A18EC4044");

    map<string, Student> students = { {"A19EC4002", s1}, {"A16EC4001", s2}, {"A16EC4045", s3},
        {"A18EC4056", s4}, {"A16EC9043", s5}, {"A16EC4032", s6}, {"A16EC3002", s7}, {"A16EC3003", s8},
        {"A17EC4043", s9}, {"A18EC4044", s10} };

    cout << "Enter the matric number => " << endl;
    string mtrc;

    getline(cin, mtrc);

    cout << "Information of found student" << endl;
    cout << "==============================" << endl;
    students[mtrc].printSummary();

    cout << "List of Courses enrolled" << endl;
    cout << "----------------------------" << endl;
    students[mtrc].printCourses();
    system("pause");
    return 0;
}