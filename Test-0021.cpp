#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, char> morseCodeToChar = {
    {".-", 'A'},    {"-...", 'B'},  {"-.-.", 'C'},  {"-..", 'D'},
    {".", 'E'},     {"..-.", 'F'},  {"--.", 'G'},   {"....", 'H'},
    {"..", 'I'},    {".---", 'J'},  {"-.-", 'K'},   {".-..", 'L'},
    {"--", 'M'},    {"-.", 'N'},    {"---", 'O'},   {".--.", 'P'},
    {"--.-", 'Q'},  {".-.", 'R'},   {"...", 'S'},   {"-", 'T'},
    {"..-", 'U'},   {"...-", 'V'},  {".--", 'W'},   {"-..-", 'X'},
    {"-.--", 'Y'},  {"--..", 'Z'},  {".----", '1'}, {"..---", '2'},
    {"...--", '3'}, {"....-", '4'}, {".....", '5'}, {"-....", '6'},
    {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {"-----", '0'}};

unordered_map<char, string> charToMorseCode;

// 初始化将字符映射到莫斯电码的哈希表
void initializeCharToMorseCode() {
    charToMorseCode.clear();  // 清空之前的映射
    for (const auto& entry : morseCodeToChar) {
        charToMorseCode[entry.second] = entry.first;
    }
}

string decodeMorse(const string& morseCode) {
    string decodedString;
    string morseChar;
    for (char c : morseCode) {
        if (c == ' ' && !morseChar.empty()) {
            // 如果遇到空格，表示一个字符的结束，进行解码
            if (morseCodeToChar.find(morseChar) != morseCodeToChar.end()) {
                decodedString += morseCodeToChar[morseChar];
                morseChar.clear();
            }
        } else if (c != ' ') {
            // 如果是莫斯电码字符，加入当前莫斯字符中
            morseChar += c;
        }
    }
    // 解码最后一个字符
    if (!morseChar.empty() &&
        morseCodeToChar.find(morseChar) != morseCodeToChar.end()) {
        decodedString += morseCodeToChar[morseChar];
    }
    return decodedString;
}

string convertToLowerCase(const string& str) {
    string result = str;
    for (char& c : result) {
        if (isupper(c)) {
            c = tolower(c);  // 将大写字母转换为小写字母
        }
    }
    return result;
}

void replaceChars(string& str, char oldChar, char newChar) {
    for (char& c : str) {
        if (c == oldChar) {
            c = newChar;
        }
    }
}

void writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件 \"" << filename << "\"！" << endl;
        return;
    }
    file << content;
    file.close();
    cout << "内容已保存到文件 \"" << filename << "\" 中。" << endl;
}

string printSubstrings(const string& mainString, const string& lengthString) {
    string modifiedString = mainString;
    replaceChars(modifiedString, '0', '.');
    replaceChars(modifiedString, '1', '-');

    string ConcatStr;  // 存储拼凑的字符串
    int lengthIndex = 0;
    bool isFirstSubstring = true;
    for (char c : lengthString) {
        if (isdigit(c)) {
            int length = c - '0';
            if (lengthIndex < modifiedString.length()) {
                string substring = modifiedString.substr(lengthIndex, length);
                writeFile("0219_PrintSSS.txt", substring + "\n");
                if (!isFirstSubstring) {
                    writeFile("0219_PrintSSS_Concatenation.txt", " ");
                } else {
                    isFirstSubstring = false;
                }
                writeFile("0219_PrintSSS_Concatenation.txt", substring);
                ConcatStr += substring + " ";  // 将子串添加到拼凑的字符串中
                lengthIndex += length;
            } else {
                break;
            }
        }
    }

    cout << "子串已经打印到文件 \"0219_PrintSSS.txt\" 中。" << endl;
    cout << "拼凑结果已经保存到文件 \"0219_PrintSSS_Concatenation.txt\" 中。"
         << endl;

    return ConcatStr;  // 返回拼凑的字符串
}

void saveToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "内容已保存到文件 \"" << filename << "\" 中。" << endl;
    } else {
        cout << "无法打开文件 \"" << filename << "\"！" << endl;
    }
}
void appToFile(const string& filename, const string& content) {
    ofstream file(filename, ios::app);  // 打开文件时使用附加模式
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "内容已追加到文件 \"" << filename << "\" 中。" << endl;
    } else {
        cout << "无法打开文件 \"" << filename << "\"！" << endl;
    }
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

int main() {
    string mainString, lengthString;

    cout << "请输入一个字符串：";
    getline(cin, mainString);

    cout << "请输入另一个字符串，用来确定子串长度：";
    getline(cin, lengthString);

    string ConcatStr =
        printSubstrings(mainString, lengthString);  // 接收拼凑的字符串
    cout << "拼凑后的字符串为：" << ConcatStr << endl;

    string decodedString = decodeMorse(ConcatStr);
    cout << "解码后的字符串为：" << decodedString << endl;

    saveToFile("0219_decodedString.txt", decodedString + "\n");

    string convertedToLowerCase = decodedString;
    // string convertedToLowerCase = "416DAE246836491F9F935E8A43CD45E7";
    convertedToLowerCase = convertToLowerCase(convertedToLowerCase);
    cout << "字符串大写字母转换处理结果为：" << convertedToLowerCase << endl;

    appToFile("0219_decodedString.txt", convertedToLowerCase + "\n");

    string originalString = "ABCDABCD-ABCD-ABCD-ABCD-ABCDABCDABCD";
    cout << "邀请码长度为：" << originalString.length() << endl;

    string resultString =
        replaceWithReplacementString(originalString, convertedToLowerCase);

    cout << "替换后的字符串为：" << resultString << endl;
    cout << "邀请码长度为：" << resultString.length() << endl;

    return 0;
}
