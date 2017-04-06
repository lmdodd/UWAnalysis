#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_1123_weighted
#cp /nfs_scratch/$USER/SMHiggs_1120_unweighted/* /nfs_scratch/$USER/SMHiggs_1123_weighted/.
cd /nfs_scratch/$USER/SM_W/


weight=0;
weightTT=0;
weightH=0;
weightW=1;
weightZ=0;
    
    
if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsForEfficiencyTracking outputFile='ggH110.root'     
    EventWeightsForEfficiencyTracking outputFile='ggH120.root'     
    EventWeightsForEfficiencyTracking outputFile='ggH125.root'     
    EventWeightsForEfficiencyTracking outputFile='ggH130.root'     
    EventWeightsForEfficiencyTracking outputFile='ggH140.root'     
    EventWeightsForEfficiencyTracking outputFile='vbfH110.root'     
    EventWeightsForEfficiencyTracking outputFile='vbfH120.root'     
    EventWeightsForEfficiencyTracking outputFile='vbfH125.root'     
    EventWeightsForEfficiencyTracking outputFile='vbfH130.root'     
    EventWeightsForEfficiencyTracking outputFile='vbfH140.root'     
    EventWeightsForEfficiencyTracking outputFile='ZH110.root'     
    EventWeightsForEfficiencyTracking outputFile='ZH120.root'     
    EventWeightsForEfficiencyTracking outputFile='ZH125.root'     
    EventWeightsForEfficiencyTracking outputFile='ZH130.root'     
    EventWeightsForEfficiencyTracking outputFile='ZH140.root'     
    EventWeightsForEfficiencyTracking outputFile='WpH110.root'     
    EventWeightsForEfficiencyTracking outputFile='WpH120.root'     
    EventWeightsForEfficiencyTracking outputFile='WpH125.root'     
    EventWeightsForEfficiencyTracking outputFile='WpH130.root'     
    EventWeightsForEfficiencyTracking outputFile='WpH140.root'     
    EventWeightsForEfficiencyTracking outputFile='WmH120.root'     
    EventWeightsForEfficiencyTracking outputFile='WmH110.root'     
    EventWeightsForEfficiencyTracking outputFile='WmH125.root'     
    EventWeightsForEfficiencyTracking outputFile='WmH130.root'     
    EventWeightsForEfficiencyTracking outputFile='WmH140.root'     

    EventWeightsForEfficiencyTracking outputFile='ggHWW125.root'
    EventWeightsForEfficiencyTracking outputFile='vbfHWW125.root'
fi

if [ $weightZ -eq 1 ]
    then
    nohup EventWeightsForEfficiencyTracking outputFile='ZJETS.root' &  
fi

if [ $weightW -eq 1 ]
    then
    nohup EventWeightsForEfficiencyTracking outputFile='WJETS.root' & 
fi

if [ $weightTT -eq 1 ]
    then
    nohup EventWeightsForEfficiencyTracking outputFile='TT.root'     &
fi

if [ $weight -eq 1 ]
    then
    nohup EventWeightsForEfficiencyTracking outputFile='EWKZ.root'  &
    nohup EventWeightsForEfficiencyTracking outputFile='DiBoson.root' & 
fi



