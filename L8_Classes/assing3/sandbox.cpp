/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"
#include <iostream>
#include <fstream>

void sandbox() {
  std::cout << "Internal Temperature: " << ChitinHydrolysis::internal_temperature << "\n";
  std::cout << "Crickets Number: " << ChitinHydrolysis::crickets_number << "\n";
  std::cout << "Water Volume: " << ChitinHydrolysis::water_volume << "ml\n";
  std::cout <<"\n";

  ChitinHydrolysis AD1("Low");
  AD1.set_CaOH_concentration(0.89/15);
  AD1.set_Initial_weight(11.11);
  AD1.set_Final_weight(13.63);
  AD1.display();

  ChitinHydrolysis AD2("Medium");
  AD2.set_CaOH_concentration(1.112/15);
  AD2.set_Initial_weight(9.67);
  AD2.set_Final_weight(10.29);
  AD2.display();

  ChitinHydrolysis AD3("High");
  AD3.set_CaOH_concentration(1.334/15);
  AD3.set_Initial_weight(11.24);
  AD3.set_Final_weight(12.35);
  AD3.display();
}

int main() {
  sandbox();

  //Short Answers
  std::ofstream myanswer("short_answer.txt");
  if (myanswer.is_open()){
    myanswer << "My short answers:" << "\n";
    myanswer << "Question 1:" << "\n";
    myanswer << "Const-correctness is a way for verifying that the variables or functions do not be modified"<< "\n";
    myanswer << "and it ensures it not modify the object."<< "\n";
    myanswer << "Question 2:" << "\n";
    myanswer << "Yes, my class is const-correct because all getter functions are const. Moreover,"<< "\n";
    myanswer << "the internal_temperature static member is const and the display function too for preventing any unexpected change."<< "\n";
  }
  myanswer.close();
  return 0;
}