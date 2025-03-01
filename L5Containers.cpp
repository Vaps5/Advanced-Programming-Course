

// Task 1: Managing Products with std::map
/*
#include <iostream>
#include <map>

void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}


// ADD NEW PRODUCT
void addInventory(std::string new_product, int new_value, std::map<std::string, int>& inventory) {
    inventory.insert({new_product, new_value});
}


// UPDATE the quantity of an existing product.
void UpdateQuantity(std::string current_product, int new_value, std::map<std::string, int>& inventory) {
    inventory[current_product] = new_value;
}


int main() {
    int finished{1};
    std::map<std::string, int> inventory;
    std::string product;
    int value;
    int conf;

    // Adding products
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 20;
    inventory["Keyboard"] = 10;


    while (finished == 1){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Welcome to the Store:\n Enter a number:\n 1. Add a new product to the inventory. \n2. Update the quantity of an existing product. \n3. Display all available products." << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cin >> conf;
        switch (conf) {
            case 1:
                int value;
                std::cout << "Enter the product\n";
                std::cin >> product;
                std::cout << "Enter the value (int)\n";
                std::cin >> value;
                addInventory(product,value,inventory);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> finished;
                break;
            case 2:
                std::cout << "Enter the product\n";
                std::cin >> product;
                std::cout << "Enter the value (int)\n";
                std::cin >> value;
                UpdateQuantity(product,value,inventory);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> finished;
                break;
            case 3:
                displayInventory(inventory);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> finished;
                break;
            default:
            std::cout << "You did not entered an option";
            break;  
        }
    }
    return 0;
}
*/





// Task 2: Tracking Unique Products with std::set
/*
#include <iostream>
#include <set>

void displayCategories(const std::set<std::string> productCategories) {
    std::cout << "Product Categories:\n";
    for (const auto& category : productCategories) {
        std::cout << "- " << category << "\n";
    }
}


// ADD NEW Category
void addCategory(std::string new_category, std::set<std::string>& productCategories) {
    productCategories.insert(new_category);
}


int main() {
    system("cls");
    int not_finished{1};
    std::set<std::string> productCategories;
    std::string new_category;
    int conf;

    // Adding categories
    productCategories.insert("Electronics");
    productCategories.insert("Accessories");
    productCategories.insert("Peripherals");


    while (not_finished == 1){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Welcome to the Store:\n Enter a number:\n 1. Add a new category. \n2.Display all categories." << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cin >> conf;
        switch (conf) {
            case 1:
                int value;
                std::cout << "Enter the product\n";
                std::cin >> new_category;
                addCategory(new_category,productCategories);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            case 2:
                displayCategories(productCategories);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            default:
            std::cout << "You did not entered an option";
            break;  
        }
    }
    return 0;
}
*/



//Task 3: Processing Orders with std::queue

/*
#include <iostream>
#include <queue>

// ADD NEW Order
void addOrder(std::string new_order, std::queue<std::string>& orders) {
    orders.push(new_order);
}


//PROCESS an order
void processingOrder(std::queue<std::string>& orders) {
    std::cout << "Processing " << orders.front() << std::endl;
    orders.pop();
}

int main() {
    system("cls");
    int not_finished{1};
    std::queue<std::string> orders;
    std::string new_order;
    int conf;

    // Adding orders
    orders.push("Order#1: Laptop");
    orders.push("Order#2: Mouse");
    orders.push("Order#3: Keyboard");

    // // Processing orders
    // while (!orders.empty()) {
    //     std::cout << "Processing " << orders.front() << std::endl;
    //     orders.pop();
    

    while (not_finished == 1){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Welcome to the Store:\n Enter a number:\n 1. Add a new order. \n2.Process an order (remove from the queue)." << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cin >> conf;
        switch (conf) {
            case 1:
                std::cout << "Enter the order\n";
                std::cin >> new_order;
                addOrder(new_order,orders);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            case 2:
                processingOrder(orders);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            default:
            std::cout << "You did not entered an option";
            break;  
        }
    }
    return 0;
};
*/



//Task 4: Handling Restocks with std::stack

/*
#include <iostream>
#include <stack>

// ADD NEW restock
void addRestock(std::string new_restock, int new_value, std::stack<std::pair<std::string, int>> restocks) {
    restocks.push({new_restock, new_value});
}


//PROCESS a restock
void processingRestock(std::stack<std::pair<std::string, int>> restocks) {
    auto item = restocks.top();
    std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
    restocks.pop();


int main(){
    system("cls");
    int not_finished{1};
    std::stack<std::pair<std::string, int>> restocks;
    std::string new_restock;
    int conf;

    // Adding restock batches
    restocks.push({"Mouse", 10});
    restocks.push({"Laptop", 2});
    restocks.push({"Keyboard", 5});

    // // Processing restocks
    // while (!restocks.empty()) {
    //     auto item = restocks.top();
    //     std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
    //     restocks.pop();
    // }
    

    while (not_finished == 1){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Welcome to the Store:\n Enter a number:\n 1. Add a new restock. \n2. Process a restock bach" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cin >> conf;
        switch (conf) {
            case 1:
                int value;
                std::cout << "Enter the restock\n";
                std::cin >> new_restock;
                std::cout << "Enter the value (int)\n";
                std::cin >> value;
                addRestock(new_restock, new_value, restocks);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            case 2:
                processingRestock(restocks);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            default:
            std::cout << "You did not entered an option";
            break;  
        }
    }
    return 0;
};
*/

//Task 5: Storing Customer Purchases with std::vector
#include <iostream>
#include <vector>

void displayItems(const std::vector<std::string> customerCart) {
    std::cout << "Items in customer cart:\n";
    for (const auto& item : customerCart) {
        std::cout << "- " << item << "\n";
    }
}


// ADD NEW Category
void addItems(std::string new_item, std::vector<std::string>& customerCart) {
    customerCart.push_back(new_item);
}


int main() {
    system("cls");
    int not_finished{1};
    std::vector<std::string> customerCart;
    std::string new_item;
    int conf;

    // Adding items to cart
    customerCart.push_back("Laptop");
    customerCart.push_back("Mouse");
    customerCart.push_back("Keyboard");


    while (not_finished == 1){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Welcome to the Store:\n Enter a number:\n 1. Add a new item. \n2.Display all items." << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cin >> conf;
        switch (conf) {
            case 1:
                int value;
                std::cout << "Enter the item\n";
                std::cin >> new_item;
                addItems(new_item,customerCart);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            case 2:
                displayItems(customerCart);
                std::cout << "Do you want to return to the menu? (0/1)\n";
                std::cin >> not_finished;
                break;
            default:
            std::cout << "You did not entered an option";
            break;  
        }
    }
    return 0;
}
