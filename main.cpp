#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "DFANode.h"

DFANode* constructDFA(std::map<char, std::string>& graph, char h) {
    std::map<char, DFANode*> storage;
    DFANode* head;

    for (auto i = graph.begin(); i != graph.end(); i++) {
        DFANode* curr;

        bool found = storage.find(i -> first) != storage.end();
        curr = found ? storage.at(i -> first) : new DFANode(i -> first);
        
        if (i -> first == h) head = curr;

        storage.insert(std::map<char, DFANode*>::value_type(i -> first, curr));
        for (int k = 0; k < i -> second.length(); k++) {
            DFANode* n;

            bool childFound = storage.find(i -> second[k]) != storage.end();
            n = childFound ? storage.at(i -> second[k]) : new DFANode(i -> second[k]);
            curr -> children -> push_back(*n);
        }
    }

    for (auto i = storage.begin(); i != storage.end(); i++) {
        DFANode* val = i -> second;
        if (val -> children -> empty()) val -> endpoint = true;
    }

    DFANode* dfa = new DFANode(' ');
    dfa -> children -> push_back(*head);

    return dfa;
}

bool acceptDFAInput(DFANode* tree, std::string input) {
    if (input.length() == 0) return true;
    DFANode* head = tree;

    while (input.length() > 0) {
        std::vector<DFANode>* children = head -> children;
        bool found = false;

        for (int i = 0; i < children -> size(); i++) {
            std::cout << children -> at(i).c << std::endl;
            if (children -> at(i).c == input[0]) {
                input = input.substr(1, input.length() - 1);
                head = &children -> at(i);

                found = true;
                break;
            }
        }

        if (!found) return false;
    }

    return false;
}

int main() {
    std::map<char, std::string> graph;
    graph['a'] = "bcd";
    graph['c'] = "gh";
    graph['d'] = "efa";

    DFANode* n = constructDFA(graph, 'a');
    bool testOne = acceptDFAInput(n, "ach");
    bool testTwo = acceptDFAInput(n, "ace");

    std::cout << testOne << " : " << testTwo << std::endl;
}