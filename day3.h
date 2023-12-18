#include <string>
using namespace std;
class day3 {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int start = 0; // 滑动窗口的起始位置
        vector<int> char_index(256, -1); // 用于存储字符的索引

        for (int end = 0; end<s.length(); end++) {
            if (char_index[s[end]] >= start) {
                // 如果字符s[end]在窗口内已经存在，更新窗口的起始位置
                start = char_index[s[end]] + 1;
            }
            char_index[s[end]] = end; // 更新字符s[end]的索引
            int current_length = end - start + 1; // 当前子串的长度
            if (current_length > max_length) {
                max_length = current_length;
            }
        }

        return max_length;
    }
};