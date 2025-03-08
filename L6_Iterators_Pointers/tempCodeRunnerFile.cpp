std::set<std::string> get_applicants(std::string filename) {
  // SHORT ANSWER
  std::ofstream My_short_answer("short_answer.txt");
  if (My_short_answer.is_open()){
    My_short_answer << "By using an ordered set, I have an ordered indexing. I can access" << "\n";
    My_short_answer << "to the ith element, besides that I can search, insert and delete elements fastly." << "\n";
    My_short_answer << "On the other hand, i=by using the unordered set I cannot access to the ith element," << "\n";
    My_short_answer << "although I can search, delete and erase elements faster than ny using the ordered set" << "\n";
    My_short_answer << "Example:" << "\n";
    My_short_answer << "" << "\n";
  }

  
  // Open file
  std::ifstream All_Students(filename);

  // Declaring set
  std::set<std::string> SET_Students = {};
  
  if (All_Students.is_open()){
    std::string current_str;
    while(std::getline(All_Students,current_str)){
      SET_Students.insert(current_str);
    }
  }
  return SET_Students;
}