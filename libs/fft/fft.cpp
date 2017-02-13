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

/** Return log of nearest power of 2 */
int fft_nbits(int n)
{
    return ceil(log(n)/log(2));
}

/** Convert array of reals to complex */
FFTComplex * fft_conv(FFTSample *arr, int n)
{
    FFTComplex *x = (FFTComplex *) malloc(sizeof(FFTComplex) * (1 << fft_nbits(n)));
    int i;
    for (i = 0; i < n; i++) {
        x[i] = arr[i];
    }
    return x;
}

/** In-place recursive FFT.
 * \param buf    Complex input samples, in a power of 2
 * \param tmp    Scratchpad array (initial call should contain copy of buf)
 * \param N      Length of buf
 * \param step   Used to traverse even/odd during recursive calls 
 * \param inv    Set to non-zero if you want IFFT
 */
static void fft_recurse(FFTComplex *buf, FFTComplex *tmp, int N, int step, int inv)
{
    int k;
    FFTComplex t;
    if (step < N) {
        fft_recurse(tmp, buf, N, step * 2, inv);    // On even elements
        fft_recurse(tmp + step, buf + step, N, step * 2, inv); // On odd elements
        for (k = 0; k < N/2; k += step) {
            if (!inv) {
                t = fft_exp(FFT_J * 2 * FFT_PI * (FFTSample) (k/N)) * tmp[2*k + step];
            } else {
                t = fft_exp(FFT_J * 2 * FFT_PI * (FFTSample) (k/N)) * tmp[2*k + step];
            }
            buf[k]       = tmp[2*k] + t;    // y[k] = y_even[k] + w*y_odd[k]
            buf[k + N/2] = tmp[2*k] - t;    // y[k + n/2] = y_even[k] - w*y_odd[k]
        }
    }
}

/** In-place FFT (wrapper for fft_recurse).
 * \param buf    Complex input samples, size is a power of 2
 * \param nbits  2^nb = Length of buf
 * \param inv    Set to non-zero if you want IFFT
 */
void fft_compute(FFTComplex *buf, int nbits, int inv)
{
    int N = 1 << nbits;
    FFTComplex *tmp = (FFTComplex *) malloc(sizeof(FFTComplex) * N);
    for (int i = 0; i < N; i++) tmp[i] = buf[i];
    fft_recurse(buf, tmp, N, 1, inv);
    for (int i = 0; i < N; i++) buf[i] *= 1/sqrt(N);
    free(tmp);
}

int main()
{
    FFTSample arr[8] = {1,1,1,1,0,0,0,0};
    FFTComplex * buf = fft_conv(arr, 8);
    for (int i = 0; i < 8; i++) {
        printf("(%f, %f) ", fft_real(buf[i]), fft_imag(buf[i]));
    }
    printf("\n");
    fft_compute(buf, fft_nbits(8), 0);
    for (int i = 0; i < 8; i++) {
        printf("(%f, %f) ", fft_real(buf[i]), fft_imag(buf[i]));
    }
    printf("\n");
    fft_compute(buf, fft_nbits(8), 1);
    for (int i = 0; i < 8; i++) {
        printf("(%f, %f) ", fft_real(buf[i]), fft_imag(buf[i]));
    }
    printf("\n");
    return 0;
}
