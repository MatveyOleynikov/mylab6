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
};

int main(){
    vector<vector<int>> vct = {{1, 2}, {3, 4}};

    printVectorVector(vct);

    int a = 5;

    dbg(a);
    return 0;
}
