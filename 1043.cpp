#include <iostream>
#include <vector>
using namespace std;
struct node {
	int data;
	node *left, *right;
};
bool is_tree(vector<int> arr, int a, int b, bool f){
	if(a >= b)
		return true;
	int flag = arr[a], i;
	if(f)
		for(i = a + 1; i < b && arr[i] < flag; i++);
	else
		for(i = a + 1; i < b && arr[i] >= flag; i++);
	for(int j = i; j < b; j++){
		if((f && arr[j] < flag) || (!f && arr[i] >= flag))
			return false;
	}
	is_tree(arr, a + 1, i, f);
	is_tree(arr, i, b, f);
}
node *build_tree(vector<int> arr, int a, int b, bool flag){
	if(a < b){
		node *n = new node();
		n->data = arr[a];
		int i;
		if(flag)
			for(i = a + 1; i < b && arr[i] < arr[a]; i++);
		else
			for(i = a + 1; i < b && arr[i] >= arr[a]; i++);
		n->right = build_tree(arr, a + 1, i, flag);
		n->left = build_tree(arr, i, b, flag);
		return n;
	}
	else
		return NULL;
}
void postorder(node *t, vector<int> &po){
	if(t->right) postorder(t->right, po);
	if(t->left) postorder(t->left, po);
	po.push_back(t->data);
	delete t;
}
void print_arr(vector<int> arr){
	for(int i = 0; i < arr.size(); i++){
		if(i != 0)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
}
int main(){
	int N;
	cin >> N;
	vector<int> preorder(N), po;
	for(int i = 0; i < N; i++)
		cin >> preorder[i];
	if(is_tree(preorder, 0, N, true)){
		cout << "YES" << endl;
		node *tree = build_tree(preorder, 0, N, true);
		postorder(tree, po);
		print_arr(po);
	}
	else if(is_tree(preorder, 0, N, false)){
		cout << "YES" << endl;
		node *tree = build_tree(preorder, 0, N, false);
		postorder(tree, po);
		print_arr(po);
	}
	else
		cout << "NO" << endl;
	return 0;
}