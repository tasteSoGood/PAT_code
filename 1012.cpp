#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct stu {
	int id, score[4], rank[4];
};
int flag;
bool com(stu a, stu b){ return a.score[flag] > b.score[flag]; }
int main(){
	int N, M, t;
	cin >> N >> M;
	vector<stu> bin(N);
	for(int i = 0; i < N; i++){
		cin >> bin[i].id >> bin[i].score[0] >> bin[i].score[1] >> bin[i].score[2];
		bin[i].score[3] = int((bin[i].score[0] + bin[i].score[1] + bin[i].score[2]) / 3);
	}
	for(flag = 0; flag < 4; flag++){
		sort(bin.begin(), bin.end(), com);
		int pre = bin[0].score[flag];
		for(int i = 0, cnt = 1; i < N; i++){
			if(bin[i].score[flag] == pre)
				bin[i].rank[flag] = cnt;
			else
				bin[i].rank[flag] = i + 1, cnt = i + 1;
			pre = bin[i].score[flag];
		}
	}
	map<int, int> search;
	for(int i = 0; i < N; i++)
		search[bin[i].id] = i + 1;//避免搜索不到第一个元素
	for(int i = 0; i < M; i++){
		cin >> t;
		if(search[t] == false)
			cout << "N/A" << endl;
		else{
			int min = bin[search[t] - 1].rank[0];
			for(int j = 1; j < 4; j++)
				if(bin[search[t] - 1].rank[j] < min)
					min = bin[search[t] - 1].rank[j];
			string ch[4] = { " A", " C", " M", " E" };
			for(int j = 0; j < 4; j++)
				if(bin[search[t] - 1].rank[(3 + j) % 4] == min){
					cout << min << ch[j] << endl;
					break;
				}
		}
	}
	return 0;
}