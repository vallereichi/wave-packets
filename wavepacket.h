#pragma once
#include <vector>
#include <complex>
#include <cmath>
#include <stdlib.h>

std::complex<double>* createArray (float length, float start, float end);

void gaussWavePacket1D (std::complex<double> *xarray, float length, double x0, double k, float sigma);

float update ();
