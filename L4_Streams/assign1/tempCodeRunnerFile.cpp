d::string> split(const std::string& s, char delim) {
    std::vector<std::string> return_vec;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delim)) {
      return_vec.push_back(token);
    }
    return return_vec;
  }