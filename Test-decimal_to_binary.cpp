#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 函数用于检查二进制字符串长度是否等于给定数值，如果不是，则在高位补零
string pad_binary_string(const string& binary_str, int desired_length) {
    if (binary_str.length() == desired_length) {
        return binary_str;
    } else if (binary_str.length() < desired_length) {
        int pad_length = desired_length - binary_str.length();
        return string(pad_length, '0') + binary_str;
    } else {
        cerr << "二进制字符串长度超出给定数值" << endl;
        return "";
    }
}

// 函数用于将字符串保存到文件
bool save_to_file(const string& filename, const string& content) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
        cout << "结果已保存到文件 " << filename << endl;
        return true;
    } else {
        cerr << "无法打开文件 " << filename << " 进行写入" << endl;
        return false;
    }
}

// 主函数
int main() {
    string binary_str;
    int desired_length;

    cout << "请输入二进制字符串: ";
    cin >> binary_str;
    cout << "请输入要求的字符串长度: ";
    cin >> desired_length;

    string padded_binary_str = pad_binary_string(binary_str, desired_length);
    if (!padded_binary_str.empty()) {
        cout << "补零后的二进制字符串为: " << padded_binary_str << endl;
        cout << "字符串长度为: " << padded_binary_str.length() << endl;

        // 将结果保存到文件
        if (!save_to_file("0219_numString.txt", padded_binary_str)) {
            return 1;  // 文件保存失败，返回错误码
        }
    }

    return 0;
}
