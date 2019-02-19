/*
 * lakecomo.h
 *
 *  Created on: 07/feb/2014
 *      Author: MatteoG
 */

#ifndef lakecomo_H_
#define lakecomo_H_

#include <math.h>
#include <vector>
#include <string>
#include "lake.h"

namespace std{

class lakecomo : public lake {
public:
        lakecomo();
        virtual ~lakecomo();

        /**
          * Level-Surface-Storage functions
          */
        double levelToSurface(double h);
        double levelToStorage(double h);
        double storageToLevel(double s);


protected:


        /**
          * Function to compute min-max release
          *  - s = lake storage
          *  - cday = day of the year (for MEF)
          */
        double min_release( double s, int cday );
        double max_release( double s, int cday );

};

}

#endif
