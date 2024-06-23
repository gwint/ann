#include <iostream>

#include "neural_network.hpp"

NeuralNetwork::NeuralNetwork() {
    std::cout << "NeuralNetwork contstr begin" << '\n';
    std::cout << "NeuralNetwork contstr end" << '\n';
}

void NeuralNetwork::train(features trainingFeatures,
                          classifications trainingClassifications) {
    std::cout << "NeuralNetwork train begin" << '\n';
    std::cout << "NeuralNetwork train end" << '\n';
}

classifications NeuralNetwork::classify(features testFeatures) {
    std::cout << "NeuralNetwork classify begin" << '\n';
    classifications testClassifications;
    std::cout << "NeuralNetwork classify end" << '\n';

    return testClassifications;
}
