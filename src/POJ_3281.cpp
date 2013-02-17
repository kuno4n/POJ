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

#define INF (1<<30) - 1

const int MAX_V = 410;

struct edge {int to, cap, rev;};
vector <edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f){
    if (v == t) return f;
    used[v] = true;
    for(int i = 0; i < SZ(G[v]); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}





int N, F, D;
bool Flike[110][110], Dlike[110][110];

int main() {
    cin >> N >> F >> D;
    MSET(Flike, false);
    MSET(Dlike, false);
    REP(i, N){
        int Fi, Di;
        cin >> Fi >> Di;
        REP(j, Fi){
            int food;
            cin >> food;
            food--;
            Flike[i][food] = true;
        }
        REP(j, Di){
            int drink;
            cin >> drink;
            drink--;
            Dlike[i][drink] = true;
        }
    }
    
    REP(i, N) add_edge(i, i+N, 1);
    
    REP(i, N){
        REP(j, F){
            if(Flike[i][j]){
                add_edge(N*2 + j, i, 1);
            }
        }
    }
    
    REP(i, N){
        REP(j, D){
            if(Dlike[i][j]){
                add_edge(N+i, N*2+F+j, 1);
            }
        }
    }
    
    int source = N*2+F+D;
    int sink = N*2+F+D+1;
    REP(i, F) add_edge(source, N*2+i, 1);
    REP(i, D) add_edge(N*2+F+i, sink, 1);
    
    cout << max_flow(source, sink) << endl;
    
    return 0;
}