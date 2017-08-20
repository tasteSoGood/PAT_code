#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node{
	int number;
	int level;
};

int main(){
	int N, M;
	cin >> N >> M;
	bool tree_maxtrix[100][100];
	memset(tree_maxtrix, 0, sizeof(tree_maxtrix));
	for(int i = 0; i < M; i++){
		int ID, K;
		cin >> ID >> K;
		for(int j = 0; j < K; j++){
			int t;
			cin >> t;
			tree_maxtrix[ID - 1][t - 1] = 1;
		}
	}
	queue<node> temp_queue;
	node cnt = {0, 0};
	temp_queue.push( {0, 0} );
	while(!temp_queue.empty()){
		bool flag = false;
		node t = temp_queue.front();
		temp_queue.pop();
		if(cnt.level != t.level){
			if(cnt.level != 0)
				cout << " ";
			cout << cnt.number;
			cnt = {0, t.level};
		}
		for(int i = 0; i < N; i++)
			if(tree_maxtrix[t.number][i] == 1){
				flag = true;
				temp_queue.push({i, t.level + 1});
			}
		if(!flag && cnt.level == t.level)
			cnt.number++;
		if(temp_queue.empty()){
			if(cnt.level != 0)
				cout << " ";
			cout << cnt.number;
		}
	}
	cout << endl;
	// cout << endl;
	// for(int i = 0; i < N; i++){
	// 	for(int j = 0; j < N; j++)
	// 		cout << tree_maxtrix[i][j] << " ";
	// 	cout << endl;
	// }
	return 0;
}
/**
8 4
01 3 02 03 04
03 2 05 06
04 1 07
07 1 08
3 2
01 1 02
02 1 03
*/