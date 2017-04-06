#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_1123_weighted
#cp /nfs_scratch/$USER/SMHiggs_1120_unweighted/* /nfs_scratch/$USER/SMHiggs_1123_weighted/.
cd /nfs_scratch/$USER/SM_new/


weight=1;
    
    
if [ $weight -eq 1 ]
    then
    echo 'Adding emptybranches to merge'
    #nohup EventWeightsForEfficiencyIsolation outputFile='muDATAB.root' branch='HLT_IsoTkMu22_v_prescale' &
    nohup EventWeightsIterativeAddBranch outputFile='muDATAC.root' & 
    nohup EventWeightsIterativeAddBranch outputFile='muDATAD.root' &
    nohup EventWeightsIterativeAddBranch outputFile='muDATAE.root' &
    nohup EventWeightsIterativeAddBranch outputFile='muDATAF.root' &
    nohup EventWeightsIterativeAddBranch outputFile='muDATAG.root' &
    nohup EventWeightsIterativeAddBranch outputFile='muDATAH.root' &
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAB.root' &
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAC.root' &
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAD.root' &
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAE.root' &
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAF.root' &
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAG.root' & 
    nohup EventWeightsIterativeAddBranch outputFile='eleDATAH.root' &  
fi

