
#ifndef SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H
#define SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H


#include "iostream"
#include <bits/stdc++.h>
using namespace std;
class symptoms_matrix {
public:
    vector<vector<int>> number_matrix(ifstream& in);
private:
public:
    const set<string> &getSymptoms() const;

    const set<string> &getDiseasesSet() const;

    const map<string, int> &getDiseases() const;

    const map<string, int> &getNumberingSymptoms() const;

    const vector<vector<string>> &getDiseasesSymptoms() const;

    const map<int, string> & getNamedDiseases()const;
private:
    set<string>symptoms;
    set<string>diseases_set;
    map<string , int>numbered_diseases;
    map<int, string>named_diseases;
    map<string , int>numbering_symptoms;
    vector<vector<string>>diseases_symptoms;


};


#endif //SYMPTOMS_CLUSTERING_SYMPTOMS_MATRIX_H
