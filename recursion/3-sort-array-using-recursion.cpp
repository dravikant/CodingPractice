#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


void insert(vector<int>&v, int temp){
    //base condition
    if(v.size()==0 || v[v.size()-1]<temp){
        v.push_back(temp);
        return;
    }

    //last element is not smaller so continue to pop back and use insert

    int last_elem = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(last_elem);
    return;
}

void sort(vector<int>&v){

    //base condition
    if(v.size()==1){
        return ;
    }

    //else sort n-1 elements 
    int temp = v[v.size()-1];
    v.pop_back();

    sort(v);

    //now insert the last element in to the sorted array

    insert(v,temp);

}

int main(){
	vector<int>v={9,0,1,4,90,67,2,120};
	sort(v);

	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}

    return 0;
}