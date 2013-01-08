
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


struct edge{int u, v, cost;};
edge E[50010];
vector<int> par; 
vector<int> rank; 

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

void init(int n){
	par.clear();
	rank.clear();
	for(int i=0; i<n; i++){
		par.push_back(i);
		rank.push_back(0);
	}
}
int find(int x){
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}
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
bool same(int x, int y){
	return find(x) == find(y);
}


LL n, m, r;

LL kruskal(){
	LL res = 0;
	init(20010);
	REP(i, r){
		if(same(E[i].u, E[i].v)) continue;
		res += E[i].cost;
		unite(E[i].u, E[i].v);
	}
	return res;
}

int main() {
	LL c;
	cin >> c;
	REP(_case, c){
		cin >> n >> m >> r;
		int x, y, d;
		REP(i, r) {
			scanf("%d %d %d", &x, &y, &d);
			edge e = {x, n+y, (-d)};
			E[i] = e;
		}
		sort(E, E+r, comp);

		cout << (n+m)*10000 + kruskal() << endl;
	}



	return 0;
}
