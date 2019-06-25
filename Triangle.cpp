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
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += min(triangle[i + 1][j + 1], triangle[i + 1][j]);
            }
        }
        return triangle[0][0];
    }
};

int main() {

    vector<vector<int >> args =
            {{2},
             {3, 4},
             {6, 5, 7},
             {4, 1, 8, 3}
            };


    vector<vector<int >> args2 = {
            {-1},
            {2, 3},
            {1, -1, -3}};
    Solution solution;
    cout << solution.minimumTotal(args2);

    return 0;
}

