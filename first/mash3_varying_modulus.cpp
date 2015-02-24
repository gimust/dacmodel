#include <fftw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "dsp/mash3.hpp"

void run(mash3 *, double *);

const int N = 1000000;

int main(void)
{
	mash3 mash3_8 ((1<<8),  (1<<8 ), (1<<8));
	mash3 mash3_16((1<<16), (1<<16), (1<<16));
	mash3 mash3_24((1<<24), (1<<24), (1<<24));
	
        double *out8 = (double *) fftw_malloc(sizeof(double) * N);
        double *out16 = (double *) fftw_malloc(sizeof(double) * N);
        double *out24 = (double *) fftw_malloc(sizeof(double) * N);

	run(&mash3_8, out8);
        run(&mash3_16, out16);
        run(&mash3_24, out24);
	
	for(int i=0; i<N;i++) {
		double val8  = 10 * log10( fabs(out8[i]  * out8[i]));
		double val16 = 10 * log10( fabs(out16[i] * out16[i]));
		double val24 = 10 * log10( fabs(out24[i] * out24[i]));
		printf("%d, %g, %g, %g\n", i, val8, val16, val24);
	}
}

void run(mash3 *mash, double *out)
{
        double *in = (double *) fftw_malloc(sizeof(double) * N);
	fftw_plan p;
	
	//single modulus
	p = fftw_plan_r2r_1d(N, in, out, FFTW_REDFT00, FFTW_ESTIMATE);
        
	for(int i=0;i<N;i++) {
	  in[i]=mash->Clock();
        }
	fftw_execute(p);
	fftw_destroy_plan(p);
}
