#pragma once

#include <string>
#include <vector>

namespace ariel
{
    class Node
    {
    public:
        std::string node_data;
        std::vector<Node *> childern;

        Node(const std::string &data) { this->node_data = data; }
        ~Node() {}
    };
}