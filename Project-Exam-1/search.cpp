#include "trie.hpp"

void Trie::searchTrie(std::string& word) {
    TrieNode* startNode = root;
    std::string path;
    
    for (const auto& letter : word) {
        if (startNode->children.find(letter) == startNode->children.end()) {
            // Message Previously Here
            std::cout << "Did you mean:" << std::endl;
            didYouMean(path, word);
            for(const auto& string : suggestions){
                std::cout << string << std::endl;
            }
            suggestions.clear();
            return;
        }
        path += letter;
        startNode = startNode->children[letter];
    }
    traverseSearch(startNode, path, validWords);
    std::cout << "Your options are: " << std::endl;
    for(const auto& string : validWords){
        std::cout << string << std::endl;
    }
    validWords.clear();
}

void Trie::traverseSearch(TrieNode* node, const std::string& path, std::unordered_set<std::string>& list ) {
    if (node == nullptr) {
        return;
    }
    
    if (node->complete) {
        list.insert(path);
    }
    for (const auto& child : node->children) {
        traverseSearch(child.second, path + child.first, list);
    }
}


void Trie:: didYouMean(std::string path, std::string word){
    if (suggestions.size() == 3 ) {
        return;
    }
    TrieNode* startNode = root;
    for (const auto& letter : path) {
        if (startNode->children.find(letter) == startNode->children.end()) {
            return;
        }
        startNode = startNode->children[letter];
    }
    didYouMeanHelper(startNode, path, suggestions, word);
    path.pop_back();
    didYouMean(path, word);
}

void Trie::didYouMeanHelper(TrieNode* node, const std::string& path, std::unordered_set<std::string>& list, std::string word) {
    if (node == nullptr || list.size() == 3) {
        return;
    }
    
    if (node->complete &&  path.size() <= word.size() && list.find(path) == list.end() ) {
        list.insert(path);
    }
    for (const auto& child : node->children) {
        didYouMeanHelper(child.second, path + child.first, list, word);
    }
}
