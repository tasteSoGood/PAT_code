#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	float amount, price, weight;/*amount也要申明为float类型，这样可以避免除整的情况*/
} r[1010];
int main(){
	int N, D;
	cin >> N >> D;
	for(int i = 0; i < N; i++)
		cin >> r[i].amount;
	for(int i = 0; i < N; i++)
		cin >> r[i].price;
	for(int i = 0; i < N; i++)
		r[i].weight = r[i].price / r[i].amount;
	sort(r, r + N, [](node a, node b){return a.weight > b.weight;});
	float sum = 0;
	for(int i = 0; i < N && D; i++){
		sum += ((r[i].amount < D) ? r[i].price : (D * r[i].weight));
		D -= ((r[i].amount < D) ? r[i].amount : D);
	}
	printf("%.2lf\n", sum);
	return 0;
}