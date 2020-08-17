#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int A[N];
deque<pair<int , int >> DQ;

void push(int x){
    while(!DQ.empty()){ //till the time deque is not empty
        if(DQ.back().first < A[x]){
            DQ.pop_back();
        }
        else break;
    }
    DQ.push_back({A[x],x});
}

int query(int l, int r){
    while(!DQ.empty()){
        if(DQ.front().second < l){
            DQ.pop_front();
        }
        else break;
    }
//query only works if we increase l and r 1 by 1
    return DQ.front().first;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
#endif
    int n , k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>A[i];

    for(int i = 1; i <= k ; i++){
        push(i);
    }    

    int l = 1, r = k;
    cout<<query(l,r)<<" ";
    for(int r = k+1 ; r <= n ; r++){
        l++;
        push(r);
        cout<<query(l , r)<<" ";
    }

}

