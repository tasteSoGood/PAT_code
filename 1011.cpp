#include <iostream>
#include <cstdio>
using namespace std;
float cnt = 1;
void print(float a, float b, float c){
	float t = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : ((a > c) ? a : c));
	cnt *= t;
	if(t == a)
		cout << "W ";
	else if(t == b)
		cout << "T ";
	else if(t == c)
		cout << "L ";
}
int main(){
	float W[3], T[3], L[3];
	for(int i = 0; i < 3; i++)
		cin >> W[i] >> T[i] >> L[i];
	for(int i = 0; i < 3; i++)
		print(W[i], T[i], L[i]);
	printf("%.2f\n", (cnt * 0.65 - 1) * 2);
	return 0;
}