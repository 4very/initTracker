#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>

typedef std::map<std::string, std::string> element_t;
typedef std::vector<element_t> database_t;
typedef std::vector<std::string> input_t;

// just a simple function to clear the terminal
void clear(int n=100){
        for (int i = 0; i < n; i++)
                std::cout << '\n';
}

input_t split(std::string str, char delimiter=' '){
        std::string buffer; input_t return_value;
        for (unsigned int i = 0; i < str.size(); i++) {
                if (str[i] == delimiter) {
                        return_value.push_back(buffer); buffer = "";
                } else
                        buffer = buffer + str[i];
        } return return_value;
}

// sort function using insersion sort
bool sortByInitiave(database_t &database){
        //TODO
        return 0;
}


bool add(std::string input, database_t &database){

        input_t split_input = split(input);
        assert(split_input[0] == "a");

        element_t element;
        element["name"] = split_input[1];
        for (unsigned int i = 2; i < split_input.size(); i = i+2) {
                assert(i < split_input.size()-1);
                if (split_input[i] == "-h") element["hp"] = split_input[i+1];
                if (split_input[i] == "-i") element["i"] = split_input[i+1];
                if (split_input[i] == "-a") element["ac"] = split_input[i+1];

        }

        for (unsigned int i = 0; i < database.size(); i++)
                if (database[i]["name"] == split_input[1]) {return 0;}

        database.push_back(element);
        return 1;
}
bool damage(unsigned int pos, unsigned int damage, database_t &database, int from=-1){
        if ( pos >= database.size()) return 0;
        if ( database[pos].find("hp") == database[pos].end() ) return 0;

        if ( std::stoi(database[pos]["hp"]) - damage <= 0 ) database[pos]["dead"] = "1";

        database[pos]["hp"] = std::stoi(database[pos]["hp"]) - damage;
        return 1;
}

bool input(database_t &database){
        std::cout << "> ";
        std::string command;
        std::cin >> command;
        switch (command[0]) {
        case 'a': std::cout << "\nadding"; break;
        case 'd': std::cout << "\ndamage"; break;
        case 'c': std::cout << "\nhealing"; break;
        case 'l': std::cout << "\nloading"; break;
        case 'i': std::cout << "\nadding Initiative"; break;
        case 'u': std::cout << "\nupdating"; break;
        case 'z': std::cout << "\nundoing"; break;
        case 'h': std::cout << "\nlisting history"; break;
        case 'e': std::cout << "\nexporting"; break;
        default: std::cout << "UNKNOWN COMMAND"; return 0;
        }
}

bool render(database_t &database){
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        clear();

        std::cout << "INITIATIVE TRACKER BY AVERY SOMMER" << '\n';


        for (int i = 0; i < w.ws_col; i++) {
                std::cout << "-";
        }       // Print dashes
        for (int i = 2; i < w.ws_row; i++) {
                std::cout << '\n';
        } // Print Newlines
        input(database);
}


int main(int argc, char const *argv[]) {
        database_t d;
        while (1==1) {

                render(d);
        }
}
