#pragma once
#include<vector>
#include<map>

using namespace std;
class day1094
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int sum = 0;
        map<int, int> station;
        for (int i = 0; i < trips.size(); i++) {
            station[trips[i][1]] = station[trips[i][1]] + trips[i][0];
            station[trips[i][2]] = station[trips[i][2]] - trips[i][0];
        }
        for (const auto& pair : station) {
            sum = sum + pair.second;
            if (sum > capacity) {
                return false;
            }
        }
        return true;
    }
};

