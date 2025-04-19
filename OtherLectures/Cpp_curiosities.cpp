#include <iostream>
#include<string>
using namespace std;

//SCOPE RESOLUTION OPERATOR IN C++
//https://www.geeksforgeeks.org/scope-resolution-operator-in-c/

//Global and local variables
// Global x
// int x = 3;

// int main() {
      
//       // Local x
//     int x = 10;
  
//       // Printing the global x
//     cout << ::x;
  
//     return 0;
// }



//Define Class Member Function Outside Class and outside he function main
// #include <iostream>
// using namespace std;

// // A sample class
// class A {
// public:
  
//     // Only declaration of member function
//     void fun();
// };

// // Definition outside class by referring to it using ::
// void A::fun() {
//       cout << "fun() called";
// }

// int main() {
//     A a;
//     a.fun();
//     return 0;
// }


// Access Class’s Static Members
// #include<iostream>
// using namespace std;

// class A {
// public:
//     static int x; 
// };

// // In C++, static members must be explicitly defined 
// // like this
// int A::x = 1;

// int main() {
    
//       // Accessing static data member
//       cout << A::x;

//     return 0;
// }


//Refer to Base Class Member in Derived Class
// #include <bits/stdc++.h>
// using namespace std;

// class Base {
// public:
//     void func() {
//         cout << "Base class func()" << endl;
//     }
// };

// class Derived : public Base {
// public:
  
//       // Overridden function
//     void func() {
//         cout << "Derived class func()" << endl;
//     }
// };

// int main() {
//     Derived obj;
  
//       // Calling base class's func() from the object of
//       // derived class
//     obj.Base::func();
  
//     obj.func();
//     return 0;
// }


//MEMBER INITIALIZER
// Member initializer lists directly initialize the member variables, 
// whereas assigning values in the constructor body involves default initialization followed by assignment.
// This can be less efficient, especially for non-primitive types like objects or large data structures.
// #include <iostream>

// class Date
// {
// private:
//     int m_year{};
//     int m_month{};
//     int m_day{};

// public:
//     Date(int year, int month, int day)
//         : m_year { year }
//         //The colon introduces the member initializer list, 
//         // which is used to initialize the member variables of the class 
//         // before the constructor body is executed.

//         , m_month { month } //Uniform initialization
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


// //If m_year were a const member, you must use the member initializer list:
// class Date {
//     private:
//         const int m_year;
//         int m_month;
//         int m_day;
    
//     public:
//         Date(int year, int month, int day)
//             : m_year { year }  // Must initialize const member here
//             , m_month { month }
//             , m_day { day }
//         {
//         }
//     };
    
// int main()
// {
//     return 0;
// }



//If I were in hp file
// class Point {
//     private:
//         int x;
//         int y;
//         std::string color;
    
//     public:
//         Point(int x, int y);
//         ~Point();
//         int getX();
//         int getY();
//     };
    
// //In cpp file

// Point::Point(int x, int y) : x(x), y(y){} // With member initializer, we do not use "this" keyword


// int main()
// {
//     return 0;
// }