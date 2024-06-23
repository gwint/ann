#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <utility>

#include "neural_network.hpp"

const std::string DATASET_PATH = "";
const int ROW_INDEX_FOR_FIELD_VALUE_START = 2;
const int ROW_INDEX_FOR_CLASSIFICATION_VALUE = 1;

std::pair<features, classifications>
_readData(std::string& filename) {
    std::pair<features, classifications> data;
    features features;
    classifications classifications;
    std::ifstream fileStream(filename);
    std::string row;
    while(std::getline(fileStream, row)) {
        std::vector<double> rowValues;
        std::stringstream valueStream(row);
        std::string value;
        int columnIdx = 0;
        while(std::getline(valueStream, value, ',')) {
            std::cout << value << '\n';
            if(columnIdx == ROW_INDEX_FOR_CLASSIFICATION_VALUE) {
                int classificationValue = 1;
                if(value == "M") {
                    classificationValue = 0;
                }
                classifications.push_back(classificationValue);
            }
            else if(columnIdx >= ROW_INDEX_FOR_FIELD_VALUE_START) {
                rowValues.push_back(stod(value));
            }
            ++columnIdx;
        }
        features.push_back(rowValues);
    }

    return std::make_pair(features, classifications);
}

std::pair<std::pair<features, classifications>, std::pair<features, classifications>>
_getPartitionedData(const std::pair<features, classifications>& data) {
    features trainingFeatures;
    features testingFeatures;
    classifications trainingLabels;
    classifications testingLabels;

    bool placeInTrainingSet = true;
    for(int i = 0; i < data.first.size(); ++i) {
        if(placeInTrainingSet) {
            trainingFeatures.push_back(data.first[i]);
            trainingLabels.push_back(data.second[i]);
        }
        else {
            testingFeatures.push_back(data.first[i]);
            testingLabels.push_back(data.second[i]);
        }

        placeInTrainingSet = !placeInTrainingSet;
    }

    return std::make_pair(std::make_pair(trainingFeatures, trainingLabels),
                          std::make_pair(testingFeatures, testingLabels));
}

int main(int argc, char** argv) {
    // TODO: Read in data.
    std::string dataFilePath = argv[1];
    std::pair<features, classifications> data = _readData(dataFilePath);
    // TODO: Partition data into training and test set.
     std::pair<std::pair<features, classifications>, std::pair<features, classifications>> partitionedData = _getPartitionedData(data);
    // TODO: Train neural network.
    features trainingFeatures = partitionedData.first.first;
    classifications trainingClassifications = partitionedData.first.second;
    NeuralNetwork ann = NeuralNetwork();
    ann.train(trainingFeatures, trainingClassifications);
    // TODO: Calculate test results.
    features testFeatures = partitionedData.second.first;
    classifications actualTestClassifications = partitionedData.second.second;

    classifications computedTestClassifications = ann.classify(testFeatures);

    std::cout << argv[1] << '\n'; 
}
