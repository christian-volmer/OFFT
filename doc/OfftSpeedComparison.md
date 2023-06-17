# OFFT speed comparison

The mission of OFFT is to provide a truly open FFT library that delivers competitive performance for arbitrary length transforms and, at the same time, keeps the code size and maintenance effort of the library reasonable. To understand what that means and where I stand, I am running a speed comparison against two popular libraries that are generally considered *best-in-class*: FFTW and Intel oneMKL. FFTW is open-source with a paid license available for closed-source projects. The Intel MKL is closed-source and requires the user to install a faily large binary package.

The results are at the bottom of this page.

## Compiler, libraries, and platform

The benchmark was compiled using GCC on Windows. Below is the output of `g++ --version`
```
g++.exe (Rev11, Built by MSYS2 project) 12.2.0
```
Both FFTW and MKL use the vendor supplied libraries, which are available from the links below
- FFTW: <http://www.fftw.org/install/windows.html>, download `fftw-3.3.5-dll64.zip`
- Intel oneMKL: <https://software.intel.com/en-us/oneapi/onemkl>, click on “Download the Stand-Alone Version”.

The speed test was run on my Intel i5-2450M laptop computer with 2.5 GHz running Windows 10. Pretty ancient, but this is what I have.

## Comments on the results

Currently, OFFT makes no use of SIMD instructions. For me, as the developer, therefore, the comparison against the no-SIMD performance of FFTW is the most interesting one. For the powers of 2 and 10, FFTW is often faster there, but OFFT is getting close, especially at larger transform sizes. For arbitrary sizes, OFFT is often faster than FFTW, even the SIMD version of FFTW. Which I find surprising, given the fact that I did not spend much effort on optimising this.

Since all modern computers have some sort of SIMD instruction set, for you, the end-user, it is the SIMD performance that counts. And clearly OFFT has some homework to do in this respect.

Numbers in the tables below are nanoseconds per $n \log n$, where $n$ is the size of the transform and $\log$ the natural logarithm. For instance, if it says $8.9$ in the table for a length-16777216 transform, it means the transform took $8.9 \times 16777216 \times 16.64 = 2.48~\text{seconds}$. 

Columns are as follows
- **OFFT:** runtime of the OFFT
- **FFTW w/ SIMD:** plan is created with flag `FFTW_ESTIMATE`.
- **FFTW w/o SIMD:** plan is created with flag `FFTW_ESTIMATE | FFTW_NO_SIMD`. Since OFFT makes no effective use of SIMD at the moment, this columns tells me where I stand with OFFT.
- **MKL 1-core:** descriptor created with `DftiSetValue(mDesc, DFTI_THREAD_LIMIT, 1)`
- **MKL 2-core:** descriptor created with `DftiSetValue(mDesc, DFTI_THREAD_LIMIT, 2)`. Speed gains are often way more than a factor of two. Interesting...

Some more remarks
- My computer is rather old and only supports the SSE4 SIMD instruction set. On more recent processors, which have the AVX or later instruction sets available, we can expect the gap between no-SIMD and SIMD performance to be even greater.
- All numbers I am showing have to be taken with a grain of salt. Not just because of background processes stealing processor time in an unpredictable manner, but also because of the CPU heating up and the operating system playing funny games with the clock speed and the scheduling in response. 
- FFTW can be a lot faster when given the flag `FFTW_MEASURE` instead of `FFTW_ESTIMATE`. I have to say though, that this increases the initialisation time considerably and literally takes forever for the longer sizes. So I am rejecting this flag for the benchmark.


