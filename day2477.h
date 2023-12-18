#include <iostream>
#include <vector>
using namespace std;

class day2477 {
private:
    int dfs(int cur, int fa, vector<vector<int>>& g, int seats, long long& res) {
        int peopleSum = 1;
        for (auto ne : g[cur]) {
            if (ne != fa) {
                int peopleCnt = dfs(ne, cur, g, seats, res);
                peopleSum += peopleCnt;
                res += (peopleCnt + seats - 1) / seats;
            }
        }
        return peopleSum;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> g(n + 1);
        for (auto& e : roads) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        long long res = 0;
        dfs(0, -1, g, seats, res); // 调用DFS函数进行遍历

        return res;
    }
};