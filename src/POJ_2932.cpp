
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

const int MAX_N = 40000;
double R[MAX_N], x[MAX_N], y[MAX_N];
int N;

bool contain(int s1, int s2){
    return (x[s1]-x[s2])*(x[s1]-x[s2]) + (y[s1]-y[s2])*(y[s1]-y[s2]) <= R[s1]*R[s1];
}

int main() {
    cin >> N;
    REP(i, N) scanf("%lf %lf %lf", R+i, x+i, y+i);

    VI res;
    
    vector < pair<double, int> > point(N*2); // x, id
    set < pair<double, int> > outer; //y, id;
    
    REP(i, N){
        point[i*2] = make_pair(x[i] - R[i], i);
        point[i*2+1] = make_pair(x[i] + R[i], i+N);
    }
    sort(ALL(point));
    
    REP(i, SZ(point)){
        pair<double, int> p = point[i];
        int id = p.second % N;
        pair<double, int> py = make_pair(y[id], id);
        if(p.second < N){
            set < pair<double, int> >::iterator it = outer.lower_bound(py);
            if(it != outer.end()){
                if(contain((*it).second, id)) continue;
            }
            if(it != outer.begin()){
                if(contain((*(--it)).second, id)) continue;
            }
            outer.insert(py);
            res.push_back(id);
        }
        else{
            outer.erase(py);
        }
    }
    
    sort(ALL(res));
    cout << SZ(res) << endl;
    REP(i, SZ(res)) printf("%d%c", res[i]+1, (i == SZ(res)-1 ? '\n' : ' '));
    
    return 0;
}



