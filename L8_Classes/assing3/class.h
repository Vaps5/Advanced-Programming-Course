#include <iostream>

class ChitinHydrolysis {
private:
    std::string concentration_type;
    double CaOH_concentration;

    double Initial_weight;
    double Final_weight;

    void validateWeight(double& weight);  
public:
    static int const crickets_number = 5;
    static int const water_volume = 5;
    static std::string const internal_temperature;
    //Static const members of non-integral types (e.g., std::string) must be initialized outside the class.

    //Default Constructor with Member initializer
    ChitinHydrolysis()
    : concentration_type {"Void"}
    , Initial_weight {0}
    , Final_weight {0} 
    {};

    //Parameterized Constructor
    ChitinHydrolysis(std::string concentration_type);
    
    //Getter functions
    std::string const get_concentration_type() {return concentration_type; }
    double const get_CaOH_concentration() {return CaOH_concentration; }
    double const get_Initial_weight() {return Initial_weight; }
    double const get_Final_weight() {return Final_weight; }

    //Setter functions
    void set_CaOH_concentration(double a);
    void set_Initial_weight(double a);
    void set_Final_weight(double a);

    //Display function
    void display() const;
};