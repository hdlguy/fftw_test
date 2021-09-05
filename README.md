# fftw_test
This is a little program to run fftw on various machines as a crude benchmarking tool.

## Results
After some experimentation a benchmark transform was selected.
* 1D
* Complex
* Double precision
* Size = 64*1024*1024 points

Four hardware platforms were tested.
* Intel Core i9-9900K under Linux => 0.64 seconds
* Xilinx ZCU104 evaluation board with XCZU7EV processor (quad Arm A53, 64bit DDR4) => 9.5 seconds
* Avnet Ultrazed SOM with XCZU3EG processor (quad Arm A53, 32 bit DDR4) => 11.6 seconds
* Avnet Microzed SOM with XCZU3EG processro (dual Arm A7, 32 bit DDR4) => 16.4 seconds

## Summary
The Intel is 15 times faster than the fastest Arm processor. No special settings were used to control optimization. My guess is that fftw automatically uses the AVX SIMD extensions on Intel processors giving it a huge advantage. The Arm NEON extensions do not handle double precision floating point.

The test will be run on an Intel i3-11600K.
