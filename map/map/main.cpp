#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

void PokemonPokedex();

int main(){
    std::map<std::string, std::string> myDictionary;
    myDictionary.insert(std::pair<std::string, std::string>("apple", "Der Apfel"));
    myDictionary.insert(std::pair<std::string, std::string>("banana", "Die Banane"));
    myDictionary.insert(std::pair<std::string, std::string>("orange", "Die Orange"));
    myDictionary.insert(std::pair<std::string, std::string>("strawberry", "Der Erdbeere"));
    
    std::cout << "The size of the dictionary is: " << myDictionary.size() << '\n';
    for (auto pair : myDictionary) {
        cout << pair.first << " " << pair.second << '\n';
    }
    //to delete elements use erase
    std::cout << '\n';
    std::cout << "After delete we get: \n";
    myDictionary.erase("apple");
    for (auto pair : myDictionary) {
        cout << pair.first << " " << pair.second << '\n';
    }
    
    //delete all elements
    myDictionary.clear();
    cout << '\n';
    cout << "Pokemon and attacks\n";
    PokemonPokedex();
    
    return 0;
}


void PokemonPokedex()
{
    map<string, list <string>> pokedex;
    list<string> pikachuAttack { "thunder shock", "tail whip" , " quick attack"};
    list<string> charmanderAttack {"flamethrower", "scary face"};
    list<string> chicoritaAttack {"razor leaf", "poiser powder"};
    
    pokedex.insert(pair<string, list<string>> ("Pikachu", pikachuAttack));
    pokedex.insert(pair<string,list<string>> ("Charmander", charmanderAttack));
    pokedex.insert(pair<string,list<string>> ("Chicorita", chicoritaAttack));
    
    for(auto pair : pokedex)
    {
        cout << pair.first << " - ";
        for(auto attack : pair.second)
        {
            cout << attack << ", ";
        }
        cout << "\n";
    }
    
}
