#include <wavepacket.h>


std::complex<double> gaussWavePacket1D (double x, double x0, double k, float sigma) {
    std::complex<double> i(0.0, 1.0);
    std::complex<double> wave = exp(i * k * (x - x0));
    double envelope = sqrt(1 / sqrt(M_PI) / sigma) * exp(- pow((x-x0), 2) / 2 / pow(sigma, 2));

    std::complex<double> gauss1D = wave * envelope;
    return gauss1D;
}

std::vector<std::complex<double>*> initializeWavePacket1D (int size, int start, int end) {
    double xarray[size];
    std::complex<double> yarray[size];
    float dx = (end - start) / size;

    for (int i = 0; i <= size; i++) {
        float x = start + i * dx;
        std::complex<double> y = gaussWavePacket1D (x, 0.0, 5.0, 0.1);

        xarray[i] = x;
        yarray[i] = y;
    }

    std::vector<std::complex<double>> psi0;
    psi0.push_back(xarray);
    psi0.push_back(yarray);

    return psi0;

}