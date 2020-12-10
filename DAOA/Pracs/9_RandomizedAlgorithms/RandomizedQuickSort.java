import java.util.*;

public class RandomizedQuickSort {
    public static void main(String[] args){
        int n;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        System.out.println("Enter the elements in array: ");
        int arr[] = new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = mScanner.nextInt();
        }

        new RandomizedQuickSort().quickSort(arr,0,n-1);
        for(int i = 0;i<n;i++){
            System.out.print(""+arr[i]+" ");
        }
        mScanner.close();
    }

    private void quickSort(int arr[], int low, int high){
        if(low<high){
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot+1, high);
        }
    }

    private int partition(int arr[], int low, int high){
        Random rand= new Random();
        int r = rand.nextInt(high-low)+low;
        int pivot = arr[r];

        int temp = arr[high];
        arr[high] = arr[r];
        arr[r] = temp;

        int i = (low-1);
        for (int j=low; j<high; j++){
            if (arr[j] < pivot){
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }
}
