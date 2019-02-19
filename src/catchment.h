/*
 * catchment.h
 *
 *  Created on: 31/oct/2013
 *      Author: MatteoG
 */

#ifndef catchment_H_
#define catchment_H_

#include <math.h>
#include <vector>
#include <string>
#include "utils.h"

namespace std{

struct catchment_param{
    int CM;              // type of catchment model_redriver (0 = historical trajectory, 1 = HBV)
    myFile inflow_file;  // inflow trajectory
};

class catchment {
public:
        catchment();
        virtual ~catchment();

        /**
          * constructor with input
          */
        catchment(catchment_param pCM);

        /**
          * function to get the inflow for day "pt" and scenario "ps"
          */
        double getInflow(int pt, int ps);
 vector<vector<double> > inflow;
protected:

        int cModel ;    // type of catchment model (0 = historical trajectory, 1 = HBV)

        // inflow


};

}

#endif /* catchment_H_ */
