#include <string>
#include <iostream>
#include <map>

typedef std::map<std::string, std::string> element_t;
typedef std::map<std::string, element_t> database_t;

// just a simple function to clear the terminal
void clear(int n=100){
        for (int i = 0; i < n; i++)
                std::cout << '\n';
}

bool add(std::string name, database_t &database, int ac=0, int hp=0){
        if ( database.find(name) != database.end() ) return 0;

        element_t element;
        element["ac"] = ac;
        element["hp"] = hp;

        database.insert(std::make_pair(name,element));
        return 1;
}


int main(int argc, char const *argv[]) {
        clear();

}
