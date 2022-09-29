#include <iostream>
#include <string>
using namespace std;
class Person {

public:
    Person() :fullName("No Name"), email("No email"), SSN(0), No_phone(0) {
        phoneNumbers = new string[0];
    }
    Person(string _fullName_, string _email_, int _SSN_, int _No_phone_)
        :fullName(_fullName_), email(_email_), SSN(_SSN_), No_phone(_No_phone_) {
        phoneNumbers = new string[_No_phone_];
    }
   virtual void printInfo();
    void readPhoneNumbers();
    virtual void readGrades() = 0;
    string getemail() { return email; }
    int getSSN() { return SSN; }


   virtual ~Person() {
        delete[] phoneNumbers;
        cout << "Base Destructor!\n";
    }
    string fullName;
    int No_phone;
    string* phoneNumbers;
protected:
    string email;
private:
    int SSN;
};
void  Person::printInfo() {
    cout << "Person [" << fullName << ", " << email << ", " << SSN << "]" << endl;
    if (No_phone > 0) {
        cout << "Registred Phone Numbers: {";
        cout << phoneNumbers[0];
        for (int i = 1; i < No_phone; ++i)
            cout << ", " << phoneNumbers[i];
        cout << "}" << endl;

    }
    else
        cout << "No Known Phone numbers.\n";

}

void Person::readPhoneNumbers() {
    if (No_phone > 0) {
        cout << "Please enter your phone numbers {" << No_phone << "}" << endl;
        for (int i = 0; i < No_phone; ++i) {
            cout << "Enter phone number #" << (i + 1) << " --> ";
            cin >> phoneNumbers[i];
        }
    }
    else
        cout << "No phone numbers" << endl;
}

class Student : public Person {

public:
    Student() : Person() {

        GPA = 0;
        numberOfCourses = 0;
        grades = new double[0];

    }

    Student(string _fullName_, string _email_, int _SSN_, int _No_phone_, double _GPA_, int _numberOfCourses_)
        : Person(_fullName_, _email_, _SSN_, _No_phone_), GPA(_GPA_), numberOfCourses(_numberOfCourses_) {
        grades = new double[_numberOfCourses_];
    }
    void readGrades();
    void printInfo();
    ~Student() {
        delete[] grades;
        cout << "Destructor from child\n";
    }
private:
    double GPA;
    int numberOfCourses;
    double* grades;


};
void  Student::printInfo() {
    cout << "Student [" << fullName << ", " << email << ", " << getSSN() << ", " << No_phone << ", " << GPA << ", " << numberOfCourses << "]" << endl;

    if (No_phone > 0) {
        cout << "Registred Phone Numbers: {";
        cout << phoneNumbers[0];
        for (int i = 1; i < No_phone; ++i)
            cout << ", " << phoneNumbers[i];
        cout << "}" << endl;

    }
    else
        cout << "No Known Phone numbers.\n";

    if (numberOfCourses > 0) {
        cout << "Grades: {";
        cout << grades[0];
        for (int i = 1; i < numberOfCourses; ++i)
            cout << ", " << grades[i];
        cout << "}" << endl;

    }
    else
        cout << "No Grades.\n";
}
void Student::readGrades() {
    if (numberOfCourses > 0) {
        cout << "Please enter your grades {" << numberOfCourses << "}" << endl;
        for (int i = 0; i < numberOfCourses; ++i) {
            cout << "Enter Grade #" << (i + 1) << " --> ";
            cin >> grades[i];
        }
    }
    else
        cout << "No Grades" << endl;
}

int main()
{

    //Person per0;
    //per0.readPhoneNumbers();
    //per0.printInfo();

    //Person per1("Dr. ALnaeli", "alnaelis@uwstout.edu", 999999999, 2);
    //per1.readPhoneNumbers();
    //per1.printInfo();
    //{
    //    Student stu1("Dr. D. Christie", "christied@uwstout.edu", 90000000, 2, 99.9, 3);
    //    stu1.readPhoneNumbers();
    //    stu1.readGrades();
    //    stu1.printInfo();
    //}
    //Person* perx = new Person("Dr. ALnaeli", "alnaelis@uwstout.edu", 999999999, 2);
    Person* perx = new Student("Dr. D. Christie", "christied@uwstout.edu", 90000000, 2, 99.9, 3);

    perx->readPhoneNumbers();
    perx->readGrades();
    perx->printInfo();
    delete perx;


    return 0;
}