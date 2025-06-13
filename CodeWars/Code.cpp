#include <string>
#include <iostream>
#include <vector>


// std::string rps(const std::string& p1, const std::string& p2)
// {
//     // p < r < s
//     if (p1 == "scissors" && p2 == "paper"){
//         return "Player 1 won!";
//     }
//     if (p1 == "paper" && p2 == "rock"){
//         return "Player 1 won!";
//     } 
//     if (p1 == "rock" && p2 == "scissors"){
//         return "Player 1 won!";
//     }
//     if (p2 == "scissors" && p1 == "paper"){
//         return "Player 2 won!";
//     }
//     if (p2 == "paper" && p1 == "rock"){
//         return "Player 2 won!";
//     } 
//     if (p2 == "rock" && p1 == "scissors"){
//         return "Player 2 won!";
//     } else {
//         return "Draw!";
//     };   

// }


// #include <vector>
// using namespace std;

// int min(vector<int> list){
//     auto a = list.begin();
//     auto b = list.end();
//     auto min = list[0];
//     for (; a < b; a++) {
//         auto current = *a;
//         if (current < min) {
//             min = current;
//         }
//     }
//     return min;
// }

// int max(vector<int> list){
//     auto a = list.begin();
//     auto b = list.end();
//     auto max = list[0];
//     for (; a < b; a++) {
//         auto current = *a;
//         if (current > max) {
//             max = current;
//         }
//     }
//     std::cout << max << " ";
//     return max;
// }

// int main(){
//     std::cout << min({9,4,8}) << " ";
// }


// int simpleMultiplication(int a){
//     if (a%2 == 0) {
//         return a*8;
//     } else {
//         return a*9;
//     }
// }

// #include <string>

// std::size_t duplicateCount(const std::string& in)
// {
//     int sum = 0;
//     vector<int> rep = [0];
//     auto a = in.begin();
//     auto b = in.end();
//     for (; a < b; a++) {
//         auto x = a+1;
//         for (; x < b; x++){
//             if (*a == *x) {
//                 sum += 1;
//                 break;
//             }
//         }
//     }
//     return sum;
// }





// int main(){
//     std::cout << duplicateCount("Indivisibilities") <<std::endl;
// }



// #include <string>
// #include <vector>

// std::vector<std::string> towerBuilder(int n) {
// //   Agregar adelante de la lista
// // i index i-1 spaces before

//   std::vector<std::string> myvec;
//   std::cout << "Hi" << std::endl;
//   for (int i = 1; i == n; i++) {
//     myvec.push_back(" ");
//   } 

//     std::string str1 = " ";
//     std::string str2 = "*";

//   for (int i = 1; i == n; i++){
//     // myvec.at(i) = (n-i)*" " +  i*"*" + (n-i)*" ";
//     for (int w = 1; w == n-i-1; w++){
//       str1 += " ";
//     }
//     for (int w = 1; w == i; w++){
//       str2 += "*";
//     }

//     std::cout << str1 << std::endl;
//     myvec.at(i) = str1 + str2 + str1;
//   }
  
//   return std::vector<std::string>(myvec);
// }

// int main(){
//   auto vec = towerBuilder(3);
//   std::cout << vec[2] << std::endl;
// }


// #include <sstream>

// std::string format_duration(int seconds) {
//     if (seconds == 0) return "now";

//     const int yr = 365 * 24 * 60 * 60;
//     const int day = 24 * 60 * 60;
//     const int hr = 60 * 60;
//     const int mnt = 60;

//     std::vector<std::pair<std::string, int>> timeUnits = {
//         {"year", yr},
//         {"day", day},
//         {"hour", hr},
//         {"minute", mnt},
//         {"second", 1}
//     };

//     std::vector<std::string> components;

//     for (const auto& unit : timeUnits) {
//         int count = seconds / unit.second;
//         seconds %= unit.second;

//         if (count > 0) {
//             std::ostringstream part;
//             part << count << " " << unit.first;
//             if (count > 1) part << "s";  
//             components.push_back(part.str());
//         }
//     }

