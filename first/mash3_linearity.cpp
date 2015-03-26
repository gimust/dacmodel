#include <string>
#include <iostream>

#include "dsp/mash3.hpp"

void test(int i);

int main(void)
{
	const int range=1<<24;
	const int steps=10;
	const int step=range/steps;

	std::cerr << "Testing from 0 to " << range << " in " << steps << " steps " << std::endl;

	std::cout << "Input Output" << std::endl;
	for(int i=0; i<range; i+=step) {
		test(i);
	}
}

void test(int value)
{
	mash3 mash;
	int N = (1<<24);
        int total=0;
 
	for(int i=0;i<N;i++) {
	  total += mash.Clock(value);
	}

	std::cout << value << " " << total << std::endl;
}
