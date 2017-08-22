#include <iostream>
using namespace std;
int main(){
	int t, a, b, N, dist[100010], M, total = 0;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> t;
		total += t;
		dist[i] = total;
	}
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		t = (dist[b - 1] - dist[a - 1] < total - dist[b - 1] + dist[a - 1]) ? (dist[b - 1] - dist[a - 1]) : (total - dist[b - 1] + dist[a - 1]);
		cout << t << endl;
	}
	return 0;
}