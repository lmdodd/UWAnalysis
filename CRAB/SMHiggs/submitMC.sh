#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

jobID= Feb23Test
jobOptions="--vsize-limit=8000  --assume-input-files-exist --input-files-per-job=2 "
for tailOptions in "$CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-MC.py"
do
    ##########WJETS SAMPLES#############
    echo $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_SMHiggs_ggHtautau_125 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/VBFHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_SMHiggs_vbfHtautau_125 $tailOptions

    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WplusHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WplusHToTauTau_120 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WplusHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WplusHToTauTau_125 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WplusHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WplusHToTauTau_130 $tailOptions

    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WminusHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WminusHToTauTau_120 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WminusHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WminusHToTauTau_125 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/WminusHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WminusHToTauTau_130 $tailOptions


    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ZHToTauTau_M120_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZHToTauTau_120 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ZHToTauTau_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZHToTauTau_125 $tailOptions
    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/ZHToTauTau_M130_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZHToTauTau_130 $tailOptions

    farmoutAnalysisJobs  $1 $jobOptions --input-dbs-path=/GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ggHWW_125 $tailOptions


    ########ZJETS SAMPLES#############
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/MINIAODSIM  ${jobID}_SMHiggs_ZJets_ext $tailOptions  

    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_Z1Jets $tailOptions  
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_Z2Jets $tailOptions  
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_Z3Jets $tailOptions  
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_Z4Jets $tailOptions  
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZJets_10to50 $tailOptions  

    ########TT SAMPLES################
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_TT $tailOptions  
    farmoutAnalysisJobs $1  $jobOptions --input-dbs-path=/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_backup_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_TT_backup $tailOptions  

    ##########WJETS SAMPLES#############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WJets $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM  ${jobID}_SMHiggs_WJets_ext $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_W1Jets $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_W2Jets $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_W3Jets $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_W4Jets $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM  ${jobID}_SMHiggs_W4Jets_ext1 $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM  ${jobID}_SMHiggs_W4Jets_ext2 $tailOptions  

    ###########WZ SAMPLES#############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WZJToLLLNu_TuneCUETP8M1_13TeV-amcnlo-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WZTo3L1Nu $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WZTo1L3Nu $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v3/MINIAODSIM  ${jobID}_SMHiggs_WZTo1L1Nu2Q $tailOptions  
    #farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/MINIAODSIM  ${jobID}_SMHiggs_WZTo2L2Q $tailOptions  

    ##########SINGLE TOP SAMPLES#############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM  ${jobID}_SMHiggs_tBar_tW $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM  ${jobID}_SMHiggs_t_tW $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_St_t_antitop $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_St_t_top $tailOptions  

    ###########WW SAMPLES#############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WWTo1L1Nu2Q $tailOptions  
    ###########ZZ SAMPLES#############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZZTo2L2Q $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ZZTo4L_13TeV_powheg_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZZTo4L $tailOptions  

    ###########VV SAMPLES#############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_VVTo2L2Nu $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/MINIAODSIM  ${jobID}_SMHiggs_VVTo2L2Nu_ext $tailOptions  

    ###########Triboson###############
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WWW_4F $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WWZ $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_WZZ $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_ZZZ $tailOptions  


    ############EWK###############
    #have extensions
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_EWKminus2jet $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_EWKplus2jet $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM   ${jobID}_SMHiggs_EWKZ2JetLL $tailOptions  
    farmoutAnalysisJobs $1 $jobOptions  --input-dbs-path=/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM  ${jobID}_SMHiggs_EWKZ2JetNuNu $tailOptions  


