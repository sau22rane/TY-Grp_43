#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> helper(vector<int> nums)
    {
        int sum = 0;
        if(nums.size()==1)
            return nums;
       
        vector<int> result;
        
        if(nums.size()%2!=0)
        {
            
            for(int i = 1 ; i<nums.size() ; i++)
            {
                if(nums[i]==nums[0])
                    sum++;                
            }
            
            if(sum >= nums.size()/2)
            {
                
                result.push_back(nums[0]);
               
            }
            nums.erase(nums.begin());
        }
        
        for(int i = 0 ; i<nums.size() -1; i+=2)
        {
            if(nums[i]==nums[i+1])
                result.push_back(nums[i]);            
        }
        result = helper(result); 
         return result;

    }
    int majorityElement(vector<int> nums ) { 
        vector<int>result = helper(nums);
        int sum = 0;
        for(int i = 0 ; i<nums.size();i++)
        {
            if(result[0] == nums[i])
                sum+=1;
        }
       
        if(sum>nums.size()/2)
            return result[0]; 
        else
            return -1;                     
    }
};
int main()
{
    int n , x;
    cout<<"Enter number of elements in array : "<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of your array"<<endl;
    for(int i = 0 ; i<n;i++)
    {
        cin>>x;
        arr.push_back(x);   
    }
    Solution* s = new Solution();
    x = s->majorityElement(arr);
   
    if(x!=-1)
        cout<<"The majority element is : "<<x<<endl;
    else
    {
         cout<<"The given array has no majority element "<<endl;
    }
    
}