//     std::ostringstream result;
//     if (components.empty()) {
//         return "now";
//     } else if (components.size() == 1) {
//         return components[0];
//     } else if (components.size() == 2) {
//         return components[0] + " and " + components[1];
//     } else {
//         for (size_t i = 0; i < components.size(); ++i) {
//             result << components[i];
//             if (i < components.size() - 2) {
//                 result << ", ";
//             } else if (i == components.size() - 2) {
//                 result << " and ";
//             }
//         }
//         return result.str();
//     }


//     return result.str();
// }




// #include <vector>
// #include <utility>

// int sum_intervals(std::vector<std::pair<int, int>> intervals) {
//     if (intervals.empty()) return 0;

//     for (size_t i = 0; i < intervals.size(); ++i) {
//         for (size_t j = i + 1; j < intervals.size(); ++j) {
//             if (intervals[i].first > intervals[j].first) {
//                 std::pair<int, int> temp = intervals[i];
//                 intervals[i] = intervals[j];
//                 intervals[j] = temp;
//             }
//         }
//     }

//     int total = 0;
//     int currentStart = intervals[0].first;
//     int currentEnd = intervals[0].second;

//     for (size_t i = 1; i < intervals.size(); ++i) {
//         int start = intervals[i].first;
//         int end = intervals[i].second;

//         if (start <= currentEnd) {
//             if (end > currentEnd) {
//                 currentEnd = end;
//             }
//         } else {
//             total += currentEnd - currentStart;
//             currentStart = start;
//             currentEnd = end;
//         }
//     }

//     total += currentEnd - currentStart;
//     return total;
// }

// #include <string>
// #include <map>
// #include <vector>
// #include <algorithm>

// class Mix {
// public:
//     static std::string mix(const std::string& s1, const std::string& s2) {
//         std::map<char, int> count1, count2;

//         for (char ch : s1) {
//             if (ch >= 'a' && ch <= 'z') {
//                 count1[ch]++;
//             }
//         }

//         for (char ch : s2) {
//             if (ch >= 'a' && ch <= 'z') {
//                 count2[ch]++;
//             }
//         }

//         std::vector<std::string> result;

//         for (char ch = 'a'; ch <= 'z'; ++ch) {
//             int c1 = count1[ch];
//             int c2 = count2[ch];

//             if (c1 <= 1 && c2 <= 1) continue;  // skip if both counts are ≤ 1

//             std::string prefix;
//             int max_count = std::max(c1, c2);

//             if (c1 > c2) {
//                 prefix = "1:";
//             } else if (c2 > c1) {
//                 prefix = "2:";
//             } else {
//                 prefix = "=:";
//             }

//             result.push_back(prefix + std::string(max_count, ch));
//         }

//         std::sort(result.begin(), result.end(), [](const std::string& a, const std::string& b) {
//             if (a.size() != b.size()) return a.size() > b.size();
//             return a < b;
//         });

//         std::string final;
//         for (size_t i = 0; i < result.size(); ++i) {
//             final += result[i];
//             if (i < result.size() - 1) {
//                 final += '/';
//             }
//         }

//         return final;
//     }
// };





// std::string add(const std::string& a, const std::string& b) {
//     int i = a.size() - 1;
//     int j = b.size() - 1;
//     int mid = 0;
//     std::string result = "";

//     while (i >= 0 || j >= 0 || mid > 0) {
//         int digitA;
//         if (i >= 0) {
//             digitA = a[i] - '0';
//         } else {
//             digitA = 0;
//         }

//         int digitB;
//         if (j >= 0) {
//             digitB = b[j] - '0';
//         } else {
//             digitB = 0;
//         }

//         int sum = digitA + digitB + mid;
//         mid = sum / 10;
//         int digit = sum % 10;

//         result += (digit + '0');

//         i--;
//         j--;
//     }

//     std::string FinalSum = "";
//     for (int k = result.size() - 1; k >= 0; --k) {
//         FinalSum += result[k];
//     }

//     return FinalSum;
// }




// #include <vector>

// int maxSequence(const std::vector<int>& arr) {
//     int max = 0;
//     int current = 0; 
    
//     for (int num : arr) {
//         current += num;  
//         if (current < 0) { 
//             current = 0;
//         }
//         if (current > max) {
//             max = current;
//         }
//     }

//     return max;
// }



// #include <string>

