
% script to visualize the Pareto Fronts obtained with different forecasts
%
% References:
% 1) Giuliani et al. (2019), Detecting the state of the climate system via
%   artificial intelligence to improve seasonal forecasts and inform
%   reservoir operations, Water Resources Research, 55 
% 2) Giuliani et al.(2020), From skill to value: isolating the influence of
%   end-user behaviour on seasonal forecast assessment, Hydrology and Earth
%   System Sciences, 24 


clear
clc

% load reference sets

load -ascii optLakeComo_perfectF.reference  % perfect inflow forecast cumulated over 51 days 
load -ascii optLakeComo_base.reference      % baseline with standard policy inputs (doy, level)
load -ascii optLakeComo_inflowF.reference   % CSI inflow forecast cumulated over 51 days 
load -ascii optLakeComo_precipF.reference   % CSI seasonal precipitation forecast
load -ascii optLakeComo_SST.reference       % CSI pre-season observed SST
load -ascii optIMPREX_EHYPEfst_full.reference   % EHYPE inflow forecast cumulated over 51 days for SYS4 system
load -ascii optIMPREX_EHYPEesp_full.reference   % EHYPE inflow forecast cumulated over 51 days for ESP system
load -ascii optIMPREX_EHYPEsim.reference        % EHYPE simulated inflow (perfect forecast) cumulated over 51 days 

%% Pareto front (1) - figure 6 
figure; 
plot( optLakeComo_base(:,end-1), optLakeComo_base(:,end), 'o', ...
    'Color', [.5 .5 .5], 'MarkerFaceColor', [.5 .5 .5] );
hold on; plot( optLakeComo_perfectF(:,end-1), optLakeComo_perfectF(:,end), 'ko', ...
    'MarkerFaceColor', [0 0 0] );
hold on; plot( optLakeComo_precipF(:,end-1), optLakeComo_precipF(:,end), 'bo', ...
    'MarkerFaceColor', [0 0 1] );
hold on; plot( optLakeComo_inflowF(:,end-1), optLakeComo_inflowF(:,end), 'ro', ...
    'MarkerFaceColor', [1 0 0] );
hold on; plot( optLakeComo_SST(:,end-1), optLakeComo_SST(:,end), 'go', ...
    'MarkerFaceColor', [0 1 0] );
legend('baseline', 'perfect forecast', 'precipitation forecast', 'inflow forecast', 'observed pre-season SST');
axis([5 15 2200 3200]); xlabel('J^{flood} (flooding days)'); ylabel('J^{supply} (deficit)')

%% Pareto front (2) - figure 4a 
figure; 
plot( optLakeComo_base(:,end-1), optLakeComo_base(:,end), 'o', ...
    'Color', [.5 .5 .5], 'MarkerFaceColor', [.5 .5 .5] );
hold on; plot( optLakeComo_perfectF(:,end-1), optLakeComo_perfectF(:,end), 'ko', ...
    'MarkerFaceColor', [0 0 0] );
hold on; plot( optIMPREX_EHYPEsim(:,end-1), optIMPREX_EHYPEsim(:,end), 'bo', ...
    'MarkerFaceColor', [0 0 1] );
hold on; plot( optIMPREX_EHYPEesp_full(:,end-1), optIMPREX_EHYPEesp_full(:,end), 'go', ...
    'MarkerFaceColor', [0 1 0] );
hold on; plot( optIMPREX_EHYPEfst_full(:,end-1), optIMPREX_EHYPEfst_full(:,end), 'ro', ...
    'MarkerFaceColor', [1 0 0] );
legend('baseline', 'perfect forecast (observations)', 'precipitation forecast (EHYPE sim)', 'ESP', 'SYS4');
axis([5 15 2200 3200]); xlabel('J^{flood} (flooding days)'); ylabel('J^{supply} (deficit)')