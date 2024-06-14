#include <iostream>
#include <fstream>
#include <string>

void writeDataToFile (double* array, int arraySize, std::string filepath)
{
    std::ofstream file (filepath);
    if (file.is_open())
    {
        for (int i = 0; i < arraySize; i++)
        {
            file << array[i] << "\n";
        }
        file.close();
    }
    else std::cout << "Unable to open file" << std::endl;

}