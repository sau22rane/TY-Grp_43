import java.util.*;

public class Branding {
    public static void main(String[] args){
        int n, min_dist;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the numebr of elements: ");
        n = mScanner.nextInt();
        int dist[] = new int[n];
        System.out.println("Enter the Distances: ");
        for(int i = 0; i<n;i++){
            dist[i] = mScanner.nextInt();
        }
        HashMap<Integer,Integer> profit = new HashMap<>();
        System.out.println("Enter the Profits: ");
        for(int i = 0; i<n;i++){
            profit.put(dist[i],mScanner.nextInt());
        }
        System.out.print("Enter the Min-distance: ");
        min_dist = mScanner.nextInt();

        int OPT[] = new int[dist[n-1]];
        int tmp = Math.min(min_dist, dist[0]);
        for(int i = 0;i<tmp;i++){
            OPT[i] = 0;
        }
        for(int i = tmp;i<dist[n-1];i++){
            if(profit.containsKey(i))
                OPT[i] = Math.max(OPT[Math.max(i-min_dist-1, 0)] + profit.get(i), OPT[i-1]);
            else
                OPT[i] = OPT[i-1];
        }
        System.out.println(OPT[dist[n-1]-1]);
        mScanner.close();
    }
}
