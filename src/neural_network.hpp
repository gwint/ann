#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

typedef std::vector<std::vector<double>> features;
typedef std::vector<int> classifications;

class NeuralNetwork {
    public:
        NeuralNetwork();
        void train(features trainingFeatures,
                   classifications trainingClassifications);
        classifications classify(features testFeatures);
};

#endif
