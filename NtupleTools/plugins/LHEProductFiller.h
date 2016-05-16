// system include files
#include <memory>
#include "TLorentzVector.h"
// user include files
#include <TTree.h>
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"

//
// class decleration
//

class LHEProductFiller : public NtupleFillerBase {
	public:
		LHEProductFiller(){
		}


		LHEProductFiller(const edm::ParameterSet& iConfig, TTree* t,edm::ConsumesCollector && iC):
			src_(iC.consumes<LHEEventProduct>(iConfig.getParameter<edm::InputTag> ("src"))),
			tag_(iConfig.getParameter<std::string>("tag"))
	{
		value1 = 0;
		value2 = 0;
		t->Branch((tag_+"_njet").c_str(),&value1,(tag_+"_njet/I").c_str());
		t->Branch((tag_+"_mll").c_str(),&value2,(tag_+"_mll/I").c_str());
	}


		~LHEProductFiller()
		{

		}


		void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
		{
			edm::Handle<LHEEventProduct> lheeventinfo;
			value1=0;
			value2=0;
			int NParton=0;
			int NL=0;
			TLorentzVector l;
			if(iEvent.getByToken(src_,lheeventinfo)) {
				int nup = lheeventinfo->hepeup().NUP;
				for (int i = 0; i < nup ; ++i) {
					if (lheeventinfo->hepeup().ISTUP[i] == 1 && (abs(lheeventinfo->hepeup().IDUP[i])<6||lheeventinfo->hepeup().IDUP[i]==21 )) {
						++NParton;	
					}
					if (lheeventinfo->hepeup().ISTUP[i] == 1 && (abs(lheeventinfo->hepeup().IDUP[i])==11||abs(lheeventinfo->hepeup().IDUP[i])==13||abs(lheeventinfo->hepeup().IDUP[i])==15 )) {
						l += TLorentzVector(lheeventinfo->hepeup().PUP[i].x[0], lheeventinfo->hepeup().PUP[i].x[1], lheeventinfo->hepeup().PUP[i].x[2], lheeventinfo->hepeup().PUP[i].x[3]);	   
						++NL;
					}

				}
			}
			

			value1 = NParton;
			if (NL==2) value2 = l.M();
			
		}


	protected:
		edm::EDGetTokenT<LHEEventProduct> src_;
		std::string tag_;
		int value1;
		int value2;


};







