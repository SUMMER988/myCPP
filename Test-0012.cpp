#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

    cout << inputString.length() << endl;
}

int main() {
    string inputString;
    cout << "请输入一个字符串：";
    cin >> inputString;

    printStringInGroupsAndToFile(inputString, 4, "0219_PrintNum.txt");

    return 0;
}
