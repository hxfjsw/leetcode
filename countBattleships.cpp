//
// Created by lion on 2019/5/16.
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

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0, m = (int)board.size(), n = (int)board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (
                        board[i][j] == '.' ||
                        (i > 0 && board[i - 1][j] == 'X') ||
                        (j > 0 && board[i][j - 1] == 'X')
                        )
                    continue;
                ++res;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}