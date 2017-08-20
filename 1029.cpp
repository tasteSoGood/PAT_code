#include <iostream>
#include <vector>
using namespace std;

long int median(vector<long int> v1, vector<long int> v2){
	int tag1 = 0, tag2 = 0, cnt = 0, res = 0;
	int N = v1.size() + v2.size();
	N = (N % 2) ? (N / 2) : (N / 2 - 1);
	while(cnt <= N){
		if(tag1 < v1.size() && tag2 < v2.size())
			res = (v1[tag1] < v2[tag2]) ? v1[tag1++] : v2[tag2++];
		else if(tag1 == v1.size() && tag2 < v2.size())
			res = v2[tag2++];
		else if(tag1 < v1.size() && tag2 == v2.size())
			res = v1[tag1++];
		cnt++;
	}
	return res;
}

int main(){
	int len_a, len_b;
	cin >> len_a;
	vector<long int> A(len_a);
	for(int i = 0; i < len_a; i++)
		cin >> A[i];
	cin >> len_b;
	vector<long int> B(len_b);
	for(int i = 0; i < len_b; i++)
		cin >> B[i];
	cout << median(A, B) << endl;
	return 0;
}