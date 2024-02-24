#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// 函数用于将文件中的 XXXXX 字符串按序替换为数字字符串
void replace_yyyyy(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行读取" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inputFile)),
                   (istreambuf_iterator<char>()));
    inputFile.close();

    int replace_number = 10000;
    size_t found = content.find("XXXXX");
    while (found != string::npos) {
        stringstream replacement_stream;
        replacement_stream << replace_number;
        string replacement = replacement_stream.str();
        content.replace(found, 5, replacement);

        found = content.find("XXXXX", found + replacement.size());
        ++replace_number;
    }

    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行写入" << endl;
        return;
    }

    outputFile << content;
    outputFile.close();
    cout << "成功替换 XXXXX 为数字字符串并写入文件 " << filename << " 中"
         << endl;
}

int main() {
    string filename = "D:\\Downloads\\0221_FILE.txt";

    replace_yyyyy(filename);

    return 0;
}
