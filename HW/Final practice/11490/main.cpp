#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Cat
{
    Cat(string n, int j, int a):name(n), occupation(j), age(a){}
    string name;
    int occupation;
    int age;
};

bool compare(const Cat* a, const Cat* b)
{
    if(a->occupation != b->occupation)
        return a->occupation < b->occupation;
    else if(a->age != b->age){
        if(a->occupation == 5)
            return a->age < b->age;
        else
            return a->age > b->age;
    }
    else{
        return a->name < b->name;
    }
}

int main()
{
    map<string,int> jobMap;
    jobMap["elder"] = 1;
    jobMap["nursy"] = 2;
    jobMap["kitty"] = 3;
    jobMap["warrior"] = 4;
    jobMap["apprentice"] = 5;
    jobMap["medicent"] = 6;
    jobMap["deputy"] = 7;
    jobMap["leader"] = 8;

    int n;      //n cats
    int food;   //portions of food
    vector<Cat*> vecCat;
    string name;
    string job;
    int occupation;
    int age;

    while(cin >> n >> food){
        vecCat.reserve(n);
        for(int i = 0; i < n; i++){
            cin >> name >> job >> age;
            occupation = jobMap[job];
            vecCat.push_back(new Cat(name, occupation, age));
        }
        sort(vecCat.begin(), vecCat.end(), compare);

        if(food < n){
            vector<Cat*>::iterator it = vecCat.begin();
            while(food--){
                cout << (*it)->name << '\n';
                //printf("%s\n", (*it)->name.c_str());
                it++;
            }
        }
        else{
            for(auto i : vecCat)
                cout << i->name << '\n';
                //printf("%s\n", i->name.c_str());
        }
        vecCat.clear();
    }
}
