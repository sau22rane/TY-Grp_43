import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

class SLR{
    ArrayList<ArrayList<String>> productions = new ArrayList<>();
    HashMap<Character, ArrayList<String>> first = new HashMap<>();
    HashMap<Character, ArrayList<Character>> follow = new HashMap<>();
    HashMap<String, Integer> transitions = new HashMap<>();
    ArrayList<String[]> action = new ArrayList<>();
    ArrayList<String[]> goTo = new ArrayList<>();
    HashMap<Character, Integer> term = new HashMap<>();
    HashMap<Character, Integer> nonTerm = new HashMap<>();
    HashMap<String, Integer> Rules = new HashMap<>();
    HashMap<Integer, String> Rules2 = new HashMap<>();
    ArrayList<String> initial = new ArrayList<>();
    Character[] nonTerminals = {'E', 'T', 'F'};
    Character[] terminals = {'n','+','*','(',')','$'};
    Character[] allCharacters = {'E', 'T', 'F', '+','*','(',')','n'};

    public void fetchRules(){

        try {
            File prodFile = new File("Productions.txt");
            Scanner myReader = new Scanner(prodFile);
            int count = 0;
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                String data1 = data.substring(0,3)+"."+data.substring(3);
                initial.add(data1);
                String data2 = data+".";
                Rules.put(data2, count);
                Rules2.put(count,data2);
                count++;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        productions.add(initial);

        for(int i = 0;i<nonTerminals.length;i++)
            nonTerm.put(nonTerminals[i], i);
        for(int i = 0;i<terminals.length;i++)
            term.put(terminals[i], i);
    };

    public void createFirst(){
        ArrayList<String> a = new ArrayList<>();
        a.add("E->.E+T");
        a.add("E->.T");
        a.add("T->.T*F");
        a.add("T->.F");
        a.add("F->.(E)");
        a.add("F->.n");
        ArrayList<String> b = new ArrayList<>();
        b.add("T->.T*F");
        b.add("T->.F");
        b.add("F->.(E)");
        b.add("F->.n");
        ArrayList<String> c = new ArrayList<>();
        c.add("F->.(E)");
        c.add("F->.n");

        first.put('E', a);
        first.put('T', b);  
        first.put('F', c);
    };

    public void createFollow(){
        ArrayList<Character> d = new ArrayList<>();
        d.add('$');
        ArrayList<Character> e = new ArrayList<>();
        e.add('$');
        e.add('+');
        e.add('*');
        e.add(')');
        ArrayList<Character> f = new ArrayList<>();
        f.add('$');
        f.add('+');
        f.add('*');
        f.add(')');
        ArrayList<Character> g = new ArrayList<>();
        g.add('$');
        g.add('+');
        g.add(')');

        follow.put('S', d);
        follow.put('T', e);
        follow.put('F', f);
        follow.put('E', g);
    };

    public void createState(){
        ArrayList<String> temp;
        for(int i=0;i<productions.size();i++){
            String[] t = new String[nonTerminals.length];
            String[] u = new String[terminals.length];
            for(int y = 0;y<nonTerminals.length;y++)
                t[y] = "--";
            goTo.add(t);
            for(int y = 0;y<terminals.length;y++)
                u[y] = "--";
            action.add(u);


            for(char j: allCharacters){

                String current_trans = "";
                temp = productions.get(i);
                // System.out.println(temp+ " "+ j);
                ArrayList<String> newState = new ArrayList<>();
                for(int x = 0;x<temp.size();x++){
                    String k = temp.get(x);
                    int index = k.indexOf('.');
                    if(index!=-1 && k.length()>index+1 && k.charAt(index+1) == j){
                        if(k.length()>=index+3){
                            String temp1 = k.substring(0, index) + j +"." + k.substring(index+2);
                            newState.add(temp1);
                            if(first.containsKey(k.charAt(index+2))){
                                newState.addAll(first.get(k.charAt(index+2)));
                            }
                        }
                        else{
                            String temp1 = k.substring(0, index) + j +".";
                            newState.add(temp1);
                        }
                        current_trans=current_trans + k +',';
                    }
                    else if(index!=-1 && k.length()==index+1 ){
                        char start = k.charAt(0);
                        if(start == 'S')
                            for(int s = 0;s<follow.get(start).size();s++){
                                action.get(i)[term.get(follow.get(start).get(s))] = "acc";
                            }
                        else
                            for(int s = 0;s<follow.get(start).size();s++){
                                action.get(i)[term.get(follow.get(start).get(s))] = "R"+Rules.get(k);
                            }
                    }
                }
                if(current_trans!=""){
                    current_trans=current_trans + j;
                    if(!transitions.containsKey(current_trans)){
                        transitions.put(current_trans,productions.size());
                        productions.add(newState);
                        if(Character.isUpperCase(j)){
                            goTo.get(i)[nonTerm.get(j)] = ""+(productions.size()-1);
                        }
                        else{
                            action.get(i)[term.get(j)] = "S"+(productions.size()-1);
                        }
                    }
                    else{
                        if(Character.isUpperCase(j)){
                            goTo.get(i)[nonTerm.get(j)] = ""+transitions.get(current_trans);
                        }
                        else{
                            action.get(i)[term.get(j)] = "S"+transitions.get(current_trans);
                        }
                    }
                }
            }
        }
    }

    public void getTable(){
        System.out.println("\n\n---------------------------------------------------------------");
        System.out.println("Table:");
        System.out.format("%4s", " ");
        for(Character i: terminals)
            System.out.format("%4s", i+" ");
        System.out.print(" | ");
        for(Character i: nonTerminals)
            System.out.format("%3s", i+" ");
        System.out.println();
        System.out.println("  --------------------------------------");
        for(int k = 0;k<action.size();k++){
            String[] i = action.get(k);
            System.out.format("%4s", k+"| ");

            for(int j = 0;j<i.length;j++)
                System.out.format("%4s", i[j]+" ");
            System.out.print(" | ");

            i = goTo.get(k);
            for(int j = 0;j<i.length;j++)
                System.out.format("%3s", i[j]+" ");
            System.out.println();
        }
        System.out.println("---------------------------------------------------------------");
    }

    public void getState(){
        System.out.println("---------------------------------------------------------------");
        for(int i = 0;i<productions.size();i++){
            System.out.println("State: S"+i);
            ArrayList<String> temp = productions.get(i);
            for(String j: temp)
                System.out.println(j);
            System.out.println("---------------------------------------------------------------");            
        }
    }

    public void check(String expression){

        System.out.println("\nParsing expression: "+expression);
        int i = 0, n = expression.length(), cur;
        char t,u;
        String move;
        HashMap<Character, Integer> Char = new HashMap<>();
        for(int j = 0;j<terminals.length;j++){
            Char.put(terminals[j], j);
        }
        for(int j = 0;j<nonTerminals.length;j++){
            Char.put(nonTerminals[j], j);
        }
        Stack<String> s = new Stack<String>();
        s.push("0");
        while(i<n){
            cur = Integer.parseInt(s.peek());
            t = expression.charAt(i);
            move = action.get(cur)[Char.get(t)];
            if(move.equals("acc")){
                System.out.println("Expression accepted");
                return;
            }
            // System.out.println(move+" "+Char.get(t)+" "+s.peek());
            u = move.charAt(0);
            if(u == 'S'){
                s.add(Character.toString(t));
                s.add(Character.toString(move.charAt(1)));
                i++;
            }
            else{

                // s.pop();
                // System.out.println(s.pop());
                String z; 
                try{
                    z = Rules2.get(Integer.parseInt(Character.toString(move.charAt(1))));
                }
                catch(NumberFormatException e){
                    System.out.println("Expression Rejected");
                    return;
                }
                t = z.charAt(0);
                for(int y = 0;y<z.length()-4;y++){
                    s.pop();
                    s.pop();
                }

                int temp = Integer.parseInt(s.peek());
                s.add(Character.toString(t));
                s.add(goTo.get(temp)[Char.get(t)]);
            }
        }
    }

}

public class SlrParser {
    public static void main(String[] args){
        SLR a = new SLR();
        a.fetchRules();
        a.createFirst();
        a.createFollow();
        a.createState();
        a.getState();
        a.getTable();
        a.check("n*n+n$");
        a.check("n**n+n+n$");
    }
}
