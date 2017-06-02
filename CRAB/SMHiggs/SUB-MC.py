import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_TrancheIV_v8'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)



#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
        [
            'HLT_IsoMu22_v', 
            'HLT_IsoMu22_eta2p1_v', 
            'HLT_IsoTkMu22_v',
            'HLT_IsoTkMu22_eta2p1_v',
            'HLT_IsoMu24_v', 
            'HLT_IsoMu24_eta2p1_v', 
            'HLT_IsoTkMu24_v', 
            'HLT_IsoTkMu24_eta2p1_v', 
            'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_v',
            'HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele25_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele25_eta2p1_WPTight_Gsf_v',	
            'HLT_Ele27_WPLoose_Gsf_v',
            'HLT_Ele27_WPTight_Gsf_v',
            'HLT_Ele27_eta2p1_WPLoose_Gsf_v',
            'HLT_Ele27_eta2p1_WPTight_Gsf_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_v',
            'HLT_Ele22_eta2p1_WPLoose_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele24_eta2p1_WPLoose_LooseIsoPFTau20_v',
            'HLT_Ele24_eta2p1_WPLoose_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele27_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v',
            'HLT_Ele32_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_v',
            'HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg_v',
            'HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v',
            'HLT_VLooseIsoPFTau140_Trk50_eta2p1_v',
            'HLT_VLooseIsoPFTau120_Trk50_eta2p1_v',
            'HLT_PFMET170_NoiseCleaned',
            'HLT_PFMET90_PFMHT90_IDTight',
            'HLT_CaloJet500_NoJetID',
            'HLT_ECALHT800'
            ])



        #EventSelection
process.load("UWAnalysis.Configuration.hTauTau_cff")

#createSystematics(process,sequence,postfix,muScale,eScale,tauScale,jetScale,unclusteredScale,electronresb = 0.0, electronrese = 0.0, oneProngScale = 1.0,oneProngPi0Scale = 1.0, threeProngScale = 1.0):
process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)
#Systematic Shifts 1sigma
#process.eventSelectionMTTauNom    = createSystematics(process,process.selectionSequenceMT,'TauNom', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982, 1.010, 1.004)
#process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT, 'TauUp',  1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982*1.006, 1.010*1.006, 1.004*1.006)
#process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT, 'TauDown', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982*0.994, 1.010*0.994, 1.004*0.994)
#
#
#process.eventSelectionETTauNom    = createSystematics(process,process.selectionSequenceET,'TauNom', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982, 1.010, 1.004)
#process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET, 'TauUp',   1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982*1.006, 1.010*1.006, 1.004*1.006)
#process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET, 'TauDown', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982*0.994, 1.010*0.994, 1.004*0.994)


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
            ]
        )


createGeneratedParticles(process,
        'genTauCands',
        [
            "keep pdgId = {tau+}",
            "keep pdgId = {tau-}"
            ]
        )


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauEventTree
addMuTauEventTree(process,'muTauEventTree')
#addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')
#addMuTauEventTree(process,'muTauEventTreeTauNom','muTausSortedTauNom','diMuonsOSSortedTauNom')


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
#addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')
#addEleTauEventTree(process,'eleTauEventTreeTauNom','eleTausSortedTauNom','diElectronsOSSortedTauNom')

#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauShortEventTree
#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauShortEventTree
#Final trees afor shapes after shifts
#addMuTauShortEventTree(process,'muTauEventTreeTauNom','muTausSortedTauNom','diMuonsOSTauNom')
#addMuTauShortEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','diMuonsOSSortedTauUp')
#addMuTauShortEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','diMuonsOSSortedTauDown')
#
#addEleTauShortEventTree(process,'eleTauEventTreeTauNom','eleTausSortedTauNom','diElectronsOSTauNom')
#addEleTauShortEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','diElectronsOSortedTauUp')
#addEleTauShortEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','diElectronsOSSortedTauDown')
#

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


process.source = cms.Source("PoolSource",
        fileNames = cms.untracked.vstring(
            $inputFileNames
            ),
        inputCommands=cms.untracked.vstring(
            'keep *',
            )
        )

process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
        )

#process.TFileService.fileName=cms.string("$outputFileName")
process.TFileService = cms.Service(
        "TFileService",
        fileName = cms.string("$outputFileName")
        )
