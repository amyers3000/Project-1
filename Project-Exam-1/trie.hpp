//
//  trie.hpp
//  Project-Exam-1
//
//  Created by Alex Myers on 3/2/24.
//

#ifndef trie_hpp
#define trie_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct TrieNode {
    bool complete;
    std::unordered_map<char, TrieNode*> children;
    
    TrieNode() : complete(false) {}
};

class Trie {
private:
    TrieNode* root;
    std::unordered_set<std::string> validWords;
    std::unordered_set<std::string> suggestions;
    
    void didYouMeanHelper(TrieNode* node, const std::string& path, std::unordered_set<std::string>& list, std::string word);
    void traverseSearch(TrieNode* node, const std::string& path, std::unordered_set<std::string>& list);
    void deleteTrie(TrieNode* node);
    
public:
    Trie();
    ~Trie();
    
    void searchTrie(std::string& word);
    void didYouMean(std::string path, std::string word);
    void insertWord(const std::string& word);
    void insertFile(const std::string& path);
    void searchConsoleInput();
};

#endif
