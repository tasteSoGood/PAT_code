#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
int N, n;
node *build_tree(vector<int> pre, vector<int> in, int a = 0, int b = N, int c = 0, int d = N){
	if(a < b && c < d){
		int i;
		node *tree = new node();
		tree->data = pre[a];
		for(i = 0; i < d - c && in[c + i] != pre[a]; i++);
		tree->left = build_tree(pre, in, a + 1, a + i + 1, c, c + i);
		tree->right = build_tree(pre, in, a + i + 1, b, c + i + 1, d);
		return tree;
	}
	else
		return NULL;
}
void post_order(node *tree, vector<int> &arr){
	if(tree->left) post_order(tree->left, arr);
	if(tree->right) post_order(tree->right, arr);
	arr.push_back(tree->data);
	delete tree;
}
int main(){
	cin >> N;
	stack<int> sta;
	vector<int> pre, in, arr;
	for(int i = 0; i < 2 * N; i++){
		string t;
		cin >> t;
		if(t == "Push"){
			cin >> n;
			sta.push(n), pre.push_back(n);
		}
		else
			in.push_back(sta.top()), sta.pop();
	}
	post_order(build_tree(pre, in), arr);
	cout << arr[0];
	for(int i = 1; i < N; i++)
		cout << " " << arr[i];
	cout << endl;
	return 0;
}