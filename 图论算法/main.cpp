#include <iostream>
#include "graph_algorithm.hpp"
using namespace std;
int main(){
	Graph test;
	int Inf = test.inf;
	test.ver = { 0, 1, 2, 3, 4, 5, 6, 7 };
	test.mat = { { 0, 12, Inf, 5, 1, Inf, Inf, Inf },
				 { 12, 0, 7, Inf, 6, Inf, Inf, 3 },
				 { Inf, 7, 0, Inf, Inf, Inf, Inf, 4 },
				 { 5, Inf, Inf, 0, 2, 10, Inf, Inf },
				 { 1, 6, Inf, 2, 0, Inf, Inf, Inf },
				 { Inf, Inf, Inf, 10, Inf, 0, 9, Inf },
				 { Inf, Inf, Inf, Inf, Inf, 9, 0, 1 },
				 { Inf, 3, 4, Inf, Inf, Inf, 1, 0 } };
	DFS(test, 0);
	cout << endl;
	BFS(test, 0);
	cout << endl;
	cnt_comp(test);
	return 0;
}