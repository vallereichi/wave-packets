#include <wavepacket.h>


using namespace std::complex_literals;

std::complex<double> gaussWavePacket1D (double x, double x0, double k, double sigma) {
    std::complex<double> i(0.0, 1.0);
    std::complex<double> wave = exp(i * k * (x - x0));
    double envelope = sqrt(1 / sqrt(M_PI) / sigma) * exp(- pow((x-x0), 2) / 2 / pow(sigma, 2));

    std::complex<double> gauss1D = wave * envelope;
    return gauss1D;
}