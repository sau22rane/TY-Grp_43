import java.util.*;

class longestSubstring{
    public static void main(String[] args){
        System.out.println("Enter a String: ");
        String data;
        Scanner s = new Scanner(System.in);
        data = s.nextLine();
        System.out.println("Length of non repeating longest Substring: "+lengthOfLongestSubstring(data));
    }
    static public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n==0)
            return 0;
        HashMap<Character,Integer> set = new HashMap<>();
        int max_sub = 1;
        int i =0,j = 0;
        for(i=0;i<n;i++){
            if(set.containsKey(s.charAt(i))){
                j = Math.max(set.get(s.charAt(i)),j);
                set.put(s.charAt(i),i+1);
            }
            else{
                set.put(s.charAt(i),i+1);
            }
                max_sub = Math.max(max_sub,i-j+1);
            
        }
        return max_sub;
    }
}