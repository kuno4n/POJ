
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

#define INF (1<<30)-1
const int MAX_V = 20010;

struct edge {int to, cap, rev;};
vector <edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(int s){
    MSET(level, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(SZ(que)){
        int v = que.front(); que.pop();
        REP(i, SZ(G[v])){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if (v == t) return f;
    for(int &i = iter[v]; i < SZ(G[v]); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
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
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}



int main() {
    int N, M;
    cin >> N >> M;
    
    REP(i, N){
        int A, B;
        scanf("%d %d", &A, &B);
        add_edge(N, i, B);
        add_edge(i, N+1, A);
    }
    REP(i, M){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        add_edge(a, b, w);
        add_edge(b, a, w);
    }
    cout << max_flow(N, N+1) << endl;

    
    return 0;
}



