import java.util.*;

public class KthRank{
    public static void main(String[] arg) 
    { 
        int n, k;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in array: ");
        n = mScanner.nextInt();
        MaxHeap maxHeap = new MaxHeap(n);
        System.out.println("Enter the elements in array: ");
        for(int i = 0;i<n;i++){
            maxHeap.insert(mScanner.nextInt());
        }
        
        System.out.print("Kth rank to find: ");
        k = mScanner.nextInt();
        for(int i=1;i<k;i++){
            maxHeap.popMax();
        }

        System.out.println("\nThe kth rank is " + maxHeap.popMax()); 
        mScanner.close();
    } 
}

class MaxHeap {
    private int[] Heap;
    private int size;
    private int maxsize;

    public MaxHeap(int maxsize){
        this.maxsize = maxsize;
        this.size = 0;
        Heap = new int[this.maxsize + 1];
        Heap[0] = Integer.MAX_VALUE;
    }

    private int parent(int pos){return pos/2;}
  
    
    private int leftChild(int pos){return (2 * pos);}
    private int rightChild(int pos){return (2 * pos) + 1;}
  
    private boolean isLeaf(int pos){
        if (pos >= (size / 2) && pos <= size){
            return true;
        }
        return false;
    }

    private void swap(int fpos, int spos){
        int tmp;
        tmp = Heap[fpos];
        Heap[fpos] = Heap[spos];
        Heap[spos] = tmp;
    }


    private void maxHeapify(int pos)
    {
        if (isLeaf(pos))
            return;

        if (Heap[pos] < Heap[leftChild(pos)] || Heap[pos] < Heap[rightChild(pos)]){

            if (Heap[leftChild(pos)] > Heap[rightChild(pos)]){
                swap(pos, leftChild(pos));
                maxHeapify(leftChild(pos));
            }
            else{
                swap(pos, rightChild(pos));
                maxHeapify(rightChild(pos));
            }
        }
    }

    public void insert(int element)
    {
        size++;
        Heap[size] = element;

        int current = size;
        while(Heap[current] > Heap[parent(current)]){
            swap(current, parent(current));
            current = parent(current);
        }
    }

    
    
    public int popMax()
    {
        int popped = Heap[1];
        Heap[1] = Heap[size--];
        maxHeapify(1);
        return popped; 
    }
}