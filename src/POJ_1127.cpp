
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

#define INF (1<<30) - 1;

double EPS = 1e-10;

double add(double a, double b){
    if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y){
    }
    P operator + (P p){
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p){
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d){
        return P(x*d, y*d);
    }
    double dot(P p){ // 内積
        return add(x*p.x, y*p.y);
    }
    double det(P p){ // 外積
        return add(x*p.y, -y*p.x);
    }
};

//線分p1-p2上に点qがあるか？
bool on_seg(P p1, P p2, P q){
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

//直線p1-p2と直線q1-q2の交点
//(q2-q1).det(p2-p1) = 0 のときは、２直線は平行。
P intersection(P p1, P p2, P q1, P q2){
    return p1 + (p2-p1) * ((q2-q1).det(q1-p1) / (q2-q1).det(p2-p1));
}



int n;
int x1[13], _y1[13], x2[13], y2[13];
bool G[13][13];

int main() {
    while(1){
        cin >> n;
        if(n == 0) break;
        REP(i, n){
            cin >> x1[i] >> _y1[i] >> x2[i] >> y2[i];
        }
        
        REP(i, n){
            G[i][i] = true;
            P p1(x1[i], _y1[i]);
            P p2(x2[i], y2[i]);
            REP(j, n){
                if(i == j) continue;
                P q1(x1[j], _y1[j]);
                P q2(x2[j], y2[j]);
                if((q2-q1).det(p2-p1) == 0){
                    G[i][j] = G[j][i] =
                    (on_seg(p1, p2, q1)
                     || on_seg(p1, p2, q2)
                     || on_seg(q1, q2, p1)
                     || on_seg(q1, q2, p2));
                }
                else{
                    P pp = intersection(p1, p2, q1, q2);
                    G[i][j] = G[j][i] = (on_seg(p1, p2, pp) && on_seg(q1, q2, pp));
                }
            }
        }
        
        REP(k, n) REP(i, n) REP(j, n) G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
        
        
        while(1){
            int a, b;
            cin >> a >> b;
            if(a == 0) break;
            cout << (G[a-1][b-1] ? "CONNECTED" : "NOT CONNECTED") << endl;
        }
        
    }
    
    
    
    
    
	return 0;
}



