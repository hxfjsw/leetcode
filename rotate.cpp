//
// Created by lion on 2019/5/6.
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
    void rotate(vector<vector<int>> &matrix) {
        size_t size = matrix.size();
        if (size < 2) {
            return;
        }

        /* diagonally flip */
        for (size_t i = 0; i < size; i++) {
            for (size_t j = i; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        /* horizontally flip */
        for (size_t i = 0; i < size; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


int main() {

    int n = 9;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            cout << i << ":" << j << endl;
        }
    }

    vector<vector<int>> args = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution solution;
    solution.rotate(args);

//    [7,4,1],
//    [8,5,2],
//    [9,6,3]
    return 0;
}