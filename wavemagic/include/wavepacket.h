#pragma once
#include <vector>
#include <complex>
#include <cmath>
#include <stdlib.h>
#include <Eigen/Sparse>

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> T;

std::complex<double>* createArray (int arraySize, float start, float end);

std::complex<double>* gaussWavePacket1D (std::complex<double> *xarray, int arraySize, double x0, double k, float sigma);

double* getProbabilityDensity (std::complex<double> *array, int arraySize);

double* compressArrays (std::complex<double> *xarray, double *probDensity, int arraySize);

static SpMat createUnitMat (int arraySize);

static SpMat createHamiltonian1D (int arraySize, SpMat V);

static SpMat setZeroPetential (int arraySize);



