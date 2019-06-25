//
// Created by lion on 2019/4/17.
//


//vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

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

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> map = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };
        string result = "";
        for (auto m = map.rbegin(); m != map.rend(); ++m) {
            while (m->first <= num) {
                result += m->second;
                num -= m->first;
            }
        }
        return result;
    }
};

int main() {
    Solution so;
    cout << so.intToRoman(3236);

    return 0;
}