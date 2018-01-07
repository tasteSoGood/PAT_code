#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
struct record {
	int left, right;
};
struct node {
	int data;
	node *left, *right;
	node(int n) {
		data = n;
		left = NULL;
		right = NULL;
	}
};
vector<record> tree;
vector<bool> who_is_root;
vector<int> ino;
int trans(char c) {
	if(c == '-')
		return -1;
	else {
		who_is_root[c - 48] = false;
		return c - 48;
	}
}
node *build_tree(int root) {
	if(root == -1)
		return NULL;
	node *new_node = new node(root);
	if(tree[root].left != -1 || tree[root].right != -1) {
		new_node->right = build_tree(tree[root].left);
		new_node->left = build_tree(tree[root].right);
	}
	return new_node;
}
void in_order(node *t){
	if(t) {
		in_order(t->left);
		ino.push_back(t->data);
		in_order(t->right);
	}
}
void level_order(node *t){
	cout << t->data;
	queue<node *> q;
	if(t->left)
		q.push(t->left);
	if(t->right)
		q.push(t->right);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		cout << " " << temp->data;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	cout << endl;
}
int main(){
	scanf("%d", &n);
	getchar();
	tree.resize(n);
	who_is_root.resize(n, true);
	for(int i = 0; i < n; i++){
		char c1, c2;
		scanf("%c %c", &c1, &c2);
		getchar();
		tree[i].left = trans(c1);
		tree[i].right = trans(c2);
	}
	int root;
	for(int i = 0; i < n; i++)
		if(who_is_root[i])
			root = i;
	node *bi_tree = build_tree(root);
	level_order(bi_tree);
	in_order(bi_tree);
	cout << ino[0];
	for(int i = 1; i < n; i++)
		cout << " " << ino[i];
	return 0;
}

/*
                       3
            2                     7
       0         -          4           6
    1     -              -     -     5     -
  -   -                            -   -
*/