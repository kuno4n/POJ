
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

int gr[210][210];

int grundy(int w, int h){
    if(gr[w][h] != -1) return gr[w][h];
    
    bool s[40010];
    fill(s, s+40010, false);
    for(int i=2; i <= w-2; i++) s[grundy(i, h) ^ grundy(w-i, h)] = true;
    for(int i=2; i <= h-2; i++) s[grundy(w, i) ^ grundy(w, h-i)] = true;
    
    int res = 0;
    while(s[res]) res++;
    return gr[w][h] = res;
}

//int grundy(int w, int h)
//{
//    if (gr[w][h] != -1) {
//        return gr[w][h];
//    }
//    bool s[210];
//    fill_n(s, 210, false);
//    for (int k = 2; w-k >= 2; k++) {
//        s[grundy(w-k, h) ^ grundy(k, h)] = true;
//    }
//    for (int k = 2; h-k >= 2; k++) {
//        s[grundy(w, h-k) ^ grundy(w, k)] = true;
//    }
//    int n = 0;
//    for (; s[n]; n++);
//    return gr[w][h] = n;
//}


int main() {
    int w, h;
    REP(i, 210) REP(j, 210) gr[i][j] = -1;
//    gr[2][2] = gr[2][3] = gr[3][2] = 0;
//    grundy(200, 200);
    while(scanf("%d %d", &w, &h)  != EOF){
        if(grundy(w, h) == 0) puts("LOSE");
        else puts("WIN");
    }

    
    return 0;
}

//int main()
//{    int W, H;
//    while (scanf("%d %d", &W, &H) != EOF) {
//        for (int i = 0; i < 210; i++) {
//            fill_n(gr[i], 210, -1);
//        }
//        gr[2][2] = 0;
//        gr[3][2] = gr[2][3] = 0;
//
//        puts(grundy(W, H) == 0 ? "LOSE" : "WIN");
//    }
//    return 0;
//}


