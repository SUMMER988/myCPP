#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::ifstream inputFile("D:\\Downloads\\0218_IN.txt");
    std::ofstream outputFile("D:\\Downloads\\0218_OUT.txt");
    std::string line;

    // 创建一个映射，将要替换的旧字符串映射到新字符串
    std::map<std::string, std::string> replacements = {
        {"🇭🇰 ", ""},
        {"🇸🇬 ", ""},
        {"🇯🇵 ", ""},
        {"🇨🇳 ", ""},
        {"🇺🇸 ", ""},
        {"🇰🇷 ", ""},
        {"专线", "云云"},
        {"专线", "云云"},
        {"0.20X", "00"},
        // 添加更多的替换对
    };

    if (inputFile.is_open() && outputFile.is_open()) {
        while (getline(inputFile, line)) {
            // 逐一查找和替换每个字符串
            for (const auto& replacement : replacements) {
                size_t pos = line.find(replacement.first);
                while (pos != std::string::npos) {
                    line.replace(pos, replacement.first.length(),
                                 replacement.second);
                    pos = line.find(replacement.first,
                                    pos + replacement.second.length());
                }
            }

            outputFile << line << std::endl;
        }

        std::cout << "替换完成" << std::endl;

        inputFile.close();
        outputFile.close();
    } else {
        std::cerr << "无法打开文件" << std::endl;
    }

    return 0;
}
