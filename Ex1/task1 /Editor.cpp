#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include <vector>
#include "Editor.h"
using namespace std;
 

void Editor::exchange_wordable(string str, Document &doc)
{ 
    vector <string> tokens; 
    stringstream check1(str); 
    string intermediate; 
    while(getline(check1, intermediate, '/')) 
    { 
        tokens.push_back(intermediate); 
    } 
    if(tokens.size()>=1&&tokens.size()<=3)
    {
        doc.exchange_words(tokens[1],tokens[2]);
    }
}



void connect_lines(string command ,Document &doc)
{
    string str = command.substr (0,command.size()-1);
        vector <string> tokens; 
    stringstream check1(str); 
    string intermediate; 
    while(getline(check1, intermediate, ',')) 
    { 
        tokens.push_back(intermediate); 
    } 
    try
    {
        int num1=std::stoi(tokens[0]);
        int num2=std::stoi(tokens[1]);
        doc.connect_line(num1-1,num2-1);
    }
    catch (std::invalid_argument const &e)
        {
         cout<<"?"<<endl;  
        }
        catch (std::out_of_range const &e)
        {
            cout<<"?"<<endl;
        }

}




bool to_earse_line(string str)
{
    if(str[str.size()-1]=='d')
    {
        try
        {
            string str2 = str.substr (0,str.size()-1);
            int i = std::stoi(str2);
            return true;
        }
        catch (std::invalid_argument const &e)
        {
         return false;   
        }
        catch (std::out_of_range const &e)
        {
            return false;
        }
    }
    return false;
}



bool to_move_to_line(string str)
{
    if(str[str.size()-1]=='n')
    {
        try
        {
            string str2 = str.substr (0,str.size()-1);
            int i = std::stoi(str2);
            return true;
        }
        catch (std::invalid_argument const &e)
        {
         return false;   
        }
        catch (std::out_of_range const &e)
        {
            return false;
        }
    }
    return false;
}




void Editor::loop()
{
    Document doc;
    string commands="";
    bool flag=true;
    while(flag)
    {
        //cout<<"first line"<<endl;

        getline(cin,commands);
        if (commands== "Q"){
            flag = false;
        }
        else if(commands=="i")
        {
            doc.add_line_before();
        }
        else if (commands == "a")
        {
            doc.add_line_after();
        }
        else if (commands=="%p")
        {
            doc.print();
        }
        else if (commands=="c")
        {
            doc.exchange_line();
        }
        else if (commands[0]=='s')
        {
            exchange_wordable(commands,doc);
        }
        else if ( to_earse_line(commands))
        {
            string str2 = commands.substr (0,commands.size()-1);
            int i = std::stoi(str2);
            doc.delete_line(i-1);
        }
        else if (to_move_to_line(commands))
        {
            string str2 = commands.substr (0,commands.size()-1);
            int i = std::stoi(str2);
            doc.move_to_line(i-1);
        }
        else if(commands[0]=='/')
        {
            string str2 = commands.substr (1,commands.size()-1);
            doc.search_after(str2);
        }
        else if(commands[0]=='?')
        {
            string str2 = commands.substr (1,commands.size()-1);
            doc.search_befor(str2);
        }
        else if(commands[commands.size()-1]=='j'&&isdigit(commands[0]))
        {
            connect_lines(commands,doc);
        }

        else cout<<"?"<<endl;
    }
}
