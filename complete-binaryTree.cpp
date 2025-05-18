#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
} TreeNode;

TreeNode* buildCompleteBinaryTree(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int cnt = 1;
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (cnt < int(nums.size())) {
            current->left = new TreeNode(nums[cnt]);
            q.push(current->left);
        }
        cnt ++ ;
        if (cnt < int(nums.size())) {
            current->right = new TreeNode(nums[cnt]);
            q.push(current->right);
        }
        cnt ++ ;
    }
    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildCompleteBinaryTree(nums);
    cout << "完全二叉树的前序遍历结果: ";// 1 2 4 5 3 6 7
    printTree(root);
    cout << endl;
    return 0;
}