## Powers of two

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core | Factors
|------------:|:----------:|:------------:|:-------------:|:----------:|:----------:|:----------
|        1024 |        2.1 |          0.5 |           1.7 |        0.5 |        0.5 | 2<sup>10</sup>
|        2048 |        2.5 |          0.6 |           1.7 |        0.5 |        0.5 | 2<sup>11</sup>
|        4096 |        2.5 |          0.8 |           1.9 |        0.5 |        0.5 | 2<sup>12</sup>
|        8192 |        2.6 |          0.8 |           2.0 |        0.6 |        0.8 | 2<sup>13</sup>
|       16384 |        2.8 |          0.9 |           2.0 |        0.6 |        0.7 | 2<sup>14</sup>
|       32768 |        3.7 |          1.2 |           3.0 |        0.8 |        0.7 | 2<sup>15</sup>
|       65536 |        3.9 |          1.2 |           2.6 |        0.9 |        0.7 | 2<sup>16</sup>
|      131072 |        3.7 |          1.4 |           3.2 |        1.2 |        0.9 | 2<sup>17</sup>
|      262144 |        4.3 |          2.1 |           4.4 |        1.2 |        0.9 | 2<sup>18</sup>
|      524288 |        4.4 |          2.8 |           4.1 |        1.2 |        0.9 | 2<sup>19</sup>
|     1048576 |        4.7 |          3.5 |           5.1 |        1.2 |        0.9 | 2<sup>20</sup>
|     2097152 |        4.9 |          3.7 |           4.9 |        1.3 |        0.9 | 2<sup>21</sup>
|     4194304 |        5.1 |          3.9 |           5.1 |        1.3 |        0.9 | 2<sup>22</sup>
|     8388608 |        5.1 |          4.3 |           5.8 |        1.3 |        0.9 | 2<sup>23</sup>
|    16777216 |        5.9 |          4.3 |           5.6 |        1.4 |        1.1 | 2<sup>24</sup>

## Powers of ten

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core | Factors
|------------:|:----------:|:------------:|:-------------:|:----------:|:----------:|:----------
|         100 |        3.8 |          0.9 |           2.3 |        1.1 |        1.1 | 2<sup>2</sup>&thinsp;&middot;&thinsp;5<sup>2</sup>
|        1000 |        3.5 |          1.3 |           2.7 |        0.8 |        0.8 | 2<sup>3</sup>&thinsp;&middot;&thinsp;5<sup>3</sup>
|       10000 |        3.6 |          1.1 |           2.5 |        0.9 |        1.0 | 2<sup>4</sup>&thinsp;&middot;&thinsp;5<sup>4</sup>
|      100000 |        4.5 |          1.5 |           3.1 |        1.5 |        1.1 | 2<sup>5</sup>&thinsp;&middot;&thinsp;5<sup>5</sup>
|     1000000 |        5.3 |          3.4 |           4.9 |        2.3 |        1.0 | 2<sup>6</sup>&thinsp;&middot;&thinsp;5<sup>6</sup>
|    10000000 |        5.4 |          2.5 |           4.2 |        2.9 |        1.0 | 2<sup>7</sup>&thinsp;&middot;&thinsp;5<sup>7</sup>

## Non-powers of two

