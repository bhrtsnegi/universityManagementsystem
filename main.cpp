#include <iostream> // for input output
#include <fstream>  // for file handling
#include <windows.h>
using namespace std;

class University
{
private:
    string Name, Subject, Semester, Address;
    int RollNo, Age, PhoneNumber;

public:
    University() : RollNo(), Name(""), Subject(""), Age(), Semester(""), PhoneNumber(), Address("") {}

    // setter functions for every value
    void setRollNo(int rollNo)
    {
        RollNo = rollNo;
    }

    void setName(string name)
    {
        Name = name;
    }

    void setSubject(string subject)
    {
        Subject = subject;
    }

    void setAge(int age)
    {
        Age = age;
    }

    void setSemester(string semester)
    {
        Semester = semester;
    }

    void setPhoneNumber(int phoneNumber)
    {
        PhoneNumber = phoneNumber;
    }

    void setAddress(string address)
    {
        Address = address;
    }

    // getter function to get values

    int getRollNo()
    {
        return RollNo;
    }

    string getName()
    {
        return Name;
    }

    string getSubject()
    {
        return Subject;
    }

    int getAge()
    {
        return Age;
    }

    string getSemester()
    {
        return Semester;
    }

    int getPhoneNumber()
    {
        return PhoneNumber;
    }

    string getAddress()
    {
        return Address;
    }
};

void add(University student)
{
    string Name, Subject, Semester, Address;
    int RollNo, Age, PhoneNumber;

    cout << "\tEnter roll number of student: ";
    cin >> RollNo;
    student.setRollNo(RollNo);

    cout << "\tEnter name of student: ";
    cin >> Name;
    student.setName(Name);

    cout << "\tEnter subject name: ";
    cin >> Subject;
    student.setSubject(Subject);

    cout << "\tEnter age of student: ";
    cin >> Age;
    student.setAge(Age);

    cout << "\tEnter semester: ";
    cin >> Semester;
    student.setSemester(Semester);

    cout << "\tEnter phone number of student: ";
    cin >> PhoneNumber;
    student.setPhoneNumber(PhoneNumber);

    cout << "\tEnter address of student: ";
    cin >> Address;
    student.setAddress(Address);

    ofstream out("E:/Projects/universityManagementsystem/university.txt", ios::app);
    if (!out)
    {
        cout << "\tError: File Can't Be Opened!" << endl;
    }
    else
    {
        out << "\t" << student.getRollNo() << ":" << student.getName() << ":" << student.getSubject() << ":" << student.getAge() << ":" << student.getSemester() << ":" << student.getPhoneNumber() << ":" << student.getAddress() << endl
            << endl;

        out.close();

        cout << "\tStudent Added Successfully." << endl;
    }
}

