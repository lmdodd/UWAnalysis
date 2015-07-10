UWAnalysis
==========

H->tautau (+ many other) Final States! : )


#Set Up instructions:

```
cmsrel CMSSW_7_4_6_patch6
cd CMSSW_7_4_6_patch6/src/
cmsenv
git cms-init 
git clone --recursive -b 746patch6_dev https://github.com/lmdodd/UWAnalysis.git   
cd UWAnalysis
source recipe13TeV.sh
export USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=reorder"
scram b -j 8
```
to run

```
cd CRAB/HTT
cmsRun LT-MC.py
```

or

```
cd CRAB/ZTT/
source submitMC.sh
source submitData.sh
```



#Building comments

Critical: Go Through CheckMes and FixMes again. Check Good Vertices.

candidateAuxFunctions brought to MiniAod (Were in TauAnalysis, use again?)

Major Changes/Issues detailed in table

| Kind Of Issue  | Issue Detail |
| ------------- | ------------- |
| StatTools Not Included  | StatTools is left behind in 715X because HiggsCombine is stuck there. StatTools can be found https://github.com/lmdodd/UWAnalysis/tree/stattools.  |
| MVAMet Overcorrects | No solution yet. Needed for svFit. Include lepton. |
| Efficiencies Application | Add Efficiencies into Ntuples, rather than computing afterwards !! TODO|
| ESscaling | Edited file to add pt2ES. This energy scle confuses me. userFloat(ESpt) was never getting filled. Now filled in TauESProducer. This should be checked. Currently output zero? |
| relIso | use Dr=0.3 | 
| no particle embedding yet | TBC |
| TBC | TBC |

In general To see what needs to be fixed ``` grep -r FIXME *``` or ``` CHECKME```. 


