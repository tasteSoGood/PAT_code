/**
 * 1. radix的查找界限是很考究的，下界是待查数字的最大数据位加1，上界是待比较数字的十进制数加1
 * 2. 在这样的大范围中，必须使用二分查找降低时间复杂度，递归操作就ok
 * 3. 请不要忽视第1条规则，下界的选定可以用来排除特殊情况，并不是为了二分查找的剪枝
 */
#include <iostream>
#include <string>
using namespace std;

int trans(char x){
	if(x >= '0' && x <= '9')
		return int(x - '0');
	else if(x >= 'a' && x <= 'z')
		return int(x - 'a' + 10);
}

bool binary_search(long long bottom, long long top, long long host, string str){
	if(bottom > top)
		return false;
	long long decimal = 0;
	long long sigma = (bottom + top) / 2;
	for(long long i = 0; i < str.size(); i++){
		decimal = decimal * sigma + trans(str[i]);
		//防止数值溢出，提前判断
		if(decimal > host)
			return binary_search(bottom, sigma - 1, host, str);
	}
	if(decimal == host){
		cout << sigma << endl;
		return true;
	}
	else if(decimal < host)
		return binary_search(sigma + 1, top, host, str);
}

bool compare(string N1, string N2, int tag, int radix){
	string one, two;
	if(tag == 1)
		one = N1, two = N2;
	else if(tag == 2)
		one = N2, two = N1;
	if(N1 == N2){//一种特殊情况
		cout << radix << endl;
		return true;
	}
	long long one_decimal = 0, low = 0;
	for(int i = 0; i < one.size(); i++)
		one_decimal = one_decimal * radix + trans(one[i]);
	for(int i = 0; i < two.size(); i++)
		if(trans(two[i]) > low)
			low = trans(two[i]);
	long long max = (one_decimal > radix) ? one_decimal : radix;
	return binary_search(low + 1, max + 1, one_decimal, two);
}

int main(){
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	if(!compare(N1, N2, tag, radix))
		cout << "Impossible" << endl;
	return 0;
}