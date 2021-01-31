import java.util.*;

public class majorityRandom {
    public static void main(String[] args) {
        int n;
        System.out.print("Enter the number of elements in the array: ");
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int[] data = new int[n];
        for(int i = 0; i<n;i++){
            data[i] = s.nextInt();
        }
        System.out.println("Majority Element is: "+randomMajor(data));

        s.close();
    }

    public static int randomMajor(int[] data){
        Random rand = new Random();
        int size = data.length;
        while(true){
            int t = rand.nextInt(size);
            int count = 0;
            for(int i = 0;i<size;i++)
                if (data[i] == data[t])
                    count++;
            if(count>size/2)
                return data[t];
        }
    }

}
