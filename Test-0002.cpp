#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 函数将十进制数转换为四位二进制数
string decimalToBinary(int decimal) {
    string binary;
    for (int i = 0; i < 4; ++i) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

int main() {
    // 十三进制数对应的十进制数
    unordered_map<char, int> hexToDecimal = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},  {'4', 4},  {'5', 5}, {'6', 6},
        {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}};

    string hexString;
    cout << "请输入十三进制数：";
    cin >> hexString;

    string binaryString;
    // 将十三进制数的每一位转换为四位二进制数
    for (char c : hexString) {
        binaryString += decimalToBinary(hexToDecimal[c]);
    }

    // 打印输出二进制数
    cout << "十三进制数 " << hexString << " 转换为二进制数为：" << binaryString
         << endl;
    cout << "该二进制数长度为 " << binaryString.length() << endl;
    // 将二进制数写入文件
    ofstream outputFile("0219_Num.txt");
    if (outputFile.is_open()) {
        outputFile << binaryString;
        outputFile.close();
        cout << "成功将二进制数保存在文件 0219_Num.txt 中。" << endl;
    } else {
        cout << "无法打开文件 0219_Num.txt 进行写入。" << endl;
    }

    return 0;
}
