/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

 #include <algorithm>
 #include <fstream>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 
 const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
 const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";
 

struct Course {
    std::string title;
    std::string number_of_units;
    std::string quarter;
};
 

#include "utils.cpp"

void parse_csv(std::string filename, std::vector<Course>& courses) {
    // Open file
    std::ifstream my_file(filename);
    if (my_file.is_open()){
      std::string current_str;
      std::vector<std::string> current_vec;
      while (std::getline(my_file,current_str)){
        current_vec = split(current_str, ',');
        struct Course current_Course {current_vec[0],current_vec[1],current_vec[2]};
        courses.push_back(current_Course);
      }
      courses.erase(courses.begin());
      // std::cout << "COURSE SIZE " << courses.size() << std::endl; 
    }
    my_file.close();
}


void write_courses_offered(std::vector<Course>& all_courses) {
  std::vector<Course> vector_c_offered;

  std::ofstream courses_file("student_output/courses_offered.csv");

  if (courses_file.is_open()) {
    courses_file << "Title,Number of Units,Quarter\n";

    for (const auto& course : all_courses) {
        if (course.quarter != "null") {
            vector_c_offered.push_back(course);
            courses_file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
        }
    }

    courses_file.close();

      for (const auto& course : vector_c_offered) {
          delete_elem_from_vector(all_courses, course);
      }
  }
}



void write_courses_not_offered(const std::vector<Course>& unlisted_courses) {
  std::ofstream not_courses_off("student_output/courses_not_offered.csv");
  if (not_courses_off.is_open()) {
    not_courses_off << "Title,Number of Units,Quarter\n";
    for (const auto& course : unlisted_courses) {
      not_courses_off << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
    }
  }


}

int main() {
  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return 0;
}

