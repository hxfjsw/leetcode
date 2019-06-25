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
    bool search(vector<int> &nums, int target) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int left = 0, right = (int) nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                return true;
            } else {
                if (target > nums[mid]) {//目标大于中值，找
                    cout << "A" << endl;
                    //if (nums[mid - 1] > nums[mid + 1]) {
                    if (nums[left] > nums[mid] && target > nums[right]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    cout << "B" << endl;
                    //if (nums[mid - 1] > nums[mid + 1]) {
                    if (nums[mid] > nums[right] && target < nums[left]) {
                        //被旋转了
                        left = mid + 1;
                    } else {
                        //没有被旋转
                        right = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};


int main() {

    vector<int> args1 = {1, 3, 1, 1, 1};
    Solution so;
    cout << so.search(args1, 3) ? "true" : "false";


    return 0;
}