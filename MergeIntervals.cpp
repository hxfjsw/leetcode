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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() < 2)return intervals;
        int slow = 0, fast = 1;
        intervals.push_back({INT_MAX - 1, INT_MAX});
        int size = (int) intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        vector<vector<int>> result = {};
        while (slow <= size && fast < size) {
            if (intervals[fast][0] <= intervals[slow][1]) {
                fast++;
            } else {
                if (fast - slow == 1) {
                    result.push_back(intervals[slow]);
                } else {
                    result.push_back({
                                             min(intervals[slow][0], intervals[fast - 1][0]),
                                             max(intervals[slow][1], intervals[fast - 1][1])
                                     });
                    slow++;
                }
                slow++, fast++;
            }
        }
        return result;
    }
};

int main() {

//    vector<vector<int>> args = {
//            {1,  3},
//            {2,  6},
//            {8,  10},
//            {15, 18}
//    };

    vector<vector<int>> args = {
            {1, 4},
            {0, 4},

    };
    Solution solution;
    auto result = solution.merge(args);
    for (auto pair:result) cout << pair[0] << ":" << pair[1] << endl;

    return 0;
}