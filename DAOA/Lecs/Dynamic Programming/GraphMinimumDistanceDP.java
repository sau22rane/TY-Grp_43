import java.util.*;
import java.util.Collection;
class Node {
    public static int count=0;
    public int id;
    public int val;
    public ArrayList<Node> neighbors;
    public ArrayList<Integer> wieghts;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
        wieghts = new ArrayList<Integer>();
        count++;
        id=count;
    }
    
    public Node(int _val) {
        val = _val;
        wieghts = new ArrayList<Integer>();
        neighbors = new ArrayList<Node>();
        count++;
        id=count;
    }
    
    public Node(int _val, ArrayList<Node> _neighbors,ArrayList<Integer> _w) {
        val = _val;
        wieghts =  _w;
        neighbors = _neighbors;
        count++;
        id=count;
    }
}
class GraphMinimumDistanceDP{
	public static void main(String[] args) 
	{  
	        //System.out.println("starts");
        	Node n1=new Node(1,new ArrayList<Node>(),new ArrayList<Integer>());
        	Node n2=new Node(2,new ArrayList<Node>(),new ArrayList<Integer>());
        	Node n3=new Node(3,new ArrayList<Node>(),new ArrayList<Integer>());
        	Node n4=new Node(4,new ArrayList<Node>(),new ArrayList<Integer>());
        	Node n5=new Node(5,new ArrayList<Node>(),new ArrayList<Integer>());
        	Node n6=new Node(6,new ArrayList<Node>(),new ArrayList<Integer>());
        	n1.neighbors.add(n6);n1.wieghts.add(-3);n1.neighbors.add(n2);n1.wieghts.add(-4);
        	n2.neighbors.add(n4);n2.wieghts.add(-1);n2.neighbors.add(n5);n2.wieghts.add(-2);
        	n3.neighbors.add(n6);n3.wieghts.add(3);n3.neighbors.add(n2);n3.wieghts.add(8);
        	n4.neighbors.add(n6);n4.wieghts.add(4);n4.neighbors.add(n1);n4.wieghts.add(6);
        	n5.neighbors.add(n3);n5.wieghts.add(-3);n5.neighbors.add(n6);n5.wieghts.add(2);
        	HashMap<Integer,Node> hash=new HashMap<>();
        	hash.put(1,n1);
        	hash.put(2,n2);
        	hash.put(3,n3);
        	hash.put(4,n4);
        	hash.put(5,n5);
        	hash.put(6,n6);
        	/*GRAPH
        	
        	
        	
        	*/
	        solution s = new solution();
	        //System.out.println("calling execute");
	        s.execute(n1,n6,6,hash) ;
	} 
}
class solution 
{
	void execute(Node start,Node end,int n,HashMap<Integer,Node> h)
	{
		int[][] dp=new int[n][n];
		for(int i=1;i<n;i++)
		{
			//System.out.println("LOOP : "+i);
			dp[i][0]=Integer.MAX_VALUE;
			ArrayList<Node> l=h.get(i).neighbors;
			ArrayList<Integer> w=h.get(i).wieghts;
			if(l.contains(end))
			{
				dp[i][1]=w.get(l.indexOf(end));
			}
			else
			{
				dp[i][1]=Integer.MAX_VALUE;
			}
		}
		//System.out.println("1st loop complete");
		for(int j=2;j<n;j++)
		{
			for(int i=1;i<n;i++)
			{
				ArrayList<Node> l=h.get(i).neighbors;
				ArrayList<Integer> w=h.get(i).wieghts;
				int max=Integer.MAX_VALUE;
				
				for(int k=0;k<l.size();k++)
				{
					if(l.get(k).equals(end))
						continue;
					max=Math.min(max,w.get(k)+dp[l.get(k).val][j-1]);
				}
				
				dp[i][j]=Math.min(dp[i][j-1],max);
				
			}
		}
		System.out.print("minimun distance from start to end : ");
		System.out.println(dp[start.val][n-1]);

	}
}
