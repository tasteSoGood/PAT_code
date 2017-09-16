#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node { double price, dist; };
bool cmp(node a, node b) { return a.dist < b.dist; }
int main(){
	double C_max, D, D_avg;
	int N;
	scanf("%lf %lf %lf %d", &C_max, &D, &D_avg, &N);
	vector<node> sta(N);
	for(int i = 0; i < N; i++)
		scanf("%lf %lf", &sta[i].price, &sta[i].dist);
	sort(sta.begin(), sta.end(), cmp);
	if(sta[0].dist != 0.0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double total_price = 0.0, total_dist = 0.0, now_price = sta[0].price, tank = 0.0;
	int now_sta = 0;
	while(total_dist < D){
		double cheapest = 100000000.0;
		int pos = -1;
		for(int i = now_sta + 1; i < sta.size() && sta[i].dist - total_dist <= C_max * D_avg; i++)
			if(sta[i].price < cheapest){
				cheapest = sta[i].price, pos = i;
				if(cheapest < now_price)
					break;
			}
		if(pos == -1 && C_max * D_avg < D - total_dist){
			printf("The maximum travel distance = %.2lf", total_dist + C_max * D_avg);
			return 0;
		}
		else if(pos == -1 && C_max * D_avg >= D - total_dist){
			total_price = total_price + ((D - total_dist) / D_avg - tank) * now_price;
			break;
		}
		if(cheapest < now_price){
			total_price = total_price + ((sta[pos].dist - total_dist) / D_avg - tank) * now_price;
			tank = 0;
		}
		else{
			total_price = total_price + (C_max - tank) * now_price;
			tank = C_max - (sta[pos].dist - total_dist) / D_avg;
		}
		total_dist = sta[pos].dist;
		now_price = cheapest;
		now_sta = pos;
	}
	printf("%.2lf", total_price);
	return 0;
}
/**
 * 极为复杂的题
 * 主要的思想为贪心算法，在加油的过程中，每次以当前加油站为基础，向后搜索
 * 搜索的范围是从下一个加油站到可能到达的最大距离，这个距离也就是 C_max * D_avg
 * 搜索的时候，如果发现一个加油站的油价比当前油价低，那么就（直接退出搜索，贪心的思想）在当前加油站加到仅仅可以到达那个低价站的油（有点复杂）
 * 如果搜索完，都没有当前的油价低，那么就在当前状态下加满油，然后转到那个较低油价的站
 * 要注意的是，车在行驶到下一个油站的时候，油箱会消耗油，所以油箱可能没油，也可能剩了一些油，这个需要算的
 * 在这个总循环的过程中，必须时刻判断当前条件是不是可以直接到达目的地，如果可以就直接退出
 * 退出的时候，要记得总价还要再加上那段距离造成的差价
 * 如果是无法到达，那么最后的输出结果也要加上当前条件下最大的可能距离
 * 第四个测试点一直过不了……
 */