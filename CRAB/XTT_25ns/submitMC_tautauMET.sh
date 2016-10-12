#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############

#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-1000_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv1000 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-1200_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv1200 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-1400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv1400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-1700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv1700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-2000_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv2000 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
#/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToZhToZinvhtautau_2HDM_M-2500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  20160929_MonoH_ZprimeZinv2500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py


/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_600_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_600_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_800_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_800_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_800_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_800_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1000_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v2/MINIAODSIM  20160929_MonoH_ZprimeA0h_1000_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v2/MINIAODSIM  20160929_MonoH_ZprimeA0h_1000_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1000_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v2/MINIAODSIM  20160929_MonoH_ZprimeA0h_1000_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1000_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1200_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1200_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1200_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1200_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1200_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1200_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1400_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1400_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1400_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v2/MINIAODSIM  20160929_MonoH_ZprimeA0h_1400_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1400_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1400_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1700_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1700_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1700_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1700_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1700_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_1700_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2000_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2000_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2000_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2000_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2000_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2000_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py

/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/RunIISpring16MiniAODv2-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM 20160929_MonoH_ZprimeA0h_2500_300 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2500_400 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2500_500 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2500_600 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2500_700 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
/cms/sw/farmout/farmoutAnalysisJobs.fix  $1 --vsize-limit=8000 --assume-input-files-exist --skip-existing-output --input-dbs-path=/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20160929_MonoH_ZprimeA0h_2500_800 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/XTT_25ns/SUB-MC-HLT2.py
