#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename C>
void print_contents(const C& c)
{
for(auto& a : c)
cout<<a<<' ';
cout<<endl;
}

template<typename C>
void inc(C& c, int n)
{
	for(auto& a : c)
		a+=n;
}

template<typename Iter1, typename Iter2>
Iter2 i_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 p=f1;p!=e1;++p)
	{
		*f2=*p;
	}
	return f2;

}

int main()
{

	constexpr int size=10;
	
	int arr[size];
	for(int i=0;i<size;i++)arr[i]=i;
	
	array<int, size> ai;
	std::copy(arr,arr+size,ai.begin());
	print_contents(arr);
	
	vector<int>vi(size);
	std::copy(arr,arr+size,vi.begin());
	print_contents(vi);
	
	list<int> li(size);
	std::copy(arr,arr+size,li.begin());
	print_contents(li);
	
	array<int, size> ai2=ai;
	vector<int> vi2=vi;
	list<int> li2=li;

	inc(ai2,2);
	inc(vi2,3);
	inc(li2,5);	
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);	
	
	i_copy(ai2.begin(),ai2.end(),vi2.begin());
	i_copy(li2.begin(),li2.end(),ai2.begin());


	list<int>::iterator lit;
    	lit = find(li2.begin(), li2.end(), 27);
    	if (lit != li2.end())
        	cout << "Found at: " << distance(li2.begin(), lit);
   	 else
        	cout << "Not found";

	
}
