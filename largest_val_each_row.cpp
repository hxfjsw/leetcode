//
// Created by lion on 2019/4/17.
//
#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x),  left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        bfs(root);
        return result;
    }

    vector<int> result = {};
    queue<TreeNode *> queue_;

    void bfs(TreeNode *root) {
        if (root == nullptr)return;

        queue_.push(root);

        while (!queue_.empty()) {
            vector<int> out;
            for (int i = queue_.size(); i > 0; --i) {
                auto t = queue_.front();
                queue_.pop();
                out.push_back(t->val);
            }
        }
    }

//    vector<vector<int>> levelOrder(Node *root) {
//        if (!root) return {};
//        vector<vector<int>> res;
//        queue<Node *> q{{root}};
//        while (!q.empty()) {
//            vector<int> out;
//            for (int i = q.size(); i > 0; --i) {
//                auto t = q.front();
//                q.pop();
//                out.push_back(t->val);
//                if (!t->children.empty()) {
//                    for (auto a : t->children) q.push(a);
//                }
//            }
//            res.push_back(out);
//        }
//        return res;
//    }
};
