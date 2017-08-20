#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<long int, int> expand(long int number){
	map<long int, int> store;
	for(long int x = 2; x <= int(sqrt(number)) && number != 1;){
		if(!(number % x)){
			store[x]++;
			number = number / x;
		}
		else
			x++;
	}
	store[number]++;
	return store;
}
void print(map<long int, int> num){
	for(map<long int, int>::iterator x = num.begin(); x != num.end(); x++){
		if(x == num.begin())
			cout << (*x).first;
		else
			cout << "*" << (*x).first;
		if((*x).second != 1)
			cout << "^" << (*x).second;
	}
}
int main(){
	long int number;
	cin >> number;
	cout << number << "=";
	print(expand(number));
	return 0;
}