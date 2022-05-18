#include "Node.hpp"
#include "Iterator.hpp"

namespace ariel
{
    class OrgChart
    {
    public:
        Node *root;
        OrgChart();
        ~OrgChart();
        OrgChart &add_root(const std::string &node_data);
        OrgChart &add_sub(const std::string &node_boss, const std::string &node_worker);

        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator end_reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        Iterator reverse_order(); // Probably meaning end_reverse_order
        Iterator begin();
        Iterator end();

        friend std::ostream &operator<<(std::ostream &org_output, const OrgChart &org_chart);
    };
}