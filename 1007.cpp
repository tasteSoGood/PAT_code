//Maximum Subsequence Sum
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

void findMaximumSubsequence(vector<int> seq){
	int sub_sum = seq[0], front = 0, rear = 0;
	int temp = 0, tempf = 0, tempr = 0;
	for(int i = 0; i < seq.size(); i++){
		temp += seq[i];
		if(temp > sub_sum)
			sub_sum = temp, front = tempf, rear = tempr;
		else if(temp < 0)
			temp = 0, tempf = i + 1, tempr = i;
		tempr++;
	}
	if(sub_sum < 0)
		cout << "0 " << seq[0] << " " << seq[seq.size() - 1];
	else
		cout << sub_sum << " " << seq[front] << " " << seq[rear];
}

int main(){
	int n;
	cin >> n;
	vector<int> store(n);
	for(int i = 0; i < n; i++)
		cin >> store[i];
	findMaximumSubsequence(store);
	getch();
	return 0;
}