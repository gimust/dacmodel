#include <fftw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "dsp/mash3.hpp"

void run(mash3 *, double *);

const int N = 1<<24;
const int VAL = ((1<<23) + 1);

int main(void)
{
	mash3 mash3((1<<24), (1<<24), (1<<24));
	
        double *in = (double *) fftw_malloc(sizeof(double) * N);
        double *out = (double *) fftw_malloc(sizeof(double) * N);
	
	fftw_plan p;
	p = fftw_plan_r2r_1d(N, in, out, FFTW_REDFT00, FFTW_ESTIMATE);
        
	for(int i=0;i<N;i++) {
	  in[i]=mash3.Clock(VAL);
        }
	
	fftw_execute(p);

	for(int i=0; i<N;i++) {
		double val = 10 * log10( fabs(out[i] * out[i]));
		printf("%d, %g\n", i, val);
	}

	fftw_destroy_plan(p);
}
