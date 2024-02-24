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

int main() {
    initializeCharToMorseCode();

    string morseCode;
    cout << "请输入一个莫斯电码字符串：";
    getline(cin, morseCode);

    string decodedString = decodeMorse(morseCode);
    cout << "解码后的字符串为：" << decodedString << endl;

    return 0;
}
