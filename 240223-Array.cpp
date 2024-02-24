#include <fstream>
#include <iostream>
#include <vector>

class Node {
   public:
    int data;
    Node(int d) : data(d) {}
};

void storeToFile(const std::vector<Node>& nodes, const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& node : nodes) {
        outfile << node.data << std::endl;
    }

    outfile.close();
}

int main() {
    std::vector<Node> nodes;
    nodes.push_back(Node(1));
    nodes.push_back(Node(2));
    nodes.push_back(Node(3));

    storeToFile(nodes, "0224_Array.txt");

    return 0;
}
