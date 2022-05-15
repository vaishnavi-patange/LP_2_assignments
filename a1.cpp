#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void seegraph(vector<vector<int>>& graph,int v){
    for(int i=1;i<=v;i++){
        cout<<i<<" : ";
        for(int j=0; j<graph[i].size(); j++){
            cout<<graph[i][j]<<"-->";
        }
        cout<<endl;
    }
}

bool dfs_exist(vector<vector<int>>&graph, vector<int>check,int node,int tosearch){
    //recursively 
    if(check[node]==0){
        if(node==tosearch){
            return true;
        }
        check[node]=1;
        for(int k=0;k<graph[node].size();k++){
            bool find=dfs_exist(graph,check,graph[node][k],tosearch);
            if(find){
                return true;
            }

        }
    }
    return false;
}

void dfs(vector<vector<int>> & graph,vector<int> &check, int node){
if(check[node]==0){
    cout<<node<<" "<<endl;
    check[node]=1;
    for(int k=0; k<graph[node].size();k++){
        dfs(graph,check,graph[node][k]);
    }

}    
}
bool bfs_exist(vector<int> check, vector<vector<int>> &graph,int node, int tosearch){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        node=q.front();
        if(node==tosearch){
            return true;
        }

        q.pop();
        if(check[node]==0){
            check[node]=1;

        }

        for(int k=0; k<graph[node].size();k++)
        {
            if(check[graph[node][k]]==0){
                check[graph[node][k]]=1;
                q.push(graph[node][k]);

            }
        }
    }

    return false;

}

void bfs(vector<int> check, vector<vector<int>> & graph,int node){
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(check[node]==0){
            cout<<node<<" ";
            check[node]=1;

        }

        for(int k=0;k<graph[node].size();k++){
            if(check[graph[node][k]]==0){
                check[graph[node][k]]=1;
                cout<<graph[node][k]<<" ";
                q.push(graph[node][k]);
            }
        }

    }
}
int main(){
    int v,e;
    cout<<"enter no. of vertices:";
    cin>>v;
    cout<<"enter no. of edges:";
    cin>>e;
    vector<vector<int>>graph;
    vector<int> nodes;
    vector<int>check;
    for(int i=0;i<=v;i++){   // initialising the graph
    graph.push_back(nodes);
    check.push_back(0);
         
    }
    cout<<"enter the edges\n";
    for(int i=0;i<e;i++){

        int e1,e2;
        cout<<"enter first node";
        cin>>e1;
        cout<<"enter second node";
        cin>>e2;
        cout<<"---------------------------------------"<<endl;
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }
        int count=0,size=v,node=1,j=0;
        seegraph(graph,v);
        int tosearch,opt;
        int conti;
        conti=1;
        while(conti){
cout<<"Enter 1  to search by dfs\nEnter 2 to search by bfs\nEnter 3 to traverse using dfs\nEnter 4 to traverse using bfs\n ";
cin>>opt;
if(opt==1){

    cout<<"enter the vertex you want to find:";
    cin>>tosearch;
    if(dfs_exist(graph,check,node,tosearch)){
        cout<<"present:))";
    }
    else{
        cout<<"not present :(";
    }


}
if(opt==2){
    cout<<"enter the vertex you want to find: ";
    cin>>tosearch;
    if(bfs_exist(check,graph,node,tosearch)){
        cout<<"present:)"<<endl;
    }
    else{
        cout<<"not_present:("<<endl;
    }
}

if(opt==3){
    cout<<"DFS traversal "<<endl;
    dfs(graph,check,node);
    for(int i=1;i<=v;i++){// initialising check array again to zero
        check[i]=0;

    }
    cout<<endl;
}
if(opt==4){
    cout<<"BFS traversal"<<endl;
    bfs(check,graph,node);
    cout<<endl;
}

cout<<"do you wanna continue??(1-yes/0-no)"<<endl;
cin>>conti;

        }
    }
