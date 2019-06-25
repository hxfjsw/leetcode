#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

class Solution {
public:
    /**
     * 最少交换次数使得两个数组变成严格单调递增
     * @param A
     * @param B
     * @return
     */
    int minSwap(vector<int> &A, vector<int> &B) {
        //int ans = INT_MAX;
        //dfs(A, B, 1, 0, ans);
        //return ans;
        return dp(A, B);
    }

private:

    int dp(vector<int> &A, vector<int> &B) {
        const int n = A.size();
        vector<int> keep(n, INT_MAX);
        vector<int> swap(n, INT_MAX);
        keep[0] = 0;
        swap[0] = 1;

        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep[i] = keep[i - 1];
                swap[i] = swap[i - 1] + 1;
            }

            if (B[i] > A[i - 1] && A[i] > B[i - 1]) {
                swap[i] = min(swap[i], keep[i - 1] + 1);
                keep[i] = min(keep[i], swap[i - 1]);
            }
        }
        return min(keep.back(), swap.back());
    }

    /**
     * 深度优先搜索
     * 会超时
     * @param A
     * @param B
     * @param i 当前处理到第几位数字
     * @param c 当前交换了多少次
     * @param ans 最优解
     */
    void dfs(vector<int> &A, vector<int> &B, int i, int c, int &ans) {
        //交换次数大于ans退栈
        if (c >= ans)return;
        //所有的元素都处理完了
        if (i == A.size()) {
            //这个时候 ans一定大于c 更新一下ans
            ans = min(ans, c);
            return;
        }
        //第i位元素符合严格单调递增，不处理当前元素，尝试搜索下一个元素
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {

            dfs(A, B, i + 1, c, ans);
        }
        //第i位元素不符合严格单调递增，并且交换可以使得第i位变成单调递增，交换元素，当前交换次数+1
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            swap(A[i], B[i]);
            dfs(A, B, i + 1, c + 1, ans);
            swap(A[i], B[i]);//复原
        }
    }

};


int main() {

    vector<int> args1 = {1, 3, 5, 4};
    vector<int> args2 = {1, 2, 3, 7};

    Solution so;
    assert(so.minSwap(args1, args2) == 1);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}