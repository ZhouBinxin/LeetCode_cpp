#pragma once
#include <string>
#include <iostream>
using namespace std;

class day5
{
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        int maxlen = 1;
        int start = 0;

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int currLen = j - i + 1;
                if (currLen > maxlen && isPalindrome(s, i, j)) {
                    maxlen = currLen;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
