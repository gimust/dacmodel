#include <string>
#include <iostream>

#include "dsp/mash3.hpp"

int main(void)
{
	mash3 mash;
	int N = 10000000;
        
	for(int i=0;i<N;i++) {
	  mash.Clock(0x400001);
          std::string s = mash.getState();
          std::cout << s << std::endl;
	}
}
