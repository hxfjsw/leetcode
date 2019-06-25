//
// Created by lion on 2019/4/25.
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
    int coinChange(vector<int> &coins, int amount) {
        return bruteForce(0, coins, amount);
//        sort(coins.begin(), coins.end());
//        int ans = INT_MAX;
//
//        dfs(coins, 0, amount, 0, ans);
//        return ans == INT_MAX ? -1 : ans;
    }


    int bruteForce(int step, vector<int> &coins, int amount) {
        if (amount == 0)return 0;
        if (step < coins.size() && amount > 0) {
            int max_value = amount / coins[step];
            int min_cost = INT_MAX;
            for (int x = 0; x <= max_value; x++) {
                if (amount >= x * coins[step]) {
                    int res = bruteForce(step + 1, coins, amount - x * coins[step]);
                    if (res != -1)
                        min_cost = min(min_cost, res + x);
                }
            }
        }
        return -1;
    }

    void dfs(vector<int> &coins, int step, int amount, int count, int &ans) {
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }

        if (step == coins.size()) return;

        const int coin = coins[step];

        for (int k = amount / coin; k >= 0 && count + k < ans; k--) {
            dfs(coins, step + 1, amount - k * coin, count + k, ans);
        }
    }

    int dp_solution(vector<int> &coins, int amount) {
        vector<int> dp((unsigned long)amount + 1, INT_MAX-1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }

    void print(vector<vector<int>> &dp) {
        for (auto row:dp) {
            for (auto i:row) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
    }
};

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution solution;
    cout << solution.coinChange(coins, amount);

    return 0;
}