#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <locale>

using namespace std;

struct Transaction {
    string invoiceNo;
    string stockCode;
    string description;
    int quantity;
    double unitPrice;
    string invoiceDate;
    string country;
};

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

string replaceComma(const string& input) {
    string result = input;
    size_t comma_pos = result.find(',');
    if (comma_pos != string::npos && result.find('.', comma_pos) == string::npos) {
        result[comma_pos] = '.';
    }
    return result;
}

Transaction parseTransaction(const string& line) {
    Transaction t;
    vector<string> tokens;
    string token;
    bool inQuotes = false;
    size_t start = 0;

    for (size_t i = 0; i < line.length(); ++i) {
        if (line[i] == '"') {
            inQuotes = !inQuotes;
        } else if (line[i] == ',' && !inQuotes) {
            token = line.substr(start, i - start);
            tokens.push_back(trim(token));
            start = i + 1;
        }
    }
    tokens.push_back(trim(line.substr(start)));

    if (tokens.size() >= 8) {
        t.invoiceNo = tokens[0];
        t.stockCode = tokens[1];
        t.description = tokens[2];
        
        try { t.quantity = stoi(tokens[3]); } 
        catch (...) { t.quantity = 0; }
        
        try { t.unitPrice = stod(replaceComma(tokens[5])); } 
        catch (...) { t.unitPrice = 0.0; }
        
        t.invoiceDate = tokens[4];
        t.country = tokens[7];
    }

    return t;
}

map<string, int> countTransactionsByCountry(const vector<Transaction>& transactions, const string& filterCountry = "") {
    map<string, int> countryCounts;
    for (const auto& t : transactions) {
        if (!t.country.empty() && (filterCountry.empty() || t.country == filterCountry)) {
            countryCounts[t.country]++;
        }
    }
    return countryCounts;
}

double calculateTotalAmount(const vector<Transaction>& transactions, bool onlyUK = false) {
    double total = 0.0;
    for (const auto& t : transactions) {
        if (!onlyUK || (onlyUK && t.country == "United Kingdom")) {
            total += t.quantity * t.unitPrice;
        }
    }
    return total;
}

void printHelp() {
    cout << "Retail Data Analytics App\n";
    cout << "Usage:\n";
    cout << "  retail_analytics [country] [--only-uk]\n";
    cout << "Options:\n";
    cout << "  country        : Filter transactions by country\n";
    cout << "  --only-uk      : Calculate total amount for UK only\n";
    cout << "  --help or -h   : Show this help message\n";
}

int main(int argc, char* argv[]) {
    string filename = "OnlineRetail.csv";
    string countryFilter = "";
    bool onlyUK = false;

    // Parse arguments
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--only-uk") {
            onlyUK = true;
        } else if (arg == "--help" || arg == "-h") {
            printHelp();
            return 0;
        } else if (arg[0] != '-') {
            countryFilter = arg;
        }
    }

    // Read file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        cerr << "Current directory: ";
        system("cd");
        return 1;
    }

    vector<Transaction> transactions;
    string line;
    int lineCount = 0;

    // Skip header
    getline(file, line);

    while (getline(file, line)) {
        lineCount++;
        if (!line.empty()) {
            try {
                Transaction t = parseTransaction(line);
                if (!t.country.empty()) {  // Skip empty/invalid transactions
                    transactions.push_back(t);
                }
            } catch (...) {
                cerr << "Warning: Error parsing line " << lineCount << "\n";
            }
        }
    }
    file.close();

    if (transactions.empty()) {
        cerr << "Error: No valid transactions found\n";
        return 1;
    }

    // Analysis
    map<string, int> countryCounts = countTransactionsByCountry(transactions, countryFilter);
    double totalAmount = calculateTotalAmount(transactions, onlyUK);

    // Output
    cout << "\nTransaction Counts:\n";
    if (countryFilter.empty()) {
        for (const auto& [country, count] : countryCounts) {
            cout << "  " << country << ": " << count << " transactions\n";
        }
    } else {
        auto it = countryCounts.find(countryFilter);
        cout << "  " << (it != countryCounts.end() ? to_string(it->second) : "0") 
             << " transactions for " << countryFilter << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Transaction Amount: $" << totalAmount;
    if (onlyUK) cout << " (UK only)";
    cout << "\n\n";

    return 0;
}