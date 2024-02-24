
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool replaceUpperCaseWithLowerCase(string& inputString) {
    bool changed = false;
    for (char& c : inputString) {
        if (isupper(c)) {
            c = tolower(c);
            changed = true;
        }
    }
    return changed;
}

void saveToFile(const string& filename, const string& content) {
    ofstream outFile(filename, ios::out);
    if (outFile.is_open()) {
        outFile << content;
        cout << "结果已保存到 " << filename << endl;
        outFile.close();
    } else {
        cerr << "无法打开文件 " << filename << " 进行写入操作。" << endl;
    }
}

int main() {
    while (true) {
        string inputString;
        cout << "请输入一个字符串（输入空字符串结束程序）：";
        getline(cin, inputString);

        // 如果输入为空字符串，则结束循环
        if (inputString.empty()) {
            break;
        }

        if (replaceUpperCaseWithLowerCase(inputString)) {
            saveToFile("0219_Replace.txt", inputString);
        } else {
            cout << "字符串中没有大写字母被替换。" << endl;
        }

        // 打印输入的字符串
        cout << "经处理的字符串为：" << inputString << endl;

        // 打印字符串的长度
        cout << "字符串的长度为：" << inputString.length() << endl;
    }

    cout << "程序结束。" << endl;

    return 0;
}
