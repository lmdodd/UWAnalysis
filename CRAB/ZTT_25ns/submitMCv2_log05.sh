#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

#######Low Mass ZJets##########
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb23_ZJets_1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-dbs-path=/DY2JetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM 25ns_NoShapes_Feb23_Z2Jets_1050 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

########TT SAMPLES################
#farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM   25ns_NoShapes_Feb23_TTJets $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb23_TT $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-ext3-v1/MINIAODSIM  25ns_NoShapes_Feb23_TT_ext3 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  
farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/TT_TuneCUETP8M1_13TeV-amcatnlo-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-ext4-v1/MINIAODSIM  25ns_NoShapes_Feb23_TT_ext4 $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  

##########WJETS SAMPLES#############

farmoutAnalysisJobs $1 --vsize-limit=8000 --assume-input-files-exist --input-files-per-job=1 --input-dbs-path=/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM  25ns_NoShapes_Feb23_WJets_MLM $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/ZTT_25ns/SUB-MC.py  



