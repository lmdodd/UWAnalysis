#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_1123_weighted
#cp /nfs_scratch/$USER/SMHiggs_1120_unweighted/* /nfs_scratch/$USER/SMHiggs_1123_weighted/.
cd /nfs_scratch/$USER/SM_fixme/


weight=1;
weightTT=1;
weightH=1;
weightW=1;
weightZ=1;
    
    
if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsForEfficiencyIsolation outputFile='ggH120.root'     
    EventWeightsForEfficiencyIsolation outputFile='ggH125.root'     
    EventWeightsForEfficiencyIsolation outputFile='ggH130.root'     
    EventWeightsForEfficiencyIsolation outputFile='vbfH120.root'     
    EventWeightsForEfficiencyIsolation outputFile='vbfH125.root'     
    EventWeightsForEfficiencyIsolation outputFile='vbfH130.root'     
    EventWeightsForEfficiencyIsolation outputFile='ZH120.root'     
    EventWeightsForEfficiencyIsolation outputFile='ZH125.root'     
    EventWeightsForEfficiencyIsolation outputFile='ZH130.root'     
    EventWeightsForEfficiencyIsolation outputFile='WpH120.root'     
    EventWeightsForEfficiencyIsolation outputFile='WpH125.root'     
    EventWeightsForEfficiencyIsolation outputFile='WpH130.root'     
    EventWeightsForEfficiencyIsolation outputFile='WmH120.root'     
    EventWeightsForEfficiencyIsolation outputFile='WmH125.root'     
    EventWeightsForEfficiencyIsolation outputFile='WmH130.root'     
fi

if [ $weightZ -eq 1 ]
    then
    EventWeightsForEfficiencyIsolation outputFile='ZJETS.root'     
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsForEfficiencyIsolation outputFile='WJETS.root'     
fi

if [ $weightTT -eq 1 ]
    then
    EventWeightsForEfficiencyIsolation outputFile='TT.root'     
fi

if [ $weight -eq 1 ]
    then
    EventWeightsForEfficiencyIsolation outputFile='EWKZ.root'     
    #EventWeightsForEfficiencyIsolation outputFile='EWK.root'     
    EventWeightsForEfficiencyIsolation outputFile='DiBoson.root'     
fi



