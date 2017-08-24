#include <iostream>
using namespace std;
int N, store[100010], hashMap[100010];
bool flag = true;
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> store[i];
		hashMap[store[i]]++;
	}
	for(int i = 0; i < N; i++)
		if(hashMap[store[i]] == 1){
			cout << store[i] << endl;
			flag = false;
			break;
		}
	if(flag)
		cout << "None" << endl;
	return 0;
}