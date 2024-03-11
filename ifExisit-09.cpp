#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\shouhou-0311.txt";  // Input
                                                                         // file
                                                                         // path
    string
        outputFilename =
            "C:\\Users\\admin\\.config\\clash\\profiles\\modified_shouhou-0311."
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
                // Replace the website with 'XXX.XXX.XXX.XXX'
                line.replace(url_start, url_end - url_start,
                             "XXX.XXX.XXX.XXX");  // Replace the website URL
            } else {
                // If URL extends to the end of the line
                line.replace(url_start, line.length() - url_start,
                             "XXX.XXX.XXX.XXX");
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
                // Replace the password with 'XXXXYYYY-XXXX-YYYY-XXXXYYYYZZZZ'
                line.replace(password_start, password_end - password_start,
                             "XXXXYYYY-XXXX-YYYY-XXXXYYYYZZZZ");
            } else {
                // If password extends to the end of the line
                line.replace(password_start, line.length() - password_start,
                             "XXXXYYYY-XXXX-YYYY-XXXXYYYYZZZZ");
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
