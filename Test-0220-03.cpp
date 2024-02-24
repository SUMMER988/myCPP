#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 函数用于统计文件中字符串的出现次数
int count_occurrences(const string& filename, const string& target) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行读取" << endl;
        return -1;  // 返回 -1 表示读取失败
    }

    int count = 0;
    string line;
    while (getline(inputFile, line)) {
        size_t found = line.find(target);
        while (found != string::npos) {
            ++count;
            found = line.find(target, found + target.size());
        }
    }

    inputFile.close();
    return count;
}

int main() {
    string filename = "D:\\Downloads\\0221_FILE.txt";
    string target = "XXXXX";

    int occurrences = count_occurrences(filename, target);
    if (occurrences >= 0) {
        cout << "文件中字符串 " << target << " 出现了 " << occurrences << " 次"
             << endl;
    }

    return 0;
}
