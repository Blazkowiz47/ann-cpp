#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <string>


class Layer 
{
    public:
        Layer();
        void initialise();
        void feedforward();
        void baackpropogation();
};

#endif