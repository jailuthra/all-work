#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

typedef double FFTSample;

typedef struct {
    FFTSample re;
    FFTSample im;
} FFTComplex;

/** Return log of nearest power of 2 */
int fft_nbits(int n)
{
    return ceil(log(n)/log(2));
}

/** Convert array of reals to complex */
FFTComplex * fft_conv(FFTSample *arr, int n)
{
    FFTComplex *x = malloc(sizeof(FFTComplex) * (1 << fft_nbits(n)));
    int i;
    for (i = 0; i < n; i++) {
        x[i].re = arr[i];
    }
    return x;
}

/** Compute e^(2pi j (k/n)) */
static inline FFTComplex fft_exp(int k, int n)
{
    const float angle = (2 * M_PI * k) / n;
    return (FFTComplex) {cos(angle), sin(angle)};
}

/** Multiply two complex numbers */
static inline FFTComplex fft_mult(FFTComplex a, FFTComplex b)
{
    return (FFTComplex) {(a.re * b.re - a.im * b.im), (a.re * b.im + a.im * b.re)};
}

/** Add two complex numbers */
static inline FFTComplex fft_add(FFTComplex a, FFTComplex b)
{
    return (FFTComplex) {a.re + b.re, a.im + b.im};
}

/** Subract two complex numbers */
static inline FFTComplex fft_sub(FFTComplex a, FFTComplex b)
{
    return (FFTComplex) {a.re - b.re, a.im - b.im};
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
                t = fft_mult(fft_exp(-k, N), tmp[2*k + step]);
            } else {
                t = fft_mult(fft_exp(k, N), tmp[2*k + step]);
            }
            buf[k] = fft_add(tmp[2*k], t);  // y[k] = y_even[k] + w*y_odd[k]
            buf[k + N/2] = fft_sub(tmp[2*k], t);   // y[k + n/2] = y_even[k] - w*y_odd[k]
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
    FFTComplex *tmp = malloc(sizeof(FFTComplex) * N);
    for (int i = 0; i < N; i++) tmp[i] = buf[i];
    fft_recurse(buf, tmp, N, 1, inv);
}

int main()
{
    FFTSample arr[8] = {1,1,1,1,0,0,0,0};
    FFTComplex * buf = fft_conv(arr, 8);
    fft_compute(buf, fft_nbits(8), 0);
    for (int i = 0; i < 8; i++) {
        printf("(%f, %f) ", buf[i].re, buf[i].im);
    }
    printf("\n");
    fft_compute(buf, fft_nbits(8), 1);
    for (int i = 0; i < 8; i++) {
        printf("(%f, %f) ", buf[i].re, buf[i].im);
    }
    printf("\n");
    return 0;
}
