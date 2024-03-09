std::pair<std::vector<std::string>, std::vector<std::string>>
fileContainsSubstrings(const std::string& filename,
                       const std::set<std::string>& substrings) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> foundSubstrings;
    std::vector<std::string> notFoundSubstrings;

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return std::make_pair(foundSubstrings, notFoundSubstrings);
    }