# OFFT speed comparison

The mission of OFFT is to provide a truly open FFT library that delivers competitive performance for arbitrary length transforms and, at the same time, keeps the code size and maintenance effort of the library reasonable. To understand what that means and where I stand, I am running a speed comparison against two popular libraries that are generally considered *best-in-class*: FFTW and Intel oneMKL. FFTW is open-source with a paid license available for closed-source projects. The Intel MKL is closed-source and requires the user to install a faily large binary package.

## Conclusion

Speed results depend on the size. But for most cases, I would say that the oneMKL is the winner and often beats the FFTW by a factor of two or even more. Trying to achive this sort of performance is out of the scope of OFFT. If this is what you need, go and get it.

Which leaves FFTW as the only realistic competitor for OFFT. For the common cases&mdash;powers of 2 and powers of 10&mdash;OFFT has still some homework to do. For short lengths, FFTW beats OFFT by a factor of 4 (sometimes more), at longer lengths the headstart is more around 2, sometimes less.

For arbitrary lengths, the headstart is not as much and OFFT and FFTW are pretty close at times.

The focus of my efforts will therefore be on understanding where these differences come from&mdash;and trying to become better with future releases of the library.


## Compiler, libraries, and platform

The benchmark was compiled using GCC on Windows. Below is the output of `g++ --version`
```
g++.exe (Rev11, Built by MSYS2 project) 12.2.0
```
Both FFTW and MKL use the vendor supplied libraries, which are available from the links below
- FFTW: <http://www.fftw.org/install/windows.html>, download `fftw-3.3.5-dll64.zip`
- Intel oneMKL: <https://software.intel.com/en-us/oneapi/onemkl>, click on “Download the Stand-Alone Version”.

The speed test was run on my Intel i5-2450M laptop computer with 2.5 GHz running Windows 10. Pretty ancient, but this is what I have.

## Results

Numbers are nanoseconds per $n \log n$, where $n$ is the size of the transform and $\log$ the natural logarithm. For example, OFFT required $8.9 \times 16777216 \times 16.64 = 2.48~\text{seconds}$ for the length-16777216 transform. 

Columns are as follows
- **OFFT:** runtime of the OFFT
- **FFTW w/ SIMD:** plan is created with flag `FFTW_ESTIMATE`.
- **FFTW w/o SIMD:** plan is created with flag `FFTW_ESTIMATE | FFTW_NO_SIMD`. Since OFFT makes no effective use of SIMD at the moment, this columns shows me the potential benefit.
- **MKL 1-core:** descriptor created with `DftiSetValue(mDesc, DFTI_THREAD_LIMIT, 1)`
- **MKL 2-core:** descriptor created with `DftiSetValue(mDesc, DFTI_THREAD_LIMIT, 2)`. Speed gains are often way more than a factor of two. Interesting...


### Powers of two

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core |
|-------------|------------|--------------|---------------|------------|------------|
|        1024 |        3.6 |          0.6 |           2.0 |        0.6 |        0.6 |
|        2048 |        4.1 |          0.8 |           2.0 |        0.7 |        0.7 |
|        4096 |        4.0 |          1.0 |           2.4 |        0.7 |        0.7 |
|        8192 |        4.0 |          1.1 |           2.5 |        0.7 |        0.9 |
|       16384 |        4.5 |          1.1 |           2.5 |        0.8 |        0.8 |
|       32768 |        4.8 |          1.5 |           3.0 |        0.8 |        0.7 |
|       65536 |        5.2 |          1.6 |           2.8 |        1.0 |        0.8 |
|      131072 |        5.7 |          1.8 |           3.7 |        1.3 |        1.4 |
|      262144 |        5.9 |          2.6 |           4.9 |        1.4 |        1.3 |
|      524288 |        6.5 |          3.6 |           5.0 |        1.4 |        1.1 |
|     1048576 |        6.9 |          4.2 |           5.7 |        1.4 |        1.0 |
|     2097152 |        7.4 |          4.3 |           5.8 |        1.4 |        1.0 |
|     4194304 |        7.1 |          4.6 |           5.9 |        1.5 |        1.0 |
|     8388608 |        7.4 |          4.9 |           6.4 |        1.5 |        1.0 |
|    16777216 |        8.9 |          4.8 |           6.4 |        1.6 |        1.1 |

