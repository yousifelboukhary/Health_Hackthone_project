#ifndef SYMPTOMS_CLUSTERING_K_MEANS_H
#define SYMPTOMS_CLUSTERING_K_MEANS_H

#include <iostream>
#include "symptoms_matrix.h"

using namespace std;

class K_means {
public:
    vector<vector<int>> disease_symptoms;
    symptoms_matrix *symptomsMatrix;
    vector<vector<int>> euclidian_matrix;

    K_means();

    static double calculate_distance(const vector<int> &seed, const vector<int> &disease_symptoms);

    __attribute__((unused)) map<int, vector<vector<int>>> calculate_centroids(vector<vector<int>> &, int);

    static map<vector<int>, int> disease_symptoms_map(vector<vector<int>>);

private:
    static vector<vector<int>> set_new_centroids(const vector<vector<int>>&, map<int, vector<vector<int>>> &);
};

#endif //SYMPTOMS_CLUSTERING_K_MEANS_H
