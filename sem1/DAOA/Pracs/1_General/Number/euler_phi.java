import java.util.*;
class euler_phi
{
	public static void main(String[] args)
	{
		solution s=new solution();
		s.execute();
	}
	
}
class solution
{
	int gcdResult=-1;
	double result;
	void gcd(int big,int small)
	{
		if(small==0)
		{
			gcdResult=big;
			return;
		}
		gcd(small,big%small);
	}
	void execute()
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter number to find phi : ");
		int n=sc.nextInt();
		this.result=n;
		int temp=n;
		int d=2;
		while(d<=Math.sqrt(temp))
		{
			if(n%d==0)
			{
				while(n%d==0)
				{
					n=n/d;
				}
				this.result*=(1	-(1/(double)d));	
				//System.out.println("d is : "+d+"   "+n);
			}	
			if(d==2)
				d++;
			else
				d=d+2;
			
		}
		if (n > 1)
		{
				this.result *= (1 - (1 / (double)n));
            			//System.out.println("d is : "+d);			
		}
            	
			
		
		System.out.println(this.result);
	}
}
