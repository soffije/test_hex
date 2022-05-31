#include <fstream>
#include <iostream>
#include "Endian.hpp"

//using namespace std;

int main()
{
    double value;
    std::cout << "Enter value: ";
    std::cin >> value;
    Endian::Float64 float64 = value;

    double bigEndianDouble = float64.Big();
    double littleEndianDouble = float64.Little();

    std::cout << "Value: " << value << "\n"
        << "BigEndian: " << bigEndianDouble << "\n"
        << "LittleEndian: " << littleEndianDouble << std::endl;

    std::cout << "Your architecture is: "
        << (Endian::Arch_Is_Big_Endian() ? "Big Endian" : "Little Endian");

    std::ofstream out("out.dat", std::ofstream::binary);

    out.write(float64.BigAsBytes(), 8);

    out.close();

    return 0;
}
