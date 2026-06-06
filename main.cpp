#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) { // verifica se os argumentos foram informados corretamente
        std::cout << "Usage: ./app k prefix\n";
        return 1;
    }
    int k = std::stoi(argv[1]); // converte k para inteiro
    std::string prefix = argv[2];

    Trie trie;
    for (int i = 0; i < numberOfGames; i++) { // insere os jogos na Trie
        trie.insert(&games[i]);
    }
    std::vector<Game*> suggestions = trie.autocomplete(prefix, k); // autocomplete

    if (suggestions.empty()) { // exibição
        std::cout << "No results found\n";
    } else {
        for (Game* g : suggestions) {
            std::cout << ">>>  " << g->getTitle() << " | " 
                      << g->getShortDescription() << " | " 
                      << g->getPopularity() << "\n\n";
        }
    } return 0;
}