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

using namespace std;

class Solution {
public:
    const string letterMap[10] = {
            " ", //数字0
            "",  //数字1
            "abc", //数字2
            "def", //数字3
            "ghi", //数字4
            "jkl", //数字5
            "mno", //数字6
            "pqrs", //数字7
            "tuv", //数字8
            "wxyz" //数字9
    };
    vector<string> result = {};

    void dfs(string &digits, int index, const string s) {
        if (digits.length() == index) {
            result.push_back(s);
            return;
        }
        string letters = letterMap[digits[index] - 0];
        for (int i = 0; i < letters.size(); i++) {
            dfs(digits, index + 1, s + letters[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits.length() == 0)return result;
        dfs(digits, 0, "");
        return result;
    }
};