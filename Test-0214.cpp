#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B;
    A = "#358#365-##84-51##-8651-8#6##77##41#";
    // cout << "请输入字符串 A：";
    // getline(cin, A);
    cout << "请输入字符串 B：";
    getline(cin, B);

    size_t index = 0;
    while ((index = A.find("#", index)) != string::npos) {
        // 找到了 "#"，则替换为对应位置的 B 中的字符
        if (!B.empty()) {
            A.replace(index, 1, B.substr(0, 1));  // 用 B 中的字符替换 "#"
            B = B.substr(1);  // 将 B 中已使用的字符去除
        } else {
            // 如果 B 中的字符已经用完，则停止替换
            break;
        }
    }

    cout << "替换后的字符串 A 为：" << A << endl;

    return 0;
}
