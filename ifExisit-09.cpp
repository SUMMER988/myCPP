#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\shouhou.txt";  // Input
                                                                    // file
                                                                    // path
    string outputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\modified_shouhou."
        "txt";  // Output file path
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

    // User input for replacements
    string serverReplacement, passwordReplacement, portReplacement;
    cout << "Enter replacement for 'server: ': ";
    getline(cin, serverReplacement);
    cout << "Enter replacement for 'password: ': ";
    getline(cin, passwordReplacement);
    cout << "Enter replacement for 'port: ': ";
    getline(cin, portReplacement);

    // Iterate through each line in the input file
    while (getline(inFile, line)) {
        // Find the position of 'server: '
        size_t server_found = line.find("server: ");
        if (server_found != string::npos) {
            // Find the start of the website URL
            size_t url_start = server_found + 8;  // Position after "server: "
            // Find the end of the website URL
            size_t url_end = line.find(
                " ", url_start);  // Find the next space after the website
            if (url_end != string::npos) {
                // Replace the website with the user-specified replacement
                line.replace(url_start, url_end - url_start,
                             serverReplacement);  // Replace the website URL
            } else {
                // If URL extends to the end of the line
                line.replace(url_start, line.length() - url_start,
                             serverReplacement);
            }
        }

        // Find the position of 'password: '
        size_t password_found = line.find("password: ");
        if (password_found != string::npos) {
            // Find the start of the password
            size_t password_start =
                password_found + 10;  // Position after "password: "
            // Find the end of the password
            size_t password_end = line.find(
                " ", password_start);  // Find the next space after the password
            if (password_end != string::npos) {
                // Replace the password with the user-specified replacement
                line.replace(password_start, password_end - password_start,
                             passwordReplacement);
            } else {
                // If password extends to the end of the line
                line.replace(password_start, line.length() - password_start,
                             passwordReplacement);
            }
        }

        // Find the position of 'port: '
        size_t port_found = line.find("port: ");
        if (port_found != string::npos) {
            // Find the start of the port
            size_t port_start = port_found + 6;  // Position after "port: "
            // Find the end of the port
            size_t port_end = line.find(
                " ", port_start);  // Find the next space after the port
            if (port_end != string::npos) {
                // Replace the port with the user-specified replacement
                line.replace(port_start, port_end - port_start,
                             portReplacement);
            } else {
                // If port extends to the end of the line
                line.replace(port_start, line.length() - port_start,
                             portReplacement);
            }
        }

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
