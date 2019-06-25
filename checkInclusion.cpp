//
// Created by lion on 2019-05-27.
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
#include <cctype>
#include <stack>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        int s1_len = s1.size();
        int s2_len = s2.size();
        vector<int> s1_cnt(26, 0);
        vector<int> s2_cnt(26, 0);
        for (int ix = 0; ix < s1_len; ix++) {
            s1_cnt[s1.at(ix) - 'a']++;
        }
        for (int ix = 0; ix < s2_len; ix++) {
            s2_cnt[s2.at(ix) - 'a']++;
            if (ix >= s1_len) {
                s2_cnt[s2.at(ix - s1_len) - 'a']--;
            }
            if (s1_cnt == s2_cnt) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    Solution solution;
    cout << (solution.checkInclusion("ab", "eidbaooo") ? "true" : "false");

    return 0;
}