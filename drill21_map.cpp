#include<iostream>
#include<string>
#include<map>
#include<numeric>
#include<stdexcept>

void read_map(std::map<std::string,int>& m)
{
	std::string s;
	int i=0;
	
	while(m.size()<10)
	{
		std::cin>>s>>i;
		m.insert(std::make_pair(s,i));
	}
}

template<typename K,typename V>
void print(const std::map<K,V>& m)
{
	int sum=0;
	for(std::pair<K,V> a : m)
	{
		std::cout<<a.first<<'\t'<<a.second<<std::endl;
	
	}
	
}
int main()
try
{
	std::map<std::string, int>msi;
	msi["a"]=1;
	msi["b"]=2;
	msi["abc"]=45;
	msi["x"]=23;
	msi["g"]=41;
	msi["wert"]=92;
	msi["j"]=30;
	msi["po"]=11;
	msi["px"]=67;
	msi["ac"]=4;

	print(msi);
	
	msi.erase("a");
	std::cout<<"a elem törlése után: "<<std::endl;
	print(msi);
	
	msi.erase(msi.begin(),msi.end());
	std::cout<<"a teljes törlés után: "<<std::endl;
	print(msi);
	
	std::cout<<"10 név érték pár megadása: "<<std::endl;
	read_map(msi);
	std::cout<<"msi: "<<std::endl;
	print(msi);
	
	  int total = std::accumulate(msi.begin(), msi.end(), 0,
            [](int sum, const std::pair<std::string,int>& p)
            { return sum += p.second; });

	std::cout << "Total of integers: " << total << '\n';
	
	std::map<int,std::string>mis;
	for(std::pair<std::string,int> a : msi)				
	{
		mis[a.second]=a.first;

	
	}
	std::cout<<std::endl<<"mis map: "<<std::endl;
	print(mis); 
	
	
	
}
catch (std::exception& e)
{
	std::cerr<<"Exception: "<<e.what()<<'\n';
	return 1;
}
catch(...)
{
	std::cerr<<"Exception"<<'\n';
	return 2;
}

