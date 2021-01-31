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
class dfs
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
        	n5.neighbors.add(n3);n5.neighbors.add(n6);n5.neighbors.add(n4);
        	n6.neighbors.add(n5);
        	/*GRAPH
        	1---2---4
        	 \  |	|
        	  \ |	|
        	   \3---5---6
        	*/
	        solution s = new solution();
	         
	        s.recur_dfs(n1) ;
	} 
}

class solution 
{
	HashMap<Node ,Integer> h=new HashMap<>();
	ArrayList<Integer> path=new ArrayList<>();
	void print(ArrayList<Integer> path)
	{
		System.out.println("path");
		for(int i=0;i<path.size();i++)
		{
			System.out.print(path.get(i)+" --> ");
		}
		System.out.println("END");
	}
	void recur_dfs(Node node)
	{
		
		this.h.put(node,1);
		//System.out.println(node.val);
		path.add(node.val);
		int count=0;
		for(Node temp : node.neighbors)
		{
			if(!this.h.containsKey(temp))
			{
				this.h.put(temp,0);
				
			}
			else if(this.h.get(temp)==1)
			{
				count++;
				continue;
			}
			
			this.recur_dfs(temp);
			this.h.put(temp,0);
			path.remove(path.size()-1);
		}
		if(count==node.neighbors.size())
		{
			//System.out.println("complete");
			print(path);
		}
		
	}
}
