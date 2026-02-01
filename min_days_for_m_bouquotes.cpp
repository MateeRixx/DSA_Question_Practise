bool no_of_flowers_avail(vector<int>& BloomDay, int mid, int m, int k) {
    int counter = 0, bouquets = 0;
    for (int i = 0; i < BloomDay.size(); i++) {
        if (BloomDay[i] <= mid) {
            counter++;
            if (counter == k) {
                bouquets++;
                counter = 0;
            }
        } else {
            counter = 0;
        }
    }
    return bouquets >= m;
}





class Solution {
public:
    int minDays(vector<int>& BloomDay, int m, int k) {
        
    int low=*min_element(BloomDay.begin(),BloomDay.end());
    int high=*max_element(BloomDay.begin(),BloomDay.end());
    int ans=high;

    if(BloomDay.size()< (long long) m*k)
        {
            ans=-1;

       
       
         }

    while(low<=high){
        int mid=low+(high-low)/2;

        if(no_of_flowers_avail(BloomDay,mid,m,k)==0)
        {
            low=mid+1;

        }
        else{
            ans=mid;
            high=mid-1;


        }
    }


    return ans;
    }
};
