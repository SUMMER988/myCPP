#include <iostream>
#include <string>

using namespace std;

string convertToLowerCase(const string& str) {
    string result = str;
    for (char& c : result) {
        if (isupper(c)) {
            c = tolower(c);  // 将大写字母转换为小写字母
        }
    }
    return result;
}

#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(const string& str) {
    int sum = 0;
    for (char c : str) {
        if (isdigit(c)) {
            sum += c - '0';  //
            // 如果是数字字符，将字符转换为对应的数字并累加到总和中
            // } else if (c == 'a' || c == 'A') {
            //     sum += 10;  // 如果是字符 'a'，则累加10
            // } else if (c == 'b' || c == 'B') {
            //     sum += 11;  // 如果是字符 'b'，则累加11
            // } else if (c == 'c' || c == 'C') {
            //     sum += 12;  // 如果是字符 'c'，则累加12
        }
    }
    return sum;
}

string replaceWithReplacementString(const string& originalString,
                                    const string& replacementString) {
    string resultString;
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

    return resultString;
}

string replaceHyphensWithZero(const string& originalString) {
    string resultString = originalString;
    for (char& c : resultString) {
        if (c == '-') {
            c = '0';  // 将连字符替换为 0
        }
    }
    return resultString;
}

int main() {
    string originalString = "ABCDABCD-ABCD-ABCD-ABCD-ABCDABCDABCD";
    string replacementString;
    string AAString = "416DAE246836491F9F935E8A43CD45E7";
    cout << "原字符串长度为：" << originalString.length() << endl;
    // cout << AAString << " 长度为：" << originalString.length() << endl;
    cout << AAString << endl;

    cout << "请输入替换字符串：";
    getline(cin, replacementString);
    cout << "输入的字符串长度为：" << replacementString.length() << endl;

    string convertedToLowerCase = replacementString;
    // string convertedToLowerCase = "416DAE246836491F9F935E8A43CD45E7";
    convertedToLowerCase = convertToLowerCase(convertedToLowerCase);
    cout << "字符串大写字母转换处理结果为：" << convertedToLowerCase << endl;

    string resultString =
        replaceWithReplacementString(originalString, convertedToLowerCase);

    cout << "替换后的字符串为：" << resultString << endl;
    cout << "字符串长度为：" << resultString.length() << endl;

    cout << "替换连字符后的字符串为：" << replaceHyphensWithZero(resultString)
         << endl;

    string NumStr = "210187957C0A61198A312633BAC766C71B55";
    //    55532155555555545455515255435515
    //        210187957C0A61198A312633BAC766C71B55
    cout << "数字字符串总和为：" << sumOfDigits(NumStr) << endl;

    return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <string>

// using namespace std;

// int charToValue(char c) {
//     if (isdigit(c)) {
//         return c - '0';  // 如果字符为数字，则返回对应的数字值
//     } else {
//         return c - 'a' +
//                10;  //
//                如果字符为小写字母，则返回对应的数值（a为10，b为11，c为12）
//     }
// }

// char valueToChar(int value) {
//     if (value < 10) {
//         return value + '0';  // 如果数值小于10，返回对应的字符
//     } else {
//         return value - 10 +
//                'a';  //
//                如果数值大于等于10，返回对应的小写字母（10为a，11为b，12为c）
//     }
// }

// string addThirteenBaseNumbers(const string& num1, const string& num2) {
//     string result;
//     int carry = 0;

//     // 从右向左遍历两个字符串，逐位相加
//     int i = num1.length() - 1, j = num2.length() - 1;
//     while (i >= 0 || j >= 0 || carry > 0) {
//         int sum = carry;
//         if (i >= 0) {
//             sum += charToValue(num1[i--]);
//         }
//         if (j >= 0) {
//             sum += charToValue(num2[j--]);
//         }
//         result +=
//             valueToChar(sum % 13);  // 取模 13
//             得到当前位的值，并转换为字符形式
//         carry = sum / 13;  // 更新进位
//     }

//     // 结果字符串是逆序的，需要反转
//     reverse(result.begin(), result.end());

//     return result;
// }

// int main() {
//     string num1, num2;

//     cout << "请输入第一个十三进制数：";
//     getline(cin, num1);

//     cout << "请输入第二个十三进制数：";
//     getline(cin, num2);

//     string result = addThirteenBaseNumbers(num1, num2);
//     cout << "两个十三进制数相加的结果为：" << result << endl;

//     return 0;
// }
