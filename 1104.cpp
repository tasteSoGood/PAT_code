#include <cstdio>
#include <vector>
using namespace std;
double solution(vector<double> v){
	double sum = 0;
	for(int i = 0; i < v.size(); i++)
		sum += (v.size() - i) * (i + 1) * v[i];
	return sum;
}
int main(){
	int N;
	scanf("%d", &N);
	vector<double> v(N);
	for(int i = 0; i < N; i++)
		scanf("%lf", &v[i]);
	printf("%.2lf\n", solution(v));
	return 0;
}/*remember, use double type*/