// class RomanHelper {
// public:
//     std::string to_roman(unsigned int n) {
//         int values[] =    {1000, 900, 500, 400, 100, 90,  50, 40,  10, 9,   5,  4,  1};
//         std::string nums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX","V","IV","I"};
        
//         std::string result;
//         for (int i = 0; i < 13; ++i) {
//             while (n >= values[i]) {
//                 result += nums[i];
//                 n -= values[i];
//             }
//         }
//         return result;
//     }

//     int from_roman(std::string rn) {
//         int values[] =    {1000, 900, 500, 400, 100, 90,  50, 40,  10, 9,   5,  4,  1};
//         std::string nums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX","V","IV","I"};

//         int total = 0;
//         for (int i = 0; i < rn.length(); ) {
//             bool matched = false;
//             for (int j = 0; j < 13; ++j) {
//                 if (rn.substr(i, nums[j].size()) == nums[j]) {
//                     total += values[j];
//                     i += nums[j].size();
//                     matched = true;
//                     break;
//                 }
//             }
//             if (!matched) break;
//         }
//         return total;
//     }
// } RomanNumerals;





// #include <vector>
// #include <cstdint>
// #include <algorithm>

// uint64_t hamber(int n) {
//     if (n <= 0) return 0;

//     std::vector<uint64_t> hamming(n);
//     hamming[0] = 1;

//     int i2 = 0, i3 = 0, i5 = 0;

//     for (int i = 1; i < n; ++i) {
//         uint64_t next2 = hamming[i2] * 2;
//         uint64_t next3 = hamming[i3] * 3;
//         uint64_t next5 = hamming[i5] * 5;

//         uint64_t next = std::min({next2, next3, next5});
//         hamming[i] = next;

//         if (next == next2) ++i2;
//         if (next == next3) ++i3;
//         if (next == next5) ++i5;
//     }

//     return hamming[n - 1];
// }







// #include <cstdint>
// #include <vector>

// using namespace std;

// uint32_t partitions(uint32_t n) {
//     vector<uint32_t> dp(n + 1, 0);
//     dp[0] = 1;

//     for (uint32_t k = 1; k <= n; ++k) {
//         for (uint32_t i = k; i <= n; ++i) {
//             dp[i] += dp[i - k];
//         }
//     }

//     return dp[n];
// }



// #include <tuple>
// #include <type_traits>

// // Helper: Only sum numeric types except char and bool
// template <typename T>
// constexpr bool is_valid_numeric =
//     std::is_arithmetic<T>::value &&
//     !std::is_same<T, char>::value &&
//     !std::is_same<T, bool>::value;

// template <typename T>
// double sum_element(const T& x) {
//     if constexpr (is_valid_numeric<T>) {
//         return static_cast<double>(x);
//     } else {
//         return 0.0;
//     }
// }

// template <typename Tuple, std::size_t... Is>
// double tuple_sum_impl(const Tuple& tpl, std::index_sequence<Is...>) {
//     return (sum_element(std::get<Is>(tpl)) + ...); // fold expression
// }

// template <typename... Ts>
// double tuple_sum(const std::tuple<Ts...>& tpl) {
//     return tuple_sum_impl(tpl, std::index_sequence_for<Ts...>{});
// }


// #include <vector>
// #include <set>
// #include <cstdint>
// #include <algorithm>

// uint32_t n_linear(const std::set<uint32_t>& m_set, size_t n) {
//     std::vector<uint32_t> m(m_set.begin(), m_set.end()); 
//     std::vector<uint32_t> res = {1};                     
//     std::vector<size_t> idx(m.size(), 0);                

//     while (res.size() <= n) {
//         std::vector<uint64_t> candidates;
//         for (size_t i = 0; i < m.size(); ++i) {
//             candidates.push_back(static_cast<uint64_t>(res[idx[i]]) * m[i] + 1);
//         }

//         uint64_t next = *std::min_element(candidates.begin(), candidates.end());

//         if (next > res.back()) {
//             res.push_back(static_cast<uint32_t>(next));
//         }

//         for (size_t i = 0; i < m.size(); ++i) {
//             if (candidates[i] == next) {
//                 idx[i]++;
//             }
//         }
//     }

//     return res[n];
// }

