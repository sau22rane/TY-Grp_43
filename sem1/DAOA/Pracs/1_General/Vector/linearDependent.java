import java.util.*;
class linearDependent
{ 
    public static void main(String[] args) 
    {  
        
        solution s = new solution(); 
        s.execute() ;
    } 
}

class solution
{
	
	void execute()  
	{ 
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter 1st vector : ");
		String s1=sc.nextLine();
		System.out.print("Enter 2st vector : ");
		String s2=sc.nextLine();
		String[] a = s1.split(" ", 5);
		String[] b = s2.split(" ", 5);
		int sum=0;
		for(int i=0;i<a.length;i++)
		{
			//System.out.println(a[i]);
			sum=sum+Integer.parseInt(a[i])*Integer.parseInt(b[i]);
		}
		if(sum==0)
			System.out.println("Linearly Independent");	
		else
			System.out.println("Linearly Dependent");
		
        	
    	}
}
