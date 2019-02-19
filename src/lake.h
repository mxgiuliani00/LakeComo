/*
 * lake.h
 *
 *  Created on: 30/jan/2014
 *      Author: MatteoG
 */

#ifndef lake_H_
#define lake_H_

#include <math.h>
#include <vector>
#include <string>
#include "utils.h"

namespace std{

struct reservoir_param{
    int EV;                // evaporation data: -1 = no evaporation, 0 = load evaporation from file, 1 = activate function
    myFile evap_rates;     // evaporation rates
    myFile rating_curve;   // rating curve
    myFile lsv_rel;        // level-surface-volume relationships
    double A;              // reservoir surface (assumed to be constant)
    double initCond;       // initial condition (level)
    myFile tailwater;      // release - tailwater
    myFile minEnvFlow;     // MEF
};

class lake {
public:
        lake();
        virtual ~lake();

        /**
         * Set/Get intial conditions
         */
        void setInitCond(double ci);
        double getInitCond();

        /**
         * Integration:
         *  - HH = fraction of day
         *  - tt = current day
         *  - s0 = initial condition (storage)
         *  - uu = decision
         *  - n_sim = inflow
         *  - cday = day of the year (for MEF)
         *  - ps = simulation scenario
         */
        vector<double> integration( int HH, int tt, double s0, double uu, double n_sim, int cday, int ps );

        /**
          * Function to compute the actual release
          *  - uu = decision
          *  - s = lake storage
          *  - cday = day of the year (for MEF)
          */
        double actual_release( double uu, double s, int cday );

        /**
          * Level-Surface-Storage relationships and tailwater level
          */
        virtual double levelToSurface(double h) = 0;
        virtual double levelToStorage(double h) = 0;
        virtual double storageToLevel(double s) = 0;
        double relToTailwater(double r) ;

        /**
         * Set reservoir characteristics
         */
        void setEvap(int pEV); // 0 = no evaporation, 1 = from file, 2 = call specific function
        void setEvapRates(myFile pEvap);
        void setRatCurve(myFile pRatCurve);
        void setLSV_Rel(myFile pLSV_Rel);
        void setMEF(myFile pMEF);
        double getMEF(double pDoy);
        void setSurface(double pA);
        void setTailwater(myFile pTailWater);

protected:

        double init_condition;                  // initial condition = storage/level

        // lake characteristics
        double A;                               // lake surface (m2)
        vector<vector<double> > lsv_rel;        // level - Surface - storage relationships
        vector<vector<double> > rating_curve;   // rating curve: level - max release - min release
        int EV;                                 // evaporation: -1 = no, 0 = hist. trajectory (evap), 1 = compute
        vector<double> evap_rates;              // evapotranspiration rates
        vector<vector<double> > tailwater;      // release - tailwater level
        vector<double> minEnvFlow;              // MEF

        /**
          * Function to compute min-max release
          *  - s = lake storage
          *  - cday = day of the year (for MEF)
          */
        virtual double min_release( double s, int cday ) = 0;
        virtual double max_release( double s, int cday ) = 0;

};

}

#endif
