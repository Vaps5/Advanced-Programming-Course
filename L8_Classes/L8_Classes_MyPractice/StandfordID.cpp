#include <string>
#include "StandfordID.h"

// parameterized constructor
StanfordID::StanfordID(std::string name, std::string sunet, int idNumber) {
this->name = name;
this->state = state;
this->age = age;
}

//Setter methods
void StanfordID::setName(std::string name) {
    this->name = name;
    }
    void StanfordID::setSunet(std::string sunet) {
    this->sunet = sunet;
    }
    void StanfordID::setID(int idNumber) {
    if (idNumber >= 0){
    this->idNumber = idNumber;
    }
}

//Destructor 
StanfordID::~StanfordID() {
    // free/deallocate any data here
    }
    
    