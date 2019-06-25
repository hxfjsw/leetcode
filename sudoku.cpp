//
// Created by lion on 2019/4/17.
//

#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

const int SIZE = 9;
const int EXIST = 1;
const int NOT_EXIST = 0;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        print(board);
        for (int y = 0; y < SIZE; ++y) {
            for (int x = 0; x < SIZE; ++x) {
                if (board[y][x] == '.')continue;
                int num = board[y][x] - '0';
                int area = (y / 3) * 3 + x / 3;
                row_map[y][num - 1] = EXIST;
                col_map[x][num - 1] = EXIST;
                area_map[area][num - 1] = EXIST;
            }
        }
        print(row_map);
        print(col_map);
        print(area_map);
        fill(board, 0, 0);
        print(board);
    }

    int row_map[9][9] = {0}, col_map[9][9] = {0}, area_map[9][9] = {0};

    bool fill(vector<vector<char >> &board, int x, int y) {
        if (y == SIZE)
            return true;
        int nx = (x + 1) % SIZE;
        int ny = (nx == 0) ? y + 1 : y;
        if (board[y][x] != '.') return fill(board, nx, ny);
        for (int i = 0; i < SIZE; i++) {
            int box_key = (y / 3) * 3 + x / 3;
            if (row_map[y][i]==NOT_EXIST && col_map[x][i]==NOT_EXIST && area_map[box_key][i]==NOT_EXIST) {
                row_map[y][i] = EXIST;
                col_map[x][i] = EXIST;
                area_map[box_key][i] = EXIST;
                board[y][x] = char(i + '1');
                print(board);
                if (fill(board, nx, ny)) return true;
                board[y][x] = '.';
                area_map[box_key][i] = NOT_EXIST;
                col_map[x][i] = NOT_EXIST;
                row_map[y][i] = NOT_EXIST;
            }
        }
        return false;
    }

    template<typename T>
    static void print(T board) {
        return;
        for (int y = 0; y < SIZE; ++y) {
            for (int x = 0; x < SIZE; ++x) {
                cout << board[y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
    vector<vector<char >> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution so;
    so.solveSudoku(board);
}