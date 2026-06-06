#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./check_database k" << std::endl;
        return 1;
    }

    int numGamesToRead = std::atoi(argv[1]);

    numGamesToRead = std::max(numGamesToRead, 0);
    numGamesToRead = std::min(numGamesToRead, numberOfGames);

    std::cout << "Reading " << numGamesToRead << " games:\n\n";

    for (int i = 0; i < numGamesToRead; i++) {
        std::cout << "Title: " << games[i].getTitle() << std::endl;
        std::cout << "Description: " << games[i].getShortDescription() << std::endl;
        std::cout << "Popularity: " << games[i].getPopularity() << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}