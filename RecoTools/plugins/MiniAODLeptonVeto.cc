#include "UWAnalysis/RecoTools/plugins/MiniAODLeptonVeto.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"



typedef MiniAODLeptonVeto<pat::Muon, pat::Tau> PATMuTauLVeto;
typedef MiniAODLeptonVeto<pat::Electron, pat::Tau> PATElecTauLVeto;
typedef MiniAODLeptonVeto<pat::Electron, pat::PackedCandidate> PATEleTrackLVeto;
typedef MiniAODLeptonVeto<pat::Muon, pat::PackedCandidate> PATMuTrackLVeto;



DEFINE_FWK_MODULE(PATMuTauLVeto);
DEFINE_FWK_MODULE(PATElecTauLVeto);
DEFINE_FWK_MODULE(PATEleTrackLVeto);
DEFINE_FWK_MODULE(PATMuTrackLVeto);

