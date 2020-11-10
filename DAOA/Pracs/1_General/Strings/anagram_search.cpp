#include<iostream>
#include<vector>
using namespace std; 
#define CHAR 26
class Solution {
public:
    bool same(vector<int> s, vector<int> p)
    {
       for(int i = 0 ;i< CHAR ; i++)
        {
           
            if(s[i]!=p[i])
                return false;
        } 
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int i = 0;
        vector<int> result , freq(CHAR,0) , pat(CHAR,0) ;
        if(s.size()==0 || p.size()>s.size())
            return result;
        for(i = 0 ;i< p.size() ; i++)
        {
            freq[s[i]-97] +=1;
            pat[p[i]-97] +=1;
        }
        for(i = p.size() ;i< s.size(); i++)
        {
            if(same(freq , pat))
                result.push_back(i-p.size());
            
            
            freq[s[i-p.size()]-97]--;
            freq[s[i]-97]++;
            
        }
        if(same(freq , pat))
                result.push_back(i-p.size());
        return result;
        
    }
};
int main()
{
    string  s , p ;
    cout<<"Enter  string :"<<endl;
    cin>>s;
    cout<<"Enter  pattern :"<<endl;
    cin>>p;
    
    Solution* sol = new Solution();

	vector<int> result = sol->findAnagrams(s,p);
    cout<<"Index at which anagram found are : "<<endl;
    for(int i = 0 ; i<result.size();i++)
    {  
        cout<<result[i]<<"\t";          
    }
	return 0;
}