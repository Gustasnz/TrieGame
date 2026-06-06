#include "Trie.hpp"

TrieNode::TrieNode(){
    isEndOfTitle=false;
    for (int i=0;i<ALPHABET_SIZE;i++){
        children[i]=nullptr;
    }
}
TrieNode::~TrieNode() {
    for (int i=0;i<ALPHABET_SIZE;i++) {
        if (children[i]!=nullptr){
            delete children[i];
        }
    }
}

Trie::Trie(){
    root= new TrieNode();
}
Trie::~Trie(){
    delete root;
}

std::string Trie::toSearchKey(std::string text){
    for(int i=0;i<text.size();i++){
        if (text[i]==' '){ // "puxa" os caracteres da direita para a esquerda
            for (int j=i;j<text.size()-1;j++){
                text[j]=text[j+1];
            }
            text.pop_back(); // remove o último que ficou sobrando
            i--; // volta uma posição para não pular o caractere que acabou de mudar de lugar
        }
        if (text[i]>='A' && text[i]<='Z'){
            text[i]=text[i]+32; // ascii
        }
    } return text;
}    


bool Trie::contains(std::string title){
    std::string titulo=toSearchKey(title);
    TrieNode* node=root;
    int indice=0;
    for (int i=0;i<titulo.size();i++){
        if (titulo[i]>='0' && titulo[i]<='9'){
            indice=26+(titulo[i]-'0');
            if (node->children[indice]!=nullptr){
                node=node->children[indice];
            }
            else{
                return false;
            }
        }
        else{
            indice=titulo[i]-'a';
            if (node->children[indice]!=nullptr){
                node=node->children[indice];
            }
            else{
                return false;
            }
        }
    }
    if (node->isEndOfTitle){
        return true;
    } return false;

}


bool Trie::insert(Game* game){
    TrieNode* node=root;
    std::string titulo=toSearchKey(game->getTitle());
    int indice=0;
    for (int i=0;i<titulo.size();i++){
        if (titulo[i]>='0' && titulo[i]<='9'){
            indice=26+(titulo[i]-'0');
            if (node->children[indice]!=nullptr){
                node=node->children[indice];
            }
            else{
                node->children[indice]=new TrieNode();
            }
        }
        else{
            indice=titulo[i]-'a';
            if (node->children[indice]!=nullptr){
            node=node->children[indice];
            }
            else{
                node->children[indice]=new TrieNode();
                node=node->children[indice]; // avança para o próximo
            }
        }
    }
    node->isEndOfTitle=true;
    node->game=game;
    return true;
}

std::vector<Game*> Trie::find_games(TrieNode* node){
    std::vector<Game*> vetor_small = {};
    std::vector<Game*> vetor={};
    if (node->isEndOfTitle){
        vetor.push_back(node->game);
    }
    for (int i=0;i<ALPHABET_SIZE;i++){
        if (node->children[i]!=nullptr){
            vetor_small=find_games(node->children[i]);
            vetor.insert(vetor.end(), vetor_small.begin(),vetor_small.end());
        }
    }
    return vetor;
}

void Trie::sortResults(std::vector<Game*>& games){
    for (size_t i=1;i<games.size();++i){
        Game* keyGame=games[i];
        int j = i-1;
        while (j>=0){
            bool swapNeeded=false;
            if (games[j]->getPopularity()<keyGame->getPopularity()){
                swapNeeded=true;
            } 
            else if (games[j]->getPopularity()==keyGame->getPopularity()){
                std::string key1=toSearchKey(games[j]->getTitle());
                std::string key2=toSearchKey(keyGame->getTitle());
                if (key1>key2){
                    swapNeeded=true;
                }
            }
            if (swapNeeded){
                games[j+1]=games[j];
                j--;
            } else {
                break;
            }
        } 
        games[j+1]=keyGame;
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){
    std::string titulo=toSearchKey(prefix);
    TrieNode* node=root;
    if (k<=0) return {};
    int indice=0;
    for (int i=0;i<titulo.size();i++){
        if (titulo[i]>='0' && titulo[i]<='9'){
            indice=26+(titulo[i]-'0');
            if (node->children[indice]!=nullptr){
            node=node->children[indice];
            }
            else{
                return {};
            }
        }
        else{
            indice=titulo[i]-'a';
            if (node->children[indice]!=nullptr){
            node=node->children[indice];
            }
            else{
                return {};
            }
        }
    };
    std::vector<Game*> vetor=find_games(node);
    sortResults(vetor);
    if (vetor.size()>k){
        vetor.resize(k);
    }
    return vetor;
}