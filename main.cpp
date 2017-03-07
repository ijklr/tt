#include <iostream>
#include "tt.h"
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    Tt<int> tt;
    vector<int> a, b;

    for(int i=0; i<500; ++i) {
	usleep(10);
	a.push_back(tt.micro());
	usleep(1000);
	b.push_back(tt.micro());
    }
    cout<<"done!"<<endl;
    print_stats(a);
    print_stats(b);

}
