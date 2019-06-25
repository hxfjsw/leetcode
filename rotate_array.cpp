//
// Created by lion on 2019/4/18.
//


#include <vector>
#include <assert.h>


using namespace std;


class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        for (int i = 0; i < k; ++i) {
            nums.insert(nums.begin(),nums.back());
            nums.pop_back();
        }
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    return 0;
}