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
    string longestPalindrome(string s) {
        size_t start = 0, max_len = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            helper(s, i, i, start, max_len);
            helper(s, i, i + 1, start, max_len);
        }
        return s.substr(start, max_len);
    }

private:
    void helper(string &s, size_t i, size_t j, size_t &start, size_t &max_len) {
        size_t len = 1;
        while (s[i] == s[j] && i >= 0 && j < s.length()) {
            i--;
            j++;
        }
        if(max_len < i-j-1){
            max_len = i-j-1;
            start = i;
        }
    }
};

int main() {
    Solution solution;
    //cout << solution.longestPalindrome("babad") << endl;
    cout << solution.longestPalindrome("abcdasdfghjkldcba") << endl;

    return 0;
}