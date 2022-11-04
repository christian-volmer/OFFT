# Introduction

“offt” is a fast, general purpose Fast Fourier Transform (FFT) open-source library for C++ 11.

Features include
- Simplicity of use
- Fast execution times for arbitrary transform lengths
- Forward and inverse transforms
- Single- and multi-dimensional transforms
- Float and double data types
- Arbitrary strides for easy application to multi-channel data (such as stereo audio or RGB images)
- Support for various DFT conventions that differ in terms of the scaling and the sign of the imaginary part. 
- Licensed under the “Boost Software License”. This is a liberal license that encourages the use of this library in commercial and closed-source software.

# Basic use

In order to do the actual transform fast, “offt” needs to perform some precomputations that depend on the length of the transform. For this reason, we first have to construct an object of the class `Fourier` and pass the length (or the dimensions, for the case of a multi-dimensional transform) as an argument to the constructor. We then call the `Transform()` and `InverseTransform()` methods to do the actual transform. 

A typical use model for a one-dimensional transform looks like this
```
    std::size_t length = 1000; // Number of complex samples in both time- and frequency-domain
    Fourier<> fourier(length); // This does all the necessary pre-computations
    ...
    std::complex<double> const *pointerToTimeDomainSamples = ...
    std::complex<double> *pointerToFrequencyDomainResult = ...

    fourier.Transform(pointerToFrequencyDomainResult, 1, pointerToTimeDomainSamples, 1);
```
The `1`s in the argument list to the `Transform()` method signify the stride of the data. In our example the stride is 1, because we assume that the samples occupy adjacent memory locations.

Above code will compute the forward FFT according to the following convention
$$
X_k = \sum_{i=0}^{N-1} x_i \; e^{+2\pi\mathrm{j}\,ik/N}.
$$
The inverse FFT can be computed with the member function `InverseTransform()` as
$$
x_i = \frac{1}{N} \sum_{k=0}^{N-1} X_k \; e^{-2\pi\mathrm{j}\,ik/N}.
$$

Complete code examples, also for multi-dimensional transforms can be found in the `examples` sub-directory.

# The directory structure

This project repository is structured as follows
```
root
  + examples
  |   + demo1 ............ simple demo for a one-dimensional transform
  |   + benchmark ........ benchmark that runs transforms of random depth and dimensions and measures various performance metrics
  + libs
      + offt .......... the “offt” library
          + include ...... public header files
          + src .......... library source code
```

# Build and run

## Using Microsoft Visual Studio

I am using “Visual Studio Express 2017 for Windows Desktop” for development. If you are a Visual Studio user, just open the provided Solution file `offt.sln` from the root directory and you are set. 

## Using CMake

CMake is a cross-platform build environment. See <https://cmake.org> for more information.

I do *not* use CMake on a daily basis and it is *not* that easy to use. Below information is to get you started, but it cannot substitute for a more thorough study of the CMake tool flow. I tested this on Windows with both the Microsoft compiler and the Windows-port of the GNU compiler, MinGW-64, from the MSYS2 distribution, see <https://www.msys2.org>.

I am assuming that you already created an (empty) directory called `build` below the root of this repository. Both CMake and the compiler must be on the system path. From within `build`, run
```
cmake ..
```
to have CMake generate the necessary make files. Then, still from within `build`, run
```
cmake --build .
```
to build the library and the example executables.

### Selecting between “Debug” and “Release” builds

If your compiler is GNU, you will have to specify the build configuration during the first step above. For example
```
cmake -D CMAKE_BUILD_TYPE=Release ..
```
If the compiler is Visual Studio, the selection of the configuration happens during the second step, like so
```
cmake --build . --config Release
```

# Technical details

“offt” implements the so-called mixed-radix Cooley-Tukey FFT algorithm. The basic idea is to decompose the length of the transform into smaller factors. For each factor, a fast FFT algorithm is called. The result of the complete transform is then computed by appropriately putting together the results from the smaller transforms. This approach is also known as “divide and conquer”. When done right, it will give a major speed improvement over the naive implementation of the Discrete Fourier Transform (DFT) formula.

“offt” employs the following methods and algorithms
- At the top there is a general implementation of an in-order out-of-place decimation-in-time mixed-radix Cooley-Tukey algorithm. 
- There are hard-coded FFT modules in the form of automatically generated “spaghetti code” for factors up to length 32
    - prime factor 2 is trivial
    - prime factors 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 use Rader's algorithm followed by a cyclic convolution based on Winograd's method
    - composite factors 6, 10, 12, 14, 15, 18, 20, 21, 22, 24, 26, 28, 30 use the decomposition due to Good and Thomas
    - prime powers 4, 9, 25, and 27 use radix-$n$ Cooley-Tukey decompositions
    - the remaining powers-of-two 8, 16, 32 use the split-radix method.
- Larger prime factors are handled by a general implementation of Rader's algorithm followed by an FFT-based cyclic convolution.
- Twiddle-factors are pre-computed and are stored in a memory efficient way.

# Release history

## Version 0.9
First release to public.

# Next steps

## Features

- Add interface for non-interleaved real and imaginary parts
- Add interface for real-valued time-domain data
- Add more constants to the `FourierParameters` structure for tools such as MATLAB, numpy, and others. 
- Support true in-place in-order transformations

## Performance

- Avoid the recursive application of Rader's algorithm because it is slow. E.g., a length-167 Rader-module does a cyclic convolution of length 166, which, in turn, needs a length-83 Rader-module, which does a cyclic convolution of length 82, which in turn needs a length-41 Rader-module.
- Improve the re-use of phasors
- Add SSE2 support
- Optimisation of the hard-coded modules. The larger ones are slower than expected.

# License

“offt” is released under the “Boost Software License”. This is a liberal license that encourages the use of this library in commercial and closed-source software.

The license and additional information can be found below.
- The license text in the file “LICENSE_1_0.txt” located in the root directory of this project.
- The license text on the boost website: <https://www.boost.org/LICENSE_1_0.txt>.
- Bbackground information on the boost website: <https://www.boost.org/users/license.html>.

“offt” is not affiliated to the Boost project.