#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n, tag = 0;
	scanf("%d\n", &n);
	vector<string> store(n);
	bool flag = true;
	for(int i = 0; i < n; i++){
		getline(cin, store[i]);
		reverse(store[i].begin(), store[i].end());
	}
	for(; flag; tag++)
		for(int i = 0; i < n; i++)
			if(tag >= store[i].size() || store[i][tag] != store[0][tag]){
				if(tag == 0){
					cout << "nai" << endl;
					return 0;
				}
				flag = false;
			}
	for(int i = tag - 2; i >= 0; i--)
		cout << store[0][i];
	cout << endl;
	return 0;
}