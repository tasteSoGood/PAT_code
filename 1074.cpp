#include <iostream>
#include <cstdio>
using namespace std;
struct node { int data, next; };
int main(){
	node r[100001];
	int n[100001];
	int a, b, c, ta, tb, tc, cnt;
	cin >> a >> b >> c;
	for(int i = 0; i < b; i++){
		cin >> ta >> tb >> tc;
		r[ta] = { tb, tc };
	}
	for(cnt = 0; a != -1; cnt++, a = r[a].next)
		n[cnt] = a;
	for(int i = 0; i < cnt - cnt % c; i += c)
		for(int j = i, k = i + c - 1; j <= k; j++, k--)
			swap(n[j], n[k]);
	for(int i = 0; i < cnt - 1; i++)
		printf("%05d %d %05d\n", n[i], r[n[i]].data, n[i + 1]);
	printf("%05d %d -1\n", n[cnt - 1], r[n[cnt - 1]].data);
	return 0;
}
/**
 * 其实这样的静态链表不需要管next域的指向，只用一次hash得到data即可
 * 要进行交换的只是各节点的所在地址，输出的时候输出后一项的地址就可以了
 */