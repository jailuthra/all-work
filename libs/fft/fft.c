#include "fft.h"

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
