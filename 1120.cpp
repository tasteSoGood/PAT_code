#include <iostream>
#include <vector>
using namespace std;
int count[40], N, t;
void friend_id(int x){
	int id = x % 10;
	for(; x; id += x % 10)
		x /= 10;
	count[id] = 1;
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> t;
		friend_id(t);
	}
	vector<int> res;
	for(int i = 0; i < 40; i++)
		if(count[i])
			res.push_back(i);
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		if(i != 0)
			cout << " ";
		cout << res[i];
	}
	cout << endl;
	return 0;
}