#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

OrgChart::OrgChart() {}

OrgChart::~OrgChart() {}

OrgChart &OrgChart::add_root(const string &node_data) { return *this; }

OrgChart &OrgChart::add_sub(const string &node_boss, const string &node_worker) { return *this; }

Iterator OrgChart::begin_level_order() { return Iterator(NULL, ""); }

Iterator OrgChart::end_level_order() { return Iterator(NULL, ""); }

Iterator OrgChart::begin_reverse_order() { return Iterator(NULL, ""); }

Iterator OrgChart::end_reverse_order() { return Iterator(NULL, ""); }

Iterator OrgChart::begin_preorder() { return Iterator(NULL, ""); }

Iterator OrgChart::end_preorder() { return Iterator(NULL, ""); }

Iterator OrgChart::reverse_order() { return Iterator(NULL, ""); }

Iterator OrgChart::begin() { return Iterator(NULL, ""); }

Iterator OrgChart::end() { return Iterator(NULL, ""); }

ostream &ariel::operator<<(ostream &org_output, const OrgChart &org) { return org_output; }