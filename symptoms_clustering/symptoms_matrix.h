//
// Created by lenovo on ١٥/١٠/٢٠٢٢.
//

#ifndef SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H
#define SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H


#include "iostream"
#include <bits/stdc++.h>
using namespace std;
class symptoms_matrix {
public:
    vector<vector<int>> number_matrix(ifstream& in);
private:
    set<string>symptoms;
    set<string>diseases_set;
    map<string , int>diseases;
    map<string , int>numbering_symptoms;
    vector<vector<string>>diseases_symptoms;


};


#endif //SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H
