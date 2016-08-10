import FWCore.ParameterSet.Config as cms


#Import tool that creates the cut sequence
from UWAnalysis.Configuration.tools.CutSequenceProducer import *

###############################			Ele-Track 		###################################
ETanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsET',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#make pat overloaded tracks collection
ETanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','patOverloadedTracks','ET')

#create dielectrons
ETanalysisConfigurator.addDiCandidateModule('diElectrons','PATElePairProducer','smearedElectronsET','smearedElectronsET','slimmedMETs','','smearedJetsET',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "",genParticles='prunedGenParticles')
ETanalysisConfigurator.addSelector('diElectronsOS','PATElePairSelector','abs(leg1.eta())<2.5&&abs(leg2.eta())<2.5&&abs(leg1.userFloat("dXY"))<0.045&&abs(leg2.userFloat("dXY"))<0.045&&abs(leg1.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dZ"))<0.2&&leg1.pt()>15&&leg2.pt()>15&&charge==0&&leg2.userFloat("CBIDVeto")>0&&leg1.userFloat("CBIDVeto")>0&&leg1.userFloat("dBRelIso03")<0.3&&leg2.userFloat("dBRelIso03")<0.3','DiElectronCreation',0,100)
ETanalysisConfigurator.addSorter('diElectronsOSSorted','PATElePairSorter')
#Make DiTaus
ETanalysisConfigurator.addDiCandidateModule('eleTracks','PATEleTrackPairProducer','smearedElectronsET','smearedTracksET','smearedMETET','smearedTausET','smearedJetsET',1,9999,text = 'AtLeastOneEleTrack',leadingObjectsOnly = False,dR = 0.3,recoMode = "",genParticles='prunedGenParticles',drmax=True)

ETanalysisConfigurator.addSelector('eleTracksElePtEta','PATEleTrackPairSelector','leg1.pt()>25&&abs(leg1.eta())<1.47','ETelectronPtEta',1)
ETanalysisConfigurator.addSelector('eleTracksTrackPtEta','PATEleTrackPairSelector','leg2.pt()>50&&abs(leg2.eta())<1.47','ETTrackPtEta',1)
ETanalysisConfigurator.addSelector('eleTracksEleID','PATEleTrackPairSelector','leg1.userFloat("eleMVAIDnonTrig90")>0','ElectronID',1)
#check conversions
ETanalysisConfigurator.addSelector('eleTracksEleConvRej','PATEleTrackPairSelector','leg1.userInt("eleConversion")==0','ETelectronConvRej',1)
ETanalysisConfigurator.addSelector('eleTracksEleVertices','PATEleTrackPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','ETelectronVertices',1)
ETanalysisConfigurator.addSelector('eleTracksChargeNot2','PATEleTrackPairSelector','abs(leg2.charge())==1','ETChargeIsABS1',1)
ETanalysisConfigurator.addEleTrackLVeto('eleTracksLVeto','TightElectrons','TightMuons')
ETanalysisConfigurator.addEleTrackLeptonIso('eleTracksLIso')
ETanalysisConfigurator.addSelector('eleTracksEleVeto','PATEleTrackPairSelector','lVeto==0','ETelectronVeto',1)
ETanalysisConfigurator.addSorter('eleTracksSorted','PATEleTrackPairSorter')
#make sure muon is not track
#ETanalysisConfigurator.addSelector('eleTracksEleIsolation','PATEleTrackPairSelector','leg1.userFloat("dBRelIso03")<0.5','ETelectronIsolation',1)
ETanalysisConfigurator.addSelector('eleTracksOS','PATEleTrackPairSelector','charge==0','ETOS',1)

#create the sequence
selectionSequenceET =ETanalysisConfigurator.returnSequence()

################################		Mu-Tau			###################################

MTanalysisConfigurator = CutSequenceProducer(initialCounter  = 'initialEventsMT',
                                  pyModuleName = __name__,
                                  pyNameSpace  = locals())

#Add smearing
MTanalysisConfigurator.addSmearing('patOverloadedTaus','triggeredPatMuons','triggeredPatElectrons','filteredJets','slimmedMETs','patOverloadedTracks','MT')
#Create di muon pairs for veto purposes
MTanalysisConfigurator.addDiCandidateModule('diMuons','PATMuPairProducer','smearedMuonsMT','smearedMuonsMT','slimmedMETs','','smearedJetsMT',0,9999,text = '',leadingObjectsOnly = False,dR = 0.15,recoMode = "",genParticles='prunedGenParticles')
MTanalysisConfigurator.addSelector('diMuonsOS','PATMuPairSelector','leg1.isPFMuon&&leg2.isPFMuon&&abs(leg1.eta())<2.4&&abs(leg2.eta())<2.4&&abs(leg1.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dZ"))<0.2&&abs(leg2.userFloat("dXY"))<0.045&&abs(leg2.userFloat("dXY"))<0.045&&charge==0&&leg1.isTrackerMuon&&leg2.isTrackerMuon&&leg1.isGlobalMuon&&leg2.isGlobalMuon&&leg1.pt()>15&&leg2.pt()>15&&leg1.userFloat("dBRelIso")<0.3 &&leg2.userFloat("dBRelIso")<0.3','DiMuonCreation',0,100)
MTanalysisConfigurator.addSorter('diMuonsOSSorted','PATMuPairSorter')

#Make DiTaus   
MTanalysisConfigurator.addDiCandidateModule('muTracks','PATMuTrackPairProducer','smearedMuonsMT','smearedTracksMT','smearedMETMT','smearedTausMT','smearedJetsMT',1,9999,text='AtLeastOneMuTrack',leadingObjectsOnly = False,dR = 0.3,recoMode ="",genParticles='prunedGenParticles',drmax=True)
MTanalysisConfigurator.addSelector('muTracksMuonPtEta','PATMuTrackPairSelector','leg1.pt()>22&&abs(leg1.eta())<1.47','MTMuonPtEta',1)
MTanalysisConfigurator.addSelector('muTracksTrackPtEta','PATMuTrackPairSelector','leg2.pt()>50&&abs(leg2.eta())<1.47','MTTrackPtEta',1)
MTanalysisConfigurator.addSelector('muTracksMuonMediumID','PATMuTrackPairSelector','leg1.userInt("mediumID")>0','MTMuonMediumID',1)
#MTanalysisConfigurator.addSelector('muTracksMuonMediumID','PATMuTrackPairSelector','leg1.isMediumMuon()','MTMuonMediumID',1)
MTanalysisConfigurator.addSelector('muTracksMuonVertices','PATMuTrackPairSelector','abs(leg1.userFloat("dZ"))<0.2&&abs(leg1.userFloat("dXY"))<0.045','MTMuonVertices',1)
MTanalysisConfigurator.addMuTrackLVeto('muTracksLVeto','TightElectrons','TightMuons')
MTanalysisConfigurator.addMuTrackLeptonIso('muTracksLIso')
MTanalysisConfigurator.addSelector('muTracksMuonVeto','PATMuTrackPairSelector','lVeto==0','MTMuonVeto',1)
MTanalysisConfigurator.addSorter('muTracksSorted','PATMuTrackPairSorter')
MTanalysisConfigurator.addSelector('muTracksOS','PATMuTrackPairSelector','charge==0','MTOS',1)


#create the sequence
selectionSequenceMT =MTanalysisConfigurator.returnSequence()
