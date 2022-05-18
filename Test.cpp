#include "sources/OrgChart.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

TEST_CASE("Testing the basics of the code")
{
    OrgChart test_chart;

    // Building a tree
    test_chart.add_root("1");
    test_chart.add_sub("1", "2");
    test_chart.add_sub("1", "3");
    test_chart.add_sub("1", "4");
    test_chart.add_sub("2", "5");
    test_chart.add_sub("3", "6");
    test_chart.add_sub("4", "7");
    test_chart.add_sub("5", "8");
    test_chart.add_sub("6", "9");
    test_chart.add_sub("7", "10");

    /*
    Visualizing the tree :
          1
      /   |   \
    2-----3-----4
    |     |     |
    5-----6-----7
    |     |     |
    8-----9-----10
    */

    // Check begin_level_order
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(0)->node_data, "1");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(1)->node_data, "2");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(2)->node_data, "3");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(3)->node_data, "4");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(4)->node_data, "5");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(5)->node_data, "6");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(6)->node_data, "7");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(7)->node_data, "8");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(8)->node_data, "9");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(9)->node_data, "10");
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(0)->node_data, "10"); // Error

    // Check begin_reverse_order
    CHECK_EQ(test_chart.begin_reverse_order().get_nodes().at(0)->node_data, "10");
    CHECK_EQ(test_chart.begin_reverse_order().get_nodes().at(9)->node_data, "1");
    CHECK_EQ(test_chart.begin_reverse_order().get_nodes().at(0)->node_data, "1"); // Error

    // Check begin_preorder
    CHECK_EQ(test_chart.begin_preorder().get_nodes().at(0)->node_data, "1");
    CHECK_EQ(test_chart.begin_preorder().get_nodes().at(9)->node_data, "10");
    CHECK_EQ(test_chart.begin_preorder().get_nodes().at(5)->node_data, "420"); // Error

    // Check the size of nodes
    CHECK_EQ(test_chart.begin_level_order().get_nodes().size(), 10);
    CHECK_EQ(test_chart.begin_level_order().get_nodes().size(), 420);

    // Check the add_sub if there is no node to add or add to throw an error
    CHECK_THROWS(test_chart.add_sub("500", "1"));
    CHECK_NOTHROW(test_chart.add_sub("1", "400")); // Its ok that there will be 2 options
    CHECK_NOTHROW(test_chart.add_sub("1", "3"));   // Its ok that there will be 2 options

    // Check the add_root function
    CHECK_NOTHROW(test_chart.add_root("420"));                                  // You can overlapse the root
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(0)->node_data, "1"); // Error
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(0)->node_data, "420");
    CHECK_NOTHROW(test_chart.add_root("800"));
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(0)->node_data, "420"); // Error
    CHECK_EQ(test_chart.begin_level_order().get_nodes().at(0)->node_data, "800");
}