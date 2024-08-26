#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    //unordered_map -> random order  (time complexity -> O(1) best and O(n) worst)
    //map -> ordered  (time complexity -> O(log n)
    unordered_map<string, int> m;

    //creation

    //1
    pair<string, int> p = make_pair("babbar", 1);
    m.insert(p);

    //2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    //3
    m["mera"] = 3;

    //updation
    m["mera"] = 4;

    //search
    cout<<m["babbar"]<<endl;
    cout<<m.at("love")<<endl;

    //cout<<m.at("unknownKey")<<endl;   //error: key didn't exist
    cout<<m["unknownKey"]<<endl;    //key is created with value 0
    cout<<m.at("unknownKey")<<endl;

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("love")<<endl;

    //erase
    cout<<m.erase("love")<<endl;
    cout<<m.size()<<endl;

    //accessing via loop
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    //accessing via iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}