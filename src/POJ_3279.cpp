
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

//int m, n, cnt, mn;
int m, n;

void flip(int i, int j, int g[15][15]){
//    cnt++;
    g[i][j] ^= 1;
    if(i>0) g[i-1][j] ^= 1;
    if(i+1<m) g[i+1][j] ^= 1;
    if(j>0) g[i][j-1] ^= 1;
    if(j+1<n) g[i][j+1] ^= 1;
    return;
}


int main() {
    cin >> m >> n;
    int grid[15][15];
    REP(i, m) REP(j, n) cin >> grid[i][j];
//    int res[15][15] = {0};
//    bool can = false;
//    mn = 400;
    
    REP(mask, (1<<n)) {
//        cnt = 0;
        int g[15][15] = {0};
        int res[15][15] = {0};
        REP(i, m) REP(j, n) g[i][j] = grid[i][j];
        REP(i, n) if(mask & (1<<i)){
            flip(0, i, g);
            res[0][i] = 1;
        }
        FOR(i, 1, m) REP(j, n) if(g[i-1][j]){
            flip(i, j, g);
            res[i][j] = 1;
        }
        REP(i, m) REP(j, n) if(g[i][j]) goto lab;
        REP(i, m){
            REP(j, n){
                cout << res[i][j];
                if(j != n-1) cout << " ";
            }
            cout << endl;
        }
        return 0;
    lab:;
    }
    cout << "IMPOSSIBLE";

    
    return 0;
}

//int main() {
//    cin >> m >> n;
//    int grid[15][15];
//    REP(i, m) REP(j, n) cin >> grid[i][j];
//    int res[15][15] = {0};
//    bool can = false;
//    mn = 400;
//    
//    REP(mask, (1<<n)) {
//        cnt = 0;
//        int g[15][15] = {0};
//        int res_tmp[15][15] = {0};
//        REP(i, m) REP(j, n) g[i][j] = grid[i][j];
//        REP(i, n) if(mask & (1<<i)){
//            flip(0, i, g);
//            res_tmp[0][i] = 1;
//        }
//        FOR(i, 1, m) REP(j, n) if(g[i-1][j]){
//            flip(i, j, g);
//            res_tmp[i][j] = 1;
//        }
//        REP(i, m) REP(j, n) if(g[i][j]) goto lab;
//        can = true;
//        if(cnt < mn){
//            mn = cnt;
//            REP(i, m) REP(j, n) res[i][j] = res_tmp[i][j];
//        }
//    lab:;
//    }
//    if(!can) cout << "IMPOSSIBLE";
//    else{
//        REP(i, m){
//            REP(j, n){
//                cout << res[i][j];
//                if(j != n-1) cout << " ";
//            }
//            if(i != m-1) cout << endl;
//        }
//        
//    }
//    
//    
//    return 0;
//}

