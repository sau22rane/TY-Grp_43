import java.util.*;
import java.util.Collection;
 class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
class bfs
{
	public static void main(String[] args) 
	{  
        
        	Node n1=new Node(1,new ArrayList<Node>());
        	Node n2=new Node(2,new ArrayList<Node>());
        	Node n3=new Node(3,new ArrayList<Node>());
        	Node n4=new Node(4,new ArrayList<Node>());
        	Node n5=new Node(5,new ArrayList<Node>());
        	Node n6=new Node(6,new ArrayList<Node>());
        	n1.neighbors.add(n2);n1.neighbors.add(n3);
        	n2.neighbors.add(n3);n2.neighbors.add(n4);n2.neighbors.add(n1);
        	n3.neighbors.add(n1);n3.neighbors.add(n2);n3.neighbors.add(n5);
        	n4.neighbors.add(n2);n4.neighbors.add(n5);
        	n5.neighbors.add(n3);n5.neighbors.add(n6);
        	n6.neighbors.add(n5);
        	/*GRAPH
        	1---2---4
        	 \  |	|
        	  \ |	|
        	   \3---5---6
        	
        	
        	*/
	        solution s = new solution();
	         
	        s.execute(n1) ;
	} 
}

class solution 
{
	void execute(Node node)
	{
		Queue<Node> q=new LinkedList<>();
		HashMap<Node ,Integer> h=new HashMap<>();
		q.add(node);
		h.put(node,1);
		while(!q.isEmpty())
		{
			Node temp=q.poll();
			System.out.println(temp.val);
			for(Node n: temp.neighbors)
			{
				if(!h.containsKey(n))
				{
					q.add(n);
					h.put(n,1);
				}
			}
		}
	}
}
