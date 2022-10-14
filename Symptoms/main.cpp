#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    set<string>symptoms;
    ifstream in(R"(C:\Users\lenovo\Documents\GitHub\Health_Hackthone_project\dataset - Copy.txt)");
    string s;
    getline(in , s);
    while(getline(in, s)) {
        stringstream symptom_set_one(s);
        string str;
        bool flag = true;
        while (getline(symptom_set_one, str, ',')) {
            if(flag){
                flag = false;
                continue;
            }
            symptoms.insert(str);
        }
    }
    ofstream out(R"(C:\Users\lenovo\Documents\GitHub\Health_Hackthone_project\symptoms_list.txt)");
    int i=1;
    bool flag = true;
    for(const auto & symptom : symptoms){
        if(flag){
            flag = false;
            continue;
        }
        out<<"symptom "<< i++ << " : "<<symptom<<endl;
    }
    return 0;
}
