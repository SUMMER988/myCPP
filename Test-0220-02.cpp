#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>

using namespace std;

// 生成不重复的四个字符的字符串
string generate_unique_string(set<string>& used_strings) {
    static const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, charset.size() - 1);

    string new_string;
    do {
        new_string.clear();
        for (int i = 0; i < 4; ++i) {
            new_string += charset[dis(gen)];
        }
    } while (used_strings.find(new_string) != used_strings.end());

    used_strings.insert(new_string);
    return new_string;
}

// 替换字符串并返回替换次数
int replace_string_in_file(const string& filename, const string& target,
                           set<string>& used_strings) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行读取" << endl;
        return 0;
    }

    string content((istreambuf_iterator<char>(inputFile)),
                   (istreambuf_iterator<char>()));
    inputFile.close();

    size_t found = content.find(target);
    int replace_count = 0;
    while (found != string::npos) {
        string replacement = generate_unique_string(used_strings);
        content.replace(found, target.size(), replacement);
        ++replace_count;
        found = content.find(target, found + replacement.size());
    }

    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行写入" << endl;
        return 0;
    }

    outputFile << content;
    outputFile.close();
    return replace_count;
}

int main() {
    string filename = "D:\\Downloads\\0221_FILE.txt";
    string target = "IPLC";
    set<string> used_strings;

    int replace_count = replace_string_in_file(filename, target, used_strings);
    if (replace_count > 0) {
        cout << "成功替换 " << target << " 字符串为不重复的字符串并写入文件 "
             << filename << " 中" << endl;
    } else {
        cout << "文件中没有找到 " << target << " 字符串" << endl;
    }

    return 0;
}
