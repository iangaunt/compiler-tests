#include <NFA.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

NFA::NFA(map<char, string>& graph, char h) {
    Node* n = NFA::constructDFA(graph, h);
    dfa = n;
}

Node* NFA::constructDFA(map<char, string>& graph, char h) {
    map<char, Node*> storage;
    Node* head;

    for (auto i = graph.begin(); i != graph.end(); i++) {
        Node* curr;

        bool found = storage.find(i -> first) != storage.end();
        curr = found ? storage.at(i -> first) : new Node(i -> first);
        
        if (i -> first == h) head = curr;

        storage.insert(map<char, Node*>::value_type(i -> first, curr));
        for (int k = 0; k < i -> second.length(); k++) {
            Node* n;

            bool childFound = storage.find(i -> second[k]) != storage.end();
            n = childFound ? storage.at(i -> second[k]) : new Node(i -> second[k]);
            curr -> children -> push_back(*n);
        }
    }

    for (auto i = storage.begin(); i != storage.end(); i++) {
        Node* val = i -> second;
        if (val -> children -> empty()) val -> endpoint = true;
    }

    Node* dfa = new Node(' ');
    dfa -> children -> push_back(*head);

    return dfa;
}

bool NFA::acceptDFAInput(string input) {
    if (input.length() == 0) return true;
    Node* head = dfa;

    while (input.length() > 0) {
        vector<Node>* children = head -> children;
        bool found = false;

        for (int i = 0; i < children -> size(); i++) {
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