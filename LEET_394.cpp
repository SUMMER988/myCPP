#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 成员变量使用 private 访问权限
    string src;
    size_t ptr;

    // 函数参数添加 const 修饰
    int getDigits() {
        int ret = 0;
        while (ptr < src.size()) {
            if (!isdigit(src[ptr])) {
                // 如果当前字符不是数字字符，退出循环
                break;
            }
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    //"3[a2[c]]"

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS (empty string)
            return "";
        }

        char cur = src[ptr];
        int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // Parse Digits
            repTime = getDigits();
            // Filter left bracket
            ++ptr;
            // Parse String inside the brackets
            string str = getString();
            // Filter right bracket
            ++ptr;
            // Construct the final string by repeating the parsed string
            while (repTime--) ret += str;
        } else if (isalpha(cur)) {
            // String -> Char String
            // Parse Char
            ret = string(1, src[ptr++]);
        }

        return ret + getString();
    }

    // 函数参数使用 const 引用，避免不必要的拷贝
    string decodeString(const string& s) {
        src = s;
        ptr = 0;
        return getString();
    }
};

int main() {
    Solution solution;
    // 测试输入字符串
    string input = "3[da2[c]]";
    string decodedString = solution.decodeString(input);
    cout << "Decoded string: " << decodedString << endl;
    return 0;
}
