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
    int maximalSquare(vector<vector<char> > &matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> v(matrix[i].size(), 0);
            for (int j = i; j < matrix.size(); ++j) {
                for (int k = 0; k < matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = max(res, getSquareArea(v, j - i + 1));
            }
        }
        return res;
    }

    int getSquareArea(vector<int> &v, int k) {
        if (v.size() < k) return 0;
        int count = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != k) count = 0;
            else ++count;
            if (count == k) return k * k;
        }
        return 0;
    }
};

int main() {


    vector<vector<char>> args1 = {
            {'0', '0', '0', '0'},
            {'0', '1', '1', '0'},
            {'0', '1', '1', '0'},
            {'0', '0', '0', '0'},
    };

    vector<vector<char>> args2 = {
            {'1', '2', '3', '4'},
            {'5', 'a', 'a', '8'},
            {'9', 'a', 'a', '0'},
            {'0', '0', '0', '0'},
    };

    auto matrix = args2;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i; j < matrix.size(); ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}