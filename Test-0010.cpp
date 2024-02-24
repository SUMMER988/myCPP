#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

uint64_t hexStringToDecimal(const string& hexString) {
    unordered_map<char, int> hexToDecimalMap = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},  {'4', 4},  {'5', 5}, {'6', 6},
        {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}};

    uint64_t decimalNumber = 0;

    // 逐位计算并累加
    for (char c : hexString) {
        decimalNumber *= 13;
        decimalNumber += hexToDecimalMap[c];
    }

    return decimalNumber;
}

int main() {
    string hexString;
    cout << "请输入一个十三进制数（以字符串形式表示）：";
    cin >> hexString;

    uint64_t decimalNumber = hexStringToDecimal(hexString);

    cout << "十三进制数 " << hexString << " 转换为十进制数为：" << decimalNumber
         << endl;

    return 0;
}
