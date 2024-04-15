#ifndef DFANODE_H
#define DFANODE_H

#include <vector>

class DFANode {
    public: 
        char c;
        std::vector<DFANode>* children;
        bool endpoint;

        DFANode(char ch);
};

#endif 