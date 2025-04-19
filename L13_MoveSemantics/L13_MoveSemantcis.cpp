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

//     // Copy Constructor

//     Buffer(const Buffer& other)
//         : size(other.size), data(new int[other.size]) {
//         std::copy(other.data, other.data + other.size, data);
//     }
//     // Assignment Operator

//     Buffer& operator=(const Buffer& other) {
//         if (this == &other) return *this;

//         delete[] data;
//         size = other.size;
//         data = new int[size];
//         std::copy(other.data, other.data + other.size, data);
//         std::cout << "Copy assignment called\n";
//         return *this;
//     }

//     // Move Constructor
//     Buffer(Buffer&& other) noexcept
//         : data(other.data), size(other.size) {
//         other.data = nullptr;
//         other.size = 0;
//         std::cout << "Move constructor called\n";
//     }
//     // Move assignment Operator
//     Buffer& operator=(Buffer&& other) noexcept {
//         if (this != &other) {
//             delete[] data;
//             data = other.data;
//             size = other.size;

//             other.data = nullptr;
//             other.size = 0;
//             std::cout << "Move assignment called\n";
//         }
//         return *this;
//     }
// };


// int main(){
//     Buffer myBuf(2);
//     Buffer myBuff(2);
//     Buffer myBufff(2);
//     myBuff = myBuf;
//     myBufff = std::move(myBuf); 
// }



// //✅ Task 2.2 Add Copy Constructor and Assignment

// class Buffer {
//     private:
//         int* data;
//         size_t size;
    
//     public:
//         Buffer(size_t s) : size(s), data(new int[s]) {
//             std::cout << "Constructor called\n";
//         }
    
//         ~Buffer() {
//             delete[] data;
//             std::cout << "Destructor called\n";
//         }
    
//         Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
//             std::copy(other.data, other.data + other.size, data);
//             std::cout << "Copy constructor called\n";
//         }
    
//         Buffer& operator=(const Buffer& other) {
//             if (this != &other) {
//                 delete[] data;
//                 size = other.size;
//                 data = new int[size];
//                 std::copy(other.data, other.data + size, data);
//                 std::cout << "Copy assignment called\n";
//             }
//             return *this;
//         }
    
//         Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
//             other.data = nullptr;
//             other.size = 0;
//             std::cout << "Move constructor called\n";
//         }
    
//         Buffer& operator=(Buffer&& other) noexcept {
//             if (this != &other) {
//                 delete[] data;
//                 data = other.data;
//                 size = other.size;
//                 other.data = nullptr;
//                 other.size = 0;
//                 std::cout << "Move assignment called\n";
//             }
//             return *this;
//         }
//     };

// int main() {
//     Buffer b1(100);
//     Buffer b2 = b1;         
//     Buffer b3 = std::move(b1); 

//     Buffer b4(50);
//     b4 = b2;                  
//     b4 = std::move(b2);       
//     return 0;
// }


// // ✅ Task 2.3 Add Move Constructor and Assignment
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

//     Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
//         std::copy(other.data, other.data + other.size, data);
//         std::cout << "Copy constructor called\n";
//     }

//     Buffer& operator=(const Buffer& other) {
//         if (this != &other) {
//             delete[] data;
//             size = other.size;
//             data = new int[size];
//             std::copy(other.data, other.data + size, data);
//             std::cout << "Copy assignment called\n";
//         }
//         return *this;
//     }

//     Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
//         other.data = nullptr;
//         other.size = 0;
//         std::cout << "Move constructor called\n";
//     }

//     Buffer& operator=(Buffer&& other) noexcept {
//         if (this != &other) {
//             delete[] data;
//             data = other.data;
//             size = other.size;
//             other.data = nullptr;
//             other.size = 0;
//             std::cout << "Move assignment called\n";
//         }
//         return *this;
//     }
// };

// int main() {
//     Buffer Buf(2);
//     Buffer Buffi = Buf;
//     Buffer Buff(3);
//     Buff = Buf;
//     Buffer Bufff = std::move(Buf);
//     Buffer Buffff(1);
//     Buffff = std::move(Buffi);
// }


// // Part 3: Using Your Class
// // ✅ Task 3.1 Create Instances and Observe Behavior
// #include <iostream>
// #include <algorithm>

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

//     Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
//         std::copy(other.data, other.data + other.size, data);
//         std::cout << "Copy constructor called\n";
//     }

//     Buffer& operator=(const Buffer& other) {
//         if (this != &other) {
//             delete[] data;
//             size = other.size;
//             data = new int[size];
//             std::copy(other.data, other.data + size, data);
//             std::cout << "Copy assignment called\n";
//         }
//         return *this;
//     }

//     Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
//         other.data = nullptr;
//         other.size = 0;
//         std::cout << "Move constructor called\n";
//     }

//     Buffer& operator=(Buffer&& other) noexcept {
//         if (this != &other) {
//             delete[] data;
//             data = other.data;
//             size = other.size;
//             other.data = nullptr;
//             other.size = 0;
//             std::cout << "Move assignment called\n";
//         }
//         return *this;
//     }
// };

// int main() {
//     Buffer b1(100);
//     Buffer b2 = b1;
//     Buffer b3 = std::move(b1);
//     Buffer b4(50);
//     b4 = b2;
//     b4 = std::move(b2);
//     return 0;
// }

// /*
// Questions: 
// • What constructors and assignments are called and when? 
// The constructor is called in line 296. 
// In line 297 the copy constructor is called.
// In line 298, the move constructor is used to move the contents of b1 into b3. 
// Then in line 300, the constructor is called again for b4(50). 
// In line 301, the copy assignment operator is called when we assign b2 to b4. 
// In line 302, the move assignment operator is called to move b2 into b4.

// • What happens to the source object after a move?
// It has no data, it is a null pointer.

// • What would happen if you did not define the move constructor/assignment?

// The program would be slower since every move is doing a deep copy.
// */


// Part 4: Performance Comparison
// ✅ Task 3.1 Measure Performance

#include <chrono>

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
    const size_t bufferSize = 10000000;

    auto startCopy = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; ++i) {
        Buffer a(bufferSize);
        Buffer b = a;
    }
    auto endCopy = std::chrono::high_resolution_clock::now();
    std::cout << "Copy duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(endCopy - startCopy).count() << " ms\n";

    auto startMove = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; ++i) {
        Buffer a(bufferSize);
        Buffer b = std::move(a);
    }
    auto endMove = std::chrono::high_resolution_clock::now();
    std::cout << "Move duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(endMove - startMove).count() << " ms\n";

    return 0;
}

// Findings:
/*
The copy constructor is much more larger in time than the move constructor since it involves allocating new memory. 
Moreover, moving transfers the pointer (without copying any data) and leaves the original object empty. 
*/


// Questions:
/*
• What did you learn about move semantics?
Move semantics let you transfer code instead of copying items. It resulted to be faster than the copy semantics, 
besides it avoid unnecessary deep copies.

• In what kinds of projects do you think this would matter?
Itn any kind of projects, but specialy if they have big results. Other projectas where it helps when passing around big
 containers like vectors or custom resource-managing objects.

• What are some risks of using std::move incorrectly?
It can lead to an error if it is not used correctly. After a move, the object is in a valid but 
empty, and it still holds its original data is a common mistake. 



*/