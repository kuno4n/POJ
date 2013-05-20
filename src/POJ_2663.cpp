#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
//#include <sys/time.h>
#include <fstream>
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
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())


LL dp[32][8];
int n;

bool can(int a, int b){
	bool res = true;
	int c = a|b;
	if(c != (a^b)) res = false;
	int ren = 0;
	REP(j, 4){
		if(j == 3 || (c&(1<<j))){
			if(ren&1) res = false;
			ren = 0;
		}
		else ren++;
	}
	return res;
}

void init() {
	REP(i, 32) REP(j, (1<<3)) dp[i][j] = 0;
	dp[0][0] = 1;
	REP(i, 30) REP(j, (1<<3)) if(dp[i][j] > 0){
		REP(k, (1<<3)) if(can(j, k)) dp[i+1][k] += dp[i][j];
	}
}

void input() {
}

void solve() {
	cout << dp[n][0] << endl;
}

int main() {
	init();
    input();
    while(cin >> n){
		if(n == -1) break;
		solve();
	}
	return 0;
}






