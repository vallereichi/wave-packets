#pragma once
#include <vector>
#include <complex>
#include <cmath>
#include <stdlib.h>

std::complex<double>* createArray (float length, float start, float end);

std::complex<double>* gaussWavePacket1D (std::complex<double> *xarray, float length, double x0, double k, float sigma);

double* getProbabilityDensity (std::complex<double> *array, int arraySize);

double* compressArrays (std::complex<double> *xarray, double *probDensity, int arraySize);

float update ();
