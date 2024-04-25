#ifndef NFA_H
#define NFA_H

#include "Node.h"

#include <map>
#include <string>

using std::map;
using std::string;

class NFA {
    public: 
        Node* dfa;

        NFA(map<char, string>& graph, char h);
        
        Node* constructDFA(map<char, string>& graph, char h);
        bool acceptDFAInput(string input);
};

#endif