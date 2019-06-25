//
// Created by lion on 2019/4/26.
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
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = (int) matrix.size(), n = (int) matrix.at(0).size();
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (matrix[y][x] == '1') {
                    int size = 0;
                    dfs(matrix, y, x, size);
                    cout << size << endl;
                }
            }
        }

        vector<int> nums;




        if(nums.size() == 0) return;
        k = k % nums.size();


        nums.insert(nums.begin(),(nums.begin() + (nums.size()-k)), nums.end());

        for(; k>0 ; k--){
            nums.pop_back();
        }
    }

    void dfs(vector<vector<char>> &matrix, int y, int x, int &size) {
        if (x < 0 || y < 0)return;
        if (x >= matrix.at(0).size() || y >= matrix.size())return;
        if (matrix[y][x] == '0')return;

        size++;
        matrix[y][x] = '0';

        dfs(matrix, y + 1, x, size);
        dfs(matrix, y, x + 1, size);
    }

};


int main() {

    vector<vector<char>> args = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    Solution solution;
    solution.maximalRectangle(args);

    return 0;
}