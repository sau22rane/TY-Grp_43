import java.io.*;
import java.util.*;
import java.nio.charset.Charset;

class read_code{
    

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

        

        int ic = 0;
        int pool_c = 0;
        int symbol_c = 0;
        int literal_c=0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt"), Charset.forName("UTF-8")))) {
            while ((line = br.readLine()) != null) {
                String[] words = line.split(" ");

                if(MOT.containsKey(words[0])){
                    int idx = MOT.get(words[0]);
                    switch (idx) {
                        case 4:{
                            System.out.println(words[0]+" "+ic);
                            String temp=words[words.length-1].substring(words[words.length-1].indexOf('\'')+1);
                            int cnst = Integer.parseInt(temp.substring(0,temp.indexOf('\'')));
                            lit.add(cnst);
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
                            ic = Integer.parseInt(words[words.length-1])-1;
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
                /* else{
                    if(MOT.containsKey(words[1])){
                        int idx = MOT.get(words[1]);
                        switch (idx) {
                            case 4:{
                                System.out.println(words[0]+" "+words[1]+" "+ic);
                                String temp=words[words.length-1].substring(words[words.length-1].indexOf('\'')+1);
                                int cnst = Integer.parseInt(temp.substring(0,temp.indexOf('\'')));
                                lit.add(cnst);
                                symbol.put(words[0].substring(0,words[0].indexOf(':')),ic);
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
                    else if(POT.containsKey(words[1])){
                        
                    }
                    else if(DL.containsKey(words[1])){
                        int idx = DL.get(words[1]);
                        switch (idx){
                            case 1:{
                                System.out.println(words[0]+" "+words[1]+" "+ic);
                                symbol.put(words[0],ic);
                                ic+= Integer.parseInt(words[words.length-1])-1;
                                break;
                            }
                            default:
                                System.out.println(words[0]+" "+words[1]+" "+ic);
                                break;
                        }
                    }
                }
                 */
                ic++;
            }
            /* if(!symbol.isEmpty()) {
                Iterator it = symbol.entrySet().iterator();
                while(it.hasNext()) {
                   Map.Entry obj = (Map.Entry)it.next();
                   System.out.println(obj.getKey()+" "+obj.getValue());
                }
             }
            if(!literal.isEmpty()) {
                Iterator it = literal.entrySet().iterator();
                while(it.hasNext()) {
                   Map.Entry obj = (Map.Entry)it.next();
                   System.out.println(obj.getKey()+" "+obj.getValue());
                }
            } */




            /* //target code
            if(MOT.containsKey(words[0])){
                int idx = MOT.get(words[0]);
                switch (idx) {
                    case 4:{
                        System.out.println(words[0]+" "+ic);
                        String temp=words[words.length-1].substring(words[words.length-1].indexOf('\'')+1);
                        int cnst = Integer.parseInt(temp.substring(0,temp.indexOf('\'')));
                        lit.add(cnst);
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
                        ic = Integer.parseInt(words[words.length-1])-1;
                        break;
                    }
                    case 2:{
                        System.out.println(words[0]+" "+ic);
                        while(lit.size()!=0){
                            literal.put(lit.remove(),ic);
                            ic++;
                        }
                        ic--;
                        break;
                    }
                    case 3:{
                        System.out.println(words[0]+" "+ic);
                        String sym = words[words.length-1].substring(0,words[words.length-1].indexOf('+'));
                        int val = Integer.parseInt(words[words.length-1].substring(words[words.length-1].indexOf('+')));
                        ic = symbol.get(sym)+val-1;
                        break;
                    }
                    case 5:{
                        System.out.print(words[0]+" "+ic);
                        while(lit.size()!=0){
                            literal.put(lit.remove(),ic);
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
            else{
                if(MOT.containsKey(words[1])){
                    int idx = MOT.get(words[1]);
                    switch (idx) {
                        case 4:{
                            System.out.println(words[0]+" "+words[1]+" "+ic);
                            String temp=words[words.length-1].substring(words[words.length-1].indexOf('\'')+1);
                            int cnst = Integer.parseInt(temp.substring(0,temp.indexOf('\'')));
                            lit.add(cnst);
                            symbol.put(words[0].substring(0,words[0].indexOf(':')),ic);
                            break;
                        }
                        default:
                            System.out.println(words[0]+" "+ic);
                            break;
                    }

                }
                else if(POT.containsKey(words[1])){
                    
                }
                else if(DL.containsKey(words[1])){
                    int idx = DL.get(words[1]);
                    switch (idx){
                        case 1:{
                            System.out.println(words[0]+" "+words[1]+" "+ic);
                            symbol.put(words[0],ic);
                            ic+= Integer.parseInt(words[words.length-1])-1;
                            break;
                        }
                        default:
                            System.out.println(words[0]+" "+words[1]+" "+ic);
                            break;
                    }
                }
            } */
            for(int a : literal)
                if(a!=0)
                    System.out.println(a);




        }
    }
}