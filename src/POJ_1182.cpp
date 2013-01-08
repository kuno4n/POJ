
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

vector<int> par;  //親
vector<int> rank; //木の深さ
// n要素で初期化
void init(int n){
    par.clear();
    rank.clear();
    for(int i=0; i<n; i++){
        par.push_back(i);
        rank.push_back(0);
    }
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を結合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
//xとyが同じ集合に属するか
bool same(int x, int y){
    return find(x) == find(y);
}

int main() {
    int n, k;
    cin >> n >> k;
    init(n*3+1);
    int res = 0;
    REP(i, k){
        int d, x, y;
        scanf("%d %d %d", &d, &x, &y);
        if(x>n || y>n){
            res++;
            continue;
        }
        if(d==1){
            if(same(x,y+n) || same(x, y+2*n)){
                res++;
                continue;
            }
            unite(x, y);
            unite(x+n, y+n);
            unite(x+n*2, y+n*2);
            continue;
        }
        if(d==2){
            if(same(x, y) || same(x, y+n*2)){
                res++;
                continue;
            }
            unite(x, y+n);
            unite(x+n, y+n*2);
            unite(x+n*2, y);
            continue;
        }
    }
    cout << res;
    

    
    return 0;
}
