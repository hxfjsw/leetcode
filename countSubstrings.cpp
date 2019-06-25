//
// Created by lion on 2019/5/6.
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
    int countSubstrings(string s) {
        if (s.empty())return 0;
        const int size = (int) s.length();
        int result = 0;
        for (int i = 0; i < size; ++i) {
            helper(s, result, i, i);
            helper(s, result, i, i + 1);
        }
        return result;
    }

    void helper(const string &s, int &result, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            result++;
            i--;
            j++;
        }
    }
};

int main() {

    Solution solution;
    cout << solution.countSubstrings("aaa");

    return 0;
}