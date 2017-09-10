#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct node { int time, p; };
bool cmp(node a, node b){return a.time < b.time;}
int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	vector<node> record;
	for(int i = 0; i < N; i++){
		int a, b, c, d;
		scanf("%d:%d:%d %d", &a, &b, &c, &d);
		node temp = { c + b * 60 + a * 3600, d * 60 };
		if(temp.time <= 61200)
			record.push_back(temp);
	}
	sort(record.begin(), record.end(), cmp);
	vector<int> serve(K, 28800);//置为08:00:00
	double wait = 0.0;
	for(int i = 0; i < record.size(); i++){
		int min = serve[0], min_tag = 0;
		for(int j = 1; j < K; j++)
			if(serve[j] < min)
				min = serve[j], min_tag = j;
		if(serve[min_tag] <= record[i].time)
			serve[min_tag] = record[i].time + record[i].p;
		else{
			wait += (serve[min_tag] - record[i].time);
			serve[min_tag] += record[i].p;
		}
	}
	printf("%.1f\n", wait / 60.0 / record.size());
	return 0;
}