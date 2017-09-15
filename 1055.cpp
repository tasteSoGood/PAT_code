#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
struct node {
	string name;
	int age, worth;
};
bool cmp(node a, node b){ return a.worth == b.worth ? (a.age == b.age ? a.name < b.name : a.age < b.age) : a.worth > b.worth; }
int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	vector<node> r(N), rt, temp;
	vector<int> age_tag(210, 0);
	for(int i = 0; i < N; i++){
		char str[9];
		scanf("%s %d %d", &str, &r[i].age, &r[i].worth);
		r[i].name = str;
	}
	sort(r.begin(), r.end(), cmp);
	for(auto it : r)
		if(age_tag[it.age] <= 100){//注意这个100
			rt.push_back(it);
			age_tag[it.age]++;
		}
	for(int i = 1; i <= K; i++){
		int a, b, c, tag;
		scanf("%d %d %d", &a, &b, &c);
		printf("Case #%d:\n", i);
		temp.clear();
		for(int j = 0; j < rt.size() && temp.size() <= a; j++)
			if(rt[j].age >= b && rt[j].age <= c)
				temp.push_back(rt[j]);
		if(temp.size() == 0)
			printf("None\n");
		else
			for(int j = 0; j < a && j < temp.size(); j++)
				printf("%s %d %d\n", temp[j].name.c_str(), temp[j].age, temp[j].worth);
	}
	return 0;
}
/**
 * 有时候，先排序再选择，未尝不是一件好事
 * 题目里面的数字范围是非常重要的一个条件
 */