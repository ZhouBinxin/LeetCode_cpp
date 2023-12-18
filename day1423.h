#pragma once
#include<vector>
using namespace std;
class day1423
{
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max, temp = 0;
        int len = cardPoints.size() - 1;
        for (int i = 0; i < k; i++) {
            temp = temp + cardPoints[i];
        }
        max = temp;
        for (int i = 0; i < k; i++) {
            temp = temp + cardPoints[len - i] - cardPoints[k - i - 1];
            if (temp > max) {
                max = temp;
            }
        }
        return max;
    }
};

