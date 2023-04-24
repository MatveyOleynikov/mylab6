#include <iostream>
#include <numeric>
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

#define all(a)     a.begin(), a.end()
#define sum(a)     ( accumulate (all(a), 0ll))
#define mine(a)    (*min_element(all(a)))
#define maxe(a)    (*max_element(all(a)))
#define mini(a)    ( min_element(all(a)) - (a).begin())
#define maxi(a)    ( max_element(all(a)) - (a).begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
//both
using vi = vector<int>;
using ls = list<short>;
using vvs = vector<vector<short>>;

template<typename T>
istream& operator>>(istream& o, vector<T> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        o >> a[i];
    }
    return o;
}

template<typename T>
ostream& operator<<(ostream& o, const vector<T> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        o << a[i] << " ";
    }
    o << '\n';
    return o;
}

void nothing(){

}

struct directedGraph{
    int n;
    int m;
    vector<vector<int>> listAdjacency;

    directedGraph(const int n, const int m, const vector<pair<int, int>>& edjes): n(n), m(m){
        listAdjacency.resize(n);

        for (int i = 0; i < m; ++i){
            listAdjacency[edjes[i].first].push_back(edjes[i].second);
        }
    }

    directedGraph backGraph() const{
        vector<pair<int, int>> edjes;
        for (int u = 0; u < n; ++u){
            for (auto v: listAdjacency[u]){
                edjes.push_back({v, u});
            }
        }

        directedGraph res(n, m, edjes);

        return res;
    }

    //common
    int countNeighbours(int u) const{
        return listAdjacency[u].size();
    }
};

int main(){
    vvi vct = {{1, 2}, {3, 4}};

    int a = 5;

    dbg(vct, a);
    dbg(sum(vct[0]));
    return 0;
}
