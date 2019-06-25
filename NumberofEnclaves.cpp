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
#include <stack>
#include <errno.h>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int cnt = 0, row, col, nth, lastRow = A.size() - 1, lastCol = A[0].size() - 1;
        stack<pair<int, int>> s;

        for(nth = 1;nth < lastRow;nth++){
            if(A[nth][0]) s.push(pair<int, int>(nth, 0));
            if(A[nth][lastCol]) s.push(pair<int, int>(nth, lastCol));
        }

        for(nth = 0;nth < A[0].size();nth++){
            if(A[0][nth]) s.push(pair<int, int>(0, nth));
            if(A[lastRow][nth]) s.push(pair<int, int>(lastRow, nth));
        }

        while(!s.empty()){
            int left, right, top, bottom;
            pair<int, int> point = s.top();
            s.pop();

            left = point.second - 1;
            right = point.second + 1;
            top = point.first - 1;
            bottom = point.first + 1;

            if(left >= 0 && A[point.first][left] == 1){
                s.push(pair<int, int>(point.first, left));
                A[point.first][left] = 0;
            }

            if(right <= lastCol && A[point.first][right] == 1){
                s.push(pair<int, int>(point.first, right));
                A[point.first][right] = 0;
            }

            if(top >= 0 && A[top][point.second] == 1){
                s.push(pair<int, int>(top, point.second));
                A[top][point.second] = 0;
            }

            if(bottom <= lastRow && A[bottom][point.second] == 1){
                s.push(pair<int, int>(bottom, point.second));
                A[bottom][point.second] = 0;
            }
        }

        for(row = 1;row < lastRow;row++)
            for(col = 1;col < lastCol;col++)
                if(A[row][col]) cnt++;

        return cnt;
    }
};

int main(){
    return 0;
}