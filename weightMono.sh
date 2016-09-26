#!/bin/sh
#mkdir /nfs_scratch/$USER/80X_charged_weighted
#cp /nfs_scratch/$USER/80X_charged_unweighted/* /nfs_scratch/$USER/80X_charged_weighted/.
cd /nfs_scratch/$USER/80X_TT/


weight=0;
weightTT=1;
weightH=0;
weightW=0;
weightZ=0;



if [ $weightH -eq 1 ]
    then
    echo 'weight higgs'
    EventWeightsIterativeGen outputFile='ggH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='vbfH125.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    #make sure Zpt root file is around!!!
    EventWeightsIterativeZJets    weight=1    histoName='MT/results' 
    hadd ZJETS.root ZJets_ext1.root Z1Jets.root Z2Jets.root Z3Jets.root Z4Jets.root ZJets_150.root
    #EventWeightsIterativeZPt    weight=1    histoName='MT/results' 
     
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
    EventWeightsIterativeTT outputFile='TTJets.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeTT has top pt reweighting
    #EventWeightsIterativeTT outputFile='TT.root'  weight=831.76     histoName='MT/results' sumHistoName='sumweights/genWeights'

fi

if [ $weight -eq 1 ]
    then

    #echo 'Weight WAMC'
    echo 'Weight ZZ'
    EventWeightsIterativeGen outputFile='ZZTo2L2Q.root'      weight=3.22  histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='ZZTo4L.root'      weight=1.212  histoName='MT/results' sumHistoName='sumweights/genWeights'


    echo 'Weight WZ 1L1NuQQ'
    EventWeightsIterativeGen outputFile='WZTo1L1Nu2Q.root'      weight=10.71   histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight WZ 2L2Q'
    EventWeightsIterativeGen outputFile='WZTo2L2Q.root'      weight=5.595   histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight WZ 1L3Nu'
    EventWeightsIterativeGen outputFile='WZTo1L3Nu.root'      weight=3.05   histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='WZJTo1L3Nu.root'      weight=4.708   histoName='MT/results' sumHistoName='sumweights/genWeights'
#add m_ll>30

    echo 'Weight WW to L1Nu QQ'
    EventWeightsIterativeGen outputFile='WWTo1L1Nu2Q.root'     weight=1.212     histoName='MT/results' sumHistoName='sumweights/genWeights'
    #EventWeightsIterativeGen outputFile='WWTo2L2Q.root'     weight=49.997    histoName='MT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight VV to 2L2Nu'
    EventWeightsIterativeGen outputFile='VVTo2L2Nu.root'     weight=11.95    histoName='MT/results' sumHistoName='sumweights/genWeights'

    echo 'Weight t_tW'
    EventWeightsIterativeGen outputFile='t_tW.root'       weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight tBar_tW'
    EventWeightsIterativeGen outputFile='tBar_tW.root'    weight=35.6    histoName='MT/results' sumHistoName='sumweights/genWeights'
    echo 'Weight St_antitop'
    EventWeightsIterativeGen outputFile='St_antitop.root'       weight=26.23    histoName='MT/results' sumHistoName='sumweights/genWeights' #80.59 pb * 3*.108
    echo 'Weight St_top'
    EventWeightsIterativeGen outputFile='St_top.root'       weight=44.07    histoName='MT/results' sumHistoName='sumweights/genWeights' #136 * 3*.108

    hadd -f DiBoson.root WWTo*root WZTo*root ZZTo*.root St_*.root t*tW.root VVTo*root
fi



#!/bin/sh
cd /nfs_scratch/$USER/80X_WJetsHT/


weightZ=0;
weightW=1;
weightZinv=0;
weightAh=0;


if [ $weightZinv -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='Zprime600Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime800Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1000Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1200Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1400Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1700Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2000Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2500Zh.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightAh -eq 1 ]
    then
    EventWeightsIterativeGen outputFile='Zprime600A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime800A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime800A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime800A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1000A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1000A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1000A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1000A700h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1000A800h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1200A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1200A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1200A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1200A700h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1200A800h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1400A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1400A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1400A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1400A700h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1400A800h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1700A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1700A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1700A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1700A700h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime1700A800h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2000A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2000A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2000A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2000A700h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2000A800h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2500A400h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2500A500h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2500A600h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2500A700h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
    EventWeightsIterativeGen outputFile='Zprime2500A800h.root'     weight=1    histoName='MT/results' sumHistoName='sumweights/genWeights'
fi

if [ $weightZ -eq 1 ]
    then
    EventWeightsIterativeZNuNu root200=ZnunuHT200.root root400=ZnunuHT400.root root600=ZnunuHT600.root root800=ZnunuHT800.root root1200=ZnunuHT1200.root root2500=ZnunuHT2500.root rootinf=ZnunuHTInf.root   weight=1    histoName='MT/results' 
    hadd Znunu.root ZnunuHT*root 
     
fi

if [ $weightW -eq 1 ]
    then
    EventWeightsIterativeWJetsHT  weight=1    histoName='MT/results' 
    hadd WJETSHT.root WJets*root 
fi

