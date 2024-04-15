#include "DFANode.h"

DFANode::DFANode(char ch) {
    c = ch;
    children = new std::vector<DFANode>();
}