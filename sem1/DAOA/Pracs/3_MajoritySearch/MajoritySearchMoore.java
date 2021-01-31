import java.util.*;


public class MajoritySearchMoore {
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

        int major = arr[0], rep = 1;

        for(int i= 1; i<n;i++){
            if(arr[i] == major)
                rep++;
            else
                rep--;

            if(rep == 0){
                major = arr[i];
                rep = 1;
            }
        }
        rep = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]==major)
                rep++;
        }

        if(rep>n/2)
            System.out.println("Majority: "+major);
        else
            System.out.println("No Majority Element");
        mScanner.close();
    }
}
