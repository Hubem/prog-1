#include <iostream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

struct Person
{
	public:
		Person(){}
		Person(string f,string l,int a):f{f},l{l},a{a}
		{
			const vector<char>invalidchars={';','?',':','[',']','*','&','^','%','$','#','@','!','.','"','\''};
			bool invname;
			bool invage;
			if (a <=0 or a>150)
				{
				throw runtime_error("Invalid age");
				invage=true;
				};
			for (int i=0;i<invalidchars.size();i++)
				if (f.find(invalidchars[i]) != string::npos || l.find(invalidchars[i]) != string::npos)
				{
				throw runtime_error("Invalid name");
				invname=true;
				};
			if(invname==true && invage==true)
				throw runtime_error("Both name and age are invalid");
				
		
		};
	
		
		string firstname()const {return f;}
		string lastname() const {return l;}
		int agee()  	  const {return a;}
		
		
		private:
		string f;
		string l;
		int a;	
};

ostream& operator<< (ostream& os, Person& p)
{
	return os<<p.firstname()<<' '<<p.lastname()<<", "<<p.agee()<<endl;
}
istream& operator>> (istream& is, Person& p)
{
	string first;
	string last;
	int a;
	cout<<"Enter a first name: ";
	is>>first;
	cout<<"Enter a last name: ";
	is>>last;
	cout<<"Enter an age: ";
	is>>a;
	p=Person(first,last,a);
	return is;
}


int main()
{
	try
	{
	Person p{"Goofy","Goofy",63};
	cout<<p;
	Person p1;
	cin>>p1;
	cout<<p1<<endl;


	cout<<"Break with typing endl";
	vector<Person>vec;
	for(Person p2; cin>>p2;)
	{
		if(p2.firstname()=="endl")break;
		vec.push_back(p2);
	}
	for(Person p: vec)
	{
		cout<<p<<endl;
		return 0;
	}
	
	}
	catch(exception& e) 
	{
	cerr<<"exception: "<<e.what()<<'\n';
	return 1;
	
	
	}
	catch(...) {
	cerr<<"error\n";
	return 2;
	}
}





