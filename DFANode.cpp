#include "DFANode.h"

DFANode::DFANode(char ch, bool end) {
    c = ch;
    endpoint = end;

    children = new std::vector<DFANode>();
}