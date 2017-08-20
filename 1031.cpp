#include <iostream>
#include <string>
using namespace std;

void printU(string str){
	int N = str.size() + 2;
	int left = N / 3, right = N / 3, bottom = N / 3 + N % 3;
	int tag1 = 0, tag2 = N - 3;
	while(tag1 <= tag2){
		if(tag2 - tag1 > bottom){
			cout << str[tag1++];
			for(int i = 0; i < bottom - 2; i++)
				cout << " ";
			cout << str[tag2--] << endl;
		}
		else
			cout << str[tag1++];
	}
	cout << endl;
}
int main(){
	string sample;
	cin >> sample;
	printU(sample);
	return 0;
}