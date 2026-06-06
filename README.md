# Sistema de Autocomplete de Jogos

## Descrição do Projeto
Este projeto implementa um sistema de autocomplete para um catálogo de jogos utilizando a estrutura de dados **Trie** (Árvore de Prefixos). A aplicação permite buscar rapidamente jogos a partir de um prefixo do título. 

O sistema foi desenvolvido com foco em modularização e orientação a objetos. A busca não diferencia maiúsculas de minúsculas, ignora espaços em branco e aceita caracteres alfanuméricos. Os resultados do autocomplete são retornados ordenados prioritariamente pela **popularidade** do jogo (em ordem decrescente) e, em caso de empate, pela ordem alfabética da chave de busca.

## Organização dos Arquivos do Projeto

A estrutura de diretórios e arquivos do projeto está organizada da seguinte forma:

```text
.
├── main.cpp              # Carrega a base de dados e gera a Trie para ser executada a busca
├── Game.hpp              # Declaração da classe Game
├── Game.cpp              # Implementação dos métodos da classe Game
├── Trie.hpp              # Declaração das classes TrieNode e Trie
├── Trie.cpp              # Implementação das funções que podem ser aplicadas a Trie (busca e ordenação)
├── GamesDatabase.hpp     # Declaração externa do array de jogos
└── GamesDatabase.cpp     # Catálogo de jogos
```

## Instruções de Compilação
Para compilar o projeto utilize o comando:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```
## Exemplos de Uso pela Linha de Comando

### Exemplo 1: Busca simples por prefixo
```bash
./app 3 ha

Hades | Roguelike de acao baseado na mitologia grega | 95
Half Life | FPS classico de ficcao cientifica | 92
Halo | FPS futurista com campanha e multiplayer | 85
```
### Exemplo 2: Busca com espaço
```bash
./app 5 "half l"

Half Life | FPS classico de ficcao cientifica | 92
```
### Exemplo 3: Sem jogo no database
```bash
./app 3 zelda

No results found