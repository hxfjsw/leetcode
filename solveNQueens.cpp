//
// Created by lion on 2019-05-29.
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
#include <stack>

using namespace std;

class Solution {
public:
    int solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return (int)res.size();
    }

private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }

    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //检查行线是否已经有皇后
        for (int i = 0; i != row; ++i)if (nQueens[i][col] == 'Q')return false;
        //检查45度线是否已经有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)if (nQueens[i][j] == 'Q')return false;
        //检查135度线是否已经有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)if (nQueens[i][j] == 'Q')return false;
        //没有皇后
        return true;
    }
};

int main() {

    Solution solution;
    vector<vector<string>> maps = solution.solveNQueens(8);

    for (vector<string> map:maps) {
        for (string row:map) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}