#include <string>
using namespace std;
class day3 {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int start = 0; // �������ڵ���ʼλ��
        vector<int> char_index(256, -1); // ���ڴ洢�ַ�������

        for (int end = 0; end<s.length(); end++) {
            if (char_index[s[end]] >= start) {
                // ����ַ�s[end]�ڴ������Ѿ����ڣ����´��ڵ���ʼλ��
                start = char_index[s[end]] + 1;
            }
            char_index[s[end]] = end; // �����ַ�s[end]������
            int current_length = end - start + 1; // ��ǰ�Ӵ��ĳ���
            if (current_length > max_length) {
                max_length = current_length;
            }
        }

        return max_length;
    }
};