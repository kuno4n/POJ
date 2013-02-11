
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

int V;
VI G[1010];
int match[1010];
bool used[1010];

void add_edge(int u, int v){
    G[u].PB(v);
    G[v].PB(u);
}

bool dfs(int v){
    used[v] = true;
    REP(i, SZ(G[v])){
        int u = G[v][i], w = match[u];
        if(w < 0 || !used[w] && dfs(w)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int res = 0;
    MSET(match, -1);
    REP(v, V){
        if(match[v] < 0){
            MSET(used, 0);
            if(dfs(v)) res++;
        }
    }
    return res;
}


int main() {
    cin >> V;
    V *= 2;
    int k;
    cin >> k;
    REP(i, k){
        int u, v;
        cin >> u >> v;
        u--; v--;
        v += (V/2);
        add_edge(u, v);
    }
    cout << bipartite_matching() << endl;
    return 0;
}



