#include <iostream>
#include<stdexcept>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>

template<typename C>
void print(const C& c, char sep='\n')
{
	std::cout<<"Container elements:\n";
	
	for(const auto elem: c)
	{
	std::cout<<elem<<sep;
	}
	std::cout<<std::endl;
};

class Less_than
{
	double v;
	public:
		Less_than(double vv): v{vv}{}
		bool operator() (const double val) {return val<v;}
};
template<typename T>
double sum(const std::vector<T>& t)
{
    double vec_sum;
    for (const auto a : t)
        vec_sum += a;
    return vec_sum;
};

int main()
try{
	
    const std::string iname {"input_floats.txt"};
    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

    std::vector<double> vd;
    for (double d; ifs >> d; )
        vd.push_back(d);

    print(vd);

    std::vector<int> vi (vd.size());
    std::copy(vd.begin(), vd.end(), vi.begin());

    for (int i = 0; i < vd.size(); ++i)
        std::cout << vd[i] << '\t' << vi[i] << '\n';

    std::cout << "Sum of vector<double>: " << sum(vd) << '\n';

    std::cout << "Difference sum(vd)-sum(vi)= " << sum(vd)-sum(vi) << std::endl;
    

   
    std::reverse(vd.begin(), vd.end());

    print(vd);

    
    double vd_mean = sum(vd) / vd.size();

    std::cout << "The mean of vd is: " << vd_mean << '\n';

     std::cout << "Elements of vd2: " <<std::endl;
            std::vector<double> vd2;
            for(auto i: vd)
            {
                if (i < vd_mean)
                {
                    vd2.push_back(i);
                }
            }
            print(vd2);


    std::cout << "Sorted vd2 elements: " <<std::endl;
            sort(vd.begin(),vd.end());
            print(vd);
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
