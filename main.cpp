#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Node.h"
#include "NFA.h"

int main() {
    std::map<char, std::string> graph;
    graph['a'] = "bcd";
    graph['c'] = "gh";
    graph['d'] = "efa";

    NFA* n = new NFA(graph, 'a');

    bool testOne = n -> acceptDFAInput("ach");
    bool testTwo = n -> acceptDFAInput("ace");

    std::cout << testOne << " : " << testTwo << std::endl;
}