//
// Created by lion on 2019-05-29.
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

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        std::string str, result;
        stack<string> st;
        while (iss >> str)st.push(str);
        while (st.size()) {
            result += (st.top() + " ");
            st.pop();
        }
        result.pop_back();
        return result;
    }
};

int main() {
    Solution solution;
    string sentance = "hello world";
    cout << solution.reverseWords(sentance) << endl;
    return 0;
}