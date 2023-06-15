# include <iostream>
# include <set>

// sets to store the movie names and the snack names
std::set<std::string> movies, snacks;

// function to book a ticket
void bookTickets(){
    // ignoring \n character from cin
    std::cin.ignore(1, '\n');
    std::string movie_name;
    int total_people;

    // asking for the name of movie
    std::cout << "Enter the movie you want to see: ";
    std::getline(std::cin, movie_name);

    // if the move is not in set
    if(movies.find(movie_name) == movies.end()){
        std::cout << "Sorry, but we are currently not airing that movie.";
        return;
    }

    // asking for the number of tickets
    std::cout << "How many tickets to book ($5 per ticket)? ";
    std::cin >> total_people;

    // if the total amount of persons is below 1
    if(total_people < 1){
        std::cout << "Bro the amount is kinda laggy!";
        return;
    }

    // successfully booking tickets
    std::cout << "Success! Booked movie " << movie_name << " for " << total_people << " people at $" << total_people * 5;
}

// function to view movies and snacks avaliable
void viewMovies(){
    // printing all of the movies
    std::cout << "Currently avaliable movies:\n"; 
    for(auto elem : movies) std::cout << elem << '\n';

    // printing all of the snacks
    std::cout << "\nAvaliable Snacks:\n";
    for(auto elem : snacks) std::cout << elem << '\n';
}

// function to buy snacks
void buySnacks(){
    // ignoring \n character from cin
    std::cin.ignore(1, '\n');
    std::string name;
    int count;

    // asking user for the snack name
    std::cout << "Enter the snack you want to eat: ";
    std::getline(std::cin, name);

    // if the snack is not found
    if(snacks.find(name) == snacks.end()){
        std::cout << "Sorry, but we are currently not airing that movie.";
        return;
    }

    // asking for the number of snacks the user want
    std::cout << "How many of that snack do you want? ($1.25 per snack)? ";
    std::cin >> count;

    // if the count is below 1
    if(count < 1){
        std::cout << "Bro the amount is kinda laggy!";
        return;
    }

    // successfully buying snacks
    std::cout << "Success! Purchased Snack " << name << " of amount " << count << " at $" << count * 1.25;
}

// main function of the program
int main(int argc, char** argv){
    // declaring the sets
    movies = {"Interstellar", "Inception", "Sherk 2", "Toy Story 4", "Avatar", "Terminators"};
    snacks = {"Coca-Cola", "Popcorns", "Water", "Sandwitch", "Borgor", "French Fries", "Pixu"};
    int choice;
    bool run = true;

    std::cout << "DILLUSIONERS MOVIE THEATRE";

    // running until the user stops
    while(run){
        // printing the menu to the user and asking for their choice
        std::cout << "\n\nSelect your choice:\n";
        std::cout << "1. Get Movie Tickets\n2. View Avaliable Movies and Snacks\n3. Buy Snacks\n4. Exit\n>> ";
        std::cin >> choice;
        std::cout << std::endl;

        // running a switch case on the user choice
        switch(choice){
            // get movie tickets
            case 1: {
                bookTickets();
                break;
            }

            // view avaliable movies and snacks
            case 2: {
                viewMovies();
                break;
            }

            // buy snacks
            case 3: {
                buySnacks();
                break;
            }

            // exit
            case 4: {
                run = false;
                break;
            }

            // invalid choice
            default: {
                std::cout << "Invalid Choice Provided. Try Again!";
            }
        }
    }
    return 0;
}