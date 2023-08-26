#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

typedef struct {
    char *ch;
    int length;
} Str;

void getnext(Str substr, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < substr.length) {
        if (j == 0 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void getnextval(Str substr, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < substr.length) {
        if (j == 0 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            if (substr.ch[i] != substr.ch[j]) {
                nextval[i] = j;
            } else {
                j = nextval[j];
            }
        }
    }
}

int KMP(Str str, Str substr, int next[]) {
    int i = 1, j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        }

        else {
            j = next[j];
        }
    }
    if (j > substr.length) {
        return i - substr.length;
    } else {
        return 0;
    }
}

int main() {
    cout << "---" << endl;

    return 0;
}
