//My practice

#include <iostream>
#include <type_traits>
#include <unordered_set>
#include <vector>

/*
template <typename T>
T min(const T&a, const T&b){
    return a < b ? a : b;
}


int main (){
    //Explicit instiation
    int m = min<int>(1,2);
    std::cout << m << std::endl;
    
    //Implicit instiation
    double n = min(1.3,1.4);
    std::cout << n << std::endl;
    
}

*/




//Multiple Template Parameters
// #include <iostream>

// template <typename T1, typename T2>
// class Pair {
// private:
//     T1 first;
//     T2 second;
// public:
//     Pair(T1 a, T2 b) : first(a), second(b) {} // Constructor

//     void display() const {
//         std::cout << "(" << first << ", " << second << ")" << std::endl;
//     }
// };
// int main() {
//     Pair<int, double> p1(10, 3.14);
//     Pair<string, char> p2("Hello", 'A');

//     p1.display();
//     p2.display();

//     return 0;
// }





// Template Specialization 
// #include <iostream>

// template <typename T>
// class Printer {
// public:
//     void print(T data) {
//         std::cout << "Data: " << data << std::endl;
//     }
// };

// // Specialization for `char*` (C-style strings)
// template <>
// class Printer<char*> {
// public:
//     void print(char* data) {
//         std::cout << "C-String: " << data << std::endl;
//     }
// };

// int main() {
//     Printer<int> p1;
//     Printer<double> p2;
//     Printer<char*> p3;

//     p1.print(42);       // Output: Data: 42
//     p2.print(3.14);     // Output: Data: 3.14
//     p3.print("Hello");  // Output: C-String: Hello

//     return 0;
// }


#include "MyPractice.hpp"

// Define the template function
template <typename T>
T Vector<T>::at(size_t i) {
    std::cout << "Accessing element at index: " << i << std::endl;
    return T(); //Always parenthesis If I want to return T type
}




//Concepts

/* Concepts are a way to constrain what types a template parameter can represent.
 * By default, writing `typename T` allows `T` to be instantiated with any type!
 * That doesn't mean, however, that after instantiation, a specific choice of `T`
 * won't necessarily cause a compiler error.
 * 
 * For example, if we tried to instantiate `min<std::ifstream>`, the function
 * would still be instantiated with `T = std::ifstream`, however, when it tries 
 * to compare the two `std::ifstream` using `operator<`, we'd get a compiler error!
 * 
 * Concepts are a way to constrain these types, so that `min` for example doesn't
 * even get instantiated in the first place if `T` doesn't have an `operator<`.
 * This leads to all around better error messages, faster compile times, etc. */


// template <typename T>
// concept Comparable = requires(T a, T b) {
//     { a < b } -> std::convertible_to<bool>;
// };

//How to use it:
//Way 1v
// template <typename T> requires Comparable<T>

//Way 2
// template <Comparable T>
// T min_constrained(const T& a, const T& b) {
//   return a < b ? a : b;
// }

// int main (){
// }



// //MY EXERCISE
// //Cpp file
// template<typename T>
// T& My_Class<T>::Proof() {
//     // std::cout << "Ok";
//     static T t;
//     return t;
// }

// int main () {

// }
