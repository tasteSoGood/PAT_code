#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<string> card = { "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2" };
	vector<string> temp(54);
	int N, shuffer[54];
	cin >> N;
	for(int i = 0; i < 54; i++)
		cin >> shuffer[i];
	for(int i = 0; i < N; i++){
		for(int i = 0; i < 54; i++)
			temp[shuffer[i] - 1] = card[i];
		card = temp;
	}
	cout << card[0];
	for(int i = 1; i < 54; i++)
		cout << " " << card[i];
	cout << endl;
	return 0;
}