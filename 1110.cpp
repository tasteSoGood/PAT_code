#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N;
struct node {
	int left, right;
};
vector<node> tree;
int main() {
	cin >> N;
	tree.resize(N);
	string str1, str2;
	vector<bool> test(N, false);
	for(int i = 0; i < N; i++){
		cin >> str1 >> str2;
		tree[i].left = str1 == "-" ? -1 : stoi(str1);
		tree[i].right = str2 == "-" ? -1 : stoi(str2);
		if(tree[i].left != -1) test[tree[i].left] = true;
		if(tree[i].right != -1) test[tree[i].right] = true;
	}
	int root;
	for(int i = 0; i < N; i++)
		if(!test[i]) {
			root = i;
			break;
		}
	queue<int> q;
	int current_node = root, cnt = 0;
	q.push(root);
	while(!q.empty()) {
		int temp = q.front();
		q.pop();
		if(temp != -1)
			current_node = temp, cnt++;
		else {
			if(cnt != N)
				cout << "NO " << root << endl;
			else
				cout << "YES " << current_node << endl;
			return 0;
		}
		q.push(tree[temp].left);
		q.push(tree[temp].right);
	}
	return 0;
}

/**
 * 千万千万要记住，即使是bool型数组也必须初始化！！！
 */