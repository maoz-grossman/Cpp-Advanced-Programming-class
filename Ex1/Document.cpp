#include<string>
#include<iostream>
#include <fstream>
#include <regex>
#include"Document.h"
using namespace std;


Document::Document()
{
    ind=txtFile.begin();
}


void Document::connect_line(int num1 ,int num2)////num should be -1 to the original
{
	list<string>::iterator it=txtFile.begin();
	for(decltype(txtFile.size())i=0; i!=num2;++i)
	{
		++it;
	}
	ind=txtFile.begin();
	for(decltype(txtFile.size())i=0; i!=num1;++i)
	{
		++ind;
	}
	(*ind)+=(*it);
	txtFile.erase(it);
}//like 3,4j connet line 3 with 4 then remove 


void Document::exchange_words(string old_word ,string new_word)
{
	//cout<<"the line before: "<<*ind<<endl;
	(*ind) = std::regex_replace(*ind,regex(old_word), new_word);
	//cout<<"we changed the line to: "<<*ind<<endl;
}//‫‪s/old/new/‬‬


void Document::add_line_before()
{
	string str="";
	bool readLines =true;
	int i=0;
	while(readLines)
	{
		getline(cin, str);
		if(str==".")
		{
			readLines=false;
		}
		else
		{
			txtFile.insert(ind,str);
			i++;
			// cout<<*ind<<" ::c"<<endl;
		}
	}
	for(int j=0;j!=i;j++)
		ind++;
}//like: i <string>  .


void Document::search_befor(string str)
{
	list<string>::iterator it =ind;
	for(ind=it; ind!=txtFile.begin();--ind)
	{
		string s2=(*ind);
		if (s2.find(str) != std::string::npos)
		{
			cout<<s2<<endl;
			break;
		}
	}
}//like: ?<string> 

void Document::search_after(string str)
{
	list<string>::iterator it =ind;
	for(ind=it; ind!=txtFile.end();++ind)
	{
		string s2=(*ind);
		if (s2.find(str) != std::string::npos)
		{
			cout<<s2<<endl;
			break;
		}
	}
}//like: /<string>


void Document::delete_line(int line)
{
	list<string>::iterator it=txtFile.begin();
	for(decltype(txtFile.size())i=0; i!=line;++i)
	{
		++it;
	}
	ind=it;
	ind++;
	txtFile.erase(it);
}//like 3d


void Document::move_to_line(int line)
{
	//cout<<"the line is :"<<line<<"list size is "<<txtFile.size()<<endl;
	if(line>txtFile.size()-1)
	{
		return;
	}
	ind = txtFile.begin();
	for(decltype(txtFile.size())i=0; i!=line;++i)
	{
		++ind;
	}
	cout<<line+1<<"	"<<*ind<<endl;
	
}//like 3n move to line 3, print 3+"\t"+the row


void Document::exchange_line()
{
	list<string>::iterator it= ind;
	this->add_line_after();
	txtFile.erase(it);
}// c <\n> string <\n> . 


void Document::add_line_after()
{
	string str="";
	bool readLines =true;
	while(readLines)
	{
		getline(cin, str);
		if(str==".")
		{
			readLines=false;
		}
		else
		{
			if (ind != txtFile.end()) 
			{
			ind++;
			ind=txtFile.insert(ind,str);
			}
			else
			{
				ind=txtFile.insert(txtFile.end(),str);
			}
		}
	}
}//a <\n> string <\n>



void Document::print()
{
    for(string str: txtFile)
    {
        cout<<str<<endl;
    }
	ind=(--txtFile.end());
}//%P print every thing
