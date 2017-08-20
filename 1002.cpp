#include <iostream>
#include <cstdio>
#include <map>
/*这里是一个map库*/
using namespace std;
int main(){
	int a = 0, t = 0;//注意，输入对象必须要先定义，这样更保险
	float cnt = 0;
	map<int, float> store;//store是一个map容器，用来存储随机定义的指数和系数
	cin >> a;
	for(int i = 0; i < a; i++){
		cin >> t;
		cin >> store[t];
	}
	cin >> a;
	for(int i = 0; i < a; i++){
		cin >> t >> cnt;
		if(store[t])
			store[t] += cnt;
		else
			store[t] = cnt;
		/*在输入的同时进行加运算*/
	}
	cnt = 0;
	for(map<int, float>::reverse_iterator i = store.rbegin(); i != store.rend(); i++)
		if(i->second)
			cnt++;
	/*这里要注意了，要输出有效指数的话，必须遍历一遍，再输出大小，题目在这个点加了很多测试点*/
	cout << cnt;
	for(map<int, float>::reverse_iterator i = store.rbegin(); i != store.rend(); i++)
		/*这里用的是一个反向迭代器*/
		if(i->second)
			printf(" %d %.1f", i->first, i->second);
		/*要记得指定浮点数精确位数的写法*/
	cout << endl;
	return 0;
}
