//
// Created by lion on 2019/5/15.
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> result;
        return result;
    }
};

int main() {

    vector<vector<string>> args = {
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"John", "johnnybravo@mail.com"},
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"Mary", "mary@mail.com"}
    };

    //[
    //        ["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
    //        ["John", "johnnybravo@mail.com"],
    //        ["Mary", "mary@mail.com"]
    // ]

    Solution solution;
    auto result = solution.accountsMerge(args);

    return 0;


}