# include <iostream>
# include <conio.h>
# include <random>
# include <sys/ioctl.h>
# include <unistd.h>

/// @brief Gets the Terminal size of the current console state in rows and cols
/// @return pair
std::pair<int, int> getTerminalSize(){
    int cols = 0, rows = 0;

    // if the TIOCGSIZE macro is declared
    # ifdef TIOCGSIZE
        struct ttysize ts;
        ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
        cols = ts.ts_cols;
        rows = ts.ts_rows;

    // if the TIOCGWINSZ macro is declared
    # elif defined(TIOCGWINSZ)
        struct winsize ts;
        ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
        cols = ts.ws_col;
        rows = ts.ws_row;
    # endif

    // returning the coloumns and rows
    return {cols, rows};
}

/// @brief The main function of the program
/// @param argc The number of arguments
/// @param argv String array of all the arguments
/// @return int
int main(int argc, char** argv){
    // variables declared here
    std::random_device rd;
    std::mt19937 mt(rd());
    std::pair<int, int> actual, guess, terminal_size;

    // getting the current terminal size
    terminal_size = getTerminalSize();

    std::cout << "WHEREVER THE CURSOR IS, YOU HAVE TO FIND IT!\nGUESS THE LOCATION";

    // randomly generating cursor location
    actual.first = mt() % terminal_size.first;
    actual.second = mt() % terminal_size.second;

    // moving the cursor to the location
    gotoxy(actual.first, actual.second);

    // asking for the user guess
    std::cout << "Enter the coloumn size and row size of the cursor respectively:\n";
    std::cin >> guess.first >> guess.second;
    
    // if the guess is correct
    if(guess == actual) std::cout << "You have guessed the correct cursor location. Congrats!";
    else std::cout << "Wrong guess! The answer is " << actual.first << 'x' << actual.second << '\n';

    return 0;
}