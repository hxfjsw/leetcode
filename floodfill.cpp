//
// Created by lion on 2019/4/17.
//
#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int oldColor, int newColor) {
        if (sr < 0 || sc < 0)
            return;
        if (sc >= image.front().size() || sr >= image.size())
            return;
        if (image[sr][sc] != oldColor)
            return;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
    }
};

int main() {

    vector<vector<int>> image1 = {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
    };

    Solution so;
    auto rst = so.floodFill(image1, 1, 1, 2);


    vector<vector<int>> image2 = {
            {0, 0, 0},
            {0, 1, 1},
    };

    auto rst2 = so.floodFill(image2, 1, 1, 1);

    for (auto c:rst) {
        for (auto i:c) {
            cout << i << " ";
        }
        cout << endl;
    }

    for (auto c:rst2) {
        for (auto i:c) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}