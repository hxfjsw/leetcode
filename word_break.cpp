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
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = (int) s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                for (int len = 1; i + len - 1 < n; ++len) {
                    if (find(wordDict.begin(), wordDict.end(), s.substr(i, len)) != wordDict.end()) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {
    string s = "catsandog";
    vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    Solution solution;
    cout << (solution.wordBreak(s, words) ? "true" : "false");

    return 0;
}