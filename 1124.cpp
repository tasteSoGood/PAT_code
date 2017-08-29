#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	map<string, bool> record;
	int M, N, S;
	bool flag = true;
	cin >> M >> N >> S;
	vector<string> win(M);
	for(int i = 0; i < M; i++)
		cin >> win[i];
	for(int i = S - 1; i < M;){
		if(record[win[i]])
			i++;
		else{
			cout << win[i] << endl;
			record[win[i]] = true;
			i += N, flag = false;
		}
	}
	if(flag)
		cout << "Keep going..." << endl;
	return 0;
}