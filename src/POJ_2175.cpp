
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

#define INF (1<<30) - 1;

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_V = MAX_N + MAX_M + 1;

int N, M;
int X[MAX_N], Y[MAX_N], B[MAX_N];
int P[MAX_M], Q[MAX_M], C[MAX_M];
int E[MAX_N][MAX_M];

int G[MAX_V][MAX_V];
int prev[MAX_V][MAX_V];
bool used[MAX_V];
int V;

int main() {
	cin >> N >> M;
	REP(i, N) cin >> X[i] >> Y[i] >> B[i];
	REP(i, M) cin >> P[i] >> Q[i] >> C[i];
	REP(i, N) REP(j, M) cin >> E[i][j];

	V = N+M+1;
	REP(i, V) REP(j, V) {
		if(i == j) G[i][j] = 0;
		else G[i][j] = INF;
	}
	REP(i, V) REP(j, V) prev[i][j] = i;

	REP(i, N) REP(j, M){
		int cost = abs(X[i]-P[j]) + abs(Y[i]-Q[j]) + 1;
		G[i][N+j] = cost;
	}
	REP(i, N) REP(j, M) if(E[i][j] > 0) {
		int cost = abs(X[i]-P[j]) + abs(Y[i]-Q[j]) + 1;
		G[N+j][i] = -cost;
	}
	REP(j, M){
		int c = 0;
		REP(i, N) c += E[i][j];
		if(c > 0) G[N+M][N+j] = 0;
		if(c < C[j]) G[N+j][N+M] = 0;
	}

	REP(k, V) REP(i, V) REP(j, V){
		if(G[i][j] > G[i][k] + G[k][j]){
			G[i][j] = G[i][k] + G[k][j];
			prev[i][j] = prev[k][j];
			if(i==j && G[i][i] < 0){
				fill(used, used+V, false);
				for(int v = i; !used[v]; v = prev[i][v]){
					used[v] = true;
					int vv = prev[i][v];
					if(vv < N && v != N+M) E[vv][v-N]++;
					else if(v < N && vv != N+M) E[v][vv-N]--;
				}
				cout << "SUBOPTIMAL" << endl;
				REP(i, N) REP(j, M) printf("%d%c", E[i][j], (j==M-1 ? '\n': ' '));
				return 0;
			}
		}
	}
	cout << "OPTIMAL" << endl;



	return 0;
}