|    Size     |    OFFT    | FFTW w/ SIMD | FFTW w/o SIMD | MKL 1-core | MKL 2-core | Factors
|------------:|:----------:|:------------:|:-------------:|:----------:|:----------:|:----------
|        1023 |        5.1 |          3.2 |           3.9 |        3.1 |        3.1 | 3&thinsp;&middot;&thinsp;11&thinsp;&middot;&thinsp;31
|        1025 |        6.7 |          8.0 |          10.0 |        3.9 |        3.9 | 5<sup>2</sup>&thinsp;&middot;&thinsp;41
|        2047 |        7.8 |          9.1 |           7.5 |        8.7 |        8.8 | 23&thinsp;&middot;&thinsp;89
|        2049 |        9.1 |          6.4 |          12.2 |        5.3 |        5.3 | 3&thinsp;&middot;&thinsp;683
|        4095 |        3.7 |          1.4 |           2.8 |        1.1 |        1.1 | 3<sup>2</sup>&thinsp;&middot;&thinsp;5&thinsp;&middot;&thinsp;7&thinsp;&middot;&thinsp;13
|        4097 |        6.0 |          7.4 |           9.1 |        9.5 |        3.7 | 17&thinsp;&middot;&thinsp;241
|        8191 |        8.3 |          6.6 |          13.0 |        4.5 |        4.5 | 8191
|        8193 |        8.0 |          8.9 |          14.0 |        9.7 |        6.8 | 3&thinsp;&middot;&thinsp;2731
|       16383 |        9.3 |          5.7 |           8.8 |        4.7 |        3.3 | 3&thinsp;&middot;&thinsp;43&thinsp;&middot;&thinsp;127
|       16385 |        7.3 |          8.2 |           9.5 |       11.5 |        3.1 | 5&thinsp;&middot;&thinsp;29&thinsp;&middot;&thinsp;113
|       32767 |        6.8 |          7.4 |           8.4 |        5.7 |        2.8 | 7&thinsp;&middot;&thinsp;31&thinsp;&middot;&thinsp;151
|       32769 |        7.2 |          5.9 |          10.7 |       14.4 |        2.5 | 3<sup>2</sup>&thinsp;&middot;&thinsp;11&thinsp;&middot;&thinsp;331
|       65535 |        5.8 |          6.4 |           7.8 |        7.1 |        2.3 | 3&thinsp;&middot;&thinsp;5&thinsp;&middot;&thinsp;17&thinsp;&middot;&thinsp;257
|       65537 |        8.4 |          7.9 |          10.8 |       13.4 |       13.2 | 65537
|      131071 |       12.5 |         11.1 |          19.2 |        6.5 |        6.5 | 131071
|      131073 |       12.4 |         11.5 |          14.6 |       13.4 |       13.9 | 3&thinsp;&middot;&thinsp;43691
|      262143 |        7.3 |          6.4 |           8.0 |        5.9 |        3.0 | 3<sup>3</sup>&thinsp;&middot;&thinsp;7&thinsp;&middot;&thinsp;19&thinsp;&middot;&thinsp;73
|      262145 |        9.0 |         11.6 |          12.4 |       13.3 |        2.5 | 5&thinsp;&middot;&thinsp;13&thinsp;&middot;&thinsp;37&thinsp;&middot;&thinsp;109
|      524287 |       14.3 |         15.9 |          21.2 |        6.6 |        6.5 | 524287
|      524289 |       14.0 |         12.3 |          15.2 |       13.3 |       11.0 | 3&thinsp;&middot;&thinsp;174763
|     1048575 |        7.6 |          7.1 |           8.2 |        4.7 |        2.4 | 3&thinsp;&middot;&thinsp;5<sup>2</sup>&thinsp;&middot;&thinsp;11&thinsp;&middot;&thinsp;31&thinsp;&middot;&thinsp;41
|     1048577 |       11.4 |         10.3 |          14.3 |       13.4 |        7.7 | 17&thinsp;&middot;&thinsp;61681
|     2097151 |        8.3 |          7.3 |          12.6 |        7.0 |        6.7 | 7<sup>2</sup>&thinsp;&middot;&thinsp;127&thinsp;&middot;&thinsp;337
|     2097153 |       13.3 |          7.8 |          12.0 |       14.4 |        4.8 | 3<sup>2</sup>&thinsp;&middot;&thinsp;43&thinsp;&middot;&thinsp;5419
|     4194303 |        9.9 |          9.3 |          11.5 |        7.3 |        4.0 | 3&thinsp;&middot;&thinsp;23&thinsp;&middot;&thinsp;89&thinsp;&middot;&thinsp;683
|     4194305 |        9.7 |          9.7 |          14.6 |       14.7 |        3.0 | 5&thinsp;&middot;&thinsp;397&thinsp;&middot;&thinsp;2113
|     8388607 |       15.3 |         15.2 |          19.3 |        7.3 |        5.8 | 47&thinsp;&middot;&thinsp;178481
|     8388609 |       19.9 |         18.6 |          23.0 |       13.5 |        9.7 | 3&thinsp;&middot;&thinsp;2796203
|    16777215 |        7.3 |          6.7 |           7.6 |        6.5 |        2.7 | 3<sup>2</sup>&thinsp;&middot;&thinsp;5&thinsp;&middot;&thinsp;7&thinsp;&middot;&thinsp;13&thinsp;&middot;&thinsp;17&thinsp;&middot;&thinsp;241
|    16777217 |        8.7 |         12.3 |          15.3 |        7.8 |        5.5 | 97&thinsp;&middot;&thinsp;257&thinsp;&middot;&thinsp;673
