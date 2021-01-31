import java.util.*;

class FastModularExponentiation{

    public static void main(String[] args) throws Exception{
        int base, index, modulus;
        Scanner mScanner = new Scanner(System.in);
        System.out.print("Base: ");
        base = mScanner.nextInt();
        System.out.print("Index: ");
        index = mScanner.nextInt();
        System.out.print("Modulus: ");
        modulus = mScanner.nextInt();
        if(base%modulus == 0){
            String output = String.format("%d^%d % %d: %d", base, index, modulus, 0);
            System.out.println(output);
        }
        else{
            base = base%modulus;
            // String output = String.format("%d^%d % %d: %d", base, index, modulus, new FastModularExponentiation().subModExp(base,index,modulus));
            System.out.println(""+base+"^"+ index + " % "+modulus+": "+new FastModularExponentiation().subModExp(base,index,modulus));
        }
        mScanner.close();
    }

    int subModExp(int base, int index, int modulus){
        if(index == 0)
            return 1;
        if(index%2 == 0)
            return ((int)Math.pow(subModExp(base, index/2, modulus),2)+modulus)%modulus;
        else
            return ((subModExp(base, (int)(index-1), modulus)%modulus * base%modulus)+modulus)%modulus;
    }

}
