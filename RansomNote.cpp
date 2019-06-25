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
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> pattern(26, 0);
        for (char m:magazine)++pattern[m - 'a'];
        for (char r:ransomNote) {
            if (pattern[r - 'a'] == 0) {
                return false;
            } else {
                --pattern[r - 'a'];
            }
        }
        return true;
    }
};