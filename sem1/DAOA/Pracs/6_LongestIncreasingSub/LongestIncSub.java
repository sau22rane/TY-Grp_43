import java.io.*;
import java.util.*;
import java.lang.*;

class LongestIncSub{
    public static void main(String[] args) throws Exception{
        int n,max = 1;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        System.out.println("Enter the elements in array: ");
        int arr[] = new int[n];
        int callBack[] = new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = mScanner.nextInt();
            callBack[i] = 1;
        }
        
        // Algorithm implementation: Dynamic approach
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(arr[j]<=arr[i]){
                    callBack[i] = Math.max(callBack[i],callBack[j]+1);
                    max = Math.max(max, callBack[i]);
                }
            }
        }
        System.out.println("Length of the Longest Increasing Subsequence: "+max);
        mScanner.close();
    }
}