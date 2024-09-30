#include <iostream>
#include <sstream>
#include <string>

bool containsRegisterStartingWithC(const std::string& extract_src) {
    std::stringstream ss(extract_src);
    std::string registerName;

    // Split the input string by commas
    while (std::getline(ss, registerName, ',')) {
        // Trim whitespace
        registerName.erase(0, registerName.find_first_not_of(" \t"));
        registerName.erase(registerName.find_last_not_of(" \t") + 1);

        // Check if it starts with 'c'
        if (registerName.rfind("c", 0) == 0) {
            return true; // Found a register starting with 'c'
        }
    }

    return false; // No register starting with 'c' found
}

int main() {
    // Example extract_src input
    std::string extract_src = "c246.w, r4.y, c248.w";

    // Call the function and print the result
    if (containsRegisterStartingWithC(extract_src)) {
        std::cout << "jt" << std::endl; // Print "jt" if true
    } else {
        std::cout << "No register starting with 'c' found." << std::endl;
    }

    return 0;
}
