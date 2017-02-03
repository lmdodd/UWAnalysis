#!/bin/sh
voms-proxy-init --voms cms --valid 100:00

######HIGGS SAMPLES #############
#ggH
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016B/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016B $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016C/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016C $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016D/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016D $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016E/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016E $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016F/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016F $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016G/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016G $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016H/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_MT_2016H $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py

farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016B/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016B $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016C/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016C $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016D/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016D $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016E/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016E $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016F/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016F $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016G/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016G $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py
farmoutAnalysisJobs  $1 --vsize-limit=8000  --assume-input-files-exist --input-dbs-path=/EmbeddingRun2016H/ElTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER 20170130_SMHiggs_EMB_ET_2016H $CMSSW_BASE $CMSSW_BASE/src/UWAnalysis/CRAB/SMHiggs/SUB-EMB.py

