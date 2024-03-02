#include <iostream>
#include "trie.hpp"


int main() {
    char flag;
    Trie* newTrie = new Trie();

    newTrie->insertFile("Dictionary.txt");
    do {
        newTrie->searchConsoleInput();

        std::cout << "Continue (y/n)? ";
        std::cin >> flag;
    } while (flag == 'y');

    delete newTrie;

    return 0;
}

