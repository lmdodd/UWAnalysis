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
class VBFVariableFiller : public NtupleFillerBase {
    public:
        VBFVariableFiller(){
        }


        VBFVariableFiller(const edm::ParameterSet& iConfig, TTree* t,edm::ConsumesCollector && iC):
            NtupleFillerBase(iConfig,t,iC),
            src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src")))
    {
        uncertNames={"AbsoluteFlavMap", "AbsoluteMPFBias", "AbsoluteScale", "AbsoluteStat", "FlavorQCD", "Fragmentation", "PileUpDataMC", "PileUpPtBB", "PileUpPtEC1", "PileUpPtEC2", "PileUpPtHF", "PileUpPtRef", "RelativeBal", "RelativeFSR", "RelativeJEREC1", "RelativeJEREC2", "RelativeJERHF", "RelativePtBB", "RelativePtEC1", "RelativePtEC2", "RelativePtHF", "RelativeStatEC", "RelativeStatFSR", "RelativeStatHF", "SinglePionECAL", "SinglePionHCAL", "SubTotalAbsolute", "SubTotalMC", "SubTotalPileUp", "SubTotalPt", "SubTotalRelative", "SubTotalScale", "TimePtEta", "Total", "Closure"};
        shiftedPt= { 
            "jesAbsoluteFlavMap+",
            "jesAbsoluteFlavMap-",
            "jesAbsoluteMPFBias+",
            "jesAbsoluteMPFBias-",
            "jesAbsoluteScale+",
            "jesAbsoluteScale-",
            "jesAbsoluteStat+",
            "jesAbsoluteStat-",
            "jesFlavorQCD+",
            "jesFlavorQCD-",
            "jesFragmentation+",
            "jesFragmentation-",
            "jesPileUpDataMC+",
            "jesPileUpDataMC-",
            "jesPileUpPtBB+",
            "jesPileUpPtBB-",
            "jesPileUpPtEC1+",
            "jesPileUpPtEC1-",
            "jesPileUpPtEC2+",
            "jesPileUpPtEC2-",
            "jesPileUpPtHF+",
            "jesPileUpPtHF-",
            "jesPileUpPtRef+",
            "jesPileUpPtRef-",
            "jesRelativeBal+",
            "jesRelativeBal-",
            "jesRelativeFSR+",
            "jesRelativeFSR-",
            "jesRelativeJEREC1+",
            "jesRelativeJEREC1-",
            "jesRelativeJEREC2+",
            "jesRelativeJEREC2-",
            "jesRelativeJERHF+",
            "jesRelativeJERHF-",
            "jesRelativePtBB+",
            "jesRelativePtBB-",
            "jesRelativePtEC1+",
            "jesRelativePtEC1-",
            "jesRelativePtEC2+",
            "jesRelativePtEC2-",
            "jesRelativePtHF+",
            "jesRelativePtHF-",
            "jesRelativeStatEC+",
            "jesRelativeStatEC-",
            "jesRelativeStatFSR+",
            "jesRelativeStatFSR-",
            "jesRelativeStatHF+",
            "jesRelativeStatHF-",
            "jesSinglePionECAL+",
            "jesSinglePionECAL-",
            "jesSinglePionHCAL+",
            "jesSinglePionHCAL-",
            "jesSubTotalAbsolute+",
            "jesSubTotalAbsolute-",
            "jesSubTotalMC+",
            "jesSubTotalMC-",
            "jesSubTotalPileUp+",
            "jesSubTotalPileUp-",
            "jesSubTotalPt+",
            "jesSubTotalPt-",
            "jesSubTotalRelative+",
            "jesSubTotalRelative-",
            "jesSubTotalScale+",
            "jesSubTotalScale-",
            "jesTimePtEta+",
            "jesTimePtEta-",
            "jesTotal+",
            "jesTotal-",
            "jesClosure+",
            "jesClosure-",
        };

        for(unsigned int i=0; i<uncertNames.size(); i++){
            njetVecUp.push_back(-999);
            njetVecDown.push_back(-999);
            vbfVecUp.push_back(-999);
            vbfVecDown.push_back(-999);
            TBranch *tempNJUp = t->Branch(("njet_"+uncertNames[i]+"Up").c_str(),&njetVecUp[i],("njet_"+uncertNames[i]+"Up/I").c_str());
            TBranch *tempNJDown = t->Branch(("njet_"+uncertNames[i]+"Down").c_str(),&njetVecDown[i],("njet_"+uncertNames[i]+"Down/I").c_str());
            TBranch *tempMUp = t->Branch(("vbfMass_"+uncertNames[i]+"Up").c_str(),&vbfVecUp[i],("vbfMass_"+uncertNames[i]+"Up/F").c_str());
            TBranch *tempMDown = t->Branch(("vbfMass_"+uncertNames[i]+"Down").c_str(),&vbfVecDown[i],("vbfMass_"+uncertNames[i]+"Down/F").c_str());
            myBranches.push_back(tempNJUp);
            myBranches.push_back(tempNJDown);
            myBranches.push_back(tempMUp);
            myBranches.push_back(tempMDown);
        }

    }


