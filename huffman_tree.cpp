#include <bits/stdc++.h>
// 哈夫曼编码的构建过程中计算最小带权路径长度​（即所有字符的编码长度乘以其出现频率的总和）
using namespace std;
int main() {
    string str;
    getline(cin, str); //空格也算字符
    unordered_map<char, int> mp;
    priority_queue<int, vector<int>, greater<>> heap;
    for (int i = 0; i < int(str.size()); i ++ ) 
        mp[str[i]] ++ ;
    for (auto item : mp)
        heap.emplace(item.second);
    int sum = 0;
    while (heap.size() > 1) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        int temp = a + b;
        heap.emplace(temp);
        sum += temp;
    }
    cout << sum << endl;
    return 0;
}