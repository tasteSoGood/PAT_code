#include <iostream>
#include <vector>
using namespace std;
bool judge(vector< vector<int> > mat, vector<bool> h){
	for(int i = 0; i < mat.size(); i++)
		for(auto it : mat[i])
			if(!h[i] && !h[it])
				return false;
	return true;
}
int main(){
	int N, M, K, a, b, c, v;
	cin >> N >> M;
	vector< vector<int> > mat(N);
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> c;
		vector<bool> h(N, false);
		for(int j = 0; j < c; j++){
			cin >> v;
			h[v] = true;
		}
		cout << (judge(mat, h) ? "Yes" : "No") << endl;
	}
	return 0;
}