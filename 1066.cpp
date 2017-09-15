#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
	int data;
	node *left, *right;
	node(int x) : data(x), left(NULL), right(NULL) {}
};
int get_height(node *r){
	return (!r) ? 0 : max(get_height(r->left), get_height(r->right)) + 1;
}
node *rot_right(node *r){
	node *t = r->left;
	r->left = t->right;
	t->right = r;
	return t;
}
node *rot_left(node *r){
	node *t = r->right;
	r->right = t->left;
	t->left = r;
	return t;
}
node *rot_left_right(node *r){
	r->left = rot_left(r->left);
	return rot_right(r);
}
node *rot_right_left(node *r){
	r->right = rot_right(r->right);
	return rot_left(r);
}
node *insert(int x, node *r){
	if(!r)
		r = new node(x);
	else if(x < r->data){
		r->left = insert(x, r->left);
		if(get_height(r->left) - get_height(r->right) == 2)
			r = x < r->left->data ? rot_right(r) : rot_left_right(r);
	}
	else{
		r->right = insert(x, r->right);
		if(get_height(r->left) - get_height(r->right) == -2)
			r = x > r->right->data ? rot_left(r) : rot_right_left(r);
	}
	return r;
}
int main(){
	int N, t;
	scanf("%d", &N);
	node *tree = NULL;
	for(int i = 0; i < N; i++){
		scanf("%d", &t);
		tree = insert(t, tree);
	}
	printf("%d", tree->data);
	return 0;
}