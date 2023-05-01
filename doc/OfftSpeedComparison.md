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
|        1024 |        2.8 |          0.6 |           2.0 |        0.6 |        0.6 |
|        2048 |        3.4 |          0.8 |           2.1 |        0.7 |        0.7 |
|        4096 |        3.5 |          1.0 |           2.4 |        0.7 |        0.7 |
|        8192 |        3.7 |          1.0 |           2.5 |        0.7 |        0.8 |
|       16384 |        4.2 |          1.0 |           2.5 |        0.8 |        0.8 |
|       32768 |        4.4 |          1.2 |           3.0 |        0.8 |        0.7 |
|       65536 |        4.3 |          1.2 |           2.8 |        1.0 |        0.8 |
|      131072 |        5.0 |          1.6 |           3.8 |        1.3 |        1.0 |
|      262144 |        5.7 |          2.3 |           4.9 |        1.4 |        0.9 |
|      524288 |        6.4 |          3.0 |           4.8 |        1.4 |        1.0 |
|     1048576 |        6.8 |          3.9 |           5.7 |        1.4 |        1.0 |
|     2097152 |        6.4 |          4.0 |           5.7 |        1.4 |        1.0 |
|     4194304 |        6.9 |          4.2 |           5.9 |        1.4 |        1.0 |
|     8388608 |        7.1 |          4.7 |           6.4 |        1.5 |        1.0 |
|    16777216 |        8.8 |          4.7 |           6.5 |        1.6 |        1.3 |

### Powers of ten

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core |
|-------------|------------|--------------|---------------|------------|------------|
|         100 |        4.6 |          0.9 |           2.5 |        1.1 |        1.1 |
|        1000 |        3.8 |          1.3 |           2.7 |        0.8 |        0.8 |
|       10000 |        4.4 |          1.0 |           2.5 |        0.9 |        1.0 |
|      100000 |        5.4 |          1.5 |           3.1 |        1.5 |        1.1 |
|     1000000 |        6.1 |          3.4 |           4.9 |        2.3 |        1.1 |
|    10000000 |        6.3 |          2.5 |           4.8 |        3.0 |        1.2 |

### Non-powers of two

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core |
|-------------|------------|--------------|---------------|------------|------------|
|        1023 |        6.1 |          3.2 |           3.9 |        3.1 |        3.1 |
|        1025 |        6.9 |          8.1 |          10.0 |        3.9 |        3.9 |
|        2047 |        8.7 |          9.3 |           7.6 |        8.7 |        8.7 |
|        2049 |       11.1 |          6.2 |          12.3 |        5.4 |        5.4 |
|        4095 |        4.1 |          1.4 |           2.8 |        1.1 |        1.1 |
|        4097 |        7.5 |          7.4 |           9.1 |        9.6 |        3.7 |
|        8191 |        9.7 |         10.6 |          15.1 |        4.5 |        4.5 |
|        8193 |        9.0 |          8.0 |          14.0 |        9.7 |        7.0 |
|       16383 |        9.4 |          5.7 |           8.8 |        4.7 |        3.1 |
|       16385 |        7.8 |          7.1 |           9.6 |       11.6 |        2.9 |
|       32767 |        8.0 |          7.4 |           8.4 |        5.8 |        2.6 |
|       32769 |        7.9 |          5.9 |          10.7 |       14.5 |        2.6 |
|       65535 |        6.9 |          6.4 |           8.0 |        7.1 |        2.5 |
|       65537 |        9.3 |          7.9 |          10.9 |       13.4 |       13.3 |
|      131071 |       14.3 |         11.0 |          19.3 |        6.6 |        6.5 |
|      131073 |       14.0 |         11.5 |          17.6 |       17.2 |       14.8 |
|      262143 |        7.5 |          6.5 |           8.0 |        6.0 |        3.0 |
|      262145 |        8.6 |         11.7 |          12.6 |       13.3 |        2.5 |
|      524287 |       15.2 |         15.9 |          21.3 |        6.6 |        6.8 |
|      524289 |       14.3 |         12.3 |          15.5 |       13.4 |       10.8 |
|     1048575 |        7.9 |          7.2 |           8.2 |        4.8 |        2.5 |
|     1048577 |       12.9 |         10.7 |          14.4 |       13.2 |        7.6 |
|     2097151 |        8.8 |          7.3 |          12.7 |        6.6 |        3.8 |
|     2097153 |       12.8 |          7.8 |          12.3 |       14.5 |        4.0 |
|     4194303 |       11.4 |          9.7 |          11.6 |        7.2 |        4.4 |
|     4194305 |       10.8 |          9.7 |          14.8 |       15.0 |        3.3 |
|     8388607 |       16.4 |         15.2 |          19.3 |        7.4 |        5.7 |
|     8388609 |       23.6 |         19.6 |          24.6 |       15.1 |       10.1 |
|    16777215 |        8.1 |          6.8 |           8.6 |        7.4 |        2.7 |
|    16777217 |        9.8 |         12.5 |          15.4 |        7.7 |        5.8 |
