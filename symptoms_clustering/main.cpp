#include <iostream>
#include <bits/stdc++.h>
#include "symptoms_matrix.h"
using namespace std;
int main() {
    symptoms_matrix *s = new symptoms_matrix() ;
    ifstream in(R"(C:\Users\lenovo\Documents\GitHub\Health_Hackthone_project\K-means\dataset.txt)");
    vector<vector<int>>euclidian_matrix = s->number_matrix(in);
    for(auto vec : euclidian_matrix){
        for(auto v: vec){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}
