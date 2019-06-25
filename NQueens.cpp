//
// Created by lion on 2019/4/18.
//


#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        solution = vector<string>(n, string(n, '.'));
        print(solution);
    }

    vector<vector<string>> result;
    vector<string> solution;

    bool check(vector<string> &board, int x, int y) {
        int size = board.size();
        for (int i = 0; i < size; ++i) {
            if (board[i][y] == 'Q')return false;
        }
    }

    inline void print(vector<string>& vec) {
        for (auto v:vec) { cout << v << endl; }cout<<endl;
    }
};

int main() {

    Solution so;
    so.solveNQueens(4);


    return 0;
}