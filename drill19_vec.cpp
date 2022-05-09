#include <iostream>
#include <string>
#include <vector>

using namespace std;


template<typename T> struct S
{
	S(T vv=0) : val{vv}{}
	T& get();
	void set(T new_t) {val=new_t;}
	void operator=(const T&);
	
	T val;
};
template<typename T>
T& S<T>::get()
{
	return val;
};


template<typename T>
void S<T>::operator=(const T& s){
	val=s;
};

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if (i < v.size()-1)
		{
			os << ", ";
		}
	}
	os << "}" << endl;
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
char ch = 0;
	is >> ch;
	if (ch != '{')
	{
		is.unget();
		return is;
	}
	for (T val; is >> val;)
	{
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	return is;
}

template<typename T> void read_val(T& v){
	cin>>v;
}

	
int main(){

	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd{3.2};
	S<string> ss {"hello"};
	S<vector<int>> svi{vector<int>{1,1,2,3,5,8}};
	
	cout<< "S<int> : "<<s.get()<<endl
	    << "S<int> : "<<si.get()<<endl
	    << "S<char> : "<<sc.get()<<endl
	    << "S<double> : "<<sd.get()<<endl
	    << "S<string> : "<<ss.get()<<endl
	    << "S<vector<int>> : ";
	    for(auto a: svi.get()){
	    cout <<a<<' ';
	    }
	    cout<<endl;
	    		
	sc.set('s');
	cout<<"S<char> : "<<sc.get()<<endl;
	
	si=30;
	cout<<"S<int> : "<<si.get()<<endl;
	
	int ii;
	read_val(ii);
	S<int>si2{ii};
	
	double dd;
	read_val(dd);
	S<double>sd2{dd};
	
	string str;
	read_val(str);
	S<string>ss2{str};
	
	cout<< "S<int> : "<<si2.get()<<endl
	 << "S<double> : "<<sd2.get()<<endl		
	 << "S<string> : "<<ss2.get()<<endl;
	 
	cout << "Vector<int>: (format: { val1, val2, val3 }) ";
   	vector<int> vi2;
   	read_val(vi2);
   	S<vector<int>> svi2 {vi2};
	cout <<"S<vector<int>> read: "<<svi2.get()<<endl;
	
}	
