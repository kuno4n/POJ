
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

    const int MAX_V = 10000;
    
    int V;
    VI G[MAX_V];
    VI rG[MAX_V];
    VI vs;
    bool used[MAX_V];
    int cmp[MAX_V];
    
    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }
    
    void dfs(int v){
        used[v] = true;
        REP(i, SZ(G[v])) if(!used[G[v][i]]) dfs(G[v][i]);
        vs.push_back(v);
    }
    
    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        REP(i, SZ(rG[v])) if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }

	
    
    // ‹­˜AŒ‹¬•ª‚Ì”‚ð‚Â‚¢‚Å‚É•Ô‚·B
    int scc(){
        MSET(used, false);
        vs.clear();
        int k = 0;
        REP(v, V) if(!used[v]) dfs(v);
        MSET(used, false);
        for(int i = SZ(vs) - 1; i >= 0; i--)
            if(!used[vs[i]]) rdfs(vs[i], k++);
        return k;
    }

	
	int cnt = 0;
	void rdfs2(int v){
        used[v] = true;
		cnt++;
        REP(i, SZ(rG[v])) if(!used[rG[v][i]]) rdfs2(rG[v][i]);
    }

int N, M;

int main() {
	cin >> N >> M;
	V = N;

	REP(i, M){
		int a, b;
		cin >> a >> b;
		a--; b--;
		add_edge(a, b);
	}

	int k = scc();
	int v = -1;
	REP(i, V) if(cmp[i] == k-1){
		v = i;
		break;
	}
	MSET(used, false);
	rdfs2(v);
	int res = 0;
	if(cnt == V){
		REP(i, V) if(cmp[i] == k-1) res++;
	}
	cout << res << endl;

	return 0;
}