### Powers of ten

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core |
|-------------|------------|--------------|---------------|------------|------------|
|         100 |        5.7 |          0.9 |           2.4 |        1.1 |        1.1 |
|        1000 |        4.7 |          1.3 |           2.7 |        0.8 |        0.8 |
|       10000 |        4.7 |          1.1 |           2.5 |        0.9 |        1.1 |
|      100000 |        5.7 |          1.5 |           3.2 |        1.7 |        1.1 |
|     1000000 |        6.6 |          3.4 |           4.9 |        2.3 |        1.0 |
|    10000000 |        6.6 |          2.8 |           4.2 |        3.0 |        1.1 |

### Non-powers of two

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core |
|-------------|------------|--------------|---------------|------------|------------|
|        1023 |        6.5 |          3.2 |           4.0 |        3.2 |        3.1 |
|        1025 |        8.7 |          8.2 |          10.0 |        4.0 |        4.0 |
|        2047 |        9.8 |          9.4 |           7.6 |        8.8 |        8.8 |
|        2049 |       11.6 |          6.2 |          12.3 |        5.4 |        5.4 |
|        4095 |        4.4 |          1.4 |           2.8 |        1.1 |        1.1 |
|        4097 |        8.3 |          7.4 |           9.1 |        9.7 |        3.7 |
|        8191 |       10.2 |          6.7 |          13.1 |        4.6 |        4.6 |
|        8193 |        9.4 |          8.8 |          14.1 |       10.1 |        7.0 |
|       16383 |       11.7 |          5.8 |           8.9 |        4.8 |        3.0 |
|       16385 |        9.4 |          8.3 |           9.7 |       11.9 |        2.9 |
|       32767 |        8.6 |          7.4 |           8.5 |        5.9 |        2.9 |
|       32769 |        8.5 |          7.4 |          10.9 |       14.8 |        2.6 |
|       65535 |        7.5 |          6.5 |           8.1 |        7.3 |        2.8 |
|       65537 |       11.3 |          9.1 |          11.0 |       13.3 |       13.8 |
|      131071 |       20.8 |         12.0 |          19.2 |        6.6 |        6.5 |
|      131073 |       15.3 |         11.8 |          15.1 |       13.5 |       12.4 |
|      262143 |        8.3 |          6.4 |           8.1 |        6.0 |        3.1 |
|      262145 |       10.9 |         11.7 |          12.5 |       13.4 |        2.7 |
|      524287 |       17.1 |         16.1 |          21.5 |        6.6 |        6.6 |
|      524289 |       16.6 |         14.6 |          16.0 |       13.5 |       10.5 |
|     1048575 |        9.4 |          7.2 |           8.2 |        4.8 |        2.5 |
|     1048577 |       13.8 |         10.4 |          14.5 |       15.0 |        9.4 |
|     2097151 |       10.4 |          8.1 |          14.2 |        7.1 |        4.0 |
|     2097153 |       16.3 |          9.6 |          13.2 |       14.6 |        4.2 |
|     4194303 |       12.1 |         10.5 |          11.9 |        7.1 |        4.6 |
|     4194305 |       11.7 |         10.2 |          14.7 |       14.8 |        3.4 |
|     8388607 |       18.9 |         16.7 |          19.2 |        7.3 |        5.7 |
|     8388609 |       24.3 |         20.0 |          24.8 |       15.5 |       10.3 |
|    16777215 |        8.7 |          6.9 |           8.4 |        7.4 |        2.8 |
|    16777217 |       10.7 |         12.5 |          15.4 |        7.8 |        5.9 |