
#ifndef SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H
#define SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H


#include "iostream"
#include <bits/stdc++.h>
using namespace std;
class symptoms_matrix {
public:
    set<string>symptoms;
    set<string>diseases_set;
    map<string , int>numbered_diseases;
    map<int, string>named_diseases;
    map<string , int>numbering_symptoms;
    map<int, set<string>>symptoms_diseases;
    vector<vector<string>>diseases_symptoms;

    __attribute__((unused)) vector<vector<int>> number_matrix(ifstream& in);

    __attribute__((unused)) const set<string> &getSymptoms() const;

    __attribute__((unused)) const set<string> &getDiseasesSet() const;

    __attribute__((unused)) const map<string, int> &getDiseases() const;

    __attribute__((unused)) const map<string, int> &getNumberingSymptoms() const;

    __attribute__((unused)) const vector<vector<string>> &getDiseasesSymptoms() const;

    __attribute__((unused)) const map<int, string> & getNamedDiseases()const;

    __attribute__((unused)) static vector<vector<int>> sort_matrix(vector<vector<int>>&);

    __attribute__((unused)) void fun(ifstream &in);
};


#endif //SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H
