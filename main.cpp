// main.cpp
#include <iostream>
#include <vector>
#include "day2477.h"
using namespace std;

int main() {
    day2477 demo;
    vector<vector<int>> roads = { {1,0},{0,2},{3,1},{1,4},{5,0} };
    int seats = 1;
    long long result = demo.minimumFuelCost(roads, seats);
    cout << result << endl;
}

