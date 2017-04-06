#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_1123_weighted
#cp /nfs_scratch/$USER/SMHiggs_1120_unweighted/* /nfs_scratch/$USER/SMHiggs_1123_weighted/.
cd /nfs_scratch/$USER/SM_new/


weight=1;
weightTT=1;
weightH=1;
weightW=1;
weightZ=1;
    
    
if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsMuonTrigger outputFile='ggH110.root'     
    EventWeightsMuonTrigger outputFile='ggH120.root'     
    EventWeightsMuonTrigger outputFile='ggH125.root'     
    EventWeightsMuonTrigger outputFile='ggH130.root'     
    EventWeightsMuonTrigger outputFile='ggH140.root'     
    EventWeightsMuonTrigger outputFile='vbfH110.root'     
    EventWeightsMuonTrigger outputFile='vbfH120.root'     
    EventWeightsMuonTrigger outputFile='vbfH125.root'     
    EventWeightsMuonTrigger outputFile='vbfH130.root'     
    EventWeightsMuonTrigger outputFile='vbfH140.root'     
    EventWeightsMuonTrigger outputFile='ZH120.root'     
    EventWeightsMuonTrigger outputFile='ZH125.root'     
    EventWeightsMuonTrigger outputFile='ZH130.root'     
    EventWeightsMuonTrigger outputFile='WpH120.root'     
    EventWeightsMuonTrigger outputFile='WpH125.root'     
    EventWeightsMuonTrigger outputFile='WpH130.root'     
    EventWeightsMuonTrigger outputFile='WmH120.root'     
    EventWeightsMuonTrigger outputFile='WmH125.root'     
    EventWeightsMuonTrigger outputFile='WmH130.root'     
fi

if [ $weightZ -eq 1 ]
    then
    nohup EventWeightsMuonTrigger outputFile='ZJETS.root' &  
fi

if [ $weightW -eq 1 ]
    then
    nohup EventWeightsMuonTrigger outputFile='WJETS.root' & 
fi

if [ $weightTT -eq 1 ]
    then
    nohup EventWeightsMuonTrigger outputFile='TT.root'     &
fi

if [ $weight -eq 1 ]
    then
    nohup EventWeightsMuonTrigger outputFile='EWKZ.root' &
    nohup EventWeightsMuonTrigger outputFile='DiBoson.root' & 
fi



