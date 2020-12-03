import java.io.*; 
import java.util.*; 

class CD
{
	HashSet<String> set;
	ArrayList<ArrayList<String>> symbol;
	ArrayList<ArrayList<String>> literal;
	int pool=0;
	public static void main(String[] args)
	{
		String code="START 1501\nREAD N\nMOVER BREG , ='10'\nMOVEM BREG , TERM\nA MULTI BREG , TERM\nLTORG\nMOVER BREG , ='2'\nMOVEM BREG , ='7'\nLTORG\nN DS 1\nTERM DS 1";
		CD t=new CD();
		
		t.func(code);
		
	}	
	void func(String code)
	{
		set=new HashSet<>();
		symbol=new ArrayList<>();
		literal=new ArrayList<>();
		int loc=-1;
		String[] meno=new String[]{"STOP","ADD","SUB","MULTI","BREG","MOVER","MOVEM","COMB",",","BC","DIV","READ","PRINT","END","START","ORIGIN","EQU","LTORG","DS","DC"};
		for(int i=0;i<meno.length;i++)
		{
			set.add(meno[i]);
		}		
		String[] line=code.split("\n");
		for(String row: line)
		{
			loc++;
			System.out.println("LOCATION log "+loc);
			//System.out.println(row);
			String[] words=row.split(" ");
			for(int i=0;i<words.length;i++)
			{
				if(words[i].equals("START"))
				{
					loc=Integer.valueOf(words[i+1])-1;
					System.out.println("LOCATION "+loc);		
					break;
				}	
				if(i==0 && !set.contains(words[i]))
				{
					ArrayList<String> temp=new ArrayList<>();
					temp.add(words[i]);
					temp.add(String.valueOf(loc));
					symbol.add(temp);
					//System.out.println(words[i]);
					//System.out.println(loc);
					continue;
				}
				if(set.contains(words[i]))
				{
					if(words[i].equals("LTORG"))
					{
						while(pool<literal.size())
						{
							ArrayList<String> templ=literal.get(pool);
							templ.add(String.valueOf(loc));
							loc++;
							pool++;
							System.out.println("POOL "+pool);
						}
					loc--;
					}
					
					continue;
				}
				if(!set.contains(words[i]) && words[i].charAt(0)=='=')
				{
					ArrayList<String> temp=new ArrayList<>();
					temp.add(words[i]);
					//temp.add(String.valueOf(loc));
					literal.add(temp);
					//System.out.println(words[i]);
					continue;
				}
				else if(!set.contains(words[i]) && check(words[i]))
				{
					ArrayList<String> temp=new ArrayList<>();
					temp.add(words[i]);
					//temp.add(String.valueOf(loc));
					symbol.add(temp);
					//System.out.println(words[i]);
					
					continue;
				}
				
				
				
			}
			
		}
			System.out.println("----------------LITERAL---------------");
			printt(literal);
			System.out.println("----------------SYMBOL --------------");
			ArrayList<ArrayList<String>> fsymbol=new ArrayList<>();
			for(ArrayList<String > itr : symbol)
			{
				if(itr.size()==2)
					fsymbol.add(itr);
				
			}
			printt(fsymbol);
		
		
	}
	void print(ArrayList<ArrayList<String>> a)
		{
			for(int i=0;i<a.size();i++)
			{
				for(int j=0;j<a.get(i).size();j++)
				{
					System.out.print(a.get(i).get(j)+" ");
				}
				
			}
		}
	void printt(ArrayList<ArrayList<String>> a)
		{
			for(int i=0;i<a.size();i++)
			{
				for(int j=0;j<a.get(i).size();j++)
				{
					System.out.print(a.get(i).get(j)+" ");
				}
				System.out.println("");				
			}
		}
		boolean check(String s)
		{
			if(s.charAt(0)<='z' && s.charAt(0)>='a')
				return true;
			if(s.charAt(0)<='Z' && s.charAt(0)>='A')
				return true;
			return false;
		}
}
