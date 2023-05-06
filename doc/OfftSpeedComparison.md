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

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core | Factors
|-------------|------------|--------------|---------------|------------|------------|-----------
|        1024 |        2.8 |          0.6 |           2.0 |        0.6 |        0.6 | 2<sup>10</sup>
|        2048 |        3.4 |          1.0 |           2.1 |        0.7 |        0.7 | 2<sup>11</sup>
|        4096 |        3.5 |          1.0 |           2.4 |        0.7 |        0.7 | 2<sup>12</sup>
|        8192 |        3.7 |          1.0 |           2.5 |        0.7 |        0.8 | 2<sup>13</sup>
|       16384 |        4.2 |          1.1 |           2.6 |        0.8 |        0.7 | 2<sup>14</sup>
|       32768 |        4.5 |          1.2 |           3.0 |        0.8 |        0.7 | 2<sup>15</sup>
|       65536 |        4.4 |          1.2 |           2.8 |        1.0 |        0.8 | 2<sup>16</sup>
|      131072 |        5.1 |          1.6 |           3.8 |        1.3 |        0.9 | 2<sup>17</sup>
|      262144 |        5.8 |          2.3 |           4.8 |        1.4 |        0.9 | 2<sup>18</sup>
|      524288 |        6.5 |          3.3 |           5.0 |        1.4 |        1.0 | 2<sup>19</sup>
|     1048576 |        6.9 |          4.0 |           5.7 |        1.4 |        1.0 | 2<sup>20</sup>
|     2097152 |        6.5 |          4.0 |           5.7 |        1.4 |        1.0 | 2<sup>21</sup>
|     4194304 |        7.2 |          4.3 |           5.9 |        1.5 |        1.0 | 2<sup>22</sup>
|     8388608 |        7.4 |          4.7 |           6.4 |        1.5 |        0.9 | 2<sup>23</sup>
|    16777216 |        8.9 |          4.7 |           6.5 |        1.6 |        1.1 | 2<sup>24</sup>

### Powers of ten

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core | Factors
|-------------|------------|--------------|---------------|------------|------------|-----------
|         100 |        4.3 |          0.8 |           2.5 |        1.1 |        1.1 | 2<sup>2</sup>&thinsp;&middot;&thinsp;5<sup>2</sup>
|        1000 |        3.8 |          1.3 |           2.7 |        0.8 |        0.8 | 2<sup>3</sup>&thinsp;&middot;&thinsp;5<sup>3</sup>
|       10000 |        4.5 |          1.1 |           2.5 |        0.9 |        1.0 | 2<sup>4</sup>&thinsp;&middot;&thinsp;5<sup>4</sup>
|      100000 |        5.5 |          1.4 |           3.1 |        1.5 |        1.1 | 2<sup>5</sup>&thinsp;&middot;&thinsp;5<sup>5</sup>
|     1000000 |        6.1 |          3.6 |           4.9 |        2.3 |        1.0 | 2<sup>6</sup>&thinsp;&middot;&thinsp;5<sup>6</sup>
|    10000000 |        6.4 |          2.5 |           5.1 |        3.2 |        1.2 | 2<sup>7</sup>&thinsp;&middot;&thinsp;5<sup>7</sup>

