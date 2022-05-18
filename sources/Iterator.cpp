#include "Iterator.hpp"

using namespace std;
using namespace ariel;

Iterator::Iterator(Node *node_root, const string &method) {}

void Iterator::iter_begin_level_order(Node *node_root) {}

void Iterator::iter_begin_reverse_order(Node *node_root) {}

void Iterator::iter_begin_preorder(Node *node_root) {}

vector<Node *> Iterator::get_nodes() { return vector<Node *>(); }

string *Iterator::operator->()
{
    string *null_iterator = NULL;
    return null_iterator;
}

bool Iterator::operator!=(const Iterator &other_iterator) { return false; }

string Iterator::operator*() { return ""; }

Iterator &Iterator::operator++() { return *this; }