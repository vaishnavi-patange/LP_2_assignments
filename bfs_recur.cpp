#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfsRec(vector<int> vec[], vector<int> &visit, queue<int> &q){
	if(q.empty()){
		return;
	}
	int ele = q.front();
	q.pop();
	cout<<ele<<" ";
	vector<int> a = vec[ele];
	for(int i=0; i<a.size(); i++){
		if(!visit[a[i]]){
			visit[a[i]] = 1;
			q.push(a[i]);
		}
	}
	bfsRec(vec, visit, q);
}

void BFS(vector<int> vec[], int n){
	vector<int> visit(n+1, 0);
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			q.push(i);
			bfsRec(vec, visit, q);
		}
	}
}

void dfsRec(vector<int> vec[], vector<int> &visit, int n)
{
	vector<int> a = vec[n];
	cout<<n<<" ";
	for(int i=0; i<a.size(); i++){
		int ele = a[i];
		if(visit[a[i]] == 0){
			visit[a[i]] = 1;
			dfsRec(vec, visit, ele);
		}
	}
}

void DFS(vector<int> vec[], int n){
	vector<int> visit(n+1, 0);
	for(int i=1; i<=n; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			dfsRec(vec, visit, i);
		}
	}
}

int main(){
	int n, edge, x, y;
	cout<<"Enter the Number of Vertices: ";
	cin>>n;
	vector<int> vec[n+1];
	cout<<"Enter the Number of Edges: ";
	cin>>edge;
	for(int i=0; i<edge; i++){
		cout<<"Enter starting index: ";
		cin>>x;
		cout<<"Enter ending index: ";
		cin>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
    // print graph
    
    for(int i=1;i<=n;i++){
        cout<<i<<" : ";
        for(int j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<"-->";
        }
        cout<<endl;
    }
	 cout<<endl;
	cout<<"\n BFS Traversal"<<endl;
	BFS(vec, n);
	cout<<"\n DFS Traversal"<<endl;
	DFS(vec, n);
}