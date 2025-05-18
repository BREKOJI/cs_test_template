#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
} TreeNode;

TreeNode * buildTree(string input);

int main() {
    string str;
    getline(cin, str);
    TreeNode * root = buildTree(str);
}

TreeNode * buildTree(string input) {
    stringstream ss(input);
    string nodeVal;
    vector<string> nodeVals;
    while (ss >> nodeVal) nodeVals.push_back(nodeVal);
    TreeNode * root = new TreeNode(stoi(nodeVals[0]));
    queue<TreeNode*> q;
    q.emplace(root);
    int cnt = 1;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (cnt < nodeVals.size() && nodeVals[cnt] != "null") {
            p -> left = new TreeNode(stoi(nodeVals[cnt]));
            q.emplace(p -> left);
        }
        cnt ++ ;
        if (cnt < nodeVals.size() && nodeVals[cnt] != "null") {
            p -> right = new TreeNode(stoi(nodeVals[cnt]));
            q.emplace(p -> right);
        }
        cnt ++ ;
    }
    return root;
}

void insert(TreeNode * &T, int num) {
    if (T == NULL) T = new TreeNode(num);
    else if (T -> val >= num) insert(T -> left, num);
    else insert(T -> right, num);
}

int main() {
    string str;
    getline(cin, str);
    unordered_map<char, int> mp;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < int(str.size()); i ++ ) {
        mp[str[i]] ++ ;
    }
    for (auto it : mp) {
        pq.emplace(it.second, it.first);
    }
    int sum = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int temp = a + b;
        pq.emplace(temp);
        sum += temp;
    }
    return sum;
}