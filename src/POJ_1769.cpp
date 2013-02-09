
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

const int INF = (1<<30) -1;

int tab[200040];

int get(int a, int b, int node, int left, int right){
    if(right <= a || b <= left) return INF;
    if(a <= left && right <= b) return tab[node];
    int m = (left + right) / 2;
    int la = get(a, b, node*2+1, left, m);
    int ra = get(a, b, node*2+2, m, right);
    return min(la, ra);
}

void update(int a, int x, int node, int left, int right){
    if(a < left || right <= a) return;
    if(left+1 == right) {
        tab[node] = min(x, tab[node]);
        return;
    }
    int m = (left+right)/2;
    update(a, x, node*2+1, left, m);
    update(a, x, node*2+2, m, right);
    tab[node] = min(tab[node*2+1], tab[node*2+2]);
}


int main() {
    fill(tab, tab+200040, INF);
    int n, m;
    cin >> n >> m;
    update(0, 0, 0, 0, n);
    REP(i, m){
        int ik, jk;
        scanf("%d %d", &ik, &jk);
        ik--; jk--;
        int mn = get(ik, jk+1, 0, 0, n);
//        OUT(mn);
        if(mn < INF){
            update(jk, mn+1, 0, 0, n);
        }
    }
    cout << get(n-1, n, 0, 0, n) << endl;

	return 0;
}
