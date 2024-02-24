#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 函数用于读取文件内容并复制粘贴多次追加到同一文件中
void copy_append_file(const string& filename, int num_copies) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行读取" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inputFile)),
                   (istreambuf_iterator<char>()));
    inputFile.close();

    ofstream outputFile(filename, ios::app);  // 追加写入模式打开文件
    if (!outputFile.is_open()) {
        cerr << "无法打开文件 " << filename << " 进行追加写入" << endl;
        return;
    }

    for (int i = 0; i < num_copies; ++i) {
        outputFile << content;
    }

    outputFile.close();
    cout << "文件内容已成功复制粘贴 " << num_copies << " 次追加到文件 "
         << filename << " 中" << endl;
}

int main() {
    string filename = "D:\\Downloads\\0221_FILE.txt";  // 修改为绝对路径
    int num_copies = 9999;

    copy_append_file(filename, num_copies);

    return 0;
}
