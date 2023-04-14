#include <iostream>
#include <vector>

using namespace std;

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

int main(){
    vector<vector<int>> vct = {{1, 2}, {3, 4}};

    printVectorVector(vct);

    return 0;
}
