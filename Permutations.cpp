//
// Created by lion on 2019/4/19.
//
//
// Created by lion on 2019/4/19.
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
    vector<vector<int>> permuteUnique(vector<int> &nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> solution = {};
        do {
            solution.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()) );
        return solution;
    }
};

int main() {
    vector<int> args = {1, 1, 2};
    Solution so;
    auto ss = so.permuteUnique(args);
    for (auto nums:ss) {
        for (auto n:nums)cout << n << " ";
        cout << endl;
    }
    return 0;
}