
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

int tcase, X, Y;
char field[12][12];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dist[12][12][12][12];

VI G[40000];
int match[40000];
bool used[40000];

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


void bdf(int x, int y, int d[12][12]){
    d[x][y] = 0;
    queue<int> qx, qy;
    qx.push(x);
    qy.push(y);
    while(SZ(qx)) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();
        REP(i, 4){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 && xx<X && yy>=0 && yy<Y && field[xx][yy]=='.' && d[xx][yy]<0){
                d[xx][yy] = d[x][y] + 1;
                qx.push(xx);
                qy.push(yy);
            }
        }
    }
    return ;
}

void solve(){
    int dnum, pnum;
    VI doorx, doory, perx, pery;
    MSET(dist, -1);
    dnum = 0; pnum = 0;
    REP(x, X) REP(y, Y) {
        if(field[x][y] == 'D'){
            bdf(x, y, dist[x][y]);
            dnum++;
            doorx.push_back(x);
            doory.push_back(y);
        }
        if(field[x][y] == '.'){
            pnum++;
            perx.push_back(x);
            pery.push_back(y);
        }
    }
    
    REP(i, 40000) G[i].clear();
    int maxt = X*Y;
    REP(i, pnum){
        REP(j, dnum){
            int time = dist[doorx[j]][doory[j]][perx[i]][pery[i]];
            if(time > 0){
                for(int t=time; t<=maxt; t++){
                    add_edge((t-1)*dnum + j, maxt*dnum + i);
                }
            }
        }
    }
    
    int matchnum = 0;
    MSET(match, -1);
    REP(time, maxt){
        for(int v=time*dnum; v<(time+1)*dnum; v++){
            if(match[v] < 0){
                MSET(used, 0);
                if(dfs(v)) matchnum++;
            }
        }
        if(matchnum == pnum){
            cout << time+1 << endl;
            return;
        }
    }
    
    cout << "impossible" << endl;
    
    return;
}

int main() {
    cin >> tcase;
    REP(c, tcase){
        cin >> X >> Y;
        REP(x, X){
            REP(y, Y){
                cin >> field[x][y];
            }
        }
        solve();
    }

    
    return 0;
}



