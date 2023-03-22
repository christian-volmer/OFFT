
# The OFFT library

The OFFT library is a fast, platform-independent, general purpose Fast Fourier Transform (FFT) open-source library written in C++ 11.

## Fast, generic, ...

Out of personal interest in the various algorithms involved, I wrote a Fast Fourier Transform library. It is as easy to use an shown in the code snipped further down. Features are

- Simplicity of use
- Arbitrary transform lengths: OFFT maintains $n \log n$ run time for arbitrary $n$.
- Forward and inverse transforms
- Single- and multi-dimensional transforms
- Float and double data types
- Arbitrary strides for easy application to multi-channel data (such as stereo audio or RGB images)
- Support for various DFT conventions that differ in terms of the scaling and the sign of the imaginary part. 
- Written in platform-independent C++ 11

## ... open, and free!

In my opinion, the FFT is to digital signal processing what addition and subtraction are to accounting. For this reason, I am making OFFT available under the very permissive [Boost Software License (BSL)](/LICENSE_1_0.txt) and explicitly encourage its use in closed-form or commercial software. The license basically says that you have to keep the copyright notice in the source code files but not in any binary code you distribute or even sell. Visit the boost website that has a [page explaining their license](https://www.boost.org/users/license.html) to learn more.

## Basic use

In order to do the actual transform fast, OFFT needs to perform some precomputations that depend on the length of the transform. Therefore, we first have to construct an object of the class `Fourier` and pass the length (or the dimensions, for the case of a multi-dimensional transform) as an argument to the constructor. We then call the `Transform()` and `InverseTransform()` methods to do the actual transform. 

A typical use model for a one-dimensional transform looks like this
```c++
    #include <offt.h>
    ...
    std::size_t length = 1000; // Number of complex samples in both time- and frequency-domain
    offt::Fourier<> fourier(length); // This does all the necessary pre-computations
    ...
    std::complex<double> const *pointerToTimeDomainSamples = ...
    std::complex<double> *pointerToFrequencyDomainResult = ...

    fourier.Transform(pointerToFrequencyDomainResult, 1, pointerToTimeDomainSamples, 1);
```
The `1`s in the argument list to the `Transform()` method signify the stride of the data. In our example the stride is 1, because we assume that the samples occupy adjacent memory locations.

Above code will compute the forward FFT according to the following convention

$$
X_k = \sum_{i=0}^{N-1} x_i \ e^{+2\pi\mathrm{j}\ ik/N}
$$

The inverse FFT can be computed with the member function `InverseTransform()` as

$$
x_i = \frac{1}{N} \sum_{k=0}^{N-1} X_k \ e^{-2\pi\mathrm{j}\ ik/N}
$$

Complete code examples, also for multi-dimensional transforms can be found in the `examples` sub-directory.


## Performance

OFFT can keep up with the best libraries available. Below is a runtime comparison against FFTW3 (<http://www.fftw.org>) and against Wolfram Mathematica 13.0 (<https://www.wolfram.com/mathematica>, I assume it uses the Intel MKL) on my old i5-2450M with 2.5 GHz. Times are in seconds, smaller numbers are better.

| Length     | OFFT <br> (one core)      | FFTW3 <br> w/o SSE2 | FFTW3 <br> with SSE2 | Mathematica <br> (one core) | Mathematica <br> (two cores) |
|------------|-----------|---------------------|----------------------|------------------------------|-------------------------------|
| 4194304    | 0.37 s    |  0.36 s             |  0.31 s              | 0.33 s                       | 0.25 s                        |
| 8388608    | 0.80 s    |  0.80 s             |  0.69 s              | 0.67 s                       | 0.55 s                        |
| 8388609    | 3.26 s    |  2.36 s             |  2.97 s              | 2.66 s                       | 2.63 s                        |
| 8388613    | 3.38 s    |  1.97 s             |  1.57 s              | 1.41 s                       | 0.96 s                        |
| 16777216   | 2.40 s    |  1.79 s             |  1.59 s              | 1.38 s                       | 1.03 s                        |
| 33554432   | 5.22 s    |  3.65 s             |  3.51 s              | 2.94 s                       | 2.39 s                        |
| 33554433   | 6.28 s    |  6.80 s             |  6.04 s              | 7.37 s                       | 5.08 s                        |
| 33554435   | 9.23 s    | 13.22 s             | 11.99 s              | 9.24 s                       | 8.45 s                        |


## The directory structure

This project repository is structured as follows

```
root
  + offt  ................ the OFFT library
  + examples
      + demo  ............ simple demo for a one-dimensional transform  
      + benchmark  ....... benchmark that runs transforms of random depth and dimensions.
                           Can be run as a self-test with command-line parameter --self-test
```

## Build and run

### Using Microsoft Visual Studio

If you are a Visual Studio user, just open the provided Solution file `offt.sln` from the root directory and you are set. 

### Using CMake

CMake is a cross-platform build environment. Visit <https://cmake.org> for more information. 

I am assuming that you already created an (empty) directory called `build` below the root of this repository. Both CMake and the compiler must be on the system path. From within `build`, run
```
cmake ..
```
to have CMake generate the necessary make files. Then, still from within `build`, run
```
cmake --build .
```
to build the library and the example executables.

#### Selecting between “Debug” and “Release” builds

If your compiler is GNU, you will have to specify the build configuration during the first step above. For example
```
cmake -D CMAKE_BUILD_TYPE=Release ..
```
If the compiler is Visual Studio, the selection of the configuration happens during the second step, e.g., 
```
cmake --build . --config Release
```

## Technical details

OFFT implements the so-called mixed-radix Cooley-Tukey FFT algorithm. The basic idea is to decompose the length of the transform into smaller factors. For each factor, a fast FFT algorithm is called. The result of the complete transform is then computed by appropriately putting together the results from the smaller transforms. This approach is also known as “divide and conquer”. When done right, it will give a major speed improvement over the naive implementation of the Discrete Fourier Transform (DFT) formula.

OFFT employs the following methods and algorithms
- At the top there is a general implementation of an in-order out-of-place decimation-in-time mixed-radix Cooley-Tukey algorithm. 
- There are hard-coded FFT modules in the form of automatically generated “spaghetti code” for factors up to length 32
    - prime factor 2 is trivial
    - prime factors 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 use Rader's algorithm followed by a cyclic convolution based on Winograd's method
    - composite factors 6, 10, 12, 14, 15, 18, 20, 21, 22, 24, 26, 28, 30 use the decomposition due to Good and Thomas
    - prime powers 4, 9, 25, and 27 use radix-n Cooley-Tukey decompositions
    - the remaining powers-of-two 8, 16, 32 use the split-radix method.
- Larger prime factors are handled by a general implementation of Rader's algorithm followed by an FFT-based cyclic convolution.
- Twiddle-factors are pre-computed and are stored in a memory efficient way.

## Release history

### Version 0.1.0
 - First release to public.


## Known limitations of the current version

- Library is still in its beginnings, API may change from one (minor) version to another.
- Public API for non-interleaved real and imaginary parts is missing.
- No in-place transforms. Source and destination buffers must be different.
- No special API for real-valued transforms.
- Extremely large transform sizes with prime factors that do not fit into 32 bits will fail (also on 64 bit targets).
