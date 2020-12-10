import java.util.*;

public class longestCommonPrefix {

    public static void main(String[] args) {
        int n;
        System.out.print("Enter the number of input Strings: ");
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        s.nextLine();

        String[] data = new String[n];
        for(int i=0;i<n;i++){
            data[i] = s.nextLine();
        }
        System.out.println("The Longest Common Prefix is: "+longestPrefix(data));
    }


    static public String longestPrefix(String[] strs) {
        int min_len=Integer.MAX_VALUE;
        for(String s: strs){
            if(s.length()<min_len)
                min_len = s.length();
            
        }
        if(min_len==Integer.MAX_VALUE||min_len==0)
            return "";
        String pre = strs[0].substring(0,min_len);
        for(String s: strs){
            for(int i=0;i<pre.length();i++){
                if(s.charAt(i)!=pre.charAt(i)){
                    pre = pre.substring(0,i);
                }
            }
        }
        return pre;
    }
}
