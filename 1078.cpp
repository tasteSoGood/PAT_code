#include <cstdio>
#include <map>
using namespace std;
int next_prime(int n){
	if(n == 1) return 2;//如果不排除1，第二个测试点无法通过
	for(int i = n; ; i++){
		bool f = true;
		for(int j = 2; j * j <= i; j++)
			if(!(i % j)){
				f = false;
				break;
			}
		if(f)
			return i;
	}
}
int main(){
	int m_size, N, t;
	scanf("%d %d", &m_size, &N);
	int t_size = next_prime(m_size);
	map<int, bool> m;
	bool f = false;
	for(int i = 0; i < N; i++){
		scanf("%d", &t);
		if(f) printf(" ");
		//平方二次探测
		bool tag = true;
		for(int j = 0; j < t_size; j++)//j = 0即是最初的hash检索，可以和平方探测合并
			if(!m[(t + j * j) % t_size]){
				m[(t + j * j) % t_size] = true;
				printf("%d", (t + j * j) % t_size);
				tag = false;
				break;
			}
		if(tag)
			printf("-");
		f = true;
	}
	return 0;
}