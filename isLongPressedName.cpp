//
// Created by lion on 2019/5/16.
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
    bool isLongPressedName(string name, string typed) {
        int name_index = 0, typed_index = 0, name_len = (int) name.length(), typed_len = (int) typed.length();
        while (name_index < name_len && typed_index < typed_len) {
            if (typed[typed_index] == name[name_index]) {
                typed_index++, name_index++;
            } else if (typed_index > 0 && typed[typed_index] == typed[typed_index - 1]) {
                typed_index++;
            } else {
                return false;
            }
        }
        while (typed_index < typed_len && typed[typed_index] == typed[typed_index - 1]) ++typed_index;
        return name_index == name_len && typed_index == typed_len;
    }
};


int main() {
    Solution solution;
    cout << solution.isLongPressedName("alex", "aaleex") << endl;
    return 0;
}