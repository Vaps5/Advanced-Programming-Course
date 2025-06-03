#include <string>
#include <iostream>
#include <vector>



int main(){
    int n = 3;
    std::string str1 = "w";
    std::string str2 = "*";
    for (int i = 1; i == n; i++){
    // myvec.at(i) = (n-i)*" " +  i*"*" + (n-i)*" ";
    for (int w = 1; w == n-i-1; w++){
      str1 += "w";
    }
    for (int w = 1; w == i; w++){
      str2 += "*";
    }
  }
  std::string str = str1 + str2 + str1;
  std::cout << str << std::endl;
}