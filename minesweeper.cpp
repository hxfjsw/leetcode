#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        dfs(board, click[0], click[1]);
        return board;
    }

private:
    inline bool check_exist(const vector<vector<char>> &board, const int x, const int y) const {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    };

    void dfs(vector<vector<char>> &board, int x, int y) {
        if (!check_exist(board, x, y))return;
        if (board[x][y] == 'E') {
            //检查周边8个格子
            int cnt = 0;
            if (check_exist(board, x - 1, y - 1) && board[x - 1][y - 1] == 'M')cnt++; //↖
            if (check_exist(board, x - 1, y) && board[x - 1][y] == 'M')cnt++;//↑
            if (check_exist(board, x - 1, y + 1) && board[x - 1][y + 1] == 'M')cnt++;//↗
            if (check_exist(board, x, y - 1) && board[x][y - 1] == 'M')cnt++;//←
            if (check_exist(board, x, y + 1) && board[x][y + 1] == 'M')cnt++;//→
            if (check_exist(board, x + 1, y - 1) && board[x + 1][y - 1] == 'M')cnt++;//↙
            if (check_exist(board, x + 1, y) && board[x + 1][y] == 'M')cnt++;//↓
            if (check_exist(board, x + 1, y + 1) && board[x + 1][y + 1] == 'M')cnt++;//↘

            if (cnt > 0) {
                board[x][y] = '0' + cnt;
            } else {
                board[x][y] = 'B';
                dfs(board,x-1,y-1);
                dfs(board,x-1,y  );
                dfs(board,x-1,y+1);
                dfs(board,x  ,y-1);
                dfs(board,x  ,y+1);
                dfs(board,x+1,y-1);
                dfs(board,x+1,y  );
                dfs(board,x+1,y+1);
            }

        }
    }
};


int main() {

    vector<vector<char>> board =
            {{'E', 'E', 'E', 'E', 'E'},
             {'E', 'E', 'M', 'E', 'E'},
             {'E', 'E', 'E', 'E', 'E'},
             {'E', 'E', 'E', 'E', 'E'}};

    vector<int> click = {3, 0};

    Solution solution;
    auto result = solution.updateBoard(board, click);

    for (auto raw : result) {
        for (auto x:raw) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
