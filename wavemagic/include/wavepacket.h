#pragma once
#include <vector>
#include <complex>
#include <cmath>
#include <stdlib.h>

std::complex<double>* createArray (int arraySize, float start, float end);

std::complex<double>* gaussWavePacket1D (std::complex<double> *xarray, int arraySize, double x0, double k, float sigma);

double* getProbabilityDensity (std::complex<double> *array, int arraySize);

double* compressArrays (std::complex<double> *xarray, double *probDensity, int arraySize);

float update ();
