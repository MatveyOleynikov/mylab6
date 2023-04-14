#include <iostream>
#include <vector>

using namespace std;

#ifdef MATVEY
#define dbg(x) do { cout << __LINE__ << ": " << #x << " = " << x << endl;} while (0)
#else
#define dbg(x)
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

template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T>> & a)
{
    for (size_t i = 0; i < a.size(); ++i){
        for (size_t j = 0; j < a[i].size(); ++j){
            o << a[i][j] << " ";
        }
        o << "\n";
    }
    o << '\n';
    return o;
}

int main(){
    vector<vector<int>> vct = {{1, 2}, {3, 4}};

    dbg(vct);

    int a = 5;

    dbg(a);
    return 0;
}
