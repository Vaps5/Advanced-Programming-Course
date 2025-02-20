#include <iostream>
#include <utility>
#include <cmath>
#include <typeinfo>


// Hello World
/*
int main (){
    std::pair<bool,std::pair<double,double>> proof{0,{0,1}};
    std::cout << "Hello World" <<std::endl;
}
*/

// Declaring a variable
/*
int main(){
    system("cls");
    auto x = 34;
    std:: cout << x << std::endl;
    std::cout << "Data type of num: " << typeid(x).name() << std::endl;
}
*/

// Doing a Struct

/*
int main(){
    struct StandfordID{
        std::string name;
        std::string sunet;
    };
    StandfordID Proof = {"Ari","Vaps"};
    std::cout << Proof << std::endl; // You cannot print a struct!
};
*/

//Pair struct
/*
int main(){
    std::pair <int,int> proof{2,3};
}*/

//Classwork

std::pair<bool,std::pair<double,double>> solveQuadratic(double a, double b, double c) {
    std::pair<bool,std::pair<double,double>> final_sol{0,{0,0}}; 
    double det = b*b - 4*a*c;
    std:: cout << det << std::endl;
    if (det < 0) {
        final_sol.first = 0;
        final_sol.second = {0,0};
    } else if (det == 0) {
        final_sol.first = 1;
        double sol1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
        final_sol.second = {sol1,sol1};
    } else {
        final_sol.first = 2;
        double sol1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
        double sol2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
        final_sol.second = {sol1,sol2};
    }
    return final_sol;
}

int main(){
    system("cls");
    std::pair<bool,std::pair<double,double>> solution = solveQuadratic(1,-3,2);
    std:: cout << "Number of solutions: " << solution.first << std::endl << "First sol: " << solution.second.first << std::endl << "Second sol: " << solution.second.second <<std::endl;
    return 0;
}

