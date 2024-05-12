#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>

#include "neural_network.hpp"

const std::string DATASET_PATH = "";
const int ROW_INDEX_FOR_FIELD_VALUE_START = 2;

std::vector<std::vector<double>>
_readData(std::string& filename) {
    std::vector<std::vector<double>> data;
    std::ifstream fileStream(filename);
    std::string row;
    while(std::getline(fileStream, row)) {
        std::vector<double> rowValues;
        std::stringstream valueStream(row);
        std::string value;
        int columnIdx = 0;
        while(std::getline(valueStream, value, ',')) {
            std::cout << value << '\n';
            if(columnIdx >= ROW_INDEX_FOR_FIELD_VALUE_START) {
                rowValues.push_back(stod(value));
            }
            ++columnIdx;
        }
        data.push_back(rowValues);
    }

    return data;
}

int main(int argc, char** argv) {
    // TODO: Read in data.
    std::string dataFilePath = argv[1];
    std::vector<std::vector<double>> data = _readData(dataFilePath);
    // TODO: Partition data into training and test set.
    // TODO: Train neural network.
    // TODO: Calculate test results.

    std::cout << argv[1] << '\n'; 
}
