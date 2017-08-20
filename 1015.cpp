#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int N){
	if(N < 2)
		return false;
	for(int i = 2; i <= sqrt(N); i++)
		if(!(N % i))
			return false;
	return true;
}
int toDecimal(string N, int D){
	int res = 0;
	for(int i = 0; i < N.size(); i++)
		res = D * res + (N[i] - 48);
	return res;
}
int reverseD(int N, int D){
	string temp;
	while(N)
		temp.push_back(N % D + 48), N /= D;
	return toDecimal(temp, D);
}
int main(){
	int N, D;
	for(;;){
		cin >> N;
		if(N < 0)
			break;
		cin >> D;
		if(isPrime(N) && isPrime(reverseD(N, D)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}