#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int main()
{
    string mnemonics[18], Class, MCcode, symbols[50], targetCode[50];
    int i=0,lc,s=0,l=0,pos,l1=0,n=1,pc=0,pl=1,tc=0, symbolAddress[50], literalAddress[50], literals[50], poolTable[50], size=0;
    
    poolTable[0] = 0;

    fstream f1;
    f1.open("mnemonics.txt");
    if(f1.is_open())
    {
        string s1;
        while(getline(f1,s1))
        {
            mnemonics[i] = s1;
            ++size;
            i++;       
        }
    }
    f1.close();
    
    f1.open("assembler1.txt");
    if(f1.is_open())
    {
        string command, s1;
        while(getline(f1,s1))
        {
            for (int j = 0; j < 18; j++)
            {
                if (s1.find(mnemonics[j]) != string::npos)
                    command = mnemonics[j];
            }
            
            pos = s1.find(command);
            if(command=="STOP")
            {
                ++lc;
                ++tc;
            }
            if(command=="COMP"||command=="MOVER"||command=="MOVEM"||command=="MULTI"||command=="ADD"||command=="SUB"||command=="DIV")
            {
                int flag = 0;
                if(command == "MOVER")
                {
                    targetCode[tc].append("(04)");
                }
                if(command == "MOVEM")
                {
                    targetCode[tc].append("(05)");
                }
                if(command == "MULTI")
                {
                    targetCode[tc].append("(03)");
                }
                if(command == "ADD")
                {
                    targetCode[tc].append("(01)");
                }
                if(command == "SUB")
                {
                    targetCode[tc].append("(02)");
                }
                if(command == "DIV")
                {
                    targetCode[tc].append("(08)");
                }
                if(command == "COMP")
                {
                    targetCode[tc].append("(06)");
                }
                
                if(pos!=0)
                {
                    int flag=0;
                    string s2 = s1.substr(0, pos-1);
                    for(i=0;i<s;i++)
                    {
                        if(s2==symbols[i])
                        {
                            symbolAddress[i]=lc;
                            flag=1;
                            break;
                        }
                    }
                    if(flag!=1)
                    {
                        symbols[s]=s2;
                        symbolAddress[s]=lc;
                        ++s;
                    }
                }
                if(s1.find("AREG")!=string::npos)
                {
                    targetCode[tc].append("(01)");
                }
                else if(s1.find("BREG")!=string::npos)
                {
                    targetCode[tc].append("(02)");
                }
                else if(s1.find("CREG")!=string::npos)
                {
                    targetCode[tc].append("(03)");
                }
                pos = s1.find(", ");
                if (pos != string::npos)
                {
                    s1.erase(0, pos+2);
                    if(s1.find('=') != string::npos)
                    {
                        pos = s1.find("='");
                        s1.erase(0, pos+2);
                        s1.pop_back();
                        for(i=0;i<l;i++)
                        {
                            if(stoi(s1)==literals[i])
                            {
                                targetCode[tc].append("#" + s1);
                                flag=1;
                                break;
                            }
                        }
                        if(flag!=1)
                        {      
                            literals[l]=stoi(s1);
                            targetCode[tc].append("#" + s1);
                            ++l;
                            flag = 0;
                        }
                    }
                    else if(s1[0]>'A'||s1[0]<'Z')
                    {
                        for(i=0;i<s;i++)
                        {
                            if(s1==symbols[i])
                            {
                                targetCode[tc].append("#" + s1);
                                flag=1;
                                break;
                            }
                        }
                        if(flag!=1)
                        {
                            symbols[s]=s1;
                            targetCode[tc].append("#" + s1);
                            ++s;
                            flag = 0;
                        }
                    }
                }
                ++lc;
                ++tc;
            }
            //if(command=="BC")
            if(command=="READ"||command=="PRINT")
            {     
                int flag = 0;           
                if(command == "READ")
                {
                    targetCode[tc].append("(09)(-)");
                }
                if(command == "PRINT")
                {
                    targetCode[tc].append("(10)(-)");
                }

                if(s1.find('=') != string::npos)
                {
                    pos = s1.find("='");
                    s1.erase(0, pos+2);
                    s1.erase(s1.length()-1,1);
                    for(i=0;i<l;i++)
                    {
                        if(stoi(s1)==literals[i])
                        {
                            targetCode[tc].append("#" + s1);
                            flag=1;
                            break;
                        }
                    }
                    if(flag!=1)
                    {                         
                       literals[l]=stoi(s1);
                       targetCode[tc].append("#" + s1);
                       ++l;
                    }
                }
                else if (pos != string::npos)
                {
                    s1.erase(pos, command.length() + 1);
                    pos = s1.find(":");
                    if (pos != string::npos)
                    {
                        string s2 = s1.substr(0,pos);
                        s1.erase(0, pos+2);
                        symbols[s]=s2;
                        symbolAddress[s]=lc;
                        ++s;
                    }                  
                    symbols[s]=s1;
                    symbolAddress[s]=lc;
                    targetCode[tc].append("#" + s1);
                    ++s;
                }
                ++lc;
                ++tc;
            }
            if(command=="END")
            {
                for(i=l1;i<l;i++)
                {
                    literalAddress[i]=lc;
                    ++l1;
                    ++lc;
                    targetCode[tc].append("(-)(-)(" + to_string(literals[i]) + ')');
                    ++tc;
                }
            }
            if(command=="START")
            {
                if (pos != string::npos)
                {
                    s1.erase(pos, command.length() + 1);
                }
                lc = stoi(s1);
                targetCode[tc].append("--------------");
                ++tc;
            }
            if(command=="ORIGIN")
            {
                if (pos != std::string::npos)
                {
                    s1.erase(pos, command.length() + 1);
                }
                pos=s1.find('+');
                string s2;
                if (pos != std::string::npos)
                {
                    s2=s1.substr(pos+1,s1.length()+1);
                    s1.erase(pos, command.length() + 1);
                    for(i=0;i<s;i++)
                    {
                       if(s1==symbols[i])
                            lc=symbolAddress[i] + stoi(s2);
                    }
                }
                else
                {
                    for(i=0;i<s;i++)
                    {
                       if(s1==symbols[i])
                            lc=symbolAddress[i];
                       else
                       {
                           try
                           {
                               int temp = stoi(s1);
                               lc=temp;
                           }
                           catch(exception a)
                           {
                               break;
                           }
                       }                       
                    }

                }
                targetCode[tc].append("--------------");
                ++tc;
            }
            if(command=="EQU")
            {
                int flag = 0;
                targetCode[tc].append("--------------");
                if(pos!=0)
                {
                    int flag=0;
                    string s2 = s1.substr(0, pos-1);
                    s2.pop_back();
                    for(i=0;i<s;i++)
                    {
                        if(s2==symbols[i])
                        {
                            symbolAddress[i]=lc;
                            flag=1;
                            break;
                        }
                    }
                    if(flag!=1)
                    {
                        symbols[s]=s2;
                        symbolAddress[s]=lc;
                        ++s;
                    }
                }
                pos = s1.find(", ");
                if (pos != string::npos)
                {
                    s1.erase(0, pos+2);
                    if(s1.find('=') != string::npos)
                    {
                        pos = s1.find("='");
                        s1.erase(0, pos+2);
                        s1.pop_back();
                        cout<< s1<<endl;
                        for(i=0;i<l;i++)
                        {
                            if(stoi(s1)==literals[i])
                            {
                                targetCode[tc].append("#" + s1);
                                flag=1;
                                break;
                            }
                        }
                        if(flag!=1)
                        {      
                            literals[l]=stoi(s1);
                            targetCode[tc].append("#" + s1);
                            ++l;
                            flag = 0;
                        }
                    }
                    else if(s1[0]>'A'||s1[0]<'Z')
                    {
                        for(i=0;i<s;i++)
                        {
                            if(s1==symbols[i])
                            {
                                targetCode[tc].append("#" + s1);
                                flag=1;
                                break;
                            }
                        }
                        if(flag!=1)
                        {
                            symbols[s]=s1;
                            targetCode[tc].append("#" + s1);
                            ++s;
                            flag = 0;
                        }
                    }
                }                
                ++lc;
                ++tc;
            }
            if(command=="LTORG")
            {   
                for(i=l1;i<l;i++)
                {
                    literalAddress[i]=lc;
                    ++l1;
                    ++lc;
                    targetCode[tc].append("(-)(-)(" + to_string(literals[i]) + ')');
                    ++tc;
                    ++pc;
                }
                poolTable[pl]=pc;
                ++pl;
            }
            if(command=="DS")
            {
                targetCode[tc].append("--------------");
                int flag=0;
                string s2 = s1.substr(0, pos-1);
                for(i=0;i<s;i++)
                {
                    if(s2==symbols[i])
                    {
                        symbolAddress[i]=lc;
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    symbols[s]=s2;
                    symbolAddress[s]=lc;
                    ++s;
                }
                if (pos != string::npos)
                {
                    s1.erase(0, pos+3);
                    lc+=stoi(s1);
                }
                ++tc;
            }
            if(command=="DC")
            {
                targetCode[tc].append("(-)(-)(");
                int flag=0;
                string s2 = s1.substr(0, pos-1);
                for(i=0;i<s;i++)
                {
                    if(s2==symbols[i])
                    {
                        symbolAddress[i]=lc;
                        flag=1;
                        break;
                    }
                }
                if(flag!=1)
                {
                    symbols[s]=s2;
                    symbolAddress[s]=lc;
                    ++s;
                }
                if (pos != std::string::npos)
                {
                    s1.erase(0, pos+3);
                    targetCode[tc].append(s1 + ')');
                    ++lc;
                }
                ++tc;
            }
        }
        f1.close();
    }
    cout<<endl;
    
    cout<<"Symbols"<<"\t\t"<<"Address"<<endl;
    cout<<"-------"<<"\t\t"<<"-------"<<endl;
    for(i=0;i<s;i++)
    {
        cout<<symbols[i]<<"\t\t"<<symbolAddress[i]<<"\n";
    }
    cout<<endl<<"Literals"<<"\t"<<"Address"<<endl;
    cout<<"--------"<<"\t"<<"-------"<<endl;
    for(i=0;i<l;i++)
    {
        cout<<literals[i]<<"\t\t"<<literalAddress[i]<<"\n";
    }
    cout<<endl<<"Pool"<<endl;
    cout<<"--------"<<endl;
    for(i=0;i<pl;i++)
    {
        cout<<poolTable[i]<<"\n";
    }

    cout<<endl<<"Target Code"<<endl;
    cout<<"--------------"<<endl<<endl;
    for(i=0;i<tc;i++)
    {
        string temp;
        int temp2;

        int slashpos = targetCode[i].find("#");

        if (slashpos != std::string::npos)
        {
            temp = targetCode[i].substr(slashpos,targetCode[i].length());
            targetCode[i].erase(slashpos, targetCode[i].length());
            temp.erase(0,1);
            try
            {
                temp2 = stoi(temp);
                for(int j=0;j<l;j++)
                {
                    if(temp2==literals[j])
                    {
                        targetCode[i].append("(" + to_string(literalAddress[j])+")");
                        break;
                    }
                }
            }
            catch(exception a)
            {      
               for(int j=0;j<s;j++)
                {
                    if(temp==symbols[j])
                    {
                        targetCode[i].append("(" + to_string(symbolAddress[j])+")");
                        break;
                    }
                }           
            }
        }        
        cout<<targetCode[i]<<"\n";
    }
    cout<<endl;
    return 0;
}