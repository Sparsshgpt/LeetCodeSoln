class Solution {
public:
    int binExp(int a,int b){
        int ans=1;
        int q=1e9+7;
        while(b){
            if(b&1)
                ans=(ans*1ll*a)%q;
            a=(a*1ll*a)%q;
            b>>=1;
        }
        return ans;
    }
    bool check(int sz,vector<int>&nums){
        int n=nums.size();
        int d=1e5+2;
        int q=1e9+7;
        long long int h=0;
        for(int i=0;i<sz;i++){
            h=h+binExp(d,sz-1-i)*1ll*nums[i];
            h%=q;
        }
        int l=0,r=sz;
        map<long long int,long long int>mp;
        mp[h]++;
        while(r<n){
            long long int nh=(d*1ll*h-binExp(d,sz)*1ll*nums[l]%q+nums[r]+q)%q;
            h=nh;
            r++;
            l++;
            mp[nh]++;
        }
        for(auto it:mp){
            if(it.second==1)
                return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n;
        int ans=n;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(mid,nums))
            {
                ans=mid;
                h=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};