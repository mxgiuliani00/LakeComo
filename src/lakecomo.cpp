/*
 * lakecomo.cpp
 *
 *  Created on: 7/feb/2014
 *      Author: MatteoG
 */

#include "lakecomo.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

lakecomo::lakecomo() {
    // TODO Auto-generated constructor stub
}

lakecomo::~lakecomo() {
    // TODO Auto-generated destructor stub
}


double lakecomo::storageToLevel(double s){
    double h0 = -0.5;
    double h = s/A + h0;
    return h;
}

double lakecomo::levelToStorage(double h){
    double h0 = -0.5;
    double s = A*(h - h0);
    return s;
}

double lakecomo::levelToSurface(double h){
    double S = A;
    return S;
}


double lakecomo::min_release(double s, int cday){
    double q = 0.0;
    double DMV = minEnvFlow[cday-1];
    double h = storageToLevel(s);
    if(h <= -0.50){
        q = 0.0;
    }else if (h <= 1.25) {
        q = DMV;
    //}else if (h <= 1.30) {
    //    q = 938.2*h - 1229.02;
    }else{
        q = 33.37*pow( (h + 2.5), 2.015);
    }
    return q;
}

double lakecomo::max_release(double s, int cday){

    double q = 0.0;
    double h = storageToLevel(s);
    if(h <= -0.5){
        q = 0.0;
    }else if (h <= -0.40) {
        q = 1488.1*h + 744.05;
    }else{
        q = 33.37*pow( (h + 2.5), 2.015);
    }

    return q;
}


