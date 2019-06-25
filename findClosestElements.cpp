//
// Created by lion on 2019/5/13.
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
//    vector<int> findClosestElements2(vector<int> &arr, int k, int x) {
//        vector<int> res = arr;
//        while (res.size() > k) {
//            if (x - res.front() <= res.back() - x) {
//                res.pop_back();
//            } else {
//                res.erase(res.begin());
//            }
//        }
//        return res;
//    }
//


    //下面这种解法是论坛上的高分解法，用到了二分搜索法。
    //其实博主最开始用的方法并不是帖子中的这两个方法，虽然也是用的二分搜索法，但博主搜的是第一个不小于x的数，然后同时向左右两个方向遍历，每次取和x距离最小的数加入结果res中，直到取满k个为止。
    //但是下面这种方法更加巧妙一些，二分法的判定条件做了一些改变，就可以直接找到要返回的k的数字的子数组的起始位置，
    //感觉非常的神奇。
    //每次比较的是mid位置和x的距离跟mid+k跟x的距离，
    //以这两者的大小关系来确定二分法折半的方向，最后找到最近距离子数组的起始位置
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int left = 0, right = (int)arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }


};


int main() {


    vector<int> arr = {0,0,1,2,3,3,4,7,7,8};
    Solution solution;
    auto rst = solution.findClosestElements(arr, 3, 5);
    for (auto r:rst)cout << r << " ";
    return 0;
}