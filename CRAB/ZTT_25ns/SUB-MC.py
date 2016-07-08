import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_miniAODv2_v1'


process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(True)



#added in etau and mutau triggers
from UWAnalysis.Configuration.tools.analysisToolsHTauTau_WIP import *
defaultReconstructionMC(process,'HLT',
                      [
			'HLT_Ele23_WPLoose_Gsf_v*', #eleTau
			'HLT_IsoMu20*' #singlemu
                      ])

                      

#EventSelection
process.load("UWAnalysis.Configuration.hTauTau_cff")

process.metCalibration.applyCalibration = cms.bool(False)

process.eventSelectionMT = cms.Path(process.selectionSequenceMT)
process.eventSelectionET = cms.Path(process.selectionSequenceET)
#Systematic Shifts 1sigma
#process.eventSelectionMTTauUp    = createSystematics(process,process.selectionSequenceMT,'TauUp',1.0,1.0,1.03,0,1.0)
#process.eventSelectionMTTauDown  = createSystematics(process,process.selectionSequenceMT,'TauDown',1.0,1.0,0.97,0,1.0)
#process.eventSelectionMTJetUp    = createSystematics(process,process.selectionSequenceMT,'JetUp',1.0,1.0,1.0,1,1.0)
#process.eventSelectionMTJetDown  = createSystematics(process,process.selectionSequenceMT,'JetDown',1.0,1.0,1.0,-1,1.0)

#process.eventSelectionETTauUp    = createSystematics(process,process.selectionSequenceET,'TauUp',1.00,1.0,1.03,0,1.0)
#process.eventSelectionETTauDown  = createSystematics(process,process.selectionSequenceET,'TauDown',1.0,1.0,0.97,0,1.0)
#process.eventSelectionETJetUp    = createSystematics(process,process.selectionSequenceET,'JetUp',1.0,1.0,1.0,1,1.0)
#process.eventSelectionETJetDown  = createSystematics(process,process.selectionSequenceET,'JetDown',1.0,1.0,1.0,-1,1.0)



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
addMuTauEventTree(process,'muTauEventTreeFinal','muTausOS','diMuonsOSSorted')


from UWAnalysis.Configuration.tools.ntupleToolsHTauTau_WIP import addEleTauEventTree
addEleTauEventTree(process,'eleTauEventTree')
addEleTauEventTree(process,'eleTauEventTreeFinal','eleTausOS','diElectronsOSSorted')

addEventSummary(process,True,'MT','eventSelectionMT')
addEventSummary(process,True,'ET','eventSelectionET')


#Final trees afor shapes after shifts
#addMuTauEventTree(process,'muTauEventTreeTauUp','muTausSortedTauUp','diMuonsOSTauUp')
#addMuTauEventTree(process,'muTauEventTreeTauDown','muTausSortedTauDown','diMuonsOSTauDown')
#addMuTauEventTree(process,'muTauEventTreeFinalTauUp','muTausOSTauUp','diMuonsOSTauUp')
#addMuTauEventTree(process,'muTauEventTreeFinalTauDown','muTausOSTauDown','diMuonsOSTauDown')
#addMuTauEventTree(process,'muTauEventTreeJetUp','muTausSortedJetUp','diMuonsOSJetUp')
#addMuTauEventTree(process,'muTauEventTreeJetDown','muTausSortedJetDown','diMuonsOSJetDown')
#addMuTauEventTree(process,'muTauEventTreeFinalJetUp','muTausOSJetUp','diMuonsOSJetUp')
#addMuTauEventTree(process,'muTauEventTreeFinalJetDown','muTausOSJetDown','diMuonsOSJetDown')
#
#addEleTauEventTree(process,'eleTauEventTreeTauUp','eleTausSortedTauUp','diElectronsOSTauUp')
#addEleTauEventTree(process,'eleTauEventTreeTauDown','eleTausSortedTauDown','diElectronsOSTauDown')
#addEleTauEventTree(process,'eleTauEventTreeFinalTauUp','eleTausOSTauUp','diElectronsOSTauUp')
#addEleTauEventTree(process,'eleTauEventTreeFinalTauDown','eleTausOSTauDown','diElectronsOSTauDown')
#addEleTauEventTree(process,'eleTauEventTreeJetUp','eleTausSortedJetUp','diElectronsOSJetUp')
#addEleTauEventTree(process,'eleTauEventTreeJetDown','eleTausSortedJetDown','diElectronsOSJetDown')
#addEleTauEventTree(process,'eleTauEventTreeFinalJetUp','eleTausOSJetUp','diElectronsOSJetUp')
#addEleTauEventTree(process,'eleTauEventTreeFinalJetDown','eleTausOSJetDown','diElectronsOSJetDown')
#
#

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
