#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    int numEnclaves(vector<vector<int>> &A) {


        for (auto i = 0; i < A.size(); ++i) {
            for (auto j = 0; j < A[0].size(); ++j) {
                if(
                        i*j==0 || //第一格子
                        i == A.size() - 1 //最后一列
                )
            }
        }

        return accumulate(begin(A), end(A), 0, [](int s, vector<int> &r) {
            return s + accumulate(begin(r), end(r), 0);
        });
    }

    void dfs(vector<vector<int>> &A, int i, int j) {
        if (i < 0 || j < 0 || i == A.size() || j == A[i].size() || A[i][j] != 1) return;

    }
};

int main() {

    Solution solution;
    vector<vector<int>> map1 = {
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
    }, map2 = {
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
    };

    cout << solution.numEnclaves(map1) << endl;
    cout << solution.numEnclaves(map2) << endl;

    return 0;
}