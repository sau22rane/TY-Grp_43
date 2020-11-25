import java.util.*;
class scheduling
{
	public static void main(String[] args)
	{
		solution s=new solution();
		int n;
		
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter number of jobs : ");
		n=sc.nextInt();
		int[][] jobs=new int[n][2];
		
		System.out.print("Enter Priority : ");
		for(int i=0;i<n;i++)
		{
			int temp=sc.nextInt();
			jobs[i][0]=temp;
		}
		System.out.print("Enter deadline : ");
		for(int i=0;i<n;i++)
		{
			int temp=sc.nextInt();
			jobs[i][1]=temp;
		}
		Arrays.sort(jobs,(a,b)->Integer.compare(a[0],b[0]));
		//s.print(jobs);
		s.execute(jobs,jobs.length);
	}
	
}
class solution
{	
	void print(int[][] a)
	{
		for(int i=0;i<a.length;i++)
			System.out.println(a[i][0]+"  "+a[i][1]);
	}
	
	void execute(int[][] jobs,int n)
	{
					
		
		int m=0;
		for(int i=0;i<n;i++)
			if(m<jobs[i][1])
				m=jobs[i][1];
		int[] result=new int[n];
		for(int i=n-1;i>=0;i--)
		{
			for(int j=jobs[i][1]-1;j>=0;j--)
			{
				if(result[j]==0)
				{
					result[j]=jobs[i][0];
					break;
				}
			}
		}
		System.out.println("Jobs allocated are : ");
		for(int i=0;i<n;i++)
		{
			if(result[i]==0)
				continue;
			System.out.print("-->"+result[i]+"");
			
		}
			
	}
}
