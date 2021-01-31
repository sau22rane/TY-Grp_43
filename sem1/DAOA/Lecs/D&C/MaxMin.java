import java.util.*;

class MaxMin{
    public static void main(String args[]){
        int arr[] = {2,6,245,676,1324,98,312,90,567,808};
        MaxMin a = new MaxMin();
        System.out.println(a.min(arr, 0, arr.length-1));
        System.out.println(a.max(arr, 0, arr.length-1));
    }

    public int min(int[] arr, int start, int end){
        if(end - start<=1)
            return Math.min(arr[start], arr[end]);
        else{
            int mid = (start+end)/2;
            return Math.min(min(arr, start, mid-1),min(arr, mid, end));
        }
    }

    public int max(int[] arr, int start, int end){
        if(end - start<=1)
            return Math.max(arr[start], arr[end]);
        else{
            int mid = (start+end)/2;
            return Math.max(max(arr, start, mid-1),max(arr, mid, end));
        }
    }
}