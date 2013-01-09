
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

#define INF (1<<30) -1 

int N, ML, MD;
LL d[1010];
int AL[10010], BL[10010], DL[10010];
int AD[10010], BD[10010], DD[10010];

int main() {
	cin >> N >> ML >> MD;
	REP(i, ML) scanf("%d %d %d", &AL[i], &BL[i], &DL[i]);
	REP(i, MD) scanf("%d %d %d", &AD[i], &BD[i], &DD[i]);

	fill(d+1, d+N+1, INF);
	d[1] = 0;


	REP(i, N){
		FOR(j, 1, N) if(d[j+1] != INF) d[j] = min(d[j], d[j+1]);

		REP(j, ML) if(d[AL[j]] != INF) d[BL[j]] = min(d[BL[j]], d[AL[j]] + DL[j]);

		REP(j, MD) if(d[BD[j]] != INF) d[AD[j]] = min(d[AD[j]], d[BD[j]] - DD[j]);
	}

	if(d[1] < 0) cout << -1;
	else if(d[N] == INF) cout << -2;
	else cout << d[N];

	return 0;
}
