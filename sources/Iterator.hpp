#include "Node.hpp"

namespace ariel
{
    class Iterator
    {
        Node *root;
        std::vector<Node *> list_of_nodes;

    public:
        Iterator(Node *node_root, const std::string &method);

        void iter_begin_level_order(Node *node_root);
        void iter_begin_reverse_order(Node *node_root);
        void iter_begin_preorder(Node *node_root);

        std::vector<Node *> get_nodes();

        std::string *operator->();
        bool operator!=(const Iterator &other_iterator);
        std::string operator*();
        Iterator &operator++();
    };
}