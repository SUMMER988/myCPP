#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// 函数用于统计文件中指定字符串出现的次数
int count_occurrences(const string& filename, const string& target) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行读取" << endl;
        return -1;  // 返回 -1 表示读取失败
    }

    int count = 0;
    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find(target);
        while (pos != string::npos) {
            ++count;
            pos = line.find(target, pos + target.length());
        }
    }

    inputFile.close();
    return count;
}

int main() {
    string filename = "D:\\Downloads\\0221_FILE.txt";  // 指定文件名
    string target = "香港";                            // 要统计的字符串

    int occurrences = count_occurrences(filename, target);
    if (occurrences >= 0) {
        cout << "文件中字符串 \"" << target << "\" 出现了 " << occurrences
             << " 次" << endl;
    }

    return 0;
}
