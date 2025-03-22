#include <iostream>


//CONSTRUCTION TYPES
//Default constructor
// class Person {
//     public:
//         std::string name;
//         int age;
    
//         // Constructor
//         Person() {
//             name = "Unknown";
//             age = 0;
//         }
    
//     };
    
//     int main() {
//         Person p1;  // Calls the constructor automatically
//         std::cout << p1.age << " " << p1.name <<std::endl;
//     }



//Parameterized Constructor
// class Person {
//     public:
//         std::string name;
//         int age;
    
//         // Constructor with parameters
//         Person(std::string pName, int pAge) {
//             name = pName;
//             age = pAge;
//         }
    
//     };
    
//     int main() {
//         Person p1("Ari", 20);
//         std::cout << p1.age << " " << p1.name <<std::endl;
// }



//Constructor with Default Values
// class Person {
//     public:
//         std::string name;
//         int age;
    
//         Person(std::string pName = "Unknown", int pAge = 0) {
//             name = pName;
//             age = pAge;
//         }
//     };
    
//     int main() {
//         Person p1;  // Uses default values
//         Person p2("Ari", 20);  // Uses provided values
    
//         std::cout << p1.age << " " << p1.name <<std::endl;
//         std::cout << p2.age << " " << p2.name <<std::endl;
// }
    



// SETTER AND GETTER (PUBLIC METHOD)

// #include <iostream>
// using namespace std;

// // Define Class Employee
// class Employee {
// private:
//     // Define Private member salary
//     int salary;

// public:
//     // Setter
//     void setSalary(int s) { salary = s; }

//     // Getter
//     int getSalary() { return salary; }
// };

// int main()
// {

//     // create object of class employee
//     Employee myObj;

//     // set the salary
//     //We are setting the value of the private member of myObj
//     // myObj.salary = ... does not run because salary is a private member
//     myObj.setSalary(10000);

//     // get the salary and print it
//     cout << "Salary is: " << myObj.getSalary();
//     return 0;
// }




//MEMBER INITIALIZER LIST
// #include <iostream>

// class Date
// {
// private:
//     int m_year{};
//     int m_month{};
//     int m_day{};

// public:
// // Member initializer list:
//     Date(int year, int month, int day)
//         : m_year { year }
//         , m_month { month }
//         , m_day { day}
//     {
//     }

//     void print() const { std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n"; }

//     int getYear() const { return m_year; }
//     int getMonth() const { return m_month; }
//     int getDay() const { return m_day; }
// };

// int main()
// {
//     Date d { 2015, 10, 14 };
//     d.print();

//     return 0;
// }





//THIS POINTER
//The this keyword in C++ is a special pointer that refers to the current instance of the
//  class. It is available in all non-static member functions and can be used to access
//  the current object's members.


//Useful for:

//Disambiguate Names:
//If a member variable has the same name as a parameter or local variable, you can use this to
//  explicitly refer to the member variable.

// #include <iostream>
// using namespace std;

// class Date {
//     private:
//         int year;
//         int month;
//         int day;
    
//     public:
//         Date(int year, int month, int day) {
//             // Date* this = &Current object
//             this->year = year;   // Use 'this' to refer to the member variable
//             this->month = month;
//             this->day = day;
//         }
//     };


// #include <iostream>
// class Person {
//     public:
//         std::string name;
//         int age;
    
//         // Constructor
//         Person() {
//             this->name = "Unknown"; //Here "this" is not necessary because there are no parameters
//             this-> age = 0;
//         }
    
//     };
    
//     int main() {
//         Person p1;  // Calls the constructor automatically
//         std::cout << p1.age << " " << p1.name <<std::endl;
//     }





//RETURN a reference to current object

// #include <iostream>
// class Date {
//     public:
//     int year;
//     int month;
//     int day;

