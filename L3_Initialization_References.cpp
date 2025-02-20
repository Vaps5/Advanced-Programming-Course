#include <stdio.h>
#include <string.h>
#include <iostream>
std::tuple<std::string> proof() {
    std::string phrase = "Proving x + y...";
    return {phrase}; //Uniform method
}

int main(){
    system("cls");
    int age = 20; //Direct method
    double num{15.55}; // Uniform method
    bool vegetarian = 1;
    
    //Structured Binding
    auto [my_proof] = proof();


    //Printing values
    std::cout << "Int is " << age << std::endl;
    std::cout << "Double is " << num << std::endl;
    std::cout << "Bool is " << vegetarian << std::endl;
    std::cout << "String is " << my_proof << std::endl;

    //References
    int& ref_age = age;
    double& ref_num{num};
    bool& ref_vege{vegetarian};

    ref_age = 25;
    std:: cout << "Pointer modification: int is " << ref_age << std::endl;

    struct Point{
        int pointx;
        int pointy;
        int pointz; 
    };

    // Structured Binding ??
    Point My_Point {2,3,4};
    auto my_x = My_Point.pointx;
    auto my_y = My_Point.pointy;
    auto my_z = My_Point.pointz;

    std::cout << std::endl;
    std::cout <<  "Structured Binding: " << std::endl << "First Point: "<< my_x << std::endl << "Second Point: "<< my_y << std::endl << "Third Point: "<< my_z <<std::endl;
    
    return 0;
}

/* L values and R values
Analyze the following expressions and classify each as an l-value or an r-value:
1.	a = 42; 
a is L value, 42 an R value

2.	int x = a + b;
x, a and b are L values, a + b is R value

3.	&a;
a is L value, &a is L value too because I can change the direction memory of a >>> &a = another memory 
space

4.	std::string s = c + " World";
s and c are left values, c + "World" is R value, "World" is R value

5.	int& refX = x;
refX and x are L values

6.	int&& rref = 100;
rref is L value, 100 is R value

*/