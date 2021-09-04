#include <stdio.h>
#include <time.h>
#include <complex.h>
#include <fftw3.h>

int main()
{

    size_t N = 16*1024*1024;
    double pi = std::acos(-1);
    fftw_complex j = {0.0, 1.0};


    printf("allocating %5.1lfMB memory\n", 2.0*double(N)*sizeof(fftw_complex)/(1024*1024));
    fftw_complex* idata = fftw_alloc_complex(N);
    fftw_complex* odata = fftw_alloc_complex(N);


    printf("planning fft\n");
    fftw_plan p = fftw_plan_dft_1d(N, idata, odata, FFTW_FORWARD, FFTW_ESTIMATE);


    printf("generating input data\n");
    double w = 2.0*pi/N;
    for (int i=0; i<N; i++) {
        idata[i][0] = cos(w*i); // real
        idata[i][1] = sin(w*i); // imag
    }


    printf("executing fft\n");
    clock_t time0, time1;
    double exec_time;
    time0 = clock();
    fftw_execute(p);
    time1 = clock();
    exec_time = (double)(time1-time0)/CLOCKS_PER_SEC;
    printf("\nfft execution time = %lf.  N = %ld\n", exec_time, N);


/*
    printf("writing odata.dat\n");
    FILE* fp = fopen("odata.dat", "w");
    for (int i=0; i<N; i++) {
        fprintf(fp, "%lf    %lf\n", odata[i][0], odata[i][1]);
    }
    fclose(fp);
*/


    printf("de-allocating memory\n");
    fftw_destroy_plan(p);
    fftw_free(idata); fftw_free(odata);

}

