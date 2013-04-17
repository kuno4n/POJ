
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

#define INF (1<<29)

int n;
string P[52], S;

set<string> s;
int K;
string st[1010];
bool ng[1010];
int next[1010][4];

string AGCT = "AGCT";

int dp[1010][1010];

int main() {
	int casenum = 1;

	while(1){
		cin >> n;
		if(n == 0) break;
		REP(i, n) cin >> P[i];
		cin >> S;

		s.clear();
		REP(i, n) for(int j = 0; j <= SZ(P[i]); j++) s.insert(P[i].substr(0, j));
		K = SZ(s);

		int ii = 0;
		for (set<string>::iterator it = (s).begin(); it != (s).end(); it++, ii++) st[ii] = *it;
		
		sort(st, st+K);
		REP(i, K) ng[i] = false;
		REP(i, K){
			REP(k, n){
				if(SZ(st[i]) >= SZ(P[k]) && P[k] == st[i].substr(SZ(st[i])-SZ(P[k]), SZ(P[k])))
					ng[i] = true;
			}
		}


		REP(i, K){
			REP(j, 4){
				string ss = st[i] + AGCT[j];
				int k;
				while(1){
					k = lower_bound(st, st+K, ss) - st;
					if(k < K && ss == st[k])break;
					ss = ss.substr(1);
				}
				next[i][j] = k;
			}
		}



		REP(i, 1010) REP(j, 1010) dp[i][j] = INF;
		dp[0][0] = 0;

		REP(i, SZ(S)){
			REP(j, K){
				if(ng[j]) continue;
				REP(k, 4){
					int nxt = next[j][k];
					dp[i+1][nxt] = min(dp[i+1][nxt], dp[i][j] + (S[i] == AGCT[k] ? 0 : 1));
				}
			}
		}

		int res = INF;
		REP(i, K) {
			if(ng[i]) continue;
			res = min(res, dp[SZ(S)][i]);
		}
		cout << "Case " << casenum++ << ": " << (res == INF ? -1 : res) << endl;
	}



	return 0;
}
