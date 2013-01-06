
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

vector <string> s;
int n, m;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x, int y){
    s[x][y] = '.';
    REP(i, 8){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == 'W') dfs(xx, yy);
    }
    return;
}

int main() {
    cin >> n >> m;
    s.clear();
    REP(i, n){
        string str;
        cin >> str;
        s.push_back(str);
    }
    int res =0 ;
    REP(i, n){
        REP(j, m){
            if(s[i][j] == 'W'){
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
