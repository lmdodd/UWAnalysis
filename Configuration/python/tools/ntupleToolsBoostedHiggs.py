import FWCore.ParameterSet.Config as cms

from UWAnalysis.Configuration.tools.analysisToolsBoostedHiggsObject import TriggerPaths,TriggerRes,TriggerProcess



def makeCollSize(srcName,tagName):
    PSet = cms.PSet(
            pluginType = cms.string("CollectionSizeFiller"),
            src        = cms.InputTag(srcName),
            tag        = cms.string(tagName)
            )
    return PSet

def makeCollSizeVeto(srcName,size, tagName):
    PSet = cms.PSet(
            pluginType = cms.string("CollectionSizeVetoFiller"),
            src        = cms.InputTag(srcName),
            size       = cms.untracked.double(size),
            tag        = cms.string(tagName)
            )
    return PSet

def makeCollSizeOS(srcName,size, tagName):
    PSet = cms.PSet(
            pluginType = cms.string("OSCollectionSizeFiller"),
            src        = cms.InputTag(srcName),
            size       = cms.untracked.double(size),
            tag        = cms.string(tagName)
            )
    return PSet



def makeLTrackGeneric(plugin,sourceDiTaus,tagName,methodName):
    PSet = cms.PSet(
            pluginType  = cms.string(plugin),
            src         = cms.InputTag(sourceDiTaus),
            tag         = cms.string(tagName),
            method      = cms.string(methodName),
            )
    return PSet

def makeMuTrackPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
    PSet = cms.PSet(
            pluginType  = cms.string("PATMuTrackPairFiller"),
            src         = cms.InputTag(sourceDiTaus),
            tag         = cms.string(tagName),
            method      = cms.string(methodName),
            leadingOnly = cms.untracked.bool(leadingOnly)
            )
    return PSet

def makeMuTrackMET(sourceDiTaus, sourceMET, prefix):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTrackPairMETFiller"),
         src         = cms.InputTag(sourceDiTaus),
         met         = cms.InputTag(sourceMET),
         tag         = cms.string(prefix)
   )
   return PSet

def makeMuTrackPOGSF(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATMuTrackPairPOGSFsFiller"),
         src         = cms.InputTag(sourceDiTaus),
         isMu      = cms.bool(True)
   )
   return PSet

def makeMuTrackJetCountPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
    PSet = cms.PSet(
            pluginType  = cms.string("PATMuTrackPairJetCountFiller"),
            src         = cms.InputTag(sourceDiTaus),
            tag         = cms.string(tagName),
            method      = cms.string(methodName),
            leadingOnly = cms.untracked.bool(leadingOnly)
            )
    return PSet

def makeEleTrackPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
    PSet = cms.PSet(
            pluginType  = cms.string("PATEleTrackPairFiller"),
            src         = cms.InputTag(sourceDiTaus),
            tag         = cms.string(tagName),
            method      = cms.string(methodName),
            leadingOnly = cms.untracked.bool(leadingOnly)
            )
    return PSet

def makeEleTrackPOGSF(sourceDiTaus):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTrackPairPOGSFsFiller"),
         src         = cms.InputTag(sourceDiTaus),
         isMu      = cms.bool(False)
   )
   return PSet


def makeEleTrackJetCountPair(sourceDiTaus,tagName,methodName,leadingOnly=True):
    PSet = cms.PSet(
            pluginType  = cms.string("PATEleTrackPairJetCountFiller"),
            src         = cms.InputTag(sourceDiTaus),
            tag         = cms.string(tagName),
            method      = cms.string(methodName),
            leadingOnly = cms.untracked.bool(leadingOnly)
            )
    return PSet

def makeEleTrackMET(sourceDiTaus, sourceMET, prefix):
   PSet = cms.PSet(
         pluginType  = cms.string("PATEleTrackPairMETFiller"),
         src         = cms.InputTag(sourceDiTaus),
         met         = cms.InputTag(sourceMET),
         tag         = cms.string(prefix)
   )
   return PSet




