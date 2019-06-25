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
    bool checkRecord(string s) {
        int late_count = 0, absent_count = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == 'P') {
                late_count = 0;
            } else if (c == 'A') {
                if (absent_count >= 1)
                    return false;

            } else if (c == 'L') {
                if (late_count >= 2)
                    return false;
                late_count++;
            }
        }
        return true;
    }
};

int main() {

    Solution solution;
    cout << solution.checkRecord("PPALLP") ? "true" : "false";


    return 0;
}