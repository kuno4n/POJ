
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define INF (1<<30)-1

vector < PII > G[5100]; 
int d1[5100]; //d1[i]ÇÕÅAí∏ì_1Ç©ÇÁÇÃç≈íZãóó£
int d2[5100]; //d2[i]ÇÕÅAí∏ì_1Ç©ÇÁÇÃÇQî‘ÇﬂÇÃç≈íZãóó£

int main() {
	int n, r;
	cin >> n >> r;
	REP(i, r){
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		G[v1].PB(make_pair(v2, cost));
		G[v2].PB(make_pair(v1, cost));
	}
	fill(d1+1, d1+n+1, INF);
	fill(d2+1, d2+n+1, INF);
	priority_queue<PII, vector< PII >, greater< PII> > que; //secondÇ™í∏ì_î‘çÜÅAfirstÇ™ç≈íZãóó£
	d1[1] = 0;
	que.push(make_pair(0, 1));

	while(!que.empty()){
		PII p = que.top(); que.pop();
		int from = p.second;
		if (d2[from] < p.first) continue;
		REP(i, SZ(G[from])){
			int to = G[from][i].first;
			int cost = G[from][i].second;
			int dist = p.first + cost;
			if(dist < d1[to]){
				swap(d1[to], dist);
				que.push(make_pair(d1[to], to));
			}
			if(dist < d2[to] && dist > d1[to]){
				d2[to] = dist;
				que.push(make_pair(d2[to], to));
			}
		}
	}

	cout << d2[n] << endl;

	return 0;
}
