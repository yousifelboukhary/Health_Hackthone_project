#include "symptoms_matrix.h"

__attribute__((unused)) vector<vector<int>> symptoms_matrix::number_matrix(ifstream &in) {
    string s;
    getline(in, s);
    while (getline(in, s)) {
        if (s.empty())
            continue;
        stringstream symptom_set_one(s);
        string str;
        vector<string> vec;
        bool flag = true;
        while (getline(symptom_set_one, str, ',')) {
            if (str.size() > 0) {
                for_each(str.begin(), str.end(), [](char &c) {
                    c = ::tolower(c);
                });
                if (flag) {
                    flag = false;
                    diseases_set.insert(str.substr(1, str.size()));
                    continue;
                }
                vec.push_back(str.substr(1, str.size()));
                symptoms.insert(str.substr(1, str.size()));
            }
        }
        diseases_symptoms.push_back(vec);
    }
    int i;
    //calculation euclidean distance between symptoms
    i = -1;
    for (const auto &symptom: symptoms) {
        if (i == -1) {
            i++;
            continue;
        }
        numbering_symptoms[symptom] = i++;
    }
    i = 0;
    for (const auto &disease: diseases_set) {
        numbered_diseases[disease] = i;
        named_diseases[i++] = disease;
    }
    i = 0;

    vector<vector<int>> euclidian_matrix(diseases_symptoms.size());
    for (auto vec: diseases_symptoms) {
        vector<int> v;
        int j = 0;
        v.resize(vec.size());
        for (const auto &str: vec) {
            v[j++] = numbering_symptoms[str];
        }
        euclidian_matrix[i++] = v;
    }

    return euclidian_matrix;
}

__attribute__((unused)) void symptoms_matrix::fun(ifstream &in) {
    string s2;
    getline(in, s2);
    while (getline(in, s2)) {
        int weight = 0;
        if (s2.empty())
            continue;
        stringstream symptom_set_one(s2);
        string str;
        vector<string> vec;
        bool flag = true;
        string dis_name;
        while (getline(symptom_set_one, str, ',')) {
            if (str.size() > 0) {
                for_each(str.begin(), str.end(), [](char &c) {
                    c = ::tolower(c);
                });
                if (flag) {
                    flag = false;
                    dis_name = str.substr(0, str.size());
                    continue;
                }
                weight += numbering_symptoms[str.substr(1, str.size())];
            }
        }
        symptoms_diseases[weight].insert(dis_name);
    }
}

__attribute__((unused)) const set<string> &symptoms_matrix::getSymptoms() const {
    return symptoms;
}

__attribute__((unused)) const set<string> &symptoms_matrix::getDiseasesSet() const {
    return diseases_set;
}

__attribute__((unused)) const map<string, int> &symptoms_matrix::getDiseases() const {
    return numbered_diseases;
}

__attribute__((unused)) const map<string, int> &symptoms_matrix::getNumberingSymptoms() const {
    return numbering_symptoms;
}

__attribute__((unused)) const vector<vector<string>> &symptoms_matrix::getDiseasesSymptoms() const {
    return diseases_symptoms;
}

__attribute__((unused)) const map<int, string> &symptoms_matrix::getNamedDiseases() const {
    return named_diseases;
}

__attribute__((unused)) vector<vector<int>> symptoms_matrix::sort_matrix(vector<vector<int>> &vec_tor) {
    for (auto &vec: vec_tor) {
        std::sort(vec.begin(), vec.end());
    }
    return vec_tor;
}


