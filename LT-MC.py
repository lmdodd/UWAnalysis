import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

from RecoTauTag.RecoTau.PATTauDiscriminationByMVAIsolationRun2_cff import *
from RecoTauTag.RecoTau.PATTauDiscriminationAgainstElectronMVA6_cfi import *

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_TrancheIV_v8'



process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
#process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
process.options.allowUnscheduled = cms.untracked.bool(True)


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)


# Make the framework shut up.
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        #'file:temp.root'
        #'file:pickevents.root'
            '/store/mc/RunIISummer16MiniAODv2/VBFHToTauTau_M125_13TeV_powheg_pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/0A1C9276-92C4-E611-B966-00266CF2CD48.root'
            #'/store/mc/RunIISummer16MiniAODv2/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2/60000/8EE3D66F-E1C3-E611-B3D5-6CC2173BBD70.root'
            #'/store/user/jbechtel/TauEmbedding_data_2016_v1/FULLEMBEDDING_DATA_CMSSW_8_0_18_FREIBURG_TEST/TauEmbedding_MuTau_data2016_v1_Run2016B/1/merged_0.root'
		),
		inputCommands=cms.untracked.vstring(
						'keep *',
						'keep *_l1extraParticles_*_*',
		)
)

#process.dump=cms.EDAnalyzer('EventContentAnalyzer')


#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
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
#Systematic Shifts 1sigma
process.eventSelectionMTTauNom    = createSystematics(process,process.selectionSequenceMT,'TauNom', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982, 1.01, 1.004)
process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT, 'TauUp',  1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982*1.006, 1.01*1.006, 1.004*1.006)
process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982*0.994, 1.01*0.994, 1.004*0.994)
#
process.eventSelectionETTauNom    = createSystematics(process,process.selectionSequenceET,'TauNom', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.982, 1.01, 1.004)
process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',   1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.988, 1.016, 1.01)
process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown', 1.00, 1.00, 1.00, 0, 1.00, 0.00, 0.00, 0.976, 1.004, 0.998)




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
#addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')


#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
#addEleTauEventTree(process,'eleTauEventTree')
#addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addMuTauShortEventTree
#from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauShortEventTree
#Final trees afor shapes after shifts
#addMuTauShortEventTree(process,'muTauEventTreeTauNom','muTausSortedTauNom','diMuonsOSTauNom')
#addMuTauShortEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','diMuonsOSTauUp')
#addMuTauShortEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','diMuonsOSTauDown')
#
#addEleTauShortEventTree(process,'eleTauEventTreeTauNom','eleTausSortedTauNom','diElectronsOSTauNom')
#addEleTauShortEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','diElectronsOSTauUp')
#addEleTauShortEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','diElectronsOSTauDown')
#

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


