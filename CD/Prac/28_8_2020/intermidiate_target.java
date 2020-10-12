import java.io.*;
import java.util.*;
import java.nio.charset.Charset;

class intermidiate_target{

    public static void main(String[] args) throws Exception{
        String line;
        HashMap<String,Integer> MOT = new HashMap<>();
        String[] mot_ins=new String[]{"STOP","ADD","SUB","MULTI","MOVER","MOVEM","COMB","BC","DIV","READ","PRINT"};
		for(int i=0;i<mot_ins.length;i++)
		{
            MOT.put(mot_ins[i],i);
        }
        HashMap<String,Integer> POT = new HashMap<>();
        String[] pot_ins=new String[]{"START","END","ORIGIN","EQU","LTORG"};
		for(int i=0;i<pot_ins.length;i++)
		{
            POT.put(pot_ins[i],i+1);
        }
        HashMap<String,Integer> DL = new HashMap<>();
        String[] dl_ins=new String[]{"DS","DC"};
		for(int i=0;i<dl_ins.length;i++)
		{
            DL.put(dl_ins[i],i+1);
        }

        HashMap<String,Integer> REG = new HashMap<>();
        String[] reg_ins=new String[]{"AREG","BREG","CREG"};
		for(int i=0;i<reg_ins.length;i++)
		{
            REG.put(reg_ins[i],i+1);
        }
        Queue<Integer> lit = new LinkedList<>();
        
        String[] symbol = new String[100];
        int[] symbol_add = new int[100];
        int[] literal = new int[100];
        int[] literal_add = new int[100];
        int[] pool = new int[100];

        String[] intermidiate_code = new String[20];

        int ic = 0;
        int pool_c = 0;
        int symbol_c = 0;
        int literal_c=0;
        int ln = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt"), Charset.forName("UTF-8")))) {
            while ((line = br.readLine()) != null) {
                String[] words = line.split(" ");
                if(MOT.containsKey(words[0])){
                    int idx = MOT.get(words[0]);
                    switch (idx) {
                        case 1:{
                            break;
                        }
                        case 2:{
                            break;
                        }
                        case 3:{
                            break;
                        }
                        case 4:{
                            System.out.println(words[0]+" "+ic);
                            String temp=words[words.length-1].substring(words[words.length-1].indexOf('\'')+1);
                            int cnst = Integer.parseInt(temp.substring(0,temp.indexOf('\'')));
                            lit.add(cnst);
                            temp = words[1].substring(0,words[0].indexOf(','));
                            cnst = REG.get(temp);
                            break;
                        }
                        case 5:{
                            System.out.println(words[0]+" "+ic);
                            String temp=words[words.length-1];
                            symbol[symbol_c] = temp;
                            break;
                        }
                        default:
                            System.out.println(words[0]+" "+ic);
                            break;
                    }
                }
                else if(POT.containsKey(words[0])){
                    int idx = POT.get(words[0]);
                    switch (idx) {
                        case 1:{
                            System.out.println(words[0]+" "+ic);
                            ic = Integer.parseInt(words[words.length-1]);
                            String temp = "(AD,0"+idx+")(-)(C,"+ic+")";
                            ic--;
                            intermidiate_code[ln] = temp;
                            System.out.println(temp);
                            break;
                        }
                        case 2:{
                            System.out.println(words[0]+" "+ic);
                            while(lit.size()!=0){
                                literal[literal_c] = lit.remove();
                                literal_add[literal_c] = ic;
                                //literal.put(lit.remove(),ic);
                                literal_c++;
                                ic++;
                            }
                            ic--;
                            break;
                        }
                        case 3:{
                            System.out.println(words[0]+" "+ic);
                            String sym = words[words.length-1].substring(0,words[words.length-1].indexOf('+'));
                            int val = Integer.parseInt(words[words.length-1].substring(words[words.length-1].indexOf('+')));
                            //search
                            
                            //ic = symbol.get(sym)+val-1;
                            break;
                        }
                        case 5:{
                            System.out.print(words[0]+" "+ic);
                            while(lit.size()!=0){
                                literal[literal_c] = lit.remove();
                                literal_add[literal_c] = ic;
                                //literal.put(lit.remove(),ic);
                                literal_c++;
                                ic++;
                            }
                            ic--;
                            System.out.println(" "+ic);
                            break;
                        }
                        default:
                            System.out.println(words[0]+" "+ic);
                            break;
                    }
                }



            }
        }

    }
}