#include <fstream>
#include <iostream>
#include <vector>

// Class representing a node with an integer data field
class Node {
   public:
    int data;
    Node(int d) : data(d){};  // Constructor initializing the data field
};

// Function to store data from a vector of nodes into a file
void storeToFile(const std::vector<Node>& nodes, const std::string& filename) {
    std::ofstream outfile(filename,
                          std::ios::app);  // Open the file in append mode
    if (!outfile.is_open()) {
        std::cerr << "Error opening file: " << filename
                  << std::endl;  // Output error message if file opening fails
        return;
    }

    // Iterate over each node in the vector
    for (const auto& node : nodes) {
        outfile << node.data
                << std::endl;  // Write the data of each node to the file
    }

    outfile.close();  // Close the file
}

int main() {
    std::vector<Node> nodes;
    nodes.push_back(Node(1));  // Add a node with data 1 to the vector
    nodes.push_back(Node(2));  // Add a node with data 2 to the vector
    nodes.push_back(Node(3));  // Add a node with data 3 to the vector

    storeToFile(
        nodes,
        "0224_Array.txt");  // Call the function to store data in the file

    return 0;
}
