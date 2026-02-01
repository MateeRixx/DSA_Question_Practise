#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int>v1 , pair<int,int> v2){
    
    
    if(v1.first/(double)v1.second >= v2.first/(double)v2.second ){
        return true;

    }

    return false;


}

int main(){

    vector<pair<int,int>> Value_and_Weight={{100,20},{60,10},{100,50},{200,50}};

    sort(Value_and_Weight.begin(),Value_and_Weight.end(),comparator);

    
    int W=90;

    int total_value=0;

    while(W!=0){
       
        for(int i=0;i<Value_and_Weight.size();i++){

            if(Value_and_Weight[i].second<=W)
       {
        total_value=total_value+Value_and_Weight[i].first;
       W=W-Value_and_Weight[i].second;
       break;
       }

       else{
            total_value=total_value+(Value_and_Weight[i].first/(double)Value_and_Weight[i].second)*W; 
            W=0;
            break;
       }
       

        }
       
       

       
    }

    cout<<total_value;




    return 0;

}