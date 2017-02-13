#!/bin/sh
farmoutAnalysisJobs --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  "$1"_SMHiggs_ggHtautau_125 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py
