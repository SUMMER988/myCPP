#include <iostream>
#include <string>

using namespace std;

int main() {
    string originalString = "c65c61a6-552a-e116-adf5-6a1bf23bf531";
    string AAString = "ddc029ec77bbbb306dc71a343949efcc";
    cout << "原字符串长度为：" << originalString.length() << endl;
    cout << AAString << " 长度为：" << originalString.length() << endl;
    string replacementString;
    string resultString;

    // 获取用户输入的替换字符串
    cout << "请输入替换字符串：";
    getline(cin, replacementString);
    cout << "输入字符串长度为：" << replacementString.length() << endl;

    size_t replacementIndex = 0;
    for (char c : originalString) {
        if (isalnum(c)) {    // 如果是英文字符或数字字符
            if (c != '-') {  // 如果不是连字符
                resultString += replacementString[replacementIndex %
                                                  replacementString.length()];
                replacementIndex++;
            } else {
                resultString += c;  // 连字符直接保留
            }
        } else {
            resultString += c;  // 其他字符直接保留
        }
    }

    cout << "替换后的字符串为：" << resultString << endl;
    cout << "字符串长度为：" << resultString.length() << endl;

    return 0;
}
