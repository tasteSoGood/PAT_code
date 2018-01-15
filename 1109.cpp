#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int N, K, cnt = 0;
struct people {
	string name;
	int height;
};
vector<people> name_list;
list<people> group[10];
bool comp(people a, people b) {
	return a.height == b.height ? a.name > b.name : a.height < b.height;
}
void rank_group(list<people> &lis, int length) {
	lis.push_back(name_list[cnt + length - 1]);
	for(int i = cnt + length - 2; i >= cnt; i -= 2) {
		lis.push_front(name_list[i]);
		if(i - 1 >= cnt)
			lis.push_back(name_list[i - 1]);
	}
	cnt = cnt + length;
}
int main() {
	cin >> N >> K;
	name_list.resize(N);
	for(int i = 0; i < N; i++)
		cin >> name_list[i].name >> name_list[i].height;
	sort(name_list.begin(), name_list.end(), comp);
	int row_number = round(N / K);
	for(int i = 0; i < K - 1; i++)
		rank_group(group[i], K);
	rank_group(group[K - 1], N - (K - 1) * row_number);
	for(int i = K - 1; i >= 0; i--){
		cout << group[i].begin()->name;
		for(list<people>::iterator j = group[i].begin(); j != group[i].end(); j++) {
			if(j == group[i].begin())
				continue;
			cout << " " << (*j).name;
		}
		cout << endl;
	}
	return 0;
}
/**
 * 未完成，有两个例子不能通过
 * 且如下的输入会导致程序崩溃
2 2
Amy 167
Tony 190
 */