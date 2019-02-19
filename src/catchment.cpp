/*
 * catchment.cpp
 *
 *  Created on: 31/oct/2013
 *      Author: matteogiuliani
 */

#include "catchment.h"
#include "utils.h"


using namespace std;

catchment::catchment() {
    // TODO Auto-generated constructor stub
}

catchment::~catchment() {
    // TODO Auto-generated destructor stub
}

catchment::catchment(catchment_param pCM){
    cModel = pCM.CM;

    switch (pCM.CM) {
    case 1:
        inflow = utils::loadMatrix(pCM.inflow_file.filename, pCM.inflow_file.row,pCM.inflow_file.col);
        break;
    // case 2: HBV do be implemented
    default:
        break;
    }
}

double catchment::getInflow(int pt, int ps){

    double q = inflow[ps][pt];
    return q;
}
