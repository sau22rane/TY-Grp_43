import java.util.*;
class angle
{ 
    public static void main(String[] args) 
    {  
        
        solution s = new solution(); 
        s.execute() ;
    } 
}

class solution
{
	double mod(String[] v)
	{
		double r=0;
		for(int i=0;i<v.length;i++)
		{
			r=r+Math.pow(Integer.parseInt(v[i]),2);
		}
		return Math.sqrt(r);
	}
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
		double moda=mod(a);
		double modb=mod(b); 
		double angle = sum/(moda*modb);
		angle = Math.acos(angle);
		System.out.println(angle);
		
        	
    	}
}
