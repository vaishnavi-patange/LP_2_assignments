#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&arr ,int n){
    for(int i=0;i<n-1;i++){
        int minele=i;
        for(int j=i;j<n;j++){
            if(arr[minele]>arr[j])
            {
                minele=j;

            }
        }

        int temp=arr[minele];
        arr[minele]=arr[i];
        arr[i]=temp;

    }
}

int main(){
int n;



    return 0;
}