ate <class T>
T maxValue(T a, T b){
    return (a > b) ? a : b;
}

int main(){
    std::cout << maxValue(2,10) << std::endl;
    std::cout << maxValue(3.9,9.2) << std::endl;
    std::cout << maxValue(std::string("A"),std::string("D")) << std::endl;
}