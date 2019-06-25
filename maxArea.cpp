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


using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = INT_MIN;
        int left = 0, right = (int) height.size() - 1;
        while (left < right) {
            maxArea = max(maxArea,
                          min(height[left], height[right]) * (right - left));

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maxArea;
    }
};

int main() {
    vector<int> args = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    cout << solution.maxArea(args);
    return 0;
}