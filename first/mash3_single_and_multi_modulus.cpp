#include <fftw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "dsp/mash3.hpp"

int main(void)
{
	mash3 mash;
	mash3 mash_mm(16777213, (1<<24), (1<<24)-1);
	
	int N = 10000000;
        double *in = (double *) fftw_malloc(sizeof(double) * N);
        double *out = (double *) fftw_malloc(sizeof(double) * N);
        double *out_mm = (double *) fftw_malloc(sizeof(double) * N);
	
	fftw_plan p;
	
	//single modulus
	p = fftw_plan_r2r_1d(N, in, out, FFTW_REDFT00, FFTW_ESTIMATE);
        
	for(int i=0;i<N;i++) {
	  in[i]=mash.Clock();
        }
	fftw_execute(p);
	fftw_destroy_plan(p);

	//multi modulus
	p = fftw_plan_r2r_1d(N, in, out_mm, FFTW_REDFT00, FFTW_ESTIMATE);
        
	for(int i=0;i<N;i++) {
	  in[i]=mash_mm.Clock();
        }
	fftw_execute(p);
	fftw_destroy_plan(p);


	for(int i=0; i<N;i++) {
		double val = 10 * log10( fabs(out[i] * out[i]));
		double val_mm = 10 * log10( fabs(out_mm[i] * out_mm[i]));
		printf("%d,%g, %g, %g\n", i, out[i], val, val_mm);
	}
}
