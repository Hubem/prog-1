#include <iostream>
#include <stdexcept>
#include <set>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include <numeric>

//valamiért nem fut le, nem ír hibát, csak kidob egy teljes manuált

struct Item
{
    std::string name;
    int id;
    double value;
};

std::ifstream& operator>>(std::ifstream& ifs, Item& item){
    std::string n; 
    int i; 
    double v;
    ifs >> n >> i >> v;
    Item it{n,i,v};
    item = it;
    return ifs;
};

struct erteksort{
    bool operator()(const Item& a, const Item& b)
    {
        return a.value > b.value;
    }
};
class nevkereses
{
    std::string name;
public:
    nevkereses(const std::string& n) : name{n} { }
    bool operator()(const Item& a) const { return a.name == name; }
};
class idkereses
{
    int id;
public:
    idkereses(int fid) : id{fid} { }
    bool operator()(const Item& a) const { return a.id == id; }
};

int main()
try{
	
	const std::string iname {"file.txt"};
	std::ifstream ifs {iname};
	if(!ifs )throw std::runtime_error("Could not read from file: "+iname);
	
	std::vector<Item>vi;
	std::ifstream file;
    file.open("file.txt");

    for (Item i ; file >> i;)
    {
        vi.push_back(i);
    };
	for(auto& i:vi)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.name < b.name; });
	
	for(auto& i:vi)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.id < b.id; });
	
	for(auto& i:vi)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::sort(vi.begin(), vi.end(), erteksort());
	std::cout<<"\nInsert 2 new elements"<<std::endl;

	vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});
	
	for(auto& i:vi)
	std::cout<<i.name<<i.id<<i.value<<std::endl;


	std::cout<<"\nErase two items identified by name"<<std::endl; 
    vi.erase(find_if(vi.begin(), vi.end(), nevkereses("horse shoe")));
    vi.erase(find_if(vi.begin(), vi.end(), nevkereses("Canon S400")));
   	
	for(auto& i:vi)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::cout<<"\nErase two items identified by iid"<<std::endl; 
    vi.erase(find_if(vi.begin(), vi.end(), idkereses(99)));
    vi.erase(find_if(vi.begin(), vi.end(), idkereses(9988)));
	
	for(auto& i:vi)
	std::cout<<i.name<<i.id<<i.value<<std::endl;


	//list
	std::list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());

	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::sort(li.begin(), li.end(),
            [](const Item& a, const Item& b) { return a.name < b.name; });
	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::sort(li.begin(), li.end(),
            [](const Item& a, const Item& b) { return a.id < b.id; });

	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::sort(li.begin(), li.end(),erteksort());
	
	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;


	std::cout<<"\nErase two items identified by name"<<std::endl; 
    li.erase(find_if(li.begin(), li.end(), nevkereses("horse shoe")));
    li.erase(find_if(li.begin(), li.end(), nevkereses("Canon S400")));

	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;

	std::cout<<"\nErase two items identified by iid"<<std::endl; 
    li.erase(find_if(li.begin(), li.end(), idkereses(99)));
    li.erase(find_if(li.begin(), li.end(), idkereses(9988)));
   
   	for(auto& i:li)
	std::cout<<i.name<<i.id<<i.value<<std::endl;
}
catch (std::exception& e)
{
std::cerr<<e.what()<<'\n';
return 1;
}
catch (...)
{
std::cerr<<"Unkown exception\n";
}

