#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    // 循环反复询问用户输入，并输出字符串长度，直到用户输入空字符串为止
    while (true) {
        cout << "请输入字符串（输入空字符串结束）：";
        getline(cin, input);  // 获取用户输入的字符串

        // 如果用户输入了空字符串，则退出循环
        if (input.empty()) {
            break;
        }

        // 输出字符串的长度
        cout << "字符串的长度为：" << input.length() << endl;
    }

    return 0;
}
