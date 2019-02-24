# LakeComo
Simulation model of Lake Como and [Evolutionary Multi-Objective Direct Policy Search](https://ascelibrary.org/doi/abs/10.1061/(ASCE)WR.1943-5452.0000570) policy design. 

Lake Como is a sub-alpine lake in the Italian lake district, northern Italy. It is the third-largest lake in Italy and reaches a maximum depth of 410 m, which makes it the fifth-deepest lake in Europe. The lake is shaped like an inverted 'Y' surrounded by mountains and primarily fed by the Adda River, which also serves as the only exit point of the lake. The lake catchment has an area of 4,733 km2, with approximately 90% in Italy and 10% in Switzerland. The hydrologic regime is snow-rainfall dominated, characterized by relatively dry winters and summers and high peaks of flow in spring and autumn, due to snowmelt and rainfall, respectively.

The Lake Como system involves numerous economic activities and has been actively studied since the 1980s. The existing regulation of the lake is driven by two primary, competing objectives: water supply, mainly for irrigation, and flood control in the city of Como, which sits at the lowest point on the lake shoreline. The agricultural districts downstream prefer to store snowmelt in the lake to satisfy the peak summer water demands, when the natural inflow is insufficient to meet irrigation requirements. Yet, storing such water increases the lake level and, consequently, the flood risk, which could instead be minimized by keeping the lake level as low as possible. These two objectives (both to be minimized) are formulated as follows:
* Flood control: the average annual number of flooding days in the simulation horizon.
* Water supply deficit: the daily average quadratic water deficit between lake releases and downstream water demands, subject to a minimum environmental flow constraint to ensure adequate environmental conditions in the Adda River.


  ----
  ### Copyright:
  
  Copyright 2018 NRM group - Politecnico di Milano
  
  Developers: Matteo Giuliani, Marta Zaniolo, Andrea Castelletti.
  
  LakeComo is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
  
  The code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License along with LakeComo.  If not, see <http://www.gnu.org/licenses/licenses.en.html>.
