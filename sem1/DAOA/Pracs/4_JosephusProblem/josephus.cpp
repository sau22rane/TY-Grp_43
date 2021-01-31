//Josephus problem

#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k-1) % n + 1;
}
int main()
{
    int n,k;
    cout<<"Enter the number of people in the Round Table:"<<"\t";
    cin>>n;
    cout<<"Enter the distance between eliminating people"<<"\t";
    cin>>k;
    cout<<endl;
    cout << "The chosen place that is not eliminated is : " << josephus(n, k);
    return 0;
}
