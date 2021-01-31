import java.io.*;
import java.util.*;
import java.lang.*;

class Node{
    int freq;
    char symbol;
    Node right, left;

    Node(char symbol, int freq){
        this.symbol = symbol;
        this.freq = freq;
        this.left = null;
        this.right = null;
    }
    Node(){
        this.left = null;
        this.right = null;
    }
}

class MyComparare implements Comparator<Node> {
    public int compare(Node a1, Node a2){ 
        return a1.freq - a2.freq;
    }
}

public class Main {
    static PriorityQueue<Node> minHeap;
    static HashMap<Character, String> hMap = new HashMap<Character, String>();
    public static void main(String[] args) {
        int n ;
        Scanner sc=new Scanner(System.in);  
        System.out.print("Enter the number of characters : ");  
        n=sc.nextInt();  
        char[]  symbolArray = new char[n];  
        System.out.println("Enter characters: ");  
        for(int i=0; i<n; i++)  
        {  
        symbolArray[i]=sc.next().charAt(0);  
        } 
        int[]  symbolFreq = new int[n];  
        System.out.println("Enter the frequency of each character: ");  
        for(int i=0; i<n; i++)  
        {  
        symbolFreq[i]=sc.nextInt();  
        } 
        
        minHeap = new PriorityQueue<Node>(symbolArray.length, new MyComparator());

        for(int i = 0;i<symbolArray.length; i++){
            Node temp = new Node(symbolArray[i], symbolFreq[i]);
            minHeap.add(temp);
        }


        Node HuffmanTree = null;

        while(minHeap.size()>1){
            Node left = minHeap.poll();
            Node right = minHeap.poll();
            Node parent = new Node('*',left.freq+right.freq);
            parent.left = left;
            parent.right = right;
            HuffmanTree = parent;
            minHeap.add(parent);
        }
        GetCode(HuffmanTree, "");
        System.out.println(hMap);

    }

    public static void GetCode(Node root, String str){
        if(root.right == null && root.left == null && Character.isLetter(root.symbol) )
            hMap.put(root.symbol, str);
        else{
            if(root.right!=null)
                GetCode(root.right, str+"1");
            if(root.left!=null)
                GetCode(root.left, str+"0");
        }
    }

}
