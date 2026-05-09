#include<bits/stdc++.h>
using namespace std;

// vector<int> howSum(int targetSum,vector<int>numbers)
// {

//     vector<int>ans;

//     if(targetSum==0){
        
//         return {};

//     }

//     if(targetSum<0){
//         return {-1};

//     }

//     for(int i=0;i<numbers.size();i++){

//         int remainder=targetSum-numbers[i];
//         vector<int>ans=howSum(remainder,numbers);

//         if(remainder==0){
//             ans.push_back(numbers[i]);
//             return ans;
            
            

//         }

        
        
//     }

//     return {-1};
    


// }

vector<int> howSum(int targetSum, vector<int>& numbers) {
    // Base Case: Success
    if (targetSum == 0) return {}; 
    // Base Case: Failure
    if (targetSum < 0) return {NULL}; 

    for (int num : numbers) {
        int remainder = targetSum - num;
        vector<int> remainderResult = howSum(remainder, numbers);

        // If the remainderResult is not a dead end
        if (remainderResult.size() == 0 || remainderResult[0] != NULL) {
            remainderResult.push_back(num);
            return remainderResult;
        }
    }

    // If no combination works
    return {-1};
}




int main()
{
    vector<int>numbers={1,4};
    int targetSum=5;

    vector<int>ans=howSum(targetSum,numbers);
    for(auto numb:ans){cout<<numb<<"\t";}

    return 0;

}