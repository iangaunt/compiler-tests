#ifndef NODE_H
#define NODE_H

#include <vector>

using std::vector;

class Node {
    public: 
        char c;
        vector<Node>* children;
        bool endpoint;

        Node(char ch);
};

#endif 