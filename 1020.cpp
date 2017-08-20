#include <iostream>
#include <queue>
using namespace std;

struct binary_tree_node {
	int number;
	binary_tree_node *left;
	binary_tree_node *right;
};

binary_tree_node *build_binary_tree(int *p_order, int *i_order, int N){
	binary_tree_node *node = new binary_tree_node;
	node->number = p_order[N - 1];
	if(N == 1){
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	int pos;
	for(int i = 0; i < N; i++)
		if(i_order[i] == node->number){
			pos = i;
			break;
		}
	int *left_p = new int[pos], *left_i = new int[pos];
	int *right_p = new int[N - pos - 1], *right_i = new int[N - pos - 1];
	for(int i = 0; i < pos; i++)
		left_p[i] = p_order[i], left_i[i] = i_order[i];
	for(int i = 0; i < N - pos - 1; i++)
		right_p[i] = p_order[i + pos], right_i[i] = i_order[i + pos + 1];
	if(pos > 0)
		node->left = build_binary_tree(left_p, left_i, pos);
	else if(pos == 0)
		node->left = NULL;
	if(N - pos - 1 > 0)
		node->right = build_binary_tree(right_p, right_i, N - pos - 1);
	else if(N - pos - 1 == 0)
		node->right = NULL;
	delete[] left_p, left_i, right_p, right_i;
	return node;
}

int main(){
	int N;
	cin >> N;
	int post_order[30], in_order[30];
	for(int i = 0; i < N; i++)
		cin >> post_order[i];
	for(int i = 0; i < N; i++)
		cin >> in_order[i];
	binary_tree_node *tree = build_binary_tree(post_order, in_order, N);
	//BFS
	queue<binary_tree_node *> q;
	q.push(tree);
	while(!q.empty()){
		if(q.front() != tree)
			cout << " ";
		cout << q.front()->number;
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		q.pop();
	}
	cout << endl;
	delete tree;
	return 0;
}