#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "请输入字符串：";
    getline(cin, input);  // 获取用户输入的字符串

    string processedString = "";  // 用于保存处理完的字符串

    // 遍历字符串，只保留小写英文字符和数字，并构建处理完的字符串
    for (char c : input) {
        if (isdigit(c)) {          // 如果是 数字
            processedString += c;  // 将字符添加到处理完的字符串中
        }
    }

    // 打印输出处理完的字符串
    cout << "处理完的字符串为：" << processedString << endl;

    // 打印输出处理完的字符串长度
    cout << "处理完的字符串长度为：" << processedString.length() << endl;

    return 0;
}
