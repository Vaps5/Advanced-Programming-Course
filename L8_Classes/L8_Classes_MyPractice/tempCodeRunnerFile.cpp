s Person {
    public:
        std::string name;
        int age;
    
        // Constructor
        Person() {
            name = "Unknown";
            age = 0;
        }
    
    };
    
    int main() {
        Person p1;  // Calls the constructor automatically
        std::cout << p1.age << " " << p1.name <<std::endl;
    }