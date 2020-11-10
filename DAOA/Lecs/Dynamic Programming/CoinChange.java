import java.util.*;

public class CoinChange{
    public static void main(String[] args){
        int n;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the numebr of Change: ");
        n = mScanner.nextInt();
        System.out.println("Enter the Change: ");
        int coins[] = new int[n];
        for(int i = 0; i<n;i++){
            coins[i] = mScanner.nextInt();
        }
        System.out.print("Enter the amount: ");
        int money = mScanner.nextInt();

        int OPT[][] = new int[n+1][money+1];
        for(int i=0;i<=money;i++){
            OPT[0][i] = 0;
            OPT[1][i] = i;
        }
        for(int j=2; j<=n; j++){
            for(int i=0;i<=money;i++){
                OPT[j][i] = Math.min(1+OPT[j][money-coins[j-1]],OPT[j-1][i]);
            }
        }
        System.out.println(OPT[n][money]);
        mScanner.close();
    }
}