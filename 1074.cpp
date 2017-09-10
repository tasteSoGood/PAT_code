#include <iostream>
#include <cstdio>
using namespace std;
struct node { int data, next; };
int main(){
	node r[100001], n[100001];
	int a, b, c, ta, tb, tc;
	cin >> a >> b >> c;
	for(int i = 0; i < b; i++){
		cin >> ta >> tb >> tc;
		r[ta] = { tb, tc };
	}
	int temp = a;
	while(temp != -1){
		n[temp] = { r[temp].data, r[temp].next };
		cout << r[temp].data << endl;
		temp = r[temp].next;
	}
	// if(r[temp].next != -1)
	// 	printf("%05d %d %05d\n", temp, r[temp].data, r[temp].next);
	// else
	// 	printf("%05d %d %d\n", temp, r[temp].data, r[temp].next);
	return 0;
}