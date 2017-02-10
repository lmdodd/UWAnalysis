#include "FWCore/Framework/interface/MakerMacros.h"
#include "UWAnalysis/NtupleTools/plugins/VBFVariables.h"
#include "Math/GenVector/VectorUtil.h" 

DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATMuTauPairVBFVariablesFiller, "PATMuTauPairVBFVariablesFiller");
DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATEleTauPairVBFVariablesFiller, "PATEleTauPairVBFVariablesFiller");
DEFINE_EDM_PLUGIN(NtupleFillerFactory, PATDiTauPairVBFVariablesFiller, "PATDiTauPairVBFVariablesFiller");


