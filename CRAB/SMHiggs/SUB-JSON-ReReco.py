import FWCore.ParameterSet.Config as cms
import os

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')


process.GlobalTag.globaltag = '80X_dataRun2_2016SeptRepro_v7'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)

# Make the framework shut up.
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 500



process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
		$inputFileNames
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
		)
)

from UWAnalysis.Configuration.JSONBtoH import myLumiList
myLumiList(process);

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstruction(process,'HLT',
        [
            'HLT_IsoMu22_eta2p1_v', 
            'HLT_IsoTkMu22_eta2p1_v',
            'HLT_IsoMu24_v', 
            'HLT_IsoTkMu24_v', 
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele25_eta2p1_WPTight_Gsf_v',	
            'HLT_Ele27_WPTight_Gsf_v',
            'HLT_Ele32_WPTight_Gsf_v',
            'HLT_Ele45_WPLoose_Gsf_L1JetTauSeeded',
            'HLT_Ele27_eta2p1_WPTight_Gsf_v',
            'HLT_VLooseIsoPFTau140_Trk50_eta2p1_v',
            'HLT_VLooseIsoPFTau120_Trk50_eta2p1_v',
            'HLT_PFMET170_NoiseCleaned',
            'HLT_PFMET90_PFMHT90_IDTight',
            'HLT_CaloJet500_NoJetID',
            'HLT_ECALHT800'
            ])



        #EventSelection
process.load("UWAnalysis.Configuration.hTauTau_cff")


process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


process.TFileService.fileName=cms.string("$outputFileName")

