#!/bin/sh
#mkdir /nfs_scratch/$USER/SMHiggs_weighted2
#cp /nfs_scratch/$USER/SMHiggs_unweighted/* /nfs_scratch/$USER/SMHiggs_weighted2/.
cd /nfs_scratch/$USER/SMHiggs_mvis_unweighted/

weight=0;
weightTT=0;
weightH=0;
weightW=0;
weightZ=0;
weightEWK=0;
weightTriBoson=0;
    
#hadd  WJETS.root WJetsMLM.root W1Jets.root W2Jets.root W3Jets.root W4Jets.root 
#hadd  VV.root WWTo*root WZTo*root ZZTo*.root VVTo*root
#hadd  DiBoson.root WWTo*root WZTo*root ZZTo*.root St_*.root t*tW.root VVTo*root EWK*2jet.root  
#hadd  DiBoson.root WWTo*root WZTo*root ZZTo*.root St_*.root t*tW.root VVTo*root WWW*root WWZ*root WZZ*root ZZZ*root EWK*2jet.root 
#hadd  EWKZ.root EWKZ*root


if [ $weightH -eq 1 ]
    then
    echo 'weight higgs to 1 pb'
    EventWeightsIterativeGen outputFile='ggH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ggH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ggH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='ZH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WpH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WpH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WpH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WmH120.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WmH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='WmH130.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    #Zpt histogram not cureently used in Zpt reweighting 
    #EventWeightsIterativeZJets    weight=1    histoName='MT/results' 
    hadd ZJETS.root ZJets_ext.root Z1Jets.root Z2Jets.root Z3Jets.root Z4Jets.root #ZJets_150.root
    EventWeightsIterativeZPt    weight=1    histoName='MT/results' 
     
fi

if [ $weightW -eq 1 ]
    then
    #EventWeightsIterativeGen outputFile='WJetsAMC.root'      weight=61526.7   histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeWJets    weight=1    histoName='MT/results'  
    hadd WJETS.root WJetsMLM.root W1Jets.root W2Jets.root W3Jets.root W4Jets.root
 
fi


if [ $weightTT -eq 1 ]
    then
    echo 'Weight TT'
    #EventWeightsIterativeTT outputFile='TTJets.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    nohup EventWeightsIterativeGen outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights' &
    #EventWeightsIterativeTT has top pt reweighting
    #EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'

fi

if [ $weight -eq 1 ]
    then

    #echo 'Weight WAMC'
    echo 'Weight ZZ'
    nohup EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights' &


    echo 'Weight WZ 1L1NuQQ'
    nohup EventWeightsIterativeGen outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight WZ 2L2Q'
    nohup EventWeightsIterativeGen outputFile='WZTo2L2Q.root'      weight=5.595   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight WZ 1L3Nu'
    nohup EventWeightsIterativeGen outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='WZTo3L1Nu.root'      weight=4.708   histoName='MT/results' sumHistoName='sumweights/genWeights' &

    echo 'Weight WW to L1Nu QQ'
    nohup EventWeightsIterativeGen outputFile='WWTo1L1Nu2Q.root'     weight=49.997     histoName='MT/results' sumHistoName='sumweights/genWeights' &
    #EventWeightsIterativeGen outputFile='WWTo2L2Q.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight VV to 2L2Nu'
    nohup  EventWeightsIterativeGen outputFile='VVTo2L2Nu.root'     weight=11.95    histoName='MT/results' sumHistoName='sumweights/genWeights' &

    echo 'Weight t_tW'
    nohup EventWeightsIterativeGen outputFile='t_tW.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight tBar_tW'
    nohup EventWeightsIterativeGen outputFile='tBar_tW.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    echo 'Weight St_antitop'
    nohup EventWeightsIterativeGen outputFile='St_antitop.root'       weight=26.23    histoName='MT/results' sumHistoName='sumweights/genWeights' & #80.59 pb * 3*.108
    echo 'Weight St_top'
    nohup EventWeightsIterativeGen outputFile='St_top.root'       weight=44.07    histoName='MT/results' sumHistoName='sumweights/genWeights' & #136 * 3*.108

    #hadd -f DiBoson.root WWTo*root WZTo*root ZZTo*.root St_*.root t*tW.root VVTo*root
fi


if [ $weightEWK -eq 1 ]
    then
    echo 'Weight EWK'
    nohup EventWeightsIterativeGen outputFile='EWKZ2JetLL.root'  weight=3.987    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='EWKZ2JetNuNu.root'  weight=10.01    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='EWKminus2jet.root'  weight=20.25    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='EWKplus2jet.root'  weight=25.62    histoName='MT/results' sumHistoName='sumweights/genWeights' &
fi

if [ $weightTriBoson -eq 1 ]
    then
    echo 'Weight Triboson'
    nohup EventWeightsIterativeGen outputFile='WWW.root'  weight=0.2086    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='WWZ.root'  weight=0.1651    histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='WZZ.root'  weight=0.05565   histoName='MT/results' sumHistoName='sumweights/genWeights' &
    nohup EventWeightsIterativeGen outputFile='ZZZ.root'  weight=0.01398   histoName='MT/results' sumHistoName='sumweights/genWeights' &
fi




