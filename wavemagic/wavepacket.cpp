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

    for (int i = 0; i < 2*arraySize; i+=2)
    {
        compressedArray[i] = std::abs(xarray[indexCounter]);
        compressedArray[i + 1] = probDensity[indexCounter];

        indexCounter++;
    }

    return compressedArray;
}


#include <Eigen/Sparse>

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> T;

static SpMat createUnitMat (int arraySize)
{
    SpMat One(arraySize, arraySize);
    One.setIdentity();

    return One;
}


static SpMat createHamiltonian1D (int arraySize, SpMat V)
{
    std::vector<T> TripletList;
    TripletList.reserve(3*arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (i == j) TripletList.push_back(T(i, j, -2));
            else if (i == j + 1) TripletList.push_back(T(i, j, 1));
            else if (i == j - 1) TripletList.push_back(T(i, j, 1));
        }
    }
    SpMat T(arraySize, arraySize);
    SpMat H(arraySize, arraySize);

    T.setFromTriplets(TripletList.begin(), TripletList.end());

    H = T + V;

    return H;
}


static SpMat setZeroPetential (int arraySize)
{
    SpMat V(arraySize, arraySize);
    return V; 
}


std::vector<Eigen::VectorXcd> CrankNicholson1D (SpMat Potential, std::complex<double>* psi_init, int arraySize, int N_Tsteps, double dt)
{
    //imaginary unit "i"
    std::complex<double> iu(0.0, 1.0);


    //create Hamiltonian
    SpMat H = createHamiltonian1D(arraySize, Potential);
    //create unit matrix
    SpMat One = createUnitMat(arraySize);

    //unitary matrices U1 and U2
    SpMat U1 = One - (0.5 * dt * iu) * H;
    SpMat U2 = One + (0.5 * dt * iu) * H;

    //compress U2 so eigen can handle it better
    U2.makeCompressed();

    //LU decomposition of U2
    Eigen::SparseLU<SpMat> solver;
    solver.analyzePattern(U2);
    solver.factorize(U2);


    //prepare everything for solving with eigen
    std::vector<Eigen::VectorXcd> psi;

    Eigen::VectorXcd psi0 = Eigen::Map<Eigen::VectorXcd>(psi_init, arraySize);
    psi.push_back(psi0);

    //solve schrödinger equation for every time step
    for (int i = 0; i < arraySize; i++)
    {
        Eigen::VectorXcd b = U1 * psi[i];

        psi.push_back(solver.solve(b));
    }

    return psi;
}
