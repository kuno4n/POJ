
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
#include "cout.h"

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

int n, m, I, J, K;
int a[100010];
VI dat[400040];

void init(int node, int L, int R){
	if(R-L == 1){
		dat[node].PB(a[L]);
		return;
	}
	int m = (L+R)/2;
	init(node*2+1, L, m);
	init(node*2+2, m, R);

	dat[node].resize(SZ(dat[node*2+1])+SZ(dat[node*2+2]));
	merge(ALL(dat[node*2+1]), ALL(dat[node*2+2]), dat[node].begin());
	return;
}

int calc(int A, int B, int x, int node, int L, int R){
	if(
}

int main() {
    cin >> n >> m;
	REP(i, n) scanf("%d", &a[i]);
	REP(i, 400040) dat[i].clear();
	init(0, 0, n);

	REP(i, m){
		scanf("%d %d %d", &I, &J, &K);
		I--; J--;
		printf("%d\n", calc(I, J, K, 0, 0, n));
	}
    return 0;
}