### Non-powers of two

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core | Factors
|-------------|------------|--------------|---------------|------------|------------|-----------
|        1023 |        6.0 |          3.2 |           3.9 |        3.1 |        3.1 | 3&thinsp;&middot;&thinsp;11&thinsp;&middot;&thinsp;31
|        1025 |        7.1 |          8.0 |           9.9 |        4.1 |        3.9 | 5<sup>2</sup>&thinsp;&middot;&thinsp;41
|        2047 |        8.6 |          9.0 |           7.6 |        8.8 |        8.8 | 23&thinsp;&middot;&thinsp;89
|        2049 |       10.9 |          6.3 |          12.2 |        5.4 |        5.4 | 3&thinsp;&middot;&thinsp;683
|        4095 |        4.2 |          1.4 |           2.8 |        1.1 |        1.1 | 3<sup>2</sup>&thinsp;&middot;&thinsp;5&thinsp;&middot;&thinsp;7&thinsp;&middot;&thinsp;13
|        4097 |        7.4 |          7.3 |           9.1 |        9.6 |        3.7 | 17&thinsp;&middot;&thinsp;241
|        8191 |        9.4 |          8.2 |          13.8 |        4.5 |        4.5 | 8191
|        8193 |        8.9 |          8.0 |          14.0 |        9.9 |        9.1 | 3&thinsp;&middot;&thinsp;2731
|       16383 |        9.7 |          5.8 |           8.9 |        4.7 |        3.2 | 3&thinsp;&middot;&thinsp;43&thinsp;&middot;&thinsp;127
|       16385 |        7.9 |          7.2 |           9.5 |       11.6 |        3.0 | 5&thinsp;&middot;&thinsp;29&thinsp;&middot;&thinsp;113
|       32767 |        7.8 |          7.4 |           8.4 |        5.7 |        3.0 | 7&thinsp;&middot;&thinsp;31&thinsp;&middot;&thinsp;151
|       32769 |        7.7 |          5.8 |          10.8 |       14.4 |        2.5 | 3<sup>2</sup>&thinsp;&middot;&thinsp;11&thinsp;&middot;&thinsp;331
|       65535 |        6.7 |          6.3 |           7.9 |        7.0 |        2.6 | 3&thinsp;&middot;&thinsp;5&thinsp;&middot;&thinsp;17&thinsp;&middot;&thinsp;257
|       65537 |        9.5 |          7.9 |          11.1 |       13.2 |       13.1 | 65537
|      131071 |       14.4 |         11.3 |          19.4 |        6.4 |        6.4 | 131071
|      131073 |       14.1 |         11.7 |          14.9 |       13.2 |       11.9 | 3&thinsp;&middot;&thinsp;43691
|      262143 |        7.5 |          6.4 |           8.0 |        5.9 |        3.2 | 3<sup>3</sup>&thinsp;&middot;&thinsp;7&thinsp;&middot;&thinsp;19&thinsp;&middot;&thinsp;73
|      262145 |        8.9 |         11.6 |          12.4 |       13.3 |        2.7 | 5&thinsp;&middot;&thinsp;13&thinsp;&middot;&thinsp;37&thinsp;&middot;&thinsp;109
|      524287 |       15.0 |         16.0 |          21.3 |        6.6 |        6.6 | 524287
|      524289 |       14.6 |         11.8 |          15.3 |       13.3 |       10.8 | 3&thinsp;&middot;&thinsp;174763
|     1048575 |        7.9 |          7.2 |           8.2 |        4.8 |        2.5 | 3&thinsp;&middot;&thinsp;5<sup>2</sup>&thinsp;&middot;&thinsp;11&thinsp;&middot;&thinsp;31&thinsp;&middot;&thinsp;41
|     1048577 |       12.8 |         10.5 |          14.5 |       13.1 |        7.6 | 17&thinsp;&middot;&thinsp;61681
|     2097151 |        9.4 |          7.2 |          12.7 |        6.5 |        4.2 | 7<sup>2</sup>&thinsp;&middot;&thinsp;127&thinsp;&middot;&thinsp;337
|     2097153 |       13.4 |          9.2 |          13.1 |       14.4 |        4.2 | 3<sup>2</sup>&thinsp;&middot;&thinsp;43&thinsp;&middot;&thinsp;5419
|     4194303 |       11.3 |         10.6 |          11.6 |        7.1 |        4.4 | 3&thinsp;&middot;&thinsp;23&thinsp;&middot;&thinsp;89&thinsp;&middot;&thinsp;683
|     4194305 |       10.7 |         10.0 |          14.9 |       15.0 |        3.4 | 5&thinsp;&middot;&thinsp;397&thinsp;&middot;&thinsp;2113
|     8388607 |       16.4 |         15.3 |          19.4 |        7.4 |        5.8 | 47&thinsp;&middot;&thinsp;178481
|     8388609 |       22.8 |         19.7 |          24.8 |       15.1 |       10.1 | 3&thinsp;&middot;&thinsp;2796203
|    16777215 |        8.1 |          6.7 |           8.5 |        7.5 |        2.8 | 3<sup>2</sup>&thinsp;&middot;&thinsp;5&thinsp;&middot;&thinsp;7&thinsp;&middot;&thinsp;13&thinsp;&middot;&thinsp;17&thinsp;&middot;&thinsp;241
|    16777217 |        9.6 |         13.4 |          15.4 |        7.7 |        5.9 | 97&thinsp;&middot;&thinsp;257&thinsp;&middot;&thinsp;673
