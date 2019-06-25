//
// Created by lion on 2019/5/7.
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
#include <unordered_set>


using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // g[A][B] = k -> A / B = k
        unordered_map<string, unordered_map<string, double>> g;
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i].first;
            const string& B = equations[i].second;
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }

        vector<double> ans;
        for (const auto& pair : queries) {
            const string& X = pair.first;
            const string& Y = pair.second;
            if (!g.count(X) || !g.count(Y)) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(divide(X, Y, g, visited));
        }
        return ans;
    }
private:
    // get result of A / B
    double divide(const string& A, const string& B,
                  unordered_map<string, unordered_map<string, double>>& g,
                  unordered_set<string>& visited) {
        if (A == B) return 1.0;
        visited.insert(A);
        for (const auto& pair : g[A]) {
            const string& C = pair.first;
            if (visited.count(C)) continue;
            double d = divide(C, B, g, visited); // d = C / B
            // A / B = C / B * A / C
            if (d > 0) return d * g[A][C];
        }
        return -1.0;
    }
};
int main() {
    vector<pair<string, string>> equations =  {{"a", "b"},{"b", "c"}};
    vector<double> values ={2.0, 3.0};
    vector<pair<string, string>> queries = {{"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"}};
    
    Solution solution;
    auto rst = solution.calcEquation(equations,values,queries);
    for(auto i:rst)cout << i << " ";
    return 0;
}