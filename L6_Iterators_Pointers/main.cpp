/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>


std::string kYourName = "Ari Padilla"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */

std::set<std::string> get_applicants(std::string filename) {
  // SHORT ANSWER
  std::ofstream My_short_answer("short_answer.txt");
  if (My_short_answer.is_open()){
    My_short_answer << "My short answers:" << "\n";
    My_short_answer << "Question 1:" << "\n";
    My_short_answer << "By using an ordered set, I have an ordered indexing. I can access" << "\n";
    My_short_answer << "to the ith element, besides that I can search, insert and delete elements fastly." << "\n";
    My_short_answer << "On the other hand, by using the unordered set, I cannot access to the ith element," << "\n";
    My_short_answer << "although I can search, delete and erase elements faster than with the ordered set" << "\n";
    My_short_answer << "\nDef Hash function: A hash function is a function that" << "\n";
    My_short_answer << "'projects a value from a set with many (or even an infinite number of) members to a value from a set with a fixed number of (fewer) members' (Wolfram MathWorld)"  << "\n";
    My_short_answer << "\nExample:" << "\n";
    My_short_answer << "Consider a function that maps each student name to an unordered set of ints that represent" << "\n";
    My_short_answer << "the number of chars in the name." << "\n";
    My_short_answer << "std::unordered_set<int> Hash_Function(std::set<std::string> names_set){" << "\n";
    My_short_answer << "  std::unordered_set<int> sizes_names_set;" << "\n";
    My_short_answer << "  for (std::string elem : names_set){" << "\n";
    My_short_answer << "    sizes_names_set.insert(elem.size());" << "\n";
    My_short_answer << "  }" << "\n";
    My_short_answer << "  return sizes_names_set;" << "\n";
    My_short_answer << "}" << "\n";
  }
  

  My_short_answer.close();
  
  // Open file
  std::ifstream All_Students(filename);

  // Declaring set
  std::set<std::string> SET_Students;
  
  if (All_Students.is_open()){
    std::string current_str;
    while(std::getline(All_Students,current_str)){
      SET_Students.insert(current_str);
    }
  }
  return SET_Students;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> matching_names;
  std::stringstream stream_name(name); // I needed #include <sstream>
  std::string first_name, last_name;
  stream_name >> first_name >> last_name;

  for (const std::string& current_student : students){
    std::stringstream stream_current_student(current_student);
    std::string first_currentstudent, last_currentstudent;
    stream_current_student >> first_currentstudent >> last_currentstudent;

    if (first_name[0] == first_currentstudent[0] && last_name[0] == last_currentstudent[0]){
      matching_names.push(&current_student);
    }
  }
  return matching_names;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) return "NO MATCHES FOUND.";

  std::string MyMatch;


  //I wanted to iterate over the possible matches but I did not notice that I cannot iterate over a queue.
  //I want to cycle the queue 15 (my favorite number) times.
  //Hence, I am adding the last element to the first position of the queue, and deleting
  //the last element, for 15 times. After that, the first element of the queue will be MyMatch.
    int cycle_count = 15; // Number of iterations before selecting
    for (int i = 0; i < cycle_count; i++) {
        // Move front element to back to cycle through queue
        matches.push(matches.front());
        matches.pop();
    }

    //SHORT ANSWER
    std::ofstream My_short_answer2("short_answer.txt", std::ios::app);
    if (My_short_answer2.is_open()){
      My_short_answer2 << "\nQuestion 2:" << "\n";
      My_short_answer2 << "If we do not save the names as pointers, we would be creating copies of the" << "\n";
      My_short_answer2 << "the elements, and since there can be many names, it would take too much storage." << "\n";
      My_short_answer2 << "Therefore, it results efficient to storage as pointers to the names." << "\n";  
      My_short_answer2 << "storage as pointers." << "\n";
      My_short_answer2 << "If the original set goes out of scope, the pointers to the elements that previously" << "\n";
      My_short_answer2 << "were in the set, would be pointing to invalid memory. It happens because the memory occupied by the set is already released." << "\n";
    }
    return *matches.front();
}


/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
