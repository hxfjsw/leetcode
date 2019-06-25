//
// Created by lion on 2019/5/13.
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        dfs(root);
        return *v.rbegin() + (k - 1);
    }

    multiset<int> v;

    void dfs(TreeNode *root) {
        if (root == NULL)return;
        v.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    };
};

int main() {
    return 0;
}