void search()
{
    string rollNo;
    cout << "\tEnter Roll Number of Student: ";
    cin >> rollNo;

    ifstream in("E:/Projects/universityManagementsystem/university.txt");
    if (!in)
    {
        cout << "\tError: File Can't Be Opened!" << endl;
    }
    string line;
    bool found = false;

    while (getline(in, line))
    {
        int data = line.find(rollNo);
        if (data != string ::npos)
        {
            cout << "\t" << line << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "\tStudent Not Found!" << endl;
    }
    in.close();
}

void update(University student)
{
    string rollNo;
    cout << "\tEnter Roll No. of Student: ";
    cin >> rollNo;

    ifstream infile("E:/Projects/universityManagementsystem/university.txt");
    ofstream outfile("E:/Projects/universityManagementsystem/university_temp.txt");
    if (!infile || !outfile)
    {
        cout << "\tError: File Can't Be Opened!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line))
    {
        if (line.find(rollNo) != string::npos)
        {
            int option;
            cout << "\t1. Edit Name." << endl;
            cout << "\t2. Edit Subject." << endl;
            cout << "\t3. Edit Age." << endl;
            cout << "\t4. Edit Semester." << endl;
            cout << "\t5. Edit Phone Number." << endl;
            cout << "\t6. Edit Address." << endl;
            cout << "\tEnter Your Choice: ";
            cin >> option;

            // Perform the update based on the option
            switch (option)
            {
            case 1: // Edit Name
            {
                string name;
                cout << "Enter New Name: ";
                cin >> name;
                student.setName(name);

                int firstPos = line.find_first_of(':');
                int secondPos = line.find(':', firstPos + 1);

                if (firstPos != string::npos && secondPos != string::npos)
                {
                    line.replace(firstPos + 1, secondPos - firstPos - 1, student.getName());
                }
                else
                {
                    cout << "Error: Invalid format in the string." << endl;
                }
                break;
            }
            case 2: // Edit Subject
            {
                string subject;
                cout << "Enter New Subject: ";
                cin >> subject;
                student.setSubject(subject);

                int firstPos = line.find_first_of(':');
                int secondPos = line.find(':', firstPos + 1);
                int thirdPos = line.find(':', secondPos + 1);

                if (secondPos != string::npos && thirdPos != string::npos)
                {
                    line.replace(secondPos + 1, thirdPos - secondPos - 1, student.getSubject());
                }
                else
                {
                    cout << "Error: Invalid format in the string." << endl;
                }
                break;
            }
            case 3: // Edit Age
            {
                int age;
                cout << "Enter New Age: ";
                cin >> age;
                student.setAge(age);

                int firstPos = line.find_first_of(':');
                int secondPos = line.find(':', firstPos + 1);
                int thirdPos = line.find(':', secondPos + 1);
                int fourthPos = line.find(':', thirdPos + 1);

                if (thirdPos != string::npos && fourthPos != string::npos)
                {
                    line.replace(thirdPos + 1, fourthPos - thirdPos - 1, to_string(student.getAge()));
                }
                else
                {
                    cout << "Error: Invalid format in the string." << endl;
                }
                break;
            }
            case 4: // Edit Semester
            {
                string semester;
                cout << "Enter New Semester: ";
                cin >> semester;
                student.setSemester(semester);

                int firstPos = line.find_first_of(':');
                int secondPos = line.find(':', firstPos + 1);
                int thirdPos = line.find(':', secondPos + 1);
                int fourthPos = line.find(':', thirdPos + 1);
                int fifthPos = line.find(':', fourthPos + 1);

                if (fourthPos != string::npos && fifthPos != string::npos)
                {
                    line.replace(fourthPos + 1, fifthPos - fourthPos - 1, student.getSemester());
                }
                else
                {
                    cout << "Error: Invalid format in the string." << endl;
                }
                break;
            }
            case 5: // Edit Phone Number
            {
                int number;
                cout << "Enter New Phone Number: ";
                cin >> number;
                student.setPhoneNumber(number);

                int firstPos = line.find_first_of(':');
                int secondPos = line.find(':', firstPos + 1);
                int thirdPos = line.find(':', secondPos + 1);
                int fourthPos = line.find(':', thirdPos + 1);
                int fifthPos = line.find(':', fourthPos + 1);
                int sixthPos = line.find(':', fifthPos + 1);

                if (fifthPos != string::npos && sixthPos != string::npos)
                {
                    line.replace(fifthPos + 1, sixthPos - fifthPos - 1, to_string(student.getPhoneNumber()));
                }
                else
                {
                    cout << "Error: Invalid format in the string." << endl;
                }
                break;
            }
            case 6: // Edit Address
            {
                string address;
                cout << "Enter New Address: ";
                cin >> address;
                student.setAddress(address);

                int newPos = line.find_last_of(':');
                line.replace(newPos + 1, string::npos, student.getAddress());
                break;
            }
            default:
                cout << "Error: Invalid Option." << endl;
                break;
            }
            outfile << line << endl;
            found = true;
        }
        else
        {
            outfile << line << endl;
        }
    }

    if (!found)
    {
        cout << "\tStudent Not Found!" << endl;
    }

    outfile.close();
    infile.close();

    remove("E:/Projects/universityManagementsystem/university.txt");
    rename("E:/Projects/universityManagementsystem/university_temp.txt", "E:/Projects/universityManagementsystem/university.txt");
    cout << "\tData Updated." << endl;
}

int main()
{
    University student;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int option;

        // message body for user
        cout << "\tWelcome to the University Management System" << endl;
        cout << "\t*******************************************" << endl;
        cout << "\t1. Add Student." << endl;
        cout << "\t2. Search Student." << endl;
        cout << "\t3. Update Student's Data. " << endl;
        cout << "\t4. Exit. " << endl;
        cout << "\tEnter Your Choice: ";
        cin >> option;

        if (option == 1)
        {
            system("cls");
            add(student);
            Sleep(6000);
        }

        else if (option == 2)
        {
            system("cls");
            search();
            Sleep(6000);
        }
        else if (option == 3)
        {
            system("cls");
            update(student);
            Sleep(6000);
        }
        else if (option == 4)
        {
            system("cls");
            exit = true;
            cout << "\tHave a nice day." << endl;
            Sleep(3000);
        }
    }
    return 0;
}
