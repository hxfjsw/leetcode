//
// Created by lion on 2019-05-29.
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
#include <cctype>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

string vec2str(const vector<int> &vec) {
    string result = "[";
    for (int i : vec) {
        result += (to_string(i) + ",");
    }
    result.pop_back();
    result += "]";
    return result;
}

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        return buildTree2(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    vector<int> preorder(TreeNode *root) {
        vector<int> result;
        this->preorder(root, result);
        return result;
    }

    vector<int> inorder(TreeNode *root) {
        vector<int> result;
        this->inorder(root, result);
        return result;
    }

    vector<int> postorder(TreeNode *root) {
        vector<int> result;
        this->postorder(root, result);
        return result;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    void serialize(TreeNode *root, stringstream &ss) {
        if (root == nullptr)return;
        ss << root->val;
        if (root->left != nullptr || root->right != nullptr) {
            ss << "[";
            serialize(root->left, ss);
            ss << ",";
            serialize(root->right, ss);
            ss << "]";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() == 0)return nullptr;
        int pos = 0;
        return deserialize(data, pos);
    }

    TreeNode *deserialize(string &data, int &pos) {
        int n = data.size(), i = pos;
        bool found_left = false;
        while (i < n) {
            if (data[i] == ',' || data[i] == ']')break;
            if (data[i] == '[') {
                found_left = true;
                break;
            }
            i++;
        }
        if (i == pos && i < n)return nullptr;
        TreeNode *node = new TreeNode(atoi(data.substr(pos, i - pos).c_str()));
        if (i == n) return node;
        pos = i;
        if (found_left) {
            // find a '['
            pos++; // skip '['
            node->left = deserialize(data, pos);
            pos++; // skip ','
            node->right = deserialize(data, pos);
            pos++; // skip ']'
        }
        return node;
    }

private:
    void preorder(TreeNode *root, vector<int> &result) {
        if (root == nullptr)return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    void inorder(TreeNode *root, vector<int> &result) {
        if (root == nullptr)return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    void postorder(TreeNode *root, vector<int> &result) {
        if (root == nullptr)return;
        inorder(root->left, result);
        inorder(root->right, result);
        result.push_back(root->val);

    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)return nullptr;


        //前序遍历先访问根节点，因此前序遍历序列的第一个字母肯定就是根节点,即3是根节点
        TreeNode *root = new TreeNode(preorder[preStart]);

        //用于查找中续遍历中的根结点
        int root_position = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (preorder[preStart] == inorder[i]) {
                root_position = i;
                break;
            }
        }

        //root_position - inorder = 左子树的长度,知道这个很容易定出左子树和右子树的范围
        root->left = buildTree(preorder, inorder, preStart + 1, preStart + root_position - inStart, inStart,
                               root_position);

        root->right = buildTree(preorder, inorder, preStart + root_position - inStart + 1, preEnd, root_position + 1,
                                inEnd);

        return root;
    }

    TreeNode *
    buildTree2(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart > postEnd)return nullptr;

        //后续遍历中的最后一个节点就是根结点，即3节点
        TreeNode *root = new TreeNode(postorder[postEnd]);

        //查找中续遍历中的根节点
        int root_position = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (postorder[postEnd] == inorder[i]) {
                root_position = i;
                break;
            }
        }

        root->right = buildTree2(postorder, inorder, root_position + 1, inEnd, postStart + (root_position - inStart),
                                 postEnd - 1);

        root->left = buildTree2(postorder, inorder, inStart, root_position - 1, postStart,
                                postStart + (root_position - inStart) - 1);

        return root;
    }
};


int main() {
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);
    TreeNode *root2 = solution.buildTree2(inorder, postorder);

    TreeNode *sample = stringToTreeNode("[3,9,20,null,null,15,7]");
    prettyPrintTree(sample);
    prettyPrintTree(root);
    prettyPrintTree(root2);

    vector<int> inorder1 = {1, 3, 2}, postorder1 = {3, 2, 1};

    TreeNode *root3 = solution.buildTree2(inorder1, postorder1);
    prettyPrintTree(root3);


    cout << vec2str(solution.preorder(sample)) << endl;
    cout << vec2str(solution.inorder(sample)) << endl;
    cout << vec2str(solution.postorder(sample)) << endl;

    string seried = solution.serialize(stringToTreeNode("[1,2,3,null,null,4,5]"));

    cout << seried << endl;

    prettyPrintTree(solution.deserialize(seried));
    return 0;
}