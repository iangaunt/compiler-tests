#ifndef DFANODE_H
#define DFANODE_H

#include <vector>

class DFANode {
    public: 
        bool endpoint;
        char c;
        std::vector<DFANode>* children;

        DFANode(char ch, bool end);
};

#endif 