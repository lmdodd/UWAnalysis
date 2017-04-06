#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_1123_weighted
#cp /nfs_scratch/$USER/SMHiggs_1120_unweighted/* /nfs_scratch/$USER/SMHiggs_1123_weighted/.
cd /nfs_scratch/$USER/SM_new/


weight=1;
weightTT=1;
weightH=2;
weightW=1;
weightZ=1;
    
    
if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsIterativeRedoMVis outputFile='ggH110.root'     
    EventWeightsIterativeRedoMVis outputFile='ggH120.root'     
    EventWeightsIterativeRedoMVis outputFile='ggH125.root'     
    EventWeightsIterativeRedoMVis outputFile='ggH130.root'     
    EventWeightsIterativeRedoMVis outputFile='ggH140.root'     
    EventWeightsIterativeRedoMVis outputFile='vbfH110.root'     
    EventWeightsIterativeRedoMVis outputFile='vbfH120.root'     
    EventWeightsIterativeRedoMVis outputFile='vbfH125.root'     
    EventWeightsIterativeRedoMVis outputFile='vbfH130.root'     
    EventWeightsIterativeRedoMVis outputFile='vbfH140.root'     
    EventWeightsIterativeRedoMVis outputFile='ZH120.root'     
    EventWeightsIterativeRedoMVis outputFile='ZH125.root'     
    EventWeightsIterativeRedoMVis outputFile='ZH130.root'     
    EventWeightsIterativeRedoMVis outputFile='WpH120.root'     
    EventWeightsIterativeRedoMVis outputFile='WpH125.root'     
    EventWeightsIterativeRedoMVis outputFile='WpH130.root'     
    EventWeightsIterativeRedoMVis outputFile='WmH120.root'     
    EventWeightsIterativeRedoMVis outputFile='WmH125.root'     
    EventWeightsIterativeRedoMVis outputFile='WmH130.root'     
fi

if [ $weightZ -eq 1 ]
    then
    nohup EventWeightsIterativeRedoMVis outputFile='ZJETS.root' &  
fi

if [ $weightW -eq 1 ]
    then
    nohup EventWeightsIterativeRedoMVis outputFile='WJETS.root' & 
fi

if [ $weightTT -eq 1 ]
    then
    nohup EventWeightsIterativeRedoMVis outputFile='TT.root'     &
fi

if [ $weight -eq 1 ]
    then
    #nohup EventWeightsIterativeRedoMVis outputFile='EWKZ.root'     &
    nohup EventWeightsIterativeRedoMVis outputFile='DiBoson.root'    & 
fi



