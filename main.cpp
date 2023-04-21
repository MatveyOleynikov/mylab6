#include <iostream>
#include <vector>

using namespace std;

#ifdef MATVEY
#define _dbg(x) do { cout << #x << "=" << x << "; "; } while (0)
#define _name(name, _1, _2, _3, _4, N, ...) name ## N
#define _dbg1(x) _dbg(x)
#define _dbg2(x, ...) _dbg(x); _dbg1(__VA_ARGS__)
#define _dbg3(x, ...) _dbg(x); _dbg2(__VA_ARGS__)
#define _dbg4(x, ...) _dbg(x); _dbg3(__VA_ARGS__)
#define dbg(...) do { cout << __LINE__ << ": "; _name(_dbg, __VA_ARGS__, 4, 3, 2, 1, 0)(__VA_ARGS__); cout << endl;} while (0)
#else
#define dbg(...)
#endif

template<typename T>
ostream& operator<<(ostream& o, const vector<T> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        o << a[i] << " ";
    }
    o << '\n';
    return o;
}

struct undirectedGraph{
    int n;
    int m;
    vector<vector<int>> listAdjacency;

    undirectedGraph(const int n, const int m, const vector<pair<int, int>>& edjes): n(n), m(m){
        listAdjacency.resize(n);

        for (int i = 0; i < m; ++i){
            listAdjacency[edjes[i].first].push_back(edjes[i].second);
            listAdjacency[edjes[i].second].push_back(edjes[i].first);
        }
    }
};


int main(){
    vector<vector<int>> vct = {{1, 2}, {3, 4}};

    int a = 5;

    dbg(vct, a);
    return 0;
}
