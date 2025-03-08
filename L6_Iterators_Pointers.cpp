#include <iostream>
#include <vector>

//Iterators
/*
std::vector<int> s = {1,2,3,4,5};
int main(){
    auto b = s.begin(); // The begin() method returns an iterator pointing to the first element of the vector
    auto e = s.end();
    std::cout << typeid(b).name() << std::endl;
    std::cout << *b << " and the last element in s is " << *(e-1) << std::endl;

    std::vector<int>::iterator it;
    it = s.begin() + 5;
    if (it == e){
        std::cout << "Yes, they are pointing to the same object" << std::endl;
    }
}
*/


//Iterators and structs

/*
int main(){
    struct Library {
        std::string books;
        std::string papers;
        std::string thesis;
    };

    Library Library0 = {"100 a.s","Lights out","Abstract Algebra"};
    Library Library1 = {"Art of Loving","Invariant regions","CEDO"};
    std::vector<Library> Libraries_vec {Library0,Library1};

    auto it = Libraries_vec.begin();
    std::string first_book = (*it).books;
    //OR we can use
    std::string f1st_book = it -> books;

    std::cout << "First book is "<< first_book << " or " << f1st_book <<std::endl;
}
*/


//Pointers vs References
/*
int main(){
    std::vector<int> x = {10,10,10};
    //Pointer
    int* ptr = &x[0];
    *ptr = 11;
    ptr += 1; // We can move through the memory 
    *ptr = 12;
    std::cout << x[0] << " and x[1] is " << x[1] << std::endl; 

    //Reference
    int& ref = x[0]; // We are limited to the memory address of x
    ref = 15;
    std::cout << x[0] << std::endl;

}
*/


