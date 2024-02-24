#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 函数将输入的二进制字符串中的每个字符进行异或处理
string performXOR(const string& binaryString) {
    string result;
    for (char c : binaryString) {
        // 异或处理
        result += (c == '0') ? '1' : '0';
    }
    return result;
}

void printStringInGroupsAndToFile(const string& inputString, int groupSize,
                                  const string& fileName) {
    ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << "输入的字符串每" << groupSize << "位打印输出：" << endl;
        for (size_t i = 0; i < inputString.length(); ++i) {
            outputFile << inputString[i];
            if ((i + 1) % groupSize == 0) {
                outputFile << endl;
            }
        }
        outputFile.close();
        cout << "成功将打印结果保存在文件 " << fileName << " 中。" << endl;
    } else {
        cout << "无法打开文件 " << fileName << " 进行写入。" << endl;
    }
}

int main() {
    string inputString;
    cout << "请输入一个二进制字符串：";
    cin >> inputString;

    string resultString = performXOR(inputString);

    // 打印输出结果
    printStringInGroupsAndToFile(resultString, 4, "0219_NumOr.txt");

    return 0;
}
