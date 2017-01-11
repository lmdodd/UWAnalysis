#!/bin/sh
#voms-proxy-init --voms cms --valid 100:00

######HIGGS SAMPLES #############
#ggH
#farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M120_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20170111_SMHiggs_ggHtautau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  20170111_SMHiggs_ggHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
#farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M130_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20170111_SMHiggs_ggHtautau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py

#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/VBFHToTauTau_M120_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20170111_SMHiggs_vbfHtautau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  20170111_SMHiggs_vbfHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/VBFHToTauTau_M130_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM  20170111_SMHiggs_vbfHtautau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py

farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/WplusHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_WplusHToTauTau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/WplusHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_WplusHToTauTau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/WplusHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_WplusHToTauTau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py

farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/WminusHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_WminusHToTauTau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/WminusHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_WminusHToTauTau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/WminusHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_WminusHToTauTau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py


farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/ZHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_ZHToTauTau_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/ZHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_ZHToTauTau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/ZHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_ZHToTauTau_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py

#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/GluGluHToWWTo2L2Nu_M120_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM 20170111_SMHiggs_ggHWW_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_ggHWW_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/GluGluHToWWTo2L2Nu_M130_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM 20170111_SMHiggs_ggHWW_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py

#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/VBFHToWWTo2L2Nu_M120_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM 20170111_SMHiggs_vbfHWW_120 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/VBFHToWWTo2L2Nu_M125_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM 20170111_SMHiggs_vbfHWW_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
#farmoutAnalysisJobs  $1 --vsize-limit=8000 --assume-input-files-exist  --input-dbs-path=/VBFHToWWTo2L2Nu_M130_13TeV_powheg_pythia8/RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/MINIAODSIM 20170111_SMHiggs_vbfHWW_130 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py

########ZJETS SAMPLES#############
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM 20170111_SMHiggs_ZJets_ext $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_Z1Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_Z2Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_Z3Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_Z4Jets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  

#farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-150_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM 20170111_SMHiggs_ZJets_150 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_ZJets_10to50 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  

########TT SAMPLES################
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000   --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_backup_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM 20170111_SMHiggs_TT_backup $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py  



