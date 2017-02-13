#!/bin/sh
voms-proxy-init --voms cms --valid 100:00


######HIGGS SAMPLES #############
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM syncNtupleEleVBF_2016_v4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-ELE.py
farmoutAnalysisJobs  $1 --assume-input-files-exist --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM syncNtupleMuVBF_2016_v4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/Sync/SUB-MU.py
