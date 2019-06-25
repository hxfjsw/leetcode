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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result = {};

        unordered_map<int, vector<string>> map;
        for (string str :strs) {
            int pattern = 0;
            for (char c:str) {
                pattern += (c - '0');
            }
            map[pattern].push_back(str);
        }

        for (auto pair : map) {
            vector<string> solution = {};
            for (string str: pair.second) {
                solution.push_back(str);
            }
            result.push_back(solution);
        }

        return result;
    }
};

int main() {

    return 0;
}