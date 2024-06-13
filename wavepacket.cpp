#include <wavepacket.h>

std::complex<double>* createArray (float length, float start, float end)
{
    std::complex<double> *array = new std::complex<double>[length + 1];
    

    float increment = (end - start) / length;

    for (int i = 0; i <= length; i++)
    {
        array[i] = start + i * increment;
    }

    return array;
}


void gaussWavePacket1D (std::complex<double> *xarray, float length, double x0, double k, float sigma)
 {
    // iu is the imaginary unit "i"
    std::complex<double> iu(0.0, 1.0);
    std::complex<double> wave;
    std::complex<double> envelope;

    for (int i = 0; i <= length; i++)
    {
        wave = exp(iu * (xarray[i] - x0) * k);
        envelope = sqrt(1 / sqrt(M_PI) / sigma) * exp(- pow((xarray[i]-x0), 2) / (2*pow(sigma, 2)));

        xarray[i] = wave * envelope;
    }
}
