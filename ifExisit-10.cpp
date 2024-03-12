#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Function to modify the server line
void modifyServerLine(string& line) {
    size_t server_found = line.find("server: ");
    if (server_found != string::npos) {
        size_t url_start = server_found + 8;  // Position after "server: "
        size_t url_end =
            line.find(" ", url_start);  // Find the next space after the website
        if (url_end != string::npos) {
            line.replace(url_start, url_end - url_start,
                         "XXX.XXX.XXX.XXX");  // Replace the website URL
        } else {
            line.replace(url_start, line.length() - url_start,
                         "XXX.XXX.XXX.XXX");
        }
    }
}

// Function to modify the password line
void modifyPasswordLine(string& line) {
    size_t password_found = line.find("password: ");
    if (password_found != string::npos) {
        size_t password_start =
            password_found + 10;  // Position after "password: "
        size_t password_end = line.find(
            " ", password_start);  // Find the next space after the password
        if (password_end != string::npos) {
            line.replace(password_start, password_end - password_start,
                         "XXXXYYYY-XXXX-YYYY-XXXXYYYYZZZZ");
        } else {
            line.replace(password_start, line.length() - password_start,
                         "XXXXYYYY-XXXX-YYYY-XXXXYYYYZZZZ");
        }
    }
}

// Function to modify the port line
void modifyPortLine(string& line) {
    size_t port_found = line.find("port: ");
    if (port_found != string::npos) {
        size_t port_start = port_found + 6;  // Position after "port: "
        size_t port_end =
            line.find(" ", port_start);  // Find the next space after the port
        if (port_end != string::npos) {
            line.replace(port_start, port_end - port_start, "XXXX");
        } else {
            line.replace(port_start, line.length() - port_start, "XXXX");
        }
    }
}

int main() {
    string inputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\shouhou.txt";  // Input
                                                                    // file path
    string outputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\modified_shouhou.txt";  // Output file path
    string line;
    ifstream inFile(inputFilename);

    if (!inFile) {
        cerr << "Unable to open file " << inputFilename << endl;
        return 1;
    }

    ofstream outFile(outputFilename);  // Output file
    if (!outFile) {
        cerr << "Unable to create output file." << endl;
        inFile.close();
        return 1;
    }

    // Iterate through each line in the input file
    while (getline(inFile, line)) {
        // Modify line based on "server:", "password:", and "port:"
        modifyServerLine(line);
        modifyPasswordLine(line);
        modifyPortLine(line);

        // Write the modified line to the output file
        outFile << line << endl;
    }

    // Close files
    inFile.close();
    outFile.close();

    cout << "Modification complete. Please check " << outputFilename << "."
         << endl;
    return 0;
}
