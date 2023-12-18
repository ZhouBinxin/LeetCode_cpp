#pragma once
#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;
class day4
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len = nums1.size() + nums2.size();
        vector<int> nums(len);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),nums.begin());
        if (len % 2) {
            result = nums[len / 2];
        }
        else {
            result = (nums[len / 2 - 1] + nums[len / 2]) / 2.0;
        }
        return result;
    }
};

