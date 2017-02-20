#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

jobID= Feb13Test
jobOptions="--vsize-limit=8000  --assume-input-files-exist --input-files-per-job=2 "
for tailOptions in "$CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-1prong.py" "$CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-1prong1pi0.py" "$CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC-3prong.py"
do
        ##########WJETS SAMPLES#############
            echo $tailOptions
                farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_SMHiggs_ggHtautau_125 $tailOptions
                    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_SMHiggs_vbfHtautau_125 $tailOptions
