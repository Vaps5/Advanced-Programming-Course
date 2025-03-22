#include <iostream>
#include "class.h"


const std::string ChitinHydrolysis::internal_temperature = "25 degrees Celsius";
//Static const members of non-integral types (e.g., std::string) must be initialized outside the class.

void ChitinHydrolysis::validateWeight(double& weight) {
    if (weight < 0) {
        weight = 0;
    };
};  


//Parameterized Constructor
ChitinHydrolysis::ChitinHydrolysis(std::string concentration_type) {
    this -> concentration_type = concentration_type;
}


//Setter functions
void ChitinHydrolysis::set_CaOH_concentration(double a) {
    if (a > 0) {
        CaOH_concentration = a;
    } else {
        std::cout << "CaOH_concentration must be positive" << std::endl;
    }
}

void ChitinHydrolysis::set_Initial_weight(double a) {
    if (a > 0) {
        Initial_weight = a;
    } else {
        std::cout << "Initial_weight is positive" << std::endl;
    }
}

void ChitinHydrolysis::set_Final_weight(double a) {
    validateWeight(a);
    Final_weight = a;
}

// Display function
void ChitinHydrolysis::display() const {
    std::cout << "Chitin Hydrolysis Process" <<"\n";
    std::cout << "Concentration Type: " << concentration_type << "\n";
    std::cout << "CaOH Concentration: " << CaOH_concentration << "g/ml\n";
    std::cout << "Initial Weight: " << Initial_weight << "g\n";
    std::cout << "Final Weight: " << Final_weight << "g\n";
    std::cout << "\n" << std::endl;
}


