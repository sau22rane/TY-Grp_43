#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result ;
        if(matrix.size()==0)
            return result;      
        int m = 0 , n = 0, i = 0  , row= matrix.size()-1,col = matrix[0].size()-1 ;               
        while(m<=row&&n<=col)
        {         
            for( i = n ; i<=col; i++)
            {             
                result.push_back(matrix[m][i] );
            }
            m++;
            for( i = m; i<=row ; i++)
            {                   
                result.push_back(matrix[i][col] );
            }
            col--;
            if(m<=row)
            {
                for( i = col ; i>=n ; i--)
                {                    
                    result.push_back(matrix[row][i] );
                }
                row--;
            }          
            if(n<=col)
            {
                for( i = row ; i>=m ; i--)
                {                     
                    result.push_back(matrix[i][n] );
                }
                 n++;
            }                    
        }
        return result;   
    }
};
int main()
{
    int m , n , x;
    vector<vector<int>> arr;
    cout<<"Enter number of rows and columns of matrix"<<endl;
    cin>>m;
    cin>>n;
    cout<<"Enter elements of matrix : "<<endl;
    for(int i = 0 ; i<m;i++)
    {
        vector<int> temp;
         for(int j = 0 ; j<n;j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    Solution* sol = new Solution();
	// Function Call
	vector<int> result = sol->spiralOrder(arr);
    cout<<"matrix in spiral order : "<<endl;
    for(int i = 0 ; i<result.size();i++)
    {
        cout<<result[i]<<"\t";          
    }
	return 0;
}