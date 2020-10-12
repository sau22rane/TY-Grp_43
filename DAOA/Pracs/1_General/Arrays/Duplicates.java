import java.util.*;
public class Duplicates {
    public static void main(String[] args)	{
        int n;
        Scanner mScanner = new Scanner(System.in);
        HashSet<Integer> duplicates = new HashSet<>();
        HashSet<Integer> distinct = new HashSet<>();
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        System.out.println("Enter the elements in array: ");

        int temp;
        for(int i = 0;i<n;i++){
            temp = mScanner.nextInt();
            if(!distinct.contains(temp))
                distinct.add(temp);
            else if(!duplicates.contains(temp))
                duplicates.add(temp);
        }
        System.out.println("\nDuplicate entries of the following number(s) found:");
        Iterator itr = duplicates.iterator();
        while (itr.hasNext()) { 
            System.out.print(""+itr.next()+" "); 
        }
        System.out.println();
        mScanner.close();
    }
}
