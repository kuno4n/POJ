
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

const int MAX_V = 400;

int V;
VI G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].PB(v);
    G[v].PB(u);
}

bool dfs(int v){
    used[v] = true;
    REP(i, SZ(G[v])){
        int u = G[v][i], w = match[u];
        if(w < 0 || (!used[w] && dfs(w))){
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

bool GG[200][200];

int main() {
    for(int c = 1; ; c++){
        int g, b, m;
        cin >> g >> b >> m;
        if(g == 0) break;
        V = g;
        REP(i, 200) REP(j, 200) GG[i][j] = false;
        REP(i, m){
            int u, v;
            cin >> u >> v;
            u--; v--;
            GG[u][v] = true;
        }
        REP(i, MAX_V) G[i].clear();
        REP(u, g) REP(v, b) if(!GG[u][v]) add_edge(u, v+200);
        cout << "Case " << c << ": " << g+b - bipartite_matching() << endl;
    }

    
    return 0;
}



