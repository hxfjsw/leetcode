//
// Created by lion on 2019/4/25.
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
    string removeKdigits(string num, int k) {
        if (num.size() < k)
            return 0;

        t1:
        for (auto it = num.begin(); it != num.end();) {
            if (k <= 0)break;
            if (*(it + 1) < *(it)) {
                //cout<<"erase:"<<*it<<endl;
                it = num.erase(it);
                k--;
                goto  t1;
            } else {
                ++it;
            }
        }

        while (num[0] == '0') num.erase(num.begin());

        while (k > 0) {
            if (!num.empty()) num.erase(num.begin());
            k--;
        }


        return num.empty() ? "0" : num;
    }
};

int main() {
    Solution solution;
    cout << solution.removeKdigits("1432219", 3) << endl;
    cout << solution.removeKdigits("10", 2) << endl;
    cout << solution.removeKdigits("10200", 1) << endl;
    cout << solution.removeKdigits("1234567890", 9) << endl;


    return 0;
}