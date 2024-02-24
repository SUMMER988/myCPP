#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstString, secondString, thirdString, fourthString;
    cout << "请输入第一个字符串：";
    getline(cin, firstString);  // 获取第一个字符串
    cout << "请输入第二个字符串：";
    getline(cin, secondString);  // 获取第二个字符串
    cout << "请输入第三个字符串：";
    getline(cin, thirdString);  // 获取第三个字符串
    cout << "请输入第四个字符串：";
    getline(cin, fourthString);  // 获取第四个字符串

    // 将四个字符串以"-"拼凑成一个字符串
    string concatenatedString = firstString + "-" + secondString + "-" +
                                thirdString + "-" + fourthString;

    // 打印输出拼凑后的字符串
    cout << "拼凑后的字符串为：" << concatenatedString << endl;

    return 0;
}
