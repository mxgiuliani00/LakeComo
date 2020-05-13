% script to create Figure 6 of the paper 

clear
clc

% load reference sets

load -ascii optLakeComo_perfectF.reference  % perfect inflow forecast cumulated over 51 days 
load -ascii optLakeComo_base.reference      % baseline with standard policy inputs (doy, level)
load -ascii optLakeComo_inflowF.reference   % CSI inflow forecast cumulated over 51 days 
load -ascii optLakeComo_precipF.reference   % CSI seasonal precipitation forecast
load -ascii optLakeComo_SST.reference       % CSI pre-season observed SST

% Pareto front
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