#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./app k prefix\n";
        return 1;
    }
    int k = std::stoi(argv[1]);
    std::string prefix = argv[2];
    Trie trie;
    for (int i = 0; i < numberOfGames; i++) {
        trie.insert(&games[i]);
    }
    std::vector<Game*> suggestions = trie.autocomplete(prefix, k);
    if (suggestions.empty()) {
        std::cout << "No results found\n";
    } else {
        for (Game* g : suggestions) {
            std::cout << ">>>  " << g->getTitle() << " | " 
                      << g->getShortDescription() << " | " 
                      << g->getPopularity() << "\n\n";
        }
    } return 0;
}