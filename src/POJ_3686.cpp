
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

const int MAX_N = 50;
const int MAX_M = 50;

int Z[MAX_N][MAX_M];


typedef pair<int, int> P;
struct edge {int to, cap, cost, rev;};
const int MAX_V = MAX_N * MAX_M + MAX_N + 2;

int V;

vector <edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h+V, 0);
    while(f > 0){
//        fill(prevv, prevv+V, -1);
//        fill(preve, preve+V, -1);
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while(SZ(que)){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            REP(i, SZ(G[v])){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF) return -1;
        REP(v, V) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}


int main(){
    int tcase;
    cin >> tcase;
    
    REP(tc, tcase){
        int N, M;
        cin >> N >> M;
        REP(i, N) REP(j, M) cin >> Z[i][j];
        int s = N + N*M;
        int t = s + 1;
        
        REP(i, MAX_V) G[i].clear();
        V = t + 1;
        
        REP(i, N) add_edge(s, i, 1, 0);
        
        REP(i, N) REP(j, M) add_edge(N+j*N+i, t, 1, 0);
        
        REP(i, N) REP(j, N) REP(k, M) add_edge(i, N+k*N+j, 1, Z[i][k]*(j+1));
        
        
        printf("%.6f\n", (double)min_cost_flow(s, t, N)/N);
    }
    

    
    return 0;
}



