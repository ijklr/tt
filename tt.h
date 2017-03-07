#include <sys/time.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>


template <typename I>
class Tt {
    public:
	Tt() {
	    gettimeofday(&_tv,NULL);
	};

	I micro() {
	    struct timeval tv;
	    gettimeofday(&tv,NULL);
	    I i = (tv.tv_sec - _tv.tv_sec) * 1000000 + 
		(tv.tv_usec - _tv.tv_usec);
	    gettimeofday(&_tv,NULL);
	    return i;
	}
    private:
	struct timeval _tv;
};

template <typename I>
void print_stats(const std::vector<I> &v) 
{
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double mean = sum / v.size();
    std::vector<double> diff(v.size());
    for(int i=0; i< diff.size(); ++i) {
	diff[i] = diff[i] - mean;
    }
    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / v.size());
    std::cout << "count="<<v.size()<<std::endl;
    std::cout << "sum="<<sum<<std::endl;
    std::cout << "mean="<<mean<<std::endl;
    std::cout << "standar deviation="<<stdev<<std::endl;
}
