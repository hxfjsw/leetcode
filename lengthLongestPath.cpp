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
    int lengthLongestPath(const string &input) {
        if (input.empty()) return 0;
        istringstream ssi(input);
        string token;
        unordered_map<int, int> mp;
        int max_len = 0;
        while (getline(ssi, token)) {
            int lvl = token.find_last_of('\t');
            string file_name = token.substr(lvl + 1);
            if (file_name.find('.') != string::npos) {
                max_len = max(max_len, mp[lvl - 1] + (int) file_name.length());
            } else {
                mp[lvl] = mp[lvl - 1] + (int) file_name.length() + 1;
            }
        }
        return max_len;
    }

};

int main() {

    Solution solution;
    cout << solution.lengthLongestPath(
            "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;

    return 0;
}