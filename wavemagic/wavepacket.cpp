#include "wavepacket.h"

std::complex<double>* createArray (int arraySize, float start, float end)
{
    std::complex<double> *array = new std::complex<double>[arraySize];
    

    float increment = (end - start) / arraySize;

    for (int i = 0; i < arraySize; i++)
    {
        array[i] = start + i * increment;
    }

    return array;
    // end point is not included in this array -> lastelement = end - increment
}


std::complex<double>* gaussWavePacket1D (std::complex<double> *xarray, int arraySize, double x0, double k, float sigma)
 {
    // iu is the imaginary unit "i"
    std::complex<double> iu(0.0, 1.0);
    std::complex<double> wave;
    std::complex<double> envelope;
    std::complex<double>* result = new std::complex<double>[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        wave = exp(iu * (xarray[i] - x0) * k);
        envelope = sqrt(1 / sqrt(M_PI) / sigma) * exp(- pow((xarray[i]-x0), 2) / (2*pow(sigma, 2)));

        result[i] = wave * envelope;
    }

    return result;
}


double* getProbabilityDensity (std::complex<double> *array, int arraySize)
{
    double* pdArray = new double[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        pdArray[i] = std::norm(array[i]);
    }

    return pdArray;
}


//function to turn a x-array and y-array into a 1D array for the vertex buffer
double* compressArrays (std::complex<double> *xarray, double *probDensity, int arraySize)
{
    double* compressedArray = new double[arraySize*2];
    int indexCounter = 0;

    for (int i = 0; i < arraySize; i+=2)
    {
        compressedArray[i] = std::abs(xarray[indexCounter]);
        compressedArray[i + 1] = probDensity[indexCounter];

        indexCounter++;
    }

    return compressedArray;
}
