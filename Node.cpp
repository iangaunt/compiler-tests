#include "Node.h"

#include <vector>

using std::vector;

Node::Node(char ch) {
    c = ch;
    children = new vector<Node>();
}