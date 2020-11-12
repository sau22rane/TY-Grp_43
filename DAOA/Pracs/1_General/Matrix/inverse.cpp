#include<iostream>
#include<vector>
using namespace std; 
#define N 5 

void getCofactor(int arr[N][N], int temp[N][N], int p, int q, int n) 
{ 
	int i = 0, j = 0; 


	for (int row = 0; row < n; row++) 
	{ 
		for (int col = 0; col < n; col++) 
		{ 
		
			if (row != p && col != q) 
			{ 
				temp[i][j++] = arr[row][col]; 

				
				if (j == n - 1) 
				{ 
					j = 0; 
					i++; 
				} 
			} 
		} 
	} 
} 


int determinant(int arr[N][N], int n) 
{ 
	int D = 0; 


	if (n == 1) 
		return arr[0][0]; 

	int temp[N][N];  

	int sign = 1; 


	for (int f = 0; f < n; f++) 
	{ 
	
		getCofactor(arr, temp, 0, f, n); 
		D += sign * arr[0][f] * determinant(temp, n - 1); 

	
		sign = -sign; 
	} 

	return D; 
} 


void adjoint(int arr[N][N],int adj[N][N] , int n) 
{ 
	if (n == 1) 
	{ 
		adj[0][0] = 1; 
		return; 
	}

	int sign = 1, temp[N][N]; 

	for (int i=0; i<n; i++) 
	{ 
		for (int j=0; j<n; j++) 
		{ 
			
			getCofactor(arr, temp, i, j, n); 

			sign = ((i+j)%2==0)? 1: -1; 

	
			adj[j][i] = (sign)*(determinant(temp, n-1)); 
		} 
	} 
} 

bool inverse(int arr[N][N], float inverse[N][N] , int n) 
{ 

	int det = determinant(arr, n); 
	if (det == 0) 
	{ 
		cout << "Singular matrix, can't find its inverse"; 
		return false; 
	} 

	int adj[N][N]; 
	adjoint(arr, adj,n); 
 
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) 
			inverse[i][j] = adj[i][j]/float(det); 

	return true; 
} 
 
template<class T> 
void display(T arr[N][N],int n) 
{ 
	for (int i=0; i<n; i++) 
	{ 
		for (int j=0; j<n; j++) 
			cout << arr[i][j] << " "; 
		cout << endl; 
	} 
} 

int main() 
{ 
    int x , m;
	int arr[N][N];
    cout<<"Enter number of rows and columns of Square matrix"<<endl;
    cin>>m;
    cout<<"Enter elements of array : "<<endl;
    for(int i = 0 ; i<m;i++)
    {
       
         for(int j = 0 ; j<m;j++)
        {
            cin>>arr[i][j];
            
        }
    
    }

	int adj[N][N]; 

	float inv[N][N]; 

	cout << "Input matrix is :\n"; 
	display(arr,m); 

	cout << "\nThe adjoint is :\n"; 
	adjoint(arr, adj,m); 
	display(adj,m); 

	cout << "\nThe Inverse is :\n"; 
	if (inverse(arr, inv,m)) 
		display(inv,m); 

	return 0; 
} 
