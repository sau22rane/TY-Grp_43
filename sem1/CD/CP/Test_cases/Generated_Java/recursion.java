import java.util.*;

public class recursion
{
	static Scanner in = new Scanner(System.in);
	static int fact (int n)  {
		if (n < 1) {
			return 1;		}
		else {
			return n * fact(n - 1);		}

	}
	static int main_(int argc, String[] args)  {
		int n = 10;
		System.out.println(fact(n));
		return 0;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
