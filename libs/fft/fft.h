#ifndef FFT_H
#define FFT_H

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
int fft_nbits(int n);

/** Convert array of reals to complex.
 * \param arr   Array of reals
 * \param n     Number of elements in the array to copy (may not be power of 2) 
 * \return      Malloc-d array of FFTComplex, size is nearest power of 2 of n
 */
FFTComplex * fft_conv(FFTSample *arr, int n);

/** In-place FFT (wrapper for fft_recurse).
 * \param buf    Complex input samples, size is a power of 2
 * \param nbits  2^nb = Length of buf
 * \param inv    Set to non-zero if you want IFFT
 */
void fft_compute(FFTComplex *buf, int nbits, int inv);

#endif // FFT_H
