#include "trie.hpp"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insertWord(const std::string& word) {
    TrieNode* current = root;
    for (char letter : word) {
        if (letter == '\r') {
            continue;
        }
        
        if (current->children.find(letter) == current->children.end()) {
            current->children[letter] = new TrieNode();
        }
        current = current->children[letter];
    }
    current->complete = true;
}


void Trie::insertFile(const std::string& path) {
    std::ifstream myfile(path);
    std::string myline;
    
    if (myfile.is_open()) {
        while (std::getline(myfile, myline)) {
            insertWord(myline);
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file: " << path << std::endl;
    }
}

void Trie::searchConsoleInput() {
    std::string word;
    
    std::cout << "Please type search queries: ";
    std::cin >> word;
    
    searchTrie(word);
}

Trie::~Trie() {
    deleteTrie(root);
}

void Trie::deleteTrie(TrieNode* node) {
    if (node == nullptr) {
        return;
    }
    
    for (auto& child : node->children) {
        deleteTrie(child.second);
    }
    
    delete node;
}


