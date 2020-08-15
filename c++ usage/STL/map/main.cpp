#include <iostream>
#include <map>

using namespace std;

int main()
{
    //data structure in map is a red-black tree
    //->sorted data, easy to insert, find, and delete(O(logN))
    //can't modify key
    map<string, string> mapStudent;
    mapStudent.insert(pair<string, string>("r000", "student_0"));
    mapStudent["r001"] = "student_1";   //also do insertion
    //if you insert a pair whose key is already in the map, nothing will be done

    map<string, string>::iterator iter;
    iter = mapStudent.find("r001");
    if(iter != mapStudent.end())
        cout << iter->first << " : " << iter->second << endl;
    else
        cout << "NOT FOUND" << endl;


    bool b = mapStudent.empty();
    if(mapStudent.erase("r000"))        //if not found, return 0
        cout << "r000 has been removed" << endl;
    else
        cout << "r000 not found in map" << endl;
    mapStudent.erase(mapStudent.begin(), mapStudent.end());
    mapStudent.clear();

    //emplace vs. insert
    //Emplace takes the arguments necessary to construct an object in place,
    //whereas insert takes (a reference to) an object.
    mapStudent.insert(pair<string, string>("r002", "Ben"));
    mapStudent.insert(make_pair("r003", "Kiddy"));
    mapStudent.emplace("r004", "Tony");     //only need necessary arguments
    for(pair<string, string> p : mapStudent)
        cout << p.first << ' ' << p.second << endl;
}
