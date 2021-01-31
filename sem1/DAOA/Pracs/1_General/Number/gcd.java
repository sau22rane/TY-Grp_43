import java.util.*;
class gcd
{
	public static void main(String[] args)
	{
		solution s=new solution();
		s.execute();
	}
	
}
class solution
{
	int result=-1;
	void gcd(int big,int small)
	{
		if(small==0)
		{
			result=big;
			return;
		}
		gcd(small,big%small);
	}
	void execute()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter 1st number");
		int a=sc.nextInt();
		System.out.println("Enter 2nd number");
		int b=sc.nextInt();
		if(a>b)
			gcd(a,b);
		else
			gcd(a,b);
		System.out.println(result);
	}
}
