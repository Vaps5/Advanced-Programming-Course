//CODE CHALLENGE


#include <iostream>
#include <vector>
#include <typeinfo>


//Part 1: Introduction to Copy vs. Move

// int main() {
//     std::vector<int> v1 = {1, 2, 3, 4};
//     std::vector<int> v2 = v1;        // Copy
//     std::vector<int> v3 = std::move(v1); // Move

//     std::cout << "v1 size: " << v1.size() << std::endl;
//     std::cout << "v2 size: " << v2.size() << std::endl;
//     std::cout << "v3 size: " << v3.size() << std::endl;
//     std::cout << typeid(v1).name() << std::endl;

//     return 0;
// }
/*
Questions:

• What is the output of this program?
The output is:
v1 size: 0
v2 size: 4
v3 size: 4

• Why does v1.size() return 0 after the move?
Because v1 was moved to v3, and thus, it is in a null pointer??

• What does std::move do?
It moves the data of an object to another, by deferencing the values of one of the objects.

• Why is v1 still in a valid but unspecified state? 
Because v1 is deferenced to a null pointer and thus, it has no specific memory storage?? 

*/


// // Part 2: Implementing Move Semantics
// // ✅ Task 2.1 Define a Simple Resource-Managing Class

// class Buffer {
// private:
//     int* data;
//     size_t size;

// public:
//     Buffer(size_t s) : size(s), data(new int[s]) {
//         std::cout << "Constructor called\n";
//     }

//     ~Buffer() {
//         delete[] data;
//         std::cout << "Destructor called\n";
//     }

//     // TODO: Add copy constructor and assignment operator

//     Buffer(const Buffer& other)
//     : data(new int[other.data])
//     , size(other.size)
//     {
//         std::copy(other.data, other.data + other.size, data);
//     }

//     Buffer& operator==(const Buffer& other) {
//         if (this == &other) {return *this};
//         delete[] data;
//         size = other.size;
//         data = new int[size];
//         std::copy(other.data, other.data + other.size, data);
//         return *this;
//     }

//     // TODO: Add move constructor and move assignment operator
// //     Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
//     other.data = nullptr;
//     other.size = 0;
//     std::cout << "Move constructor called\n";
// }

// Buffer& operator=(Buffer&& other) noexcept {
//     if (this != &other) {
//         delete[] data;
//         data = other.data;
//         size = other.size;

//         other.data = nullptr;
//         other.size = 0;
//         std::cout << "Move assignment called\n";
//     }
//     return *this;
// };


// int main(){
//     Buffer myBuf(2);
//     Buffer myBuff(2);
//     Buffer myBufff(2);
//     myBuff==myBuf;
//     myBufff = myBuf;

// }



class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t s) : size(s), data(new int[s]) {
        std::cout << "Constructor called\n";
    }

    ~Buffer() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    // TODO: Add copy constructor and assignment operator
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy constructor called\n";
    }
    
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
            std::cout << "Copy assignment called\n";
        }
        return *this;
    }
    // TODO: Add move constructor and move assignment operator

    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor called\n";
    }
    
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
    
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assignment called\n";
        }
        return *this;
    }
};

int main() {
    Buffer b1(100);
    Buffer b2 = b1;           // Should call copy constructor
    Buffer b3 = std::move(b1); // Should call move constructor

    Buffer b4(50);
    b4 = b2;                  // Should call copy assignment
    b4 = std::move(b2);       // Should call move assignment
    return 0;
}
