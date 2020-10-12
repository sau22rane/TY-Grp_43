import java.util.*;

public class MinMax {
    public static void main(String[] args){
        int n,min = Integer.MAX_VALUE,max = Integer.MIN_VALUE,temp;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        
        System.out.println("Enter the elements in array: ");
        for(int i = 0;i<n;i++){
            temp = mScanner.nextInt();
            min = Math.min(min,temp);
            max = Math.max(max, temp);
        }

        System.out.println("Max element in the array: "+max+"\nMin element in the array: "+min);
    }
}
