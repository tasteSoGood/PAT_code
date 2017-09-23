#include <cstdio>
#include <vector>
using namespace std;
struct node { int key, id; };
node one[100001];
int main(){
	int start, N, K;
	scanf("%d %d %d", &start, &N, &K);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		one[a] = { b, c };
	}
	vector<node> two, three;
	for(; start != -1; start = one[start].id)
		two.push_back({one[start].key, start});
	for(auto it : two)
		if(it.key < 0)
			three.push_back(it);
	for(auto it : two)
		if(it.key >= 0)
			three.push_back(it);
	two.clear();
	for(auto it : three)
		if(it.key <= K)
			two.push_back(it);
	for(auto it : three)
		if(it.key > K)
			two.push_back(it);
	for(int i = 0; i < two.size() - 1; i++)//这里不能使用n，因为静态链表也可能出现断链的情况
		printf("%05d %d %05d\n", two[i].id, two[i].key, two[i + 1].id);
	printf("%05d %d -1\n", two[two.size() - 1].id, two[two.size() - 1].key);
	return 0;
}