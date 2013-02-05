
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

int n, m, p, a, b;
int t[8], G[30][30];
double dp[30][1<<8];




double rec(int node, int used){
	if(node == b) return dp[node][used] = 0.0;
	if(dp[node][used] != -1) return dp[node][used];
	double res = (double)INF;
	REP(next, m){
		if(G[node][next] == INF) continue;
		REP(useT, n){
			if(used & (1<<useT)) continue;
			double tmp = rec(next, used+(1<<useT));
			if(tmp == (double)INF) continue;
			res = min(res, tmp+(double)G[node][next]/t[useT]);
		}
	}
	return dp[node][used] = res;
}

int main() {

	while(1){

		cin >> n >> m >> p >> a >> b;
		if(n==0 && m==0 && p==0 && a==0 && b==0) break;
		a--; b--;

		REP(i, 8) t[i] = 0;
		REP(i, 30) REP(j, 30) G[i][j] = INF;
		REP(i, 30) REP(j, (1<<8)) dp[i][j] = -1.0;

		REP(i, n) cin >> t[i];
		REP(i, p){
			int x, y, z;
			cin >> x >> y >> z;
			x--; y--;
			G[x][y] = z;
			G[y][x] = z;
		}

		double res = rec(a, 0);
		if(res == (double)INF) cout << "Impossible";
		else printf("%.5f", res);
		cout << endl;

	}

	return 0;
}
