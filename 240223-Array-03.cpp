#include <fstream>
#include <iostream>
#include <vector>

class Node {
   public:
    int data;
    Node(int d) : data(d){};
};

void storeToFile(const std::vector<Node>& nodes, const std::string& filename) {
    std::fstream outfile(filename, std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    for (const auto& node : nodes) {
        outfile << node.data << std::endl;
    }
    outfile << "Success" << std::endl;

    std::cout << "saveToFile success! " << std::endl;

    outfile.close();
}

void overwriteFile(const std::vector<Node>& nodes,
                   const std::string& filename) {
    std::ofstream outfile(filename, std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& node : nodes) {
        outfile << node.data << std::endl;
    }

    outfile << "OVERWRITE" << std::endl;

    std::cout << "overwriteFile successs! " << std::endl;

    outfile.close();
}

int main() {
    std::vector<Node> nodes;
    nodes.push_back(Node(1));
    nodes.push_back(Node(2));
    nodes.push_back(Node(4));
    while (true) {
        storeToFile(nodes, "0224_Array.txt");
    }

    // overwriteFile(nodes, "0224_Array.txt");

    return 0;
}
