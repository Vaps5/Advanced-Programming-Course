/*
#include <iostream>


int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;  // Takes input from the user and saves it into age
    // std::cin is an input stream that extracts data from the keyboard.
    std::cout << "You are " << age << " years old." << std::endl;
    return 0;
}
*/

/*
#include <iostream>
#include <sstream>  // Include the stringstream library

int main() {
    std::string data = "42 3.14 Hello";  // A string containing multiple values
    std::stringstream MyStream(data);  // Create a string stream

    //int num;
    //double pi;
    //std::string word;

    //MyStream >> num >> pi >> word;  // Extract values from the stream
`   int first;
    double second;
    std::string last;


    std::cout << "Integer: " << num << "\n";
    std::cout << "Double: " << pi << "\n";
    std::cout << "Word: " << word << "\n";

    return 0;
}
*/

/*
//TYPE CONVERSION

#include <sstream>

int main() {
    std::string str = "1234";  // String containing a number
    int number;
    
    std::stringstream ss(str); // Create a stream from the string
    ss >> number;  // Convert string to integer

    std::cout << "Converted number: " << number << std::endl;
    return 0;
}
*/

/*
#include <iostream>
#include <sstream>
int main() {
    /// partial Bjarne Quote
    std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
    /// create a stringstream
    std::stringstream ss(initial_quote);


    /// declaring variables
    std::string first;
    std::string last;
    std::string language, extracted_quote;

    // Extracting the first three words using >>  
    ss >> first >> last >> language;

    // Extracting the remaining part of ss and save it in extracted_quote
    std::getline(ss, extracted_quote); 


    std::cout << first << " " << last << "said this: "<< language << " " <<
    extracted_quote + " "<< std::endl;
    }
*/


/*
#include <iostream>
#include <sstream>
#include <fstream>


//INPUT FILES
int inputFileStreamExample() {
    std::ifstream ifs("L4_Practice.txt");
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);
        std::cout << "Read from the file: " << line << "\n"; 
    }
    if (ifs.is_open()) {
        std::string lineTwo;
        std::getline(ifs, lineTwo);
        std::cout <<  "Read from the file: " << lineTwo << "\n";
    }
    return 0;
}

int main(){
    inputFileStreamExample();
}
*/

#include <iostream>
#include <sstream>
#include <fstream>


//OUTPUT FILES

int main() {
    /// associating file on construction
    std::ofstream ofs("Hello.txt");
    if (ofs.is_open()) {
    ofs << "Hello CS106L!" << "\n";
    }
    ofs.close();
    ofs << "this will not get written";
    ofs.open("Hello.txt", std::ios::app);
    ofs << "this will though! It’s open again";
    return 0;
    }