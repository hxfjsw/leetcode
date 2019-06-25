//
// Created by lion on 2019/4/25.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <numeric>
#include <string>
#include <sstream>
#include <limits>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <queue>


using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty())return 0;
        int m = (int) grid.size(), n = (int) grid.at(0).size(), nums = 0;
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == '1') {
                    dfs(grid, y, x);//找到了第一个岛屿的一个角
                    nums++;
                }
            }
        }
        return nums;
    }

    void dfs(vector<vector<char>> &grid, int y, int x) {
        if (y < 0 || x < 0)return;
        if (y >= grid.size() || x >= grid.at(0).size())return;
        if (grid[y][x] == '0')return;
        grid[y][x] = '0';
        dfs(grid, y, x + 1);
        dfs(grid, y, x - 1);
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
    }

};

int main() {

    vector<vector<char>> grid1 = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };

    Solution solution;
    cout << solution.numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };

    cout << solution.numIslands(grid2) << endl;


    return 0;
}