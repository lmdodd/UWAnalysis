import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_dataRun2_2016SeptRepro_v7'



#process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)


# Make the framework shut up.
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:embedded.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)

#process.dump=cms.EDAnalyzer('EventContentAnalyzer')


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionEMB(process,'HLT',
        [
            'HLT_IsoMu18_v', 
            'HLT_IsoMu20_v', 
            'HLT_IsoMu22_v', 
            'HLT_IsoMu22_eta2p1_v', 
            'HLT_IsoTkMu22_eta2p1_v',
            'HLT_IsoTkMu22_v',
            'HLT_IsoMu24_v', 
            'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele23_WPLoose_Gsf_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_v',
            'HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele24_WPLoose_Gsf_v',
            'HLT_Ele25_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele25_eta2p1_WPTight_Gsf_v',	
            'HLT_Ele27_WPLoose_Gsf_v',
            'HLT_Ele27_WPTight_Gsf_v',
            'HLT_Ele27_eta2p1_WPLoose_Gsf_v',
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

#process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
#process.eventSelectionETJetUp    = createSystematics(process,process.selectionSequenceET,'JetUp',1.0,1.0,1.0,1,1.0)

createGeneratedParticles(process,
        'genDaughters',
        [
            "keep++ pdgId = {Z0}",
            "keep pdgId = {tau+}",
            "keep pdgId = {tau-}",
            "keep pdgId = {mu+}",
            "keep pdgId = {mu-}",
            "keep pdgId = 6",
            "keep pdgId = -6",
            "keep pdgId = 11",
            "keep pdgId = -11",
            "keep pdgId = 25",
            "keep pdgId = 35",
            "keep pdgId = 37",
            "keep pdgId = 36"
            ]
        )


createGeneratedParticles(process,
        'genTauCands',
        [
            "keep pdgId = {tau+} & mother.pdgId()= {Z0}",
            "keep pdgId = {tau-} & mother.pdgId() = {Z0}"
            ]
        )


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauShortEventTree
#addMuTauShortEventTree(process,'muTauEventTreeJetUp','muTausSortedJetUp','diMuonsOSJetUp')

#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauShortEventTree
#addEleTauShortEventTree(process,'muTauEventTreeJetUp','eleTausSortedJetUp','diElectronsOSJetUp')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')

from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauShortEventTree
from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauShortEventTree
#Final trees afor shapes after shifts
addMuTauShortEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','diMuonsOSTauUp')
addMuTauShortEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','diMuonsOSTauDown')
addMuTauShortEventTree(process,'muTauEventTreeFinalTauUp','muTausOSTauUp','diMuonsOSTauUp')
addMuTauShortEventTree(process,'muTauEventTreeFinalTauDown','muTausOSTauDown','diMuonsOSTauDown')
addMuTauShortEventTree(process,'muTauEventTreeJetUp','muTausSortedJetUp','diMuonsOSJetUp')
addMuTauShortEventTree(process,'muTauEventTreeJetDown','muTausSortedJetDown','diMuonsOSJetDown')
addMuTauShortEventTree(process,'muTauEventTreeFinalJetUp','muTausOSJetUp','diMuonsOSJetUp')
addMuTauShortEventTree(process,'muTauEventTreeFinalJetDown','muTausOSJetDown','diMuonsOSJetDown')
#

#
addEleTauShortEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','diElectronsOSTauUp')
addEleTauShortEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','diElectronsOSTauDown')
addEleTauShortEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','diElectronsOSTauUp')
addEleTauShortEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','diElectronsOSTauDown')
addEleTauShortEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','diElectronsOSJetUp')
addEleTauShortEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','diElectronsOSJetDown')
addEleTauShortEventTree(process,'eleTauEventTreeFinalJetUp','eleTausOSJetUp','diElectronsOSJetUp')
addEleTauShortEventTree(process,'eleTauEventTreeFinalJetDown','eleTausOSJetDown','diElectronsOSJetDown')
#
