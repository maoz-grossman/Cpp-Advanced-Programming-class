#include<string>
#include<iostream>
#include<list>
#include <iterator>
using namespace std;

class Document
{
list<string>::iterator ind;//point on the current index
list<string>txtFile;//the text we editing
public:
Document();//consturcture
void exit_editor(string str);//Q getout
void connect_line(int num1 ,int num2);//like 4,3j connet line 3 with 4
void exchange_words(string old_word, string new_word);
void exchange_line();//like: c<\n>string<\n>
void search_befor(string str);// like: ?<string>
void search_after(string str);//like: /string
void delete_line(int line);//like 3d
void move_to_line(int line);//like 3n move to line 3, print 3+"\t"+the row
void add_line_before();// a<\n> string <\n> . 
void add_line_after();//i <\n> string <\n>
void print();//%P print every thing
};