import java.util.*;

public class Transpose {
    public static void main(String[] args){
        int n,m;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Dimension of m*n matrix:\nm = ");
        m = mScanner.nextInt();
        System.out.print("n = ");
        n = mScanner.nextInt();
        System.out.println("\nEnter your matrix:");
        int[][] mat = new int[m][n];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                mat[i][j] = mScanner.nextInt();
            }
        }

        int[][] mat_t = new int[n][m];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                mat_t[j][i] = mat[i][j];
            }
        }

        System.out.println("\nTranspose of input Matrix:");
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                System.out.print(""+mat_t[i][j]+" ");
            }
            System.out.println();
        }


        
        mScanner.close();
    }
}
