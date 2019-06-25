//
// Created by lion on 2019/5/14.
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
    bool isNStraightHand(vector<int> &hand, int W) {
        map<int, int> count;
        for (int h:hand)++count[h];
        for (auto c:count) {
            int start = c.first, number = c.second;
            if (number > 0) {
                for (int i = 0; i < W; ++i) {
                    if (!count.count(i + start)) {
                        return false;
                    }
                    count[i + start] -= number;
                    if (count[start + i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int W = 3;

    Solution solution;
    cout << solution.isNStraightHand(hand, W) ? "true" : "false";

    return 0;
}