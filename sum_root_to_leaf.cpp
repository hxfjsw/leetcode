//
// Created by lion on 2019/4/17.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == nullptr)return 0;
        dfs(root, 0);
        return result;
    }

    int sum = 0, result = 0;

    void dfs(TreeNode *root, int depth) {
        sum *= 10;
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            result += sum;
        }
        if (root->left) {
            dfs(root->left, depth + 1);
            sum /= 10;
        }
        if (root->right) {
            dfs(root->right, depth + 1);
            sum /= 10;
        }
    }

};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if (node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)return true;
        dfs(root);
        pres.push_back(root);
    }

    vector<TreeNode *> pres;
    bool dfs(TreeNode *root) {
        TreeNode *pre = pres.back();
        if (root->left) {
            pres.push_back(root);
            dfs(root->left);
            pres.pop_back();
        }
        if (root->left && root->right) {
            return root->left->val < pre->val && root->right->val > pre->val;
        }
        if (root->right) {
            pres.push_back(root);
            dfs(root->right);
            pres.pop_back();
        }
        return true;
    }
};

class Solution3{
public:
    int romanToInt(string s) {
        if(s.size()==0)return 0;

        unordered_map<char, int> map = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        for(char c:s){
            int num = map[c];
            cout<<num;
        }

    }
};

int main() {

    TreeNode *root = stringToTreeNode("[1,5,1,null,null,null,6]");
    prettyPrintTree(root);
    Solution so;
    cout << so.sumNumbers(root);
    //assert(so.sumNumbers(root) == 25);

    return 0;
}