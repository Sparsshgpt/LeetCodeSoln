class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n= nums.size();
        int sum =0;
        for(int i=0; i<n; i++){
            int pos=i+1;
            if(n%pos==0){
                sum+=(nums[i]*nums[i]);
                
            }
        }
        return sum;
        
    }
};