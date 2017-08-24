#include <iostream>
#include <string>
using namespace std;
int main(){
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	char e, f;
	int g;
	bool flag = false;
	for(int i = 0; i < min(a.size(), b.size()); i++){
		if(a[i] <= 'G' && a[i] >= 'A' && a[i] == b[i] && !flag)
			e = a[i], flag = true;
		else if(((a[i] >= '0' && a[i] <= '9') || (a[i] <= 'N' && a[i] >= 'A')) && a[i] == b[i] && flag){
			f = a[i];
			break;
		}
	}
	for(int i = 0; i < min(c.size(), d.size()); i++)
		if(((c[i] <= 'z' && c[i] >= 'a') || (c[i] <= 'Z' && c[i] >= 'A')) && c[i] == d[i]){
			g = i;
			break;
		}
	string week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	cout << week[int(e - 'A')] << ((f >= '0' && f <= '9') ? " 0" : " ") << ((f >= '0' && f <= '9') ? (f - 48) : (f - 'A' + 10)) << ((g < 10)? ":0" : ":") << g << endl;
	return 0;
}