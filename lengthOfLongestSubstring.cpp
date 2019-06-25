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
#include <unordered_set>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())return 0;
        unordered_map<char, int> m;
        int result = 0, left = INT_MIN;
        for (int i = 0; i < s.length(); ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            result = max(result, i - left);
        }
        return result;
    }
};

int main() {

    Solution solution;
   cout << solution.lengthOfLongestSubstring("bbbb");

    return 0;
}