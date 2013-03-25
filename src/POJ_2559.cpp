
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

int n, h[100000], L[100000], R[100000], st[100000];

int main() {
	while(1){
		cin >> n;
		if(n == 0) break;
		REP(i, n) scanf("%d", &h[i]);

		int stcnt = 0;
		REP(i, n){
			while(stcnt > 0 && h[st[stcnt-1]] >= h[i]) stcnt--;
			if(stcnt == 0) L[i] = 0;
			else L[i] = st[stcnt-1] + 1;
			st[stcnt++] = i;
		}
		stcnt = 0;
		for(int i = n-1; i >= 0; i--){
			while(stcnt > 0 && h[st[stcnt-1]] >= h[i]) stcnt--;
			if(stcnt == 0) R[i] = n;
			else R[i] = st[stcnt-1];
			st[stcnt++] = i;
		}

		LL res = 0;
		REP(i, n) res = max(res, (LL)h[i] * (R[i] - L[i]));
		cout << res << endl;
	}



	return 0;
}
