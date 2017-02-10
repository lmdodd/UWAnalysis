// system include files
#include <memory>

// user include files
#include "CommonTools/Utils/interface/StringObjectFunction.h"
#include "DataFormats/PatCandidates/interface/LookupTableRecord.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "Math/GenVector/VectorUtil.h" 
#include "TMath.h"

#include <TTree.h>

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"
#include "CommonTools/UtilAlgos/interface/StringCutObjectSelector.h"

//
// class decleration
//
template<typename T>
class VBFVariablesFiller : public NtupleFillerBase {
    public:
        VBFVariablesFiller(){
        }


        VBFVariablesFiller(const edm::ParameterSet& iConfig, TTree* t,edm::ConsumesCollector && iC):
            NtupleFillerBase(iConfig,t,iC),
            src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))),
            tag_(iConfig.getParameter<std::string>("tag")),
            cut_(iConfig.getParameter<std::string>("cut"))
    {

        njets=-999.;
        vbfmass=-999.;
        cut = new StringCutObjectSelector<pat::Jet>(cut_,true);
        branch1 = t->Branch(("njet_"+tag_).c_str(),&njets,("njet_"+tag_+"/I").c_str());
        branch2 = t->Branch(("vbfMass_"+tag_).c_str(),&vbfmass,("vbfMass_"+tag_+"/F").c_str());
    }


        ~VBFVariablesFiller()
        { 
            if(function!=0) delete function;
            if(cut!=0) delete cut;
        }


        void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
        {
            edm::Handle<std::vector<T> > handle;

            njets=-999;
            vbfmass=-999;

            //rank is 1 or 2
            int rnk1=-1;
            int rnk2=-1;
            unsigned int i=0;
            unsigned int j=0;
            //printf("Get Jets\n");
            pat::Jet firstJet;
            pat::Jet secondJet;

            if(iEvent.getByToken(src_,handle)) { //event exists
                if(handle->size()>0){//JEts exits 

                    njets=0;
                    for(unsigned int i=0;i<handle->at(0).jets().size();++i)
                        if((*cut)(*(handle->at(0).jets().at(i))))
                            njets++;



                    if(handle->at(0).jets().size()>1){//At least 2 jets

                        while (rnk1==-1 && handle->at(0).jets().size()>i){
                            if((*cut)(*(handle->at(0).jets().at(i)))) rnk1=i;
                            i++;
                        }
                        j=rnk1+1;
                        while (rnk2==-1&&handle->at(0).jets().size()>j){
                            if((*cut)(*(handle->at(0).jets().at(j)))) rnk2=j;
                            j++;
                        }


                        if (rnk1!=-1) firstJet= (*(handle->at(0).jets().at((int) rnk1)));
                        if (rnk2!=-1) secondJet = (*(handle->at(0).jets().at((int) rnk2)));

                    }//At least 2 jets 

                    vbfmass = (firstJet.p4()+secondJet.p4()).M();


                }//at least 1 JET Exists, jets defined 
                //compute variables


            }//events exist 
        }

    protected:
        edm::EDGetTokenT<std::vector<T>> src_;
        std::string tag_;
        std::string cut_;
        int njets;
        float vbfmass;
        StringObjectFunction<pat::Jet>*function;
        StringCutObjectSelector<pat::Jet>*cut;
        TBranch *branch1;
        TBranch *branch2;
        //std::vector<TBranch> myBranchesNjet;
        //std::vector<TBranch> myBranchesVBF;
        //std::vector< std::string > uncertNames;
};


#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"
typedef VBFVariablesFiller<PATMuTauPair> PATMuTauPairVBFVariablesFiller;
typedef VBFVariablesFiller<PATElecTauPair> PATEleTauPairVBFVariablesFiller;
typedef VBFVariablesFiller<PATDiTauPair> PATDiTauPairVBFVariablesFiller;





