#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_SVfit_weighted
#cp /nfs_scratch/$USER/SMHiggs_SVfit_unweighted/* /nfs_scratch/$USER/SMHiggs_SVfit_weighted/.
cd /nfs_scratch/$USER/zjetssync/


weightZ=1;
    
    
if [ $weightZ -eq 1 ]
    then
    #EventWeightsIterativeZSync    weight=1    histoName='MT/results' 
    #hadd ZJETS.root ZJets_ext1.root Z1Jets.root Z2Jets.root Z3Jets.root Z4Jets.root
    EventWeightsIterativeZPt    weight=1    histoName='MT/results' 
fi

