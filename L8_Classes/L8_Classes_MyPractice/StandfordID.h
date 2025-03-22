#include <string>

class StanfordID {
    private:
        std::string name;
        std::string sunet;
        std::string state;
        int age;
        int idNumber;
    public:
        // constructor for our StudentID
        StanfordID(std::string name, std::string sunet, int idNumber);
        // methods to get name, sunet, and idNumber, respectively
        std::string getName();
        std::string getSunet();
        int getID();
        // methods to set name, sunet, and idNumber, respectively
        void setName(std::string name);
        void setSunet(std::string sunet);
        void setID(int idNumber);
        //destructor for our StudentID
        ~ StanfordID(); 
    };