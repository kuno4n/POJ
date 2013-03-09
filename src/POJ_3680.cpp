
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

const int MAX_N = 200;
const int MAX_K = 200;
int N, K;
int a[MAX_N];
int b[MAX_N];
int w[MAX_N];

typedef pair<int, int> P;
struct edge {int to, cap, cost, rev;};
const int MAX_V = MAX_N*2 + 2;

int V; // Vは別途忘れずに設定すること。「最後のノード番号＋１」であることに注意。sinkと同じ数ではない。sink+1。
vector <edge> G[MAX_V]; // 使い回す場合は、Gも忘れず初期化すること
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
        cin >> N >> K;
        REP(i, N) cin >> a[i] >> b[i] >> w[i];
        VI point;
        REP(i, N){
            point.push_back(a[i]);
            point.push_back(b[i]);
        }
        sort(ALL(point));
        point.erase(unique(ALL(point)), point.end());
        int m = SZ(point);
        int s = m;
        int t = s + 1;
        V = t + 1;
        
        REP(i, V) G[i].clear();
        FOR(i, 1, m) add_edge(i-1, i, INF, 0);
        add_edge(s, 0, K, 0);
        add_edge(m-1, t, K, 0);
        
        REP(i, N){
            int u = find(ALL(point), a[i]) - point.begin();
            int v = find(ALL(point), b[i]) - point.begin();
            add_edge(v, u, 1, w[i]);
            add_edge(s, v, 1, 0);
            add_edge(u, t, 1, 0);
        }
        int res = min_cost_flow(s, t, K+N);
        REP(i, N) res -= w[i];
        cout << -res << endl;
        

    }
    

    
    return 0;
}



