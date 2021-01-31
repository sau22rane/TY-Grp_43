import java.util.*;

public class Missing {
    public static void main(String[] args) {
        int n;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        System.out.println("Enter the elements in array: ");
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += mScanner.nextInt();
        }
        int missing = (n+2)*(n+1)/2 - sum;
        System.out.println("\nThe missing element is: "+missing);
        mScanner.close();
    }
}
