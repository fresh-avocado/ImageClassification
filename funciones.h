#ifndef FUNCIONES
#define FUNCIONES

#include "VectorCaracteristico.h"
#include <cmath>

template <typename T>
double dist1(VC<T> vc1, VC<T> vc2) {
    double dist = 0;
    for (int i = 0; i < min(vc1.get().size(), vc2.get().size()); ++i) {
        dist += pow(vc1.get()[i] - vc2.get()[i], 2);
    }
    return sqrt(dist);
}

template <typename T>
double dist2(VC<T> vc1, VC<T> vc2) {
    double dist = 0;
    for (int i = 0; i < min(vc1.get().size(), vc2.get().size()); ++i) {
        dist += pow(vc1.get()[i] - vc2.get()[i], 2);
    }
    return dist;
}

template <typename T>
double dist3(VC<T> vc1, VC<T> vc2) {
    double dist = 0;
    for (int i = 0; i < min(vc1.get().size(), vc2.get().size()); ++i) {
        dist += abs(vc1.get()[i] - vc2.get()[i]);
    }
    return dist;
}

#endif