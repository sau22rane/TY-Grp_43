import java.util.*;

public class GaussianElimination {
    public static void main(String[] args){
        int n;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Dimension of your equations:\nn = ");
        n = mScanner.nextInt();
        System.out.println("\nEnter your augmented-matrix("+n+"*"+n+1+"):");
        float[][] mat = new float[m][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n+1;j++){
                mat[i][j] = mScanner.nextFloat();
            }
        }

        for(int i= 0 ;i<n-1;i++){
            if(mat[i][i]!=1){
                float div = mat[i][i];
                for(int j = i;j<n+1;j++){
                    mat[i][j] = mat[i][j]/div;
                }
                for(int j = i+1;j<n; j++){
                    for(int k = 0;k<=n;k++){
                        
                    }
                }
            }
        }

        mScanner.close();
    }
}
