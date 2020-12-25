import java.util.*;

public class conditional
{
	static Scanner in = new Scanner(System.in);
	static int max (int a, int b)  {
		if (a > b) {
			return a;		}
		else {
			return b;		}

	}
	static int main_(int argc, String[] args)  {
		int a = 0, b = 0;
		a = in.nextInt();
		b = in.nextInt();
		System.out.println(max(a, b));
		return 0;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
