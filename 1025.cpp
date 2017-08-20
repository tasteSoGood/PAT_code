#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct testee {
	long long reg_num;
	int score, frank, from, rank;
};
bool compare(testee a, testee b){
	return !(a.score < b.score || (a.score == b.score && a.reg_num > b.reg_num));
}
int main(){
	int N, loc_num;
	cin >> N;
	vector<testee> result;
	for(int i = 0; i < N; i++){
		cin >> loc_num;
		vector<testee> temp(loc_num);
		for(int j = 0; j < loc_num; j++){
			cin >> temp[j].reg_num >> temp[j].score;
			temp[j].from = i + 1;
		}
		sort(temp.begin(), temp.end(), compare);
		temp[0].rank = 1;
		for(int i = 1; i < temp.size(); i++)
			temp[i].rank = (temp[i - 1].score == temp[i].score) ? temp[i - 1].rank : (i + 1);
		result.insert(result.end(), temp.begin(), temp.end());
	}
	sort(result.begin(), result.end(), compare);
	result[0].frank = 1;
	printf("%d\n", result.size());
	for(int i = 1; i < result.size(); i++)
		result[i].frank = (result[i - 1].score == result[i].score) ? result[i - 1].frank : (i + 1);
	for(int i = 0; i < result.size(); i++)
		printf("%013lld %d %d %d\n", result[i].reg_num, result[i].frank, result[i].from, result[i].rank);
	/**
	 * 切记：格式化输出非常重要，以后碰到一般情况最好用格式化输出
	 */
	return 0;
}