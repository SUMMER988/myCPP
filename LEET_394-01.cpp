#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string src;
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size()) {
            if (!isdigit(src[ptr])) {
                break;
            }
            ret = ret * 10 + src[ptr] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            return "";
        }

        char cur = src[ptr];
        int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            repTime = getDigits();
            ++ptr;
            string str = getString();
            ++ptr;
            while (repTime--) {
                ret += str;
            }
        } else if (isalpha(cur)) {
            ret = string(1, src[ptr++]);
        }
    }
}
