#include <iostream>
#include <bits/stdc++.h>
#include "K_means.h"

using namespace std;

vector<set<string>> clusters(vector<vector<int>> disease_symptoms_vector, K_means *k, ifstream &in);

int main() {
    ifstream in("dataset.txt");
    K_means *k = new K_means();
    vector<set<string>>clustering = clusters(k->disease_symptoms, k, in);
    for (auto cl: clustering) {
        for (auto s: cl) {
            cout << s << " ------ ";
        }
        cout << endl << endl << endl;
    }
    return 0;
}

vector<set<string>> clusters(vector<vector<int>> disease_symptoms_vector, K_means *k, ifstream &in) {
    vector<int> c1 = {43, 44, 57, 58, 61, 62, 88, 98, 108, 114};
    vector<int> c2 = {0, 30, 36, 39, 40, 52, 63, 68, 90, 125};
    vector<int> c3 = {8, 16, 23, 42};
    vector<int> c4 = {7, 84, 93, 98};
    vector<int> c5 = {43, 59, 69, 101, 118, 120};
    vector<vector<int>> centroids = {c1, c2, c3, c4, c5};
    map<vector<int>, int> mp = k->disease_symptoms_map(std::move(disease_symptoms_vector));
    map<int, vector<vector<int>>> mapping = k->calculate_centroids(centroids, 2); //checked for correctness
    k->symptomsMatrix->fun(in);
    map<int, set<string>> s_d = k->symptomsMatrix->symptoms_diseases;
    vector<set<string>> clustering;
    for (auto it: mapping) {
        set<string> cluster;
        for (auto vec: it.second) {
            int sum = 0;
            set<string> st;
            for (auto v: vec) {
                sum += v;
            }
            st = s_d[sum];
            for (auto it: st) {
                cluster.insert(it);
            }
        }
        clustering.push_back(cluster);
    }
    return clustering;
}
