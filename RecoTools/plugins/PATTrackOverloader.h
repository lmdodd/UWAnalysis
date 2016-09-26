// -*- C++ -*-
//
//

// system include files
#include <memory>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"

#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "Math/GenVector/VectorUtil.h"
//
// class declaration
#include <boost/foreach.hpp>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/angle.h"


class PATTrackOverloader : public edm::EDProducer {
   public:
  
  

  explicit PATTrackOverloader(const edm::ParameterSet& iConfig):
  src_(consumes<pat::PackedCandidateCollection>(iConfig.getParameter<edm::InputTag>("src"))),
  taus_(consumes<pat::TauCollection>(iConfig.getParameter<edm::InputTag>("src"))),
  muons_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
  vtxSrc_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vtxSrc"))),
  threshold_(iConfig.getParameter<double>("threshold"))
  {
    produces<pat::PackedCandidateCollection>();

  }
  
  ~PATTrackOverloader() {}
   private:


  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
  {
    using namespace edm;
    using namespace reco;
    std::auto_ptr<pat::PackedCandidateCollection> out(new pat::PackedCandidateCollection);


    Handle<pat::TauCollection > taus;
    iEvent.getByToken(taus_, taus);
    Handle<pat::MuonCollection > muons;
    iEvent.getByToken(muons_, muons);

    edm::Handle<reco::VertexCollection> vertices;
    iEvent.getByToken(vtxSrc_, vertices);
    reco::Vertex primary;
    //const reco::Vertex& thePV = *vertices->begin();
    //
    Handle<pat::PackedCandidateCollection > tracks;
    if(iEvent.getByToken(src_,tracks))       {

        for(unsigned int i=0;i<tracks->size();++i) {
            pat::PackedCandidate trk = tracks->at(i);
            if (abs(trk.pdgId())!=211) continue;
            if (trk.pt()>threshold_)
                out->push_back(trk);
        }

    }


    iEvent.put(out);


  } 

  // ----------member data ---------------------------
  edm::EDGetTokenT<pat::PackedCandidateCollection> src_;
  edm::EDGetTokenT<pat::TauCollection> taus_;
  edm::EDGetTokenT<pat::MuonCollection> muons_;
  edm::EDGetTokenT<reco::VertexCollection> vtxSrc_;
  double threshold_;


};