//     //This function setYear returns a reference (alias, not the memory adress) to the object
//     //Instead, "this" is a pointer to the current object Date. 
//     //Then, *this is a reference to the current object Date 
//         Date& setYear(int year) {
//             this->year = year;
//             return *this;  // Return the current object for method chaining
//         }
//     };

//     int main() {
//     Date MyDate;
//     Date& MyDate_Reference = MyDate.setYear(2025);
//     MyDate_Reference.setYear(2024);
//     std::cout << MyDate.year << std::endl;
// }


//METHOD CHAINING
// class Date {
//     public:

//     int year;
//     int month;
//     int day;


//         Date& setYear(int year) {
//             this->year = year;
//             return *this;
//         }
    
//         Date& setMonth(int month) {
//             this->month = month;
//             return *this;
//         }
//     };
    
//     int main() {
//         Date date;
//         date.setYear(2023).setMonth(10);  // Method chaining
//         std::cout << date.year << " "<< date.month << std::endl;    
//         return 0;
//     }


//THIS VS MEMBER INITIALIZER
//Example Combining Both Approaches
// class Date {
//     private:
//         const int year;  // const member
//         int month;
//         int day;
    
//     public:
//         Date(int year, int month, int day)
//             : year(year) {  // Initialize const member in initializer list
//             // Perform conditional assignment in constructor body
//             if (month >= 1 && month <= 12) {
//                 this->month = month;
//             } else {
//                 this->month = 1;  // Default value
//             }
//             this->day = day;
//         }
//     };



//EXAMPLE of class: Date
// #include <iostream>

// class Date
// {
// private:
//     int m_year{};
//     int m_month{};
//     int m_day{};

// public:
//     Date(int year, int month, int day)//Constructor assign values to the private variables
//         : m_year { year }
//         , m_month { month }
//         , m_day { day}
//     {
//     }

//     void print() const { std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n"; }

//     int getYear() const { return m_year; }
//     int getMonth() const { return m_month; }
//     int getDay() const { return m_day; }
// };

// int main()
// {
//     Date d { 2015, 10, 14 };
//     d.print();

//     return 0;
// }

// However, as classes get longer and more complicated, having all the member function definitions
//  inside the class can make the class harder to manage and work with. Using an already-written class only
//  requires understanding its public interface (the public member functions), not how the class works
//  underneath the hood. The member function implementations clutter up the public interface with details 
//  that aren’t relevant to actually using the class.
// To help address this, C++ allows us to separate the “declaration” portion of the class 
// from the “implementation” portion by defining member functions outside of the class definition.
// If you define a class inside a source (.cpp) file, that class is only usable within that particular source
//  file. In larger programs, it’s common that we’ll want to use the classes we write in multiple source files.
//https://www.learncpp.com/cpp-tutorial/classes-and-header-files/






//DESTRUCTOR

// C++ program to demonstrate the execution of constructor
// // and destructor

// #include <iostream>
// using namespace std;

// class Test {
// public:
//     // User-Defined Constructor
//     Test() { cout << "\n Constructor executed"; }

//     // User-Defined Destructor
//     ~Test() { cout << "\nDestructor executed"; }
// };

// int main()
// {
//     Test t;

//     return 0;
// }


// C++ program to demonstrate the number of times
// constructor and destructors are called

#include <iostream>
using namespace std;
// It is static so that every class object has the same
// value
static int Count = 0;
class Test {
public:
    // User-Defined Constructor
    Test()
    {

        // Number of times constructor is called
        Count++;
        cout << "No. of Object created: " << Count << endl;
    }

    // User-Defined Destructor
    ~Test()
    {
        // It will print count in decending order
        cout << "No. of Object destroyed: " << Count
             << endl;
        Count--;
        // Number of times destructor is called
    }
};

// driver code
int main()
{
    Test t, t1, t2, t3;

    //Calling a destructor
    t1.~Test();

    return 0;
}

//Note: Objects are destroyed in the reverse order of their creation. In this case, t3
//  is the first to be destroyed, while t is the last.