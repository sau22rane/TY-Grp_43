#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Edge
{
    public :
    int src , dest , weight;
};
class Graph
{
    public :
    int v , e;
    vector<Edge> edges;
    vector<Edge> minSpanningTree()
    {
        unordered_set<int> uset;
        vector<Edge> tree;
        sort();
        int i = 0;
        while(uset.size()!=v-1 )
        {
            if( uset.find(edges[i].src) == uset.end() && uset.find(edges[i].dest) == uset.end())//check cycle
            {
                uset.insert(edges[i].src);
                uset.insert(edges[i].dest);
                tree.push_back(edges[i]);
            }
            i++;  
        }
        
    }
    void sort()
    {
        for(int i = 0 ; i<edges.size()-1 ; i++)
        {
            for(int j = 0 ; j<edges.size()-i-1; j++)
            {
                
                if(edges[j].weight>edges[j+1].weight)
                {
                    Edge e ;
                    e = edges[j];
                    edges[j] = edges[j+1];
                    edges[j+1] = e;
                }
            }
        }
    }
};

int main()
{
    Graph* g = new Graph();
    int x , y , z;
    cout<<"Enter number of vertices in graph : "<<endl;
    cin>>x;
    g->v = x;
    cout<<"Enter number of edges in graph : "<<endl;
    cin>>x;
    g->e = x;
    vector<Edge> edges;
    for(int i = 0 ; i <g->e ; i++)
    {
    Edge e ;
    cout<<"Enter edge source , destination and weight of " <<i+1<<" edge : "<<endl;
    cin>>x;
    cin>>y;
    cin>>z;
    e.src = x ; e.dest = y , e.weight = z;
    edges.push_back(e);
    }
    g->edges = edges;
    g->sort();
    
    edges = g->minSpanningTree();
    for(int i = 0 ; i <edges.size(); i++)
    {
        cout<<"source : "<<edges[i].src<<"destination : "<<edges[i].dest<<"weight : "<<edges[i].weight;
    }
    return 0; 
}