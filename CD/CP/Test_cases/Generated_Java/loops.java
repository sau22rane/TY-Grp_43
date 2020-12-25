import java.util.*;

public class loops
{
	static Scanner in = new Scanner(System.in);
	static int main_(int argc, String[] args)  {
		int i = 1;
		int fib = 1;
		int target = 10;
		int temp = 0;
		while (i < target) {
			temp = fib;
			fib += temp;
			i++;
		}
		System.out.println(fib);
		return 0;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
