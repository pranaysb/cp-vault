// bits/stdc++.h replacement
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

int seven(int x, int y){
    if(x/10==7 || x%10==7 || y/10==7 || y%10==7)
    return 1;
}
//56+9
int main(){
// int t; cin>>t; while(t--){
    int n,x,y;
    cin>>n>>x>>y;
    if(seven(x,y))
    cout<<0<<endl;
    else{
        int ans=INT_MAX;
        while(1){
            if(x+n<60)
            x=x+n;
            if(x+n>=60)
            {
                if(y+1<=23)
                y=y+(n/60) +1;
                else
                y=0 + n/60;

                x=(60-n);
            }

        }

    }

// }
    return 0;
}