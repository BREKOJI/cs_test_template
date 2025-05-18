#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
} TreeNode;

TreeNode* buildTree(const string & input);
int goodNodes(TreeNode* root);
int dfs(TreeNode * root, int path_max);

int main() {
    // 3 1 4 2 null 1 5
    // 3
    // 3 1 4 3 null 1 5
    // 4
    string input;
    getline(cin, input);
    TreeNode * root = buildTree(input);
    if (root == NULL) return 0;
    cout << goodNodes(root) << endl;
    return 0;
}

TreeNode* buildTree(const string & input) {
    stringstream ss(input);
    string nodeVal;
    vector<string> nodeVals;
    while (ss >> nodeVal) {
        nodeVals.push_back(nodeVal);
    }
    
    if (nodeVals.empty()) return NULL;
    TreeNode * root = new TreeNode(stoi(nodeVals[0]));
    queue<TreeNode*> q;
    q.push(root);
    int cnt = 1;
    while (!q.empty()) {
        TreeNode * p = q.front();
        q.pop();
        if (cnt < int(nodeVals.size()) && nodeVals[cnt] != "null") {
            p -> left = new TreeNode(stoi(nodeVals[cnt]));
            q.push(p -> left);
        }
        cnt ++ ;
        if (cnt < int(nodeVals.size()) && nodeVals[cnt] != "null") {
            p -> right = new TreeNode(stoi(nodeVals[cnt]));
            q.push(p -> right);
        }
        cnt ++ ;
    }
    return root;
}

int goodNodes(TreeNode* root) {
    return dfs(root, INT_MIN);
}

int dfs(TreeNode * root, int path_max) {
    if (root == NULL) return 0;
    int res = 0;
    if (root -> val >= path_max) {
        res ++ ;
        path_max = root -> val;
    }
    res += dfs(root -> left, path_max) + dfs(root -> right, path_max);
    return res;
}