        ~VBFVariableFiller()
        { 
            //if(function!=0) delete function;
            //if(cut!=0) delete cut;
        }


        void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
        {
            edm::Handle<std::vector<T> > handle;
            //printf("Get Jets\n");
            if(iEvent.getByToken(src_,handle) && !iEvent.isRealData()) { //event exists
                if(handle->size()>0){//JEts exits 

                    for ( unsigned int c=0;c<shiftedPt.size();c++){
                        //StringCutObjectSelector<pat::Jet> cut(cuts[c],true); 
                        pat::Jet firstJet;
                        pat::Jet secondJet;
                        vbfmass=-999;


                        njets=0;
                        for(unsigned int i=0;i<handle->at(0).jets().size();++i){
                            //if( cut(*(handle->at(0).jets().at(i)))){
                            //id Loose and eta jets already cleaned
                            if( handle->at(0).jets().at(i)->userCand(shiftedPt[c])->pt()>30 )  {
                                njets++;
                            }
                        }//end njet loop


                        if (njets>1){
                            if(  handle->at(0).jets().at(0)->userCand(shiftedPt[c])->pt()>20  &&  handle->at(0).jets().at(1)->userCand(shiftedPt[c])->pt()>20) {
                                firstJet= (*(handle->at(0).jets().at(0)));
                                secondJet= (*(handle->at(0).jets().at(1)));   
                                vbfmass = (firstJet.userCand(shiftedPt[c])->p4()+secondJet.userCand(shiftedPt[c])->p4()).M();
                            }
                        }

                        int type = c % 2; // 0 is njet(vbf)Up, 1 is njet(vbf)Down
                        //std::cout<<"njets: "<<njets<<std::endl;
                        //std::cout<<"vbfmass: "<<vbfmass<<std::endl;
                        if (type==0){
                            njetVecUp[c/2]=njets;
                            vbfVecUp[c/2]=vbfmass;
                        }
                        else {
                            njetVecDown[c/2]=njets;
                            vbfVecDown[c/2]=vbfmass;
                        }

                        }//end cut [i]
                    }//at least 1 JET Exists, jets defined 
                    //compute variables

                }//events exist 

                /*std::cout<<"mybranches size"<<<myBranches.size<<std::endl;
                  for (unsigned int i=0;i<myBranches.size();i++){
                  myBranches.at(i)->Fill();
                  }
                  */

            }

            protected:
            edm::EDGetTokenT<std::vector<T>> src_;
            int njets;
            float vbfmass;
            StringCutObjectSelector<pat::Jet>*cut;
            StringObjectFunction<pat::Jet>*function;

            //std::vector<StringCutObjectSelector<pat::Jet>*> cutnew;
            std::vector<TBranch*> myBranches;
            std::vector<int> njetVecUp;
            std::vector<int> njetVecDown;
            std::vector<float> vbfVecUp;
            std::vector<float> vbfVecDown;

            std::vector< std::string > uncertNames;
            std::vector< std::string > cuts;
            std::vector< std::string > shiftedPt;
        };


#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"
        typedef VBFVariableFiller<PATMuTauPair> PATMuTauPairVBFVariableFiller;
        typedef VBFVariableFiller<PATElecTauPair> PATEleTauPairVBFVariableFiller;
        typedef VBFVariableFiller<PATDiTauPair> PATDiTauPairVBFVariableFiller;





