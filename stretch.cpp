# include <iostream>

/// @brief Function to print the stretched version of a string
/// @param str the string to be printed
void stretchPrint(std::string str){
    // iterating through the string
    for(auto elem : str){
        // printing all the elements
        std::cout << elem << "   ";
    }
}

/// @brief Function to check if a string has only spaces
/// @param str the string to be checked for spaces
/// @return bool
bool onlySpaces(std::string str){
    // iterating through the string
    for(auto elem : str){
        // if the current index is not a space, return false
        if(elem != ' ') return false;
    }

    return true;
}

/// @brief The main method of the program
/// @param argc total number of arguments passed
/// @param argv string array containing all the arguments
/// @return int
int main(int argc, char** argv){
    std::string str;

    // asking user for the string
    std::cout << "Enter your string: ";
    std::getline(std::cin, str);

    // if the string is empty or it only has spaces
    if(str == "" || onlySpaces(str)){
        std::cout << "Bro the input is kinda laggy!";
        return 0;
    }

    // stretching the word given by user and printing it
    std::cout << "Stretching your word....\n";
    stretchPrint(str);
    std::cout << std::endl;
    return 0;
}