#include "K_means.h"

K_means::K_means() {
    symptomsMatrix = new symptoms_matrix();
    ifstream in("dataset.txt");
    euclidian_matrix = symptomsMatrix->number_matrix(in);
    disease_symptoms = euclidian_matrix;
    symptoms_matrix::sort_matrix(euclidian_matrix);
}

double K_means::calculate_distance(const vector<int> &seed, const vector<int> &disease_symptoms) {
    //Using Manhattan Distance
    int n = min(seed.size(), disease_symptoms.size());
    double distance = 0;
    int i;
    for (i = 0; i < n; i++) {
        distance += abs(seed[i] - disease_symptoms[i]);
    }
    while (i < seed.size()) {
        distance++;
        i++;
    }
    while (i < disease_symptoms.size()) {
        distance++;
        i++;
    }
    return distance;
}

__attribute__((unused)) map<int, vector<vector<int>>> K_means::calculate_centroids(vector<vector<int>> &centroids, int iterations) {
    map<int, vector<vector<int>>> centroid_classes;
    while (iterations--) {
        for (const auto &vec: euclidian_matrix) {
            double distance = INT_MAX;
            unordered_map<int, vector<int>> mp;
            double center_distance = 0;
            int i;
            int centroid_num = 1;
            for (i = 0; i < centroids.size(); i++) {
                center_distance = calculate_distance(centroids[i], vec);
                if (center_distance < distance) {
                    distance = center_distance;
                    centroid_num = i + 1;
                    mp[centroid_num] = vec;
                }
            }
            centroid_classes[centroid_num].push_back(vec);
        }
        centroids = set_new_centroids(centroids, centroid_classes);
        if (iterations > 0)
            centroid_classes.clear();
    }
    return centroid_classes;
}

vector<vector<int>> K_means::set_new_centroids(const vector<vector<int>>& centroids, map<int, vector<vector<int>>> &matrix) {
    vector<vector<int>> new_centroids(5);
    int centroid_num = 0;
    for (auto it: matrix) {
        int n = INT_MAX;
        int n2 = INT_MIN;
        for (auto &vec: it.second) {
            int s = vec.size();
            n = min(n, s);
            n2 = max(n2, s);
        }
        vector<int> c(n, 0);
        int j = 0;
        vector<int> divisors(n);
        for (auto &vec: it.second) {
            for (int i = 0; i < n; i++) {
                c[i] += vec[i];
                j++;
                divisors[i]++;
            }
            j = 0;
        }
        int k = 0;
        for (auto &v: c) {
            v = v / divisors[k++];
        }
        for (; j < n2; j++) {
            c.push_back(1);
        }
        new_centroids[centroid_num++] = c;
    }
    return new_centroids;
}

map<vector<int>, int> K_means::disease_symptoms_map(vector<vector<int>> vec) {
    map<vector<int>, int> mp;
    int i = 0;
    for (auto v: vec) {
        mp[v] = i++;
    }
    return mp;
}

