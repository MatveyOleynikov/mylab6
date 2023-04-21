#include <iostream>
#include <vector>

using namespace std;

#ifdef MATVEY
#define dbg(x) do { cout << __LINE__ << ": " << #x << " = " << x << endl;} while (0)
#else
#define dbg(x)
#endif

void printVector(const vector<int>& vec){
    for (auto elem: vec){
        cout << elem << " ";
    }
    cout << "\n";
}

void printVectorVector(const vector<vector<int>>& vecVec){
    for (auto vec: vecVec){
        for (auto elem: vec){
            cout << elem << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

struct tree{
    int n;
    int m;
    vector<vector<int>> listAdjacency;

    //common
    bool cycle(const int pred, const int cur, vector<bool>& visited) const{
        if (visited[cur]){
            return true;
        }

        visited[cur] = true;
        bool res;

        for (auto nxt: listAdjacency[cur]){
            if (nxt != pred){
                cycle(cur, nxt, visited);
            }
        }
    }

    //only for tree
    void numberOfDescendants(int cur, int pred, vector<int>& numberDescandants){
        numberDescandants[cur] = 1;
        for (auto nxt: listAdjacency[cur]){
            if (nxt != pred){
                numberOfDescendants(nxt, cur, numberDescandants);
                numberDescandants[cur] += numberDescandants[nxt];
            }
        }
    }

    tree(const int n, const int m, const vector<pair<int, int>>& edjes): n(n), m(m){
        listAdjacency.resize(n);

        for (int i = 0; i < m; ++i){
            listAdjacency[edjes[i].first].push_back(edjes[i].second);
            listAdjacency[edjes[i].second].push_back(edjes[i].first);
        }

        vector<bool> visited;
        if (cycle(0, -1, visited)){
            exit(1);
        }
    }
};

int main(){
    vector<vector<int>> vct = {{1, 2}, {3, 4}};

    printVectorVector(vct);

    int a = 5;

    dbg(a);
    return 0;
}