def addMuTrackEventTree(process,name,src = 'muTracksSorted', srcLL = 'diMuonsOSSorted', srcU='TightMuons', srcE='TightElectrons'):
    process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
    eventTree = cms.EDAnalyzer('EventTreeMaker',
           genEvent = cms.InputTag('generator'),
           coreCollections = cms.InputTag(src),
           trigger = cms.PSet(
               pluginType = cms.string("TriggerFiller"),
               #src        = cms.InputTag("TriggerResults","","HLT"),
               src = cms.InputTag(TriggerRes,"",TriggerProcess),
               prescales = cms.InputTag("patTrigger"),
               paths      = cms.vstring(TriggerPaths)
               ),

           pu = cms.PSet(
               pluginType = cms.string("PUFiller"),
               src        = cms.InputTag("slimmedAddPileupInfo"),
               tag        = cms.string("pu")
               ),
           cov = cms.PSet(
               pluginType = cms.string("METSignificanceFiller"),
               src        = cms.InputTag("METSignificance"),
               tag        = cms.string("metcov")
               ),
           PVsSync = cms.PSet(
               pluginType = cms.string("VertexSizeFiller"),
               src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
               tag        = cms.string("npv")
               ),
           PVs = cms.PSet(
               pluginType = cms.string("VertexSizeFiller"),
               src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
               tag        = cms.string("vertices")
               ),
           muTrackPOG = makeMuTrackPOGSF(src),#FILLED

           muTrackSize = makeCollSize(src,"nCands"),
           muTrackOS = makeCollSizeOS(src,0,"os"),
           genTaus = makeCollSize("genTauCands","genTaus"), 
           muMuSize = makeCollSize(srcLL,"diLeptons"),#CHECKME
           muMuSizeVeto = makeCollSizeVeto(srcLL,0,"dilepton_veto"),#CHECKME

           muonsSizeMT = makeCollSize(srcU,"tightMuons"),
           muonsSizeMTVeto = makeCollSizeVeto(srcU,1,"extramuon_veto"),
           electronsSizeMT = makeCollSize(srcE,"tightElectrons"),
           electronsSizeMTVeto = makeCollSizeVeto(srcE,0,"extraelec_veto"),

           muTrackDR = makeMuTrackPair(src,"dR","dR12"), 

           muTrackCharge = makeMuTrackPair(src,"charge","charge"),
           q_1 = makeMuTrackPair(src,"q_1","leg1.charge"),
           q_2 = makeMuTrackPair(src,"q_2","leg2.charge"),
           muTrackPt = makeMuTrackPair(src,"pth","pt"),
           muTrackHT = makeMuTrackPair(src,"ht","ht"),
           muTrackMass = makeMuTrackPair(src,"m_vis","mass"),
           muTracklVeto = makeMuTrackPair(src,"lVeto","lVeto"),
           muTracklIso = makeMuTrackPair(src,"lIso","lIso"),

           muTrackFullPt = makeMuTrackPair(src,"fullPt","fullPt"),
           muTrackEta = makeMuTrackPair(src,"fullEta","fullEta"),
           muTrackPhi = makeMuTrackPair(src,"fullPhi","fullPhi"),
           muTrackE = makeMuTrackPair(src,"fullEnergy","fullEnergy"),

           muTrackPt1 =  makeMuTrackPair(src,"pt_1","leg1.pt"), 
           muTrackPt2 =  makeMuTrackPair(src,"pt_2","leg2.pt"), 
           muTrackEta1 = makeMuTrackPair(src,"eta_1","leg1.eta"),
           muTrackEta2 = makeMuTrackPair(src,"eta_2","leg2.eta"),
           muTrackPhi1 = makeMuTrackPair(src,"phi_1","leg1.phi"),
           muTrackPhi2 = makeMuTrackPair(src,"phi_2","leg2.phi"),

           muTrackMassLL = makeLTrackGeneric("PATMuPairFiller",srcLL,"LLmass","mass"),
           muTrackPt1LL =  makeLTrackGeneric("PATMuPairFiller",srcLL,"LLpt_1","leg1.pt"), 
           muTrackPt2LL =  makeLTrackGeneric("PATMuPairFiller",srcLL,"LLpt_2","leg2.pt"), 
           muTrackEta1LL = makeLTrackGeneric("PATMuPairFiller",srcLL,"LLeta_1","leg1.eta"),
           muTrackEta2LL = makeLTrackGeneric("PATMuPairFiller",srcLL,"LLeta_2","leg2.eta"),
           muTrackPhi1LL = makeLTrackGeneric("PATMuPairFiller",srcLL,"LLphi_1","leg1.phi"),
           muTrackPhi2LL = makeLTrackGeneric("PATMuPairFiller",srcLL,"LLphi_2","leg2.phi"),

           muTrackMET1 = makeMuTrackMET(src,"slimmedMETs","pf"),
           muTrackMET2 = makeMuTrackMET(src,"slimmedMETsPuppi","puppi"),

           muTrackMET = makeMuTrackPair(src,"met","met.pt()"),
           muTrackMETPhi = makeMuTrackPair(src,"metphi","met.phi()"),

           muTrackMT = makeMuTrackPair(src,"mt12","mt12MET"),
           muTrackMT1 = makeMuTrackPair(src,"mt_1","mt1MET"),
           muTrackMT2 = makeMuTrackPair(src,"mt_2","mt2MET"),

           muTrackMJJ = makeMuTrackPair(src,"mJJ","mJJ"),
           muTrackJJPt = makeMuTrackPair(src,"ptJJ","ptJJ"),
           muTrackJJEta = makeMuTrackPair(src,"etaJJ","etaJJ"),
           muTrackJJPhi = makeMuTrackPair(src,"phiJJ","phiJJ"),
           muTrackJJEnergy = makeMuTrackPair(src,"energyJJ","energyJJ"),
           muTrackVBFDEta = makeMuTrackPair(src,"jdeta","vbfDEta"),
           muTrackVBFMass = makeMuTrackPair(src,"mjj","vbfMass"),#vbfMass
           muTrackVBFJets20 = makeMuTrackPair(src,"njetigap20","vbfNJetsGap20"),
           muTrackVBFJets30 = makeMuTrackPair(src,"njetingap","vbfNJetsGap30"),

           #Muon IDs and Isolation
           muTrackRelPFIsoDB03 = makeMuTrackPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
           muTrackRelPFIsoDB04 = makeMuTrackPair(src,"iso04_1",'leg1.userFloat("dBRelIso")'),
           muTracksumCharged04 = makeMuTrackPair(src,"sumChargedHadronPt04_1",'leg1.pfIsolationR04().sumChargedHadronPt'),
           muTracksumNeutral04 = makeMuTrackPair(src,"sumNeutralHadronPt04_1",'leg1.pfIsolationR04().sumNeutralHadronEt'),
           muTracksumPhoton04 = makeMuTrackPair(src,"sumPhotonPt04_1",'leg1.pfIsolationR04().sumPhotonEt'),
           muTracksumPU04 = makeMuTrackPair(src,"sumPUPt04_1",'leg1.pfIsolationR04().sumPUPt'),

           muTracksumCharged03 = makeMuTrackPair(src,"sumChargedHadronPt03_1",'leg1.pfIsolationR03().sumChargedHadronPt'),
           muTracksumNeutral03 = makeMuTrackPair(src,"sumNeutralHadronPt03_1",'leg1.pfIsolationR03().sumNeutralHadronEt'),
           muTracksumPhoton03 = makeMuTrackPair(src,"sumPhotonPt03_1",'leg1.pfIsolationR03().sumPhotonEt'),
           muTracksumPU03 = makeMuTrackPair(src,"sumPUPt03_1",'leg1.pfIsolationR03().sumPUPt'),

           muTrackLooseID = makeMuTrackPair(src,"id_m_loose_1",'leg1.isLooseMuon()'),
           muTrackMediumID = makeMuTrackPair(src,"id_m_medium_1_INVALID",'leg1.isMediumMuon()'),
           muTrackUserMediumID = makeMuTrackPair(src,"id_m_medium_1",'leg1.userInt("mediumID")'),
           muTrackMuTriggerMatch = makeMuTrackPair(src,"lTrigger",'leg1.userFloat("hltL3crIsoL1sMu20L1f0L2f10QL3f22QL3trkIsoFiltered0p09")'),
           muTrackPzeta = makeMuTrackPair(src,"pZeta",'pZeta-1.5*pZetaVis'),
           muTrackPZ = makeMuTrackPair(src,"pZ",'pZeta'),
           muTrackPZV = makeMuTrackPair(src,"pzetavis",'pZetaVis'),
           muTrackHadMass = makeMuTrackPair(src,"m_2",'leg2.mass()'),

           muTrackMuDZ = makeMuTrackPair(src,"dZ_1","leg1.userFloat('dZ')"),
           muTrackTauDZ = makeMuTrackPair(src,"dZ_2","leg2.dz"),
           muTrackMuDXY = makeMuTrackPair(src,"d0_1","leg1.userFloat('dXY')"),
           muTrackTauDXY = makeMuTrackPair(src,"d0_2","leg2.dxy"),


           muTrackGenPt1 = makeMuTrackPair(src,"genPt1",'p4Leg1gen().pt()'),
           muTrackGenPt2 = makeMuTrackPair(src,"genPt2",'p4Leg2gen().pt()'),
           muTrackPdg1 = makeMuTrackPair(src,"pdg1",'genPdg1()'),
           muTrackPdg2 = makeMuTrackPair(src,"pdg2",'genPdg2()'),
           muTrackVisGenPt1 = makeMuTrackPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
           muTrackVisGenPt2 = makeMuTrackPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
           muTrackGenVisMass = makeMuTrackPair(src,"genVisMass",'p4VisGen().M()'),
           muTrackGenMassMatched = makeMuTrackPair(src,"genFullMassMatched",'p4gen().M()'),
           muTrackGenMass = makeMuTrackPair(src,"fullGenMass",'genBosonMass()'),
           muTrackGenBosonPt = makeMuTrackPair(src,"genpT",'p4GenBoson().pt()'),
           muTrackGenBosonMass = makeMuTrackPair(src,"genMass",'p4GenBoson().M()'),
           muTrackGenBosonPx = makeMuTrackPair(src,"genpX",'p4GenBoson().px()'),
           muTrackGenBosonPy = makeMuTrackPair(src,"genpY",'p4GenBoson().py()'),
           muTrackGenBosonVisPx = makeMuTrackPair(src,"vispX",'p4GenBosonVis().px()'),
           muTrackGenBosonVisPy = makeMuTrackPair(src,"vispY",'p4GenBosonVis().py()'),
           muTrackGenIsPrompt1 = makeMuTrackPair(src,"isPrompt1",'isPrompt1()'),
           muTrackGenIsPromptFS1 = makeMuTrackPair(src,"isPromptFS1",'isPromptFS1()'),
           muTrackGenIsDirectTauDecay1 = makeMuTrackPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
           muTrackGenIsDirectTauDecayFS1 = makeMuTrackPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),
           muTrackGenIsPrompt2 = makeMuTrackPair(src,"isPrompt2",'isPrompt2()'),
           muTrackGenIsPromptFS2 = makeMuTrackPair(src,"isPromptFS2",'isPromptFS2()'),
           muTrackGenIsDirectTauDecay2 = makeMuTrackPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
           muTrackGenIsDirectTauDecayFS2 = makeMuTrackPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),
           #Jets
           muTrackJetsPt20nbtag = makeMuTrackJetCountPair(src,"nbtag",'userFloat("isbtagged")&&pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
           muTrackJetsPt20nbtagLoose = makeMuTrackJetCountPair(src,"nbtagLooseNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.46'),
           muTrackJetsPt20nbtagNoSF = makeMuTrackJetCountPair(src,"nbtagNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
           muTrackJetsPt30nbtagNoSf = makeMuTrackJetCountPair(src,"nbtag30",'userFloat("isbtagged")&&pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
           muTrackJetsPt30nbtag = makeMuTrackJetCountPair(src,"nbtag30",'pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>.8'),
           muTrackJetsPt30njets = makeMuTrackJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
           muTrackJetsPt30njetsnopu = makeMuTrackJetCountPair(src,"njetspuID",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),
           muTrackJetsPt20njets = makeMuTrackJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),
           muTrackJetsPt20njetsnopu = makeMuTrackJetCountPair(src,"njetspt20puID",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),
           muTrackJetsPt20TagMatch = makeMuTrackJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
           muTrackJetsPt20TagNoMatch = makeMuTrackJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),
           mumuDR = makeLTrackGeneric("PATMuPairFiller",srcLL,"diLeptonDR","dR12"),#FIXME

           higgsPt = cms.PSet(
                   pluginType = cms.string("PATGenParticleFiller"),
                   src        = cms.InputTag("genDaughters"),
                   tag        = cms.string("higgsPt"),
                   method     = cms.string('pt()'),
                   leadingOnly=cms.untracked.bool(True)
                   ), 

           muTrackLHEProduct = cms.PSet(
                   pluginType = cms.string("LHEProductFiller"),
                   src        = cms.InputTag("externalLHEProducer"),
                   tag        = cms.string("LHEProduct"),
                   ),
           muTrackEmbedPtWeight = cms.PSet(
                   pluginType = cms.string("GenFilterInfoWeightFiller"),
                   src        = cms.InputTag("generator"),
                   #src        = cms.InputTag("generator","EmbWeight"),
                   tag        = cms.string("aMCNLO_weight"),
                   ),#FIXME #CHECKME
           muTrackEmbedPt = cms.PSet(
                   pluginType = cms.string("PATGenParticleFiller"),
                   src        = cms.InputTag("genDaughters"),
                   tag        = cms.string("embeddedPt"),#CHECKME
                   method     = cms.string("pt"),
                   leadingOnly=cms.untracked.bool(False)
                   ),#FIXME #CHECKME
           muTrackEmbedEta = cms.PSet(
                   pluginType = cms.string("PATGenParticleFiller"),
                   src        = cms.InputTag("genDaughters"),
                   tag        = cms.string("embeddedEta"),
                   method     = cms.string("eta"),
                   leadingOnly=cms.untracked.bool(False)
                   )#FIXME #CHECKME

           )

    setattr(process, name, eventTree)
    p = cms.Path(getattr(process,name))
    setattr(process, name+'Path', p)



#Tree for e+tau + MET final state
def addEleTrackEventTree(process,name,src='eleTracksSorted',srcLL='diElectronsOSSorted', srcU='TightMuons', srcE='TightElectrons'):
    process.TFileService = cms.Service("TFileService", fileName = cms.string("analysis.root") )
    eventTree = cms.EDAnalyzer('EventTreeMaker',
           genEvent = cms.InputTag('generator'),
           coreCollections = cms.InputTag(src),
           trigger = cms.PSet(
               pluginType = cms.string("TriggerFiller"),
               #src        = cms.InputTag("TriggerResults","","HLT"),
               src = cms.InputTag(TriggerRes,"",TriggerProcess),
               prescales = cms.InputTag("patTrigger"),
               paths      = cms.vstring(TriggerPaths)
               ),
           pu = cms.PSet(
               pluginType = cms.string("PUFiller"),
               src        = cms.InputTag("slimmedAddPileupInfo"),
               tag        = cms.string("pu")
               ),
           cov = cms.PSet(
               pluginType = cms.string("METSignificanceFiller"),
               src        = cms.InputTag("METSignificance"),
               tag        = cms.string("metcov")
               ),
           PVsSync = cms.PSet(
               pluginType = cms.string("VertexSizeFiller"),
               src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
               #src        = cms.InputTag("primaryVertexFilter"),
               tag        = cms.string("npv")
               ),
           PVs = cms.PSet(
               pluginType = cms.string("VertexSizeFiller"),
               src        = cms.InputTag("offlineSlimmedPrimaryVertices"),
               #src        = cms.InputTag("primaryVertexFilter"),
               tag        = cms.string("vertices")
               ),

           eTrackPOG = makeEleTrackPOGSF(src),#FILLED

           muonsSizeET = makeCollSize(srcU,"tightMuons"),
           muonsSizeETVeto = makeCollSizeVeto(srcU,0,"extramuon_veto"),
           electronsSizeET = makeCollSize(srcE,"tightElectrons"),
           electronsSizeETVeto = makeCollSizeVeto(srcE, 1,"extraelec_veto"),

           eleTrackSize = makeCollSize(src,"nCands"),
           eleTrackOS = makeCollSizeOS(src,0,"os"),
           eleEleSize = makeCollSize(srcLL,"diLeptons"),
           eleEleSizeVeto = makeCollSizeVeto(srcLL,0,"dilepton_veto"),
           genTaus = makeCollSize("genTauCands","genTaus"), #FIXME

           eleTrackDR = makeEleTrackPair(src,"dR","dR12"), 

           eleTrackCharge = makeEleTrackPair(src,"charge","charge"),
           eleTrackCharge1 = makeEleTrackPair(src,"q_1","leg1.charge"),
           eleTrackCharge2 = makeEleTrackPair(src,"q_2","leg2.charge"),

           eleTrackPt = makeEleTrackPair(src,"pth","pt"),
           eleTrackHT = makeEleTrackPair(src,"ht","ht"),
           eleTrackMass = makeEleTrackPair(src,"m_vis","mass"),
           eleTracklVeto = makeEleTrackPair(src,"lVeto","lVeto"),
           eleTracklIso = makeEleTrackPair(src,"lIso","lIso"),

           eleTrackFullPt = makeEleTrackPair(src,"fullPt","fullPt"),
           eleTrackEta = makeEleTrackPair(src,"fullEta","fullEta"),
           eleTrackPhi = makeEleTrackPair(src,"fullPhi","fullPhi"),
           eleTrackE = makeEleTrackPair(src,"fullEnergy","fullEnergy"),

           eleTrackPt1 =  makeEleTrackPair(src,"pt_1","leg1.pt"), 
           eleTrackPt2 =  makeEleTrackPair(src,"pt_2","leg2.pt"), 
           eleTrackEta1 = makeEleTrackPair(src,"eta_1","leg1.eta"),
           eleTrackSCEta1 = makeEleTrackPair(src,"SCeta_1","leg1.superCluster().eta()"),
           eleTrackEta2 = makeEleTrackPair(src,"eta_2","leg2.eta"),
           eleTrackPhi1 = makeEleTrackPair(src,"phi_1","leg1.phi"),
           eleTrackPhi2 = makeEleTrackPair(src,"phi_2","leg2.phi"),


           eleTrackMET1 = makeEleTrackMET(src,"slimmedMETs","pf"),
           eleTrackMET2 = makeEleTrackMET(src,"slimmedMETsPuppi","puppi"),
           #eleTrackMET3 = makeEleTrackMET(src,"MVAMET:MVAMET","mva"),

           eleTrackMET = makeEleTrackPair(src,"met","met.pt()"),
           eleTrackMETPhi = makeEleTrackPair(src,"metphi","met.phi()"),
           eleTrackMT = makeEleTrackPair(src,"mt12","mt12MET"),
           eleTrackMT1 = makeEleTrackPair(src,"mt_1","mt1MET"),
           eleTrackMT2 = makeEleTrackPair(src,"mt_2","mt2MET"),

                              #BTAGS AND JETS
                              eleTrackMJJReg = makeEleTrackPair(src,"mJJReg","mJJReg"),
                              eleTrackMJJ = makeEleTrackPair(src,"mJJ","mJJ"),
                              eleTrackJJPt = makeEleTrackPair(src,"ptJJ","ptJJ"),
                              eleTrackJJEta = makeEleTrackPair(src,"etaJJ","etaJJ"),
                              eleTrackJJPhi = makeEleTrackPair(src,"phiJJ","phiJJ"),
                              eleTrackJJEnergy = makeEleTrackPair(src,"energyJJ","energyJJ"),
                              eleTrackVBFDEta = makeEleTrackPair(src,"vbfDEta","vbfDEta"),
                              eleTrackVBFDPhi = makeEleTrackPair(src,"vbfDPhi","vbfDPhi"),
                              eleTrackVBFMass = makeEleTrackPair(src,"mjj","vbfMass"), #vbfMass
                              eleTrackVBFJets20 = makeEleTrackPair(src,"njetingap20","vbfNJetsGap20"),
                              eleTrackVBFJets30 = makeEleTrackPair(src,"njetingap","vbfNJetsGap30"),

                              #eleTrackDZVZ = makeEleTrackPair(src,"dz_vz",'abs(leg1.vz-leg2.vz)'),
                              eleTrackDPhi = makeEleTrackPair(src,"dPhi12",'dPhi12'),
                              eleTrackDPhi1MET = makeEleTrackPair(src,"dPhi1MET",'dPhi1MET'),
                              eleTrackDPhi2MET = makeEleTrackPair(src,"dPhi2MET",'dPhi2MET'),
                              eleTrackPzeta = makeEleTrackPair(src,"pZeta",'pZeta-1.5*pZetaVis'),#EO 
                              eleTrackPZ = makeEleTrackPair(src,"pzeta",'pZeta'),#EO
                              eleTrackPZV = makeEleTrackPair(src,"pzetavis",'pZetaVis'),#EO

                  #Trigger
                              eleTrackEleTriggerMatch2016_25 = makeEleTrackPair(src,"lTrigger25",'leg1.userFloat("hltEle25erWPTightGsfTrackIsoFilter")'),
                              eleTrackEleTriggerMatch2016_27 = makeEleTrackPair(src,"lTrigger27",'leg1.userFloat("hltEle27erWPLooseGsfTrackIsoFilter")'),

                              #Ele IDs and Isolation
                              eleTrackRelPFIsoDB03 = makeEleTrackPair(src,"iso_1",'leg1.userFloat("dBRelIso03")'),
                              eleTrackRelPFIsoDB04 = makeEleTrackPair(src,"iso04_1",'leg1.userFloat("dBRelIso")'),
                              eleTrackEleIsoChHadIso = makeEleTrackPair(src,"eleIsoChHadIso",'leg1.userFloat("eleIsoChHadIso")'),
                              eleTrackEleIsoPUChHadIso = makeEleTrackPair(src,"eleIsoPUChHadIso",'leg1.userFloat("eleIsoPUChHadIso")'),
                              eleTrackEleIsoPhotonIso = makeEleTrackPair(src,"eleIsoPhotonIso",'leg1.userFloat("eleIsoPhotonIso")'),
                              eleTrackEleIsoNeuHadIso = makeEleTrackPair(src,"eleIsoNeuHadIso",'leg1.userFloat("eleIsoNeuHadIso")'),
                              eleTrackEleIsoSumChHadPt = makeEleTrackPair(src,"eleIsoSumChHadPt",'leg1.userFloat("eleIsoSumChHadPt")'),
                              eleTrackEleIsoSumNeuHadPt = makeEleTrackPair(src,"eleIsoSumNeuHadPt",'leg1.userFloat("eleIsoSumNeuHadPt")'),
                              eleTrackEleIsoSumPhoEt = makeEleTrackPair(src,"eleIsoSumPhoEt",'leg1.userFloat("eleIsoSumPhoEt")'),
                              eleTrackEleIsoSumPUPt = makeEleTrackPair(src,"eleIsoSumPUPt",'leg1.userFloat("eleIsoSumPUPt")'),

                              eleTrackHadMass = makeEleTrackPair(src,"m_2",'leg2.mass()'),
                              eleTrackHaddxy = makeEleTrackPair(src,"dxy_2",'leg2.dxy()'),
                              eleTrackHaddz = makeEleTrackPair(src,"dxy_2",'leg2.dz()'),

                              eleTrackMVANonTrig80 = makeEleTrackPair(src,"id_e_mva_nt_80_1",'leg1.userFloat("eleMVAIDnonTrig80")'),#CHECKME #rename
                              eleTrackMVANonTrig90 = makeEleTrackPair(src,"id_e_mva_nt_90_1",'leg1.userFloat("eleMVAIDnonTrig90")'),#CHECKME #rename
                              eleTrackCBIDVeto = makeEleTrackPair(src,"id_e_cut_veto_1",'leg1.userFloat("CBIDVeto")'),#CHECKME #rename
                              eleTrackCBIDLoose = makeEleTrackPair(src,"id_e_cut_loose_1",'leg1.userFloat("CBIDLoose")'),#CHECKME #rename
                              eleTrackCBIDMedium = makeEleTrackPair(src,"id_e_cut_medium_1",'leg1.userFloat("CBIDMedium")'),#CHECKME #rename
                              eleTrackCBIDTight = makeEleTrackPair(src,"id_e_cut_tight_1",'leg1.userFloat("CBIDTight")'),#CHECKME #rename


                              eleTrackEleDZ = makeEleTrackPair(src,"dZ_1","leg1.userFloat('dZ')"),
                              #eleTrackTauDZ = makeEleTrackPair(src,"dZ_2","leg2.userFloat('taudZ')"),
                              eleTrackEleDXY = makeEleTrackPair(src,"d0_1","leg1.userFloat('dXY')"),
                              #eleTrackTauDXY = makeEleTrackPair(src,"d0_2","leg2.userFloat('taudXY')"),
                              eleTrackConversion = makeEleTrackPair(src,"eleConversion","leg1.userInt('eleConversion')"),
                              eleTrackPassConversion = makeEleTrackPair(src,"ePassConversion",'leg1.passConversionVeto()'),

                              eleTrackGenPt1 = makeEleTrackPair(src,"genPt1",'p4Leg1gen().pt()'),
                              eleTrackGenPt2 = makeEleTrackPair(src,"genPt2",'p4Leg2gen().pt()'),
                              eleTrackPdg1 = makeEleTrackPair(src,"pdg1",'genPdg1()'),
                              eleTrackPdg2 = makeEleTrackPair(src,"pdg2",'genPdg2()'),
                              eleTrackVisGenPt1 = makeEleTrackPair(src,"genVisPt1",'p4VisLeg1gen().pt()'),
                              eleTrackVisGenPt2 = makeEleTrackPair(src,"genVisPt2",'p4VisLeg2gen().pt()'),
                              eleTrackGenVisMass = makeEleTrackPair(src,"genVisMass",'p4VisGen().M()'),
                              eleTrackGenMassMatched = makeEleTrackPair(src,"genFullMassMatched",'p4gen().M()'),
                              eleTrackGenBosonMass = makeEleTrackPair(src,"genMass",'p4GenBoson().M()'),
                              eleTrackGenBosonPt = makeEleTrackPair(src,"genpT",'p4GenBoson().pt()'),
                              eleTrackGenBosonPx = makeEleTrackPair(src,"genpX",'p4GenBoson().px()'),
                              eleTrackGenBosonPy = makeEleTrackPair(src,"genpY",'p4GenBoson().py()'),
                              eleTrackGenBosonVisPx = makeEleTrackPair(src,"vispX",'p4GenBosonVis().px()'),
                              eleTrackGenBosonVisPy = makeEleTrackPair(src,"vispY",'p4GenBosonVis().py()'),
                              eleTrackGenMass = makeEleTrackPair(src,"fullGenMass",'genBosonMass()'),

                              eleTrackGenIsPrompt1 = makeEleTrackPair(src,"isPrompt1",'isPrompt1()'),
                              eleTrackGenIsPromptFS1 = makeEleTrackPair(src,"isPromptFS1",'isPromptFS1()'),
                              eleTrackGenIsDirectTauDecay1 = makeEleTrackPair(src,"isTauDecay1",'isDirectPromptTauDecayProduct1()'),
                              eleTrackGenIsDirectTauDecayFS1 = makeEleTrackPair(src,"isTauDecayFS1",'isDirectPromptTauDecayProductFS1()'),
                              eleTrackGenIsPrompt2 = makeEleTrackPair(src,"isPrompt2",'isPrompt2()'),
                              eleTrackGenIsPromptFS2 = makeEleTrackPair(src,"isPromptFS2",'isPromptFS2()'),
                              eleTrackGenIsDirectTauDecay2 = makeEleTrackPair(src,"isTauDecay2",'isDirectPromptTauDecayProduct2()'),
                              eleTrackGenIsDirectTauDecayFS2 = makeEleTrackPair(src,"isTauDecayFS2",'isDirectPromptTauDecayProductFS2()'),



                  #Jets
                              eleTrackJetsPt20nbtag = makeEleTrackJetCountPair(src,"nbtag",'userFloat("isbtagged")&&pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTrackJetsPt20nbtagNoSF = makeEleTrackJetCountPair(src,"nbtagNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTrackJetsPt20nbtagLoose = makeEleTrackJetCountPair(src,"nbtagLooseNoSF",'pt()>20&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.46'),
                              eleTrackJetsPt30nbtagNoSF = makeEleTrackJetCountPair(src,"nbtag30NoSF",'pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTrackJetsPt30nbtag = makeEleTrackJetCountPair(src,"nbtag30",'userFloat("isbtagged")&&pt()>30&&abs(eta)<2.4&&userFloat("idLoose")&&bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")>0.8'),
                              eleTrackJetsPt30njets = makeEleTrackJetCountPair(src,"njets",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")'),
                              eleTrackJetsPt30njetsLoosepu = makeEleTrackJetCountPair(src,"njetspuID",'pt()>30&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),
                              eleTrackJetsPt20njets = makeEleTrackJetCountPair(src,"njetspt20",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")'),
                              eleTrackJetsPt20njetsLoosepu = makeEleTrackJetCountPair(src,"njetspt20puID",'pt()>20&&abs(eta)<4.7&&userFloat("idLoose")&&!userFloat("puIDLoose")'),

                              eleTrackJetsPt20TagMatch = makeEleTrackJetCountPair(src,"nTaggableJetsPt20Matched",'pt()>20&&abs(eta)<2.4&&abs(partonFlavour)==5'),
                              eleTrackJetsPt20TagNoMatch = makeEleTrackJetCountPair(src,"nTaggableJetsPt20NotMatched",'pt()>30&&abs(eta)<2.4&&abs(partonFlavour)!=5'),

                              eeDR = makeLTrackGeneric("PATElePairFiller",srcLL,"diLeptonDR","dR12"),#FIXME

                              eleTrackMassLL =  makeLTrackGeneric("PATElePairFiller",srcLL,"LLmass","mass"), 
                              eleTrackPt1LL =  makeLTrackGeneric("PATElePairFiller",srcLL,"LLpt_1","leg1.pt()"), 
                              eleTrackPt2LL =  makeLTrackGeneric("PATElePairFiller",srcLL,"LLpt_2","leg2.pt()"), 
                              eleTrackEta1LL = makeLTrackGeneric("PATElePairFiller",srcLL,"LLeta_1","leg1.eta()"),
                              eleTrackEta2LL = makeLTrackGeneric("PATElePairFiller",srcLL,"LLeta_2","leg2.eta()"),
                              eleTrackPhi1LL = makeLTrackGeneric("PATElePairFiller",srcLL,"LLphi_1","leg1.phi()"),
                              eleTrackPhi2LL = makeLTrackGeneric("PATElePairFiller",srcLL,"LLphi_2","leg2.phi()"),



                              eleTrackLHEProduct2 = cms.PSet(
                                      pluginType = cms.string("LHEProductFiller"),
                                      src        = cms.InputTag("externalLHEProducer"),
                                      tag        = cms.string("LHEProduct"),
                                      ),
                              eleTrackEmbedPtWeight = cms.PSet(
                                      pluginType = cms.string("GenFilterInfoWeightFiller"),
                                      src        = cms.InputTag("generator"),
                                      tag        = cms.string("aMCNLO_weight"),
                                      ),
                              higgsPt = cms.PSet(
                                      pluginType = cms.string("PATGenParticleFiller"),
                                      src        = cms.InputTag("genDaughters"),
                                      tag        = cms.string("higgsPt"),
                                      method     = cms.string('pt()'),
                                      leadingOnly=cms.untracked.bool(True)
                                      ),
                              eleTrackEmbedPt = cms.PSet(
                                      pluginType = cms.string("PATGenParticleFiller"),
                                      src        = cms.InputTag("genDaughters"),
                                      tag        = cms.string("embeddedPt"),#CHECKME
                                      method     = cms.string("pt"),
                                      leadingOnly=cms.untracked.bool(False)
                                      ),
                              eleTrackEmbedEta = cms.PSet(
                                      pluginType = cms.string("PATGenParticleFiller"),
                                      src        = cms.InputTag("genDaughters"),
                                      tag        = cms.string("embeddedEta"),#CHECKME
                                      method     = cms.string("eta"),
                                      leadingOnly=cms.untracked.bool(False)
                                      )
                              )

    setattr(process, name, eventTree)
    p = cms.Path(getattr(process,name))
    setattr(process, name+'Path', p)


