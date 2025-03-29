#include <iostream>

// //Task 1
// template <class T>
// T maxValue(T a, T b){
//     return (a > b) ? a : b;
// }

// int main(){
//     std::cout << maxValue(2,10) << std::endl;
//     std::cout << maxValue(3.9,9.2) << std::endl;
//     std::cout << maxValue(std::string("X"),std::string("D")) << std::endl;
// }


// //Task 2
// // Task 1.2: Overload a Template Function
// template <class T>
// T maxValue(T a, T b, T c) {
//     return maxValue(maxValue(a, b), c);
// }

// int main() {
//     std::cout << maxValue(1, 15, -3) << std::endl;
//     std::cout << maxValue(13, 2, 122) << std::endl;
// }

// //Concepts
// #include <iostream>
// #include <concepts>

// template <typename T>
// concept Numeric = std::integral<T> || std::floating_point<T>;

// template <Numeric T>
// T add(T a, T b) {
//     return a + b;
// }

// int main() {
//     std::cout << add(21, 22) << std::endl;       
//     std::cout << add(34.4, 10.8) << std::endl;
//     // cout << add("a", "b");
//     return 0;
// }


// //Variadic Templates
// //Task 3.1: Write a Variadic Template Function

// template <typename T>
// void printAll(T t) {
//     std::cout << t << std::endl;
// }

// template <typename T, typename... Args>
// void printAll(T t, Args... args) {
//     std::cout << t << " ";
//     printAll(args...);
// }

// int main() {
//     printAll(1, 2, 3, 4, '5','6'); 
// }


//Task 3.2: Variadic Template for Summation

// template <typename T>
// T sum(T t) {
//     return t;
// }

// template <typename T, typename... Args>
// T sum(T t, Args... args) {
//     return t + sum(args...);
// }

// int main() {
//     std::cout << sum(11, 12, 9, 4, 5) << std::endl;
//     std::cout << sum(33.24, 9.23, 4.544) << std::endl;
// }


// //Part 2: Template Metaprogramming
// // Task 4.1: Compile-Time Factorial Using Templates
// template <int x>
// struct factorial {
//     static constexpr int value = x * factorial<x - 1>::value;
// };

// template <>
// struct factorial<0> {
//     static constexpr int value = 1;
// };

// int main() {
//     constexpr int result = factorial<7>::value;
//     std::cout << result << std::endl;  // Should print 120
// }


//Task 4.2: Fibonacci Series Using Template Metaprogramming

template <int x>
struct Fibonacci {
    static constexpr int value = Fibonacci<x - 1>::value + Fibonacci<x - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    constexpr int result = Fibonacci<5>::value;
    std::cout << result << std::endl; 
}
