#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <complex>
#else
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#endif

#ifndef FFT_PI
#    define FFT_PI 3.14159265358979323846
#endif

#ifdef __cplusplus
#   define fft_exp std::exp
#   define fft_real std::real
#   define fft_imag std::imag
#   define fft_abs std::abs
#   define FFT_J FFTComplex(0.0, 1.0)
    typedef double FFTSample;
    typedef std::complex<FFTSample> FFTComplex;
#else
#   define FFTSample double
#   define fft_exp cexp
#   define fft_real creal
#   define fft_imag cimag
#   define fft_abs cabs
#   define FFT_J I
    typedef FFTSample _Complex FFTComplex;
#endif

int fft_nbits(int n)
{
    return ceil(log(n)/log(2));
}

FFTComplex * fft_conv(FFTSample *arr, int n)
{
    FFTComplex *x = (FFTComplex *) malloc(sizeof(FFTComplex) * (1 << fft_nbits(n)));
    int i;
    for (i = 0; i < n; i++) {
        x[i] = arr[i];
    }
    return x;
}

static void fft_recurse(FFTComplex *buf, FFTComplex *tmp, int N, int step, int inv)
{
    int k;
    FFTComplex t, ang;
    if (step < N) {
        fft_recurse(tmp, buf, N, step * 2, inv);    // On even elements
        fft_recurse(tmp + step, buf + step, N, step * 2, inv); // On odd elements
        for (k = 0; k < N/2; k += step) {
            ang = (FFTComplex) k / (FFTComplex) N;
            if (!inv) {
                t = fft_exp(-FFT_J * 2.0 * FFT_PI * ang) * tmp[2*k + step];
            } else {
                t = fft_exp(FFT_J * 2.0 * FFT_PI * ang) * tmp[2*k + step];
            }
            buf[k]       = tmp[2*k] + t;    // y[k] = y_even[k] + w*y_odd[k]
            buf[k + N/2] = tmp[2*k] - t;    // y[k + n/2] = y_even[k] - w*y_odd[k]
        }
    }
}

void fft_compute(FFTComplex *buf, int nbits, int inv)
{
    int N = 1 << nbits;
    FFTComplex *tmp = (FFTComplex *) malloc(sizeof(FFTComplex) * N);
    for (int i = 0; i < N; i++) tmp[i] = buf[i];
    fft_recurse(buf, tmp, N, 1, inv);
    for (int i = 0; i < N; i++) buf[i] *= 1/sqrt(N);
    free(tmp);
}

void show(FFTComplex *buf)
{
    for (int i = 0; i < 8; i++) {
        if (!fft_imag(buf[i])) {
        printf("%g ", fft_real(buf[i]));
        } else {
        printf("(%g, %g) ", fft_real(buf[i]), fft_imag(buf[i]));
        }
    }
}

int main()
{
    FFTSample arr[8] = {1,1,1,1,0,0,0,0};
    FFTComplex * buf = fft_conv(arr, 8);
    show(buf);
    printf("\n");
    fft_compute(buf, fft_nbits(8), 0);
    show(buf);
    printf("\n");
    return 0;
}
