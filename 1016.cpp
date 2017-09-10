#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int rule[24], N;
struct node {
	string name, situation;
	int month, time;
};
bool cmp(node a, node b) { return a.name != b.name ? a.name < b.name : a.time < b.time; }
float spend(int a, int b){
	float res = 0.0;
	for(int i = a; i < b; i++)
		res += rule[i % 1440 / 60];
	return res / 100.0;
}
int main(){
	for(int i = 0; i < 24; i++)
		scanf("%d", &rule[i]);
	scanf("%d", &N);
	vector<node> r(N);
	for(int i = 0; i < N; i++){
		node temp;
		int a, b, c, d;
		cin >> temp.name;
		scanf("%d:%d:%d:%d", &a, &b, &c, &d);
		cin >> temp.situation;
		temp.month = a;
		temp.time = d + c * 60 + b * 1440;
		r[i] = temp;
	}
	sort(r.begin(), r.end(), cmp);
	map< string, vector<node> > c;
	for(auto i : r)
		c[i.name].push_back(i);
	for(auto it : c){
		printf("%s %02d\n", it.first.c_str(), it.second[0].month);
		float cnt = 0.0;
		for(int j = 0; j < it.second.size(); j++)
			if(it.second[j].situation == "on-line" && j != it.second.size() - 1 && it.second[j + 1].situation == "off-line"){
				float t = spend(it.second[j].time, it.second[j + 1].time);
				cnt += t;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n", it.second[j].time / 1440, it.second[j].time % 1440 / 60, it.second[j].time % 60, it.second[j + 1].time / 1440, it.second[j + 1].time % 1440 / 60, it.second[j + 1].time % 60, it.second[j + 1].time - it.second[j].time, t);
			}
		printf("Total amount: $%.2f\n", cnt);
	}
	return 0;
}