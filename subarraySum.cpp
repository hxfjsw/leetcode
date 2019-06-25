//
// Created by lion on 2019/5/7.
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
    int subarraySum(vector<int> &nums, int k) {
        map<int, int> counts{{0, 1}};
        int cur_sum = 0, ans = 0;
        for (const auto num : nums) {
            cur_sum += num;
            ans += counts[cur_sum - k];
            ++counts[cur_sum];
        }
        return ans;
    }
};

int main() {

    Solution solution;
    vector<int> args = {1,1,1,1};
    cout << solution.subarraySum(args, 2);

    return 0;
}