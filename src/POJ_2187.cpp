
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
        double dot(P p){ // “àÏ
            return add(x*p.x, y*p.y);
        }
        double det(P p){ // ŠOÏ
            return add(x*p.y, -y*p.x);
        }
    };
    

	//Ž«‘‡‚Å”äŠr
	bool cmp_x(const P& p, const P& q){
		if(p.x != q.x) return p.x < q.x;
		return p.y < q.y;
	}
    
	//“Ê•ï‚ð‹‚ß‚éB
	//n‚Í—v‘f”B
	vector<P> convex_hull(P* ps, int n){
		sort(ps, ps+n, cmp_x);
		int k = 0;
		vector<P> qs(n*2);
		REP(i, n){
			while(k>1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
			qs[k++] = ps[i];
		}
		for(int i=n-2, t=k; i>=0; i--){
			while(k>t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
			qs[k++] = ps[i];
		}
		qs.resize(k-1);
		return qs;
	}

	// ‹——£‚Ì“ñæ
	double dist(P p, P q){
		return (p - q).dot(p - q);
	}


	
const int MAX_N = 50000;
int x[MAX_N], y[MAX_N], N;
P ps[MAX_N];

int main() {
	cin >> N;
	REP(i, N) scanf("%d %d", x + i, y + i);
	REP(i, N) ps[i] = P((double)x[i], (double)y[i]);
	vector<P> qs = convex_hull(ps, N);

	int res = 0;
	REP(i, SZ(qs)) REP(j, SZ(qs)) res = max(res, (int)dist(qs[i], qs[j]));
	cout << res << endl;

	return 0;
}
