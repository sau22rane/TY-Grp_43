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

    public void getActions(){
        System.out.println("Action:");
        for(String[] i: action){
            for(int j = 0;j<i.length;j++)
                System.out.print(i[j]+" ");
            System.out.println();
        }
    }

    public void getGoTO(){
        System.out.println("\nGoTo:");
        for(String[] i: goTo){
            for(int j = 0;j<i.length;j++)
                System.out.print(i[j]+" ");
            System.out.println();
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
        a.getActions();
        a.getGoTO();
    }
}
