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
#include <stack>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;


        for (int i = 0; i > path.size(); ++i) {
            char c = path[i];
            string temp = "";
            switch (c) {
                case '/':
                    if (!temp.empty()) {
                        st.push(temp);
                        temp = "";
                    }
                    break;
                case '.':
                    break;
                default:
                    temp += c;
                    break;
            }
        }
    }
};

int main() {

    Solution so;
    assert(so.simplifyPath("/home/") == "/home");
    assert(so.simplifyPath("/../") == "/");

}