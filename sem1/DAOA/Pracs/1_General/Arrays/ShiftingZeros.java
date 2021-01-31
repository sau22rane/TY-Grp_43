import java.util.*;

public class ShiftingZeros {
    public static void main(String[] args){
        int n;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements in array: ");
        for(int i = 0;i<n;i++){
            arr[i] = mScanner.nextInt();
        }

        for(int i=0,j=n-1;i<j;){
            
            if(arr[j]==0)
                j--;
            else if(arr[i]==0){
                arr[i] = arr[j];
                arr[j] = 0;
                j--;
                i++;
            }
            else    
                i++;
        }

        for(int i =0;i<n;i++){
            System.out.print(""+arr[i]+" ");
        }

        mScanner.close();
    }
}
