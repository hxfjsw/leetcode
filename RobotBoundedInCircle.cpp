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

    const static int top = 1;
    const static int right = 2;
    const static int down = 3;
    const static int left = 4;
    vector<int> position;
    int curr;

    bool isRobotBounded(string instructions) {
        position = {0, 0};
        curr = top;
        for (char cmd : instructions) {
            switch (cmd) {
                case 'G':
                    //直走 1 个单位

                    switch (curr) {
                        case top:
                            position[1]++;
                            break;
                        case right:
                            position[0]++;
                            break;
                        case down:
                            position[1]--;
                            break;
                        case left:
                            position[0]--;
                            break;
                    }
                    break;
                case 'L':
                    //左转 90 度
                    curr = (curr + 1) % 4;
                    break;
                case 'R':
                    curr = (curr - 1) % 4;
                    break;
                default:
                    break;
            }
        }
        return position[0] == 0 && position[1] == 0;
    }
};

int main() {
    string cmds = "GGLLGG";
    Solution solution;
    cout << solution.isRobotBounded(cmds) << endl;
    cout << solution.isRobotBounded("GL") << endl;

}