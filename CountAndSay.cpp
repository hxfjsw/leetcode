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
    string countAndSay(int n) {
        string result = "";
        countAndSay("1", result, n - 1);
        return result;
    }
    void countAndSay(string n, string &result, int remain_steps) {
        if (remain_steps == 0)return;
        result = "";
        int count = 0;
        char start = n[0];
        for (int i = 0; i < n.size(); i++) {
            if (start == n[i]) {
                count++;
            } else {
                result += (to_string(count) + start);
                count = 1;
                start = n[i];
            }
        }
        if (count > 0) {
            result += (to_string(count) + start);
        }
        return countAndSay(result, result, remain_steps - 1);
    }
};

int main() {
    Solution solution;
    cout << solution.countAndSay(9);

    return 0;
}