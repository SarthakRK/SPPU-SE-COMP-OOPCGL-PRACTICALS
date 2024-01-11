//Problem Statement:-

/*Write a program in C++ to use map associative containers. The keys will be the names of states
and the values will be the populations of the states. When the program runs, the user is prompted
to type the name of a state. The program then looks in the map, using the state name as an index
and returns the population of the state.*/

//Code:-

#include<iostream>
#include<string>
#include<map>
#include<utility>
using namespace std;

int main()
{
    typedef map<string,int> maptype;

    maptype populationmap;

    populationmap.insert(pair<string,int>("MAHARSHTRA",9579));
    populationmap.insert(pair<string,int>("ASSAM",6366));
    populationmap.insert(pair<string,int>("PUNJAB",8868));
    populationmap.insert(pair<string,int>("RAJASTHAN",4344));
    populationmap.insert(pair<string,int>("GUJRAT",2142));
    populationmap.insert(pair<string,int>("KASHMIR",1345));


    maptype::iterator iter=--populationmap.end();
    populationmap.erase(iter);
    

    cout<<"SIZE OF THE POPULATION MAP IS ";
    cout<<populationmap.size()<<endl;

    for(iter=populationmap.begin();iter!=populationmap.end();iter++)
    {
        cout<<iter->first<<": "<<iter->second<<" MILLION"<<endl;
    }

    string z;
    cout<<"ENTER THE STATE TO CHECK POPULATION :";
    cin>>z;
    string state(z);
    iter=populationmap.find(state);

    if(iter!=populationmap.end())
    {
        cout<<state<<"'S POPULATION IS "<<iter->second<<" MILLION"<<endl;
    }
    else
    {
        cout<<"STATE IS NOT IN THE POPULATION MAP"<<endl;
    }

    populationmap.clear();

    return 0;
}
