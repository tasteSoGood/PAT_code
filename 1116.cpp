#include <iostream>
#include <map>
using namespace std;
bool isPrime(int x){
	if(x <= 1)
		return false;
	for(int i = 2; i * i <= x; i++)
		if(!(x % i))
			return false;
	return true;
}
int main(){
	int N, K;
	string t;
	map<string, int> record;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> t;
		record[t] = i;
	}
	cin >> K;
	for(int i = 0; i < K; i++){
		cin >> t;
		if(record[t] == 1){
			cout << t << ": Mystery Award" << endl;
			record[t] = -1;
		}
		else if(isPrime(record[t])){
			cout << t << ": Minion" << endl;
			record[t] = -1;
		}
		else if(record[t] == 0)
			cout << t << ": Are you kidding?" << endl;
		else if(record[t] == -1)
			cout << t << ": Checked" << endl;
		else{
			cout << t << ": Chocolate" << endl;
			record[t] = -1;
		}
	}
	return 0;
}