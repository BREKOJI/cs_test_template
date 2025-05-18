#include <bits/stdc++.h>
using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/7 11:35 上午
 * Desc ：给定⼀个 1~n 的排列 P，即⻓度为 n，且 1~n 中所有数字都恰好出现⼀次的序列。
 * 现在按顺序将排列中的元素⼀⼀插⼊到初始为空的⼆叉搜索树中（左小右大），问最后每个节点的⽗亲节点的元素是什么。
 * 特别地，根节点的⽗亲节点元素视为 0。
 * inputs : 
 * 5
 * 2 3 5 1 4
 * output : 2 0 2 5 3
 */
typedef struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {};
} TreeNode;

void insertNode(TreeNode* &T, int num);  //插入节点
void inOrder(TreeNode* T_father, TreeNode* T_child);    //中序遍历

int main() {
    int n;
    cin >> n;
    TreeNode* root = NULL;    //指向根节点
    while (n -- ) {           //构造二叉搜索树
        int num;
        cin >> num;
        insertNode(root, num);
    }
    inOrder(NULL, root);
    return 0;
}

//递归插入节点
void insertNode(TreeNode* &T, int num) { 
    if (T == NULL) {    
        T = new TreeNode(num);
        return;
    }
    if (num <= T -> val) insertNode(T -> left, num);
    else insertNode(T -> right, num);
}

//中序遍历
void inOrder(TreeNode* T_father, TreeNode* T_child) {
    if (T_child != NULL) {
        inOrder(T_child, T_child->left);
        if (T_father == NULL) cout << 0 << " ";   //根节点的父节点元素为 0
        else cout << T_father -> val << " ";
        inOrder(T_child, T_child -> right);
    }
}