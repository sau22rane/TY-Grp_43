import java.io.*; 
import java.util.*; 

class LR0
{
    // String [] Grammer = {"S->E","E->E+T","E->T","T->T*F","T->F","F->(E)","F->id"};
    String [] Grammer = {"S->C","C->AB","A->a", "B->a"};
    enum Action {a,$,A,B,C};
    int action[] = new int[5];
    ArrayList<int[]> LR0_table = new ArrayList<int[]>();
	public static void main(String[] args)
	{
        int state = 0;
        while(true){
                
        }
    }
}