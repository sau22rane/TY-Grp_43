import java.util.*;
class count_zero
{
	public static void main(String[] args)
	{
		solution s=new solution();
		s.execute();
	}
	
}
class solution
{
	
	int result=0;
	
	void execute()
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter n! : ");
		int n=sc.nextInt();
		int i=5;
		while(n/i!=0)
		{
			result+=(int)n/i;
			i=i*5;
		}
		System.out.println(this.result);
	}
}
