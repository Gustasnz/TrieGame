#ifndef TRIE_HPP
#define TRIE_HPP
#include "Game.hpp"
#include <vector>
#include <string>
const int ALPHABET_SIZE = 36;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;
    TrieNode();
    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    ~Trie();
    std::string toSearchKey(std::string text);
    bool contains(std::string title);
    bool insert(Game* game);
    std::vector<Game*> find_games(TrieNode* node);
    void sortResults(std::vector<Game*>& games);
    std::vector<Game*> autocomplete(std::string prefix, int k);
};

#endif