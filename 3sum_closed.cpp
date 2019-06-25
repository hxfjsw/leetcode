//
// Created by lion on 2019/5/13.
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
#include <limits.h>


using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int ans = 0, diff = INT_MAX, sum, left, right;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            left = i + 1, right = (int) nums.size() - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                } else if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};

int main() {

    vector<int> args = {-1, 2, 1, -4};

    Solution solution;
    cout << solution.threeSumClosest(args, 1);

    return 0;
}