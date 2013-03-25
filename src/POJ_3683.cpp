
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
#include <iomanip>
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

const int MAX_V = 2000;

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

// 強連結成分の数をついでに返す。
// 強連結成分の１番末尾の番号（cmp[]に入ってる）は、k-1なので注意。
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

int n;
int s[1000], t[1000], d[1000];

int main() {
    cin >> n;
    REP(i, n){
        int sh, sm, th, tm, dm;
        scanf("%d:%d %d:%d %d", &sh, &sm, &th, &tm, &dm);
        s[i] = sh * 60 + sm;
        t[i] = th * 60 + tm;
        d[i] = dm;
    }
    
    V = n * 2;
    
    REP(i, n){
        for(int j = i+1; j < n; j++){
            int i1 = s[i];
            int i2 = s[i] + d[i];
            int i3 = t[i] - d[i];
            int i4 = t[i];
            int j1 = s[j];
            int j2 = s[j] + d[j];
            int j3 = t[j] - d[j];
            int j4 = t[j];
            
            if(j1 < i2 && i1 < j2){
                add_edge(i, j+n);
                add_edge(j, i+n);
            }
            if(j1 < i4 && i3 < j2){
                add_edge(i+n, j+n);
                add_edge(j, i);
            }
            if(j3 < i2 && i1 < j4){
                add_edge(i, j);
                add_edge(j+n, i+n);
            }
            if(j3 < i4 && i3 < j4){
                add_edge(i+n, j);
                add_edge(j+n, i);
            }
        }
    }
    
    scc();
    
    REP(i, n) if(cmp[i] == cmp[i+n]){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, n){
        int hh1, mm1, hh2, mm2;
        string shh1, smm1, shh2, smm2;
        if(cmp[i] > cmp[i+n]){
            hh1 = s[i] / 60;
            mm1 = s[i] % 60;
            hh2 = (s[i] + d[i]) / 60;
            mm2 = (s[i] + d[i]) % 60;
        }
        else{
            hh1 = (t[i] - d[i]) / 60;
            mm1 = (t[i] - d[i]) % 60;
            hh2 = t[i] / 60;
            mm2 = t[i] % 60;
        }
        stringstream ss;
        ss << setw(2) << setfill('0') << hh1;
        ss >> shh1;
        stringstream ss2;
        ss2 << setw(2) << setfill('0') << mm1;
        ss2 >> smm1;
        stringstream ss3;
        ss3 << setw(2) << setfill('0') << hh2;
        ss3 >> shh2;
        stringstream ss4;
        ss4 << setw(2) << setfill('0') << mm2;
        ss4 >> smm2;
        
        cout << shh1 << ":" << smm1 << " " << shh2 << ":" << smm2 << endl;


    }


    return 0;
}



