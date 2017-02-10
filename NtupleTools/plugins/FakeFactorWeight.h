// system include files
#include <memory>

// user include files

#include <TTree.h>

#include "UWAnalysis/NtupleTools/interface/NtupleFillerBase.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "HTTutilities/Jet2TauFakes/interface/FakeFactor.h"
//#include "UWAnalysis/Configuration/data/fitfunc

#include "CommonTools/Utils/interface/StringObjectFunction.h"
#include "boost/filesystem.hpp"

//
// class decleration
//

template<typename T>
class EventWeightFiller : public NtupleFillerBase {
    public:
        EventWeightFiller(){
        }


        EventWeightFiller(const edm::ParameterSet& iConfig, TTree* t, edm::ConsumesCollector && iC ):
            src_(iC.consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("src"))), 
            tag_(iConfig.getParameter<std::string>("tag")),
            isMu_(iConfig.getParameter<bool>("isMuon"))
    {
        value = new float[5];
        t->Branch((tag_+"FFWeight").c_str(),&value[2],(tag_+"FFWeight/F").c_str());
        std::string base = std::getenv("CMSSW_BASE");
        std::string ff_mt_path_incl =   "/src/HTTutilities/Jet2TauFakes/data/mt/0Jet/fakeFactors_20170111.root";
        std::string ff_mt_path_0jet =   "/src/HTTutilities/Jet2TauFakes/data/mt/0Jet/fakeFactors_20170111.root";
        std::string ff_mt_path_boosted =   "/src/HTTutilities/Jet2TauFakes/data/mt/boosted/fakeFactors_20170111.root";
        std::string ff_mt_path_vbf =   "/src/HTTutilities/Jet2TauFakes/data/mt/vbf/fakeFactors_20170111.root";
        std::string ff_et_path_incl =   "/src/HTTutilities/Jet2TauFakes/data/et/0Jet/fakeFactors_20170111.root";
        std::string ff_et_path_0jet =   "/src/HTTutilities/Jet2TauFakes/data/et/0Jet/fakeFactors_20170111.root";
        std::string ff_et_path_1jet =   "/src/HTTutilities/Jet2TauFakes/data/et/boosted/fakeFactors_20170111.root";
        std::string ff_et_path_vbf =   "/src/HTTutilities/Jet2TauFakes/data/et/vbf/fakeFactors_20170111.root";

        std::string fileIncl;
        std::string file0jet;
        std::string file1jet;
        std::string file2jet;
        if (isMu_) {
            fileIncl= base+ff_mt_path_incl;
            file0jet= base+ff_mt_path_0jet;
            file1jet= base+ff_mt_path_boosted;
            file2jet= base+ff_mt_path_vbf;
            bool fis   = boost::filesystem::exists( file0jet   ) && boost::filesystem::exists( fileIncl ) && boost::filesystem::exists( file2jet  ) && boost::filesystem::exists( file1jet);
            std::cout<<"file exist: "<<fis<<std::endl;
        }
        else {
            fileIncl= base+ff_et_path_incl;
            file0jet= base+ff_et_path_0jet;
            file1jet= base+ff_et_path_1jet;
            file2jet= base+ff_et_path_vbf;
            bool fis   = boost::filesystem::exists( file0jet   ) && boost::filesystem::exists( fileIncl ) && boost::filesystem::exists( file2jet  ) && boost::filesystem::exists( file1jet) ;
            std::cout<<"file exist: "<<fis<<std::endl;

        }
        FakeFactor* ff_mt_0jet = (FakeFactor*)ff_mt_file_0jet->Get("ff_comb");
        FakeFactor* ff_mt_boosted = (FakeFactor*)ff_mt_file_boosted->Get("ff_comb");
        FakeFactor* ff_mt_vbf = (FakeFactor*)ff_mt_file_vbf->Get("ff_comb");


        FakeFactor* ff_et_0jet = (FakeFactor*)ff_et_file_0jet->Get("ff_comb");
        FakeFactor* ff_et_boosted = (FakeFactor*)ff_et_file_boosted->Get("ff_comb");
        FakeFactor* ff_et_vbf = (FakeFactor*)ff_et_file_vbf->Get("ff_comb");

    }


        ~EventWeightFiller()
        { 
        }

        void fill(const edm::Event& iEvent, const edm::EventSetup& iSetup)
        {

            float weight=0.0;
            float taupt=0.0;
            float tauDM=0.0;
            int njets=0.0;
            float mvis=0.0;
            float mt=1.0;
            float iso=1.0;
            float vbfMass=1.0;
            float charge=1.0;
            float byTightIsolationMVArun2v1DBoldDMwLT_2,byVLooseIsolationMVArun2v1DBoldDMwLT_2,againstElectronVLooseMVA6_2,againstElectronTightMVA6_2,againstMuonLoose3_2,againstMuonTight3_2;
            /*t->SetBranchAddress("pt_2",&taupt);
            t->SetBranchAddress("tauDecayMode",&tauDM);
            t->SetBranchAddress("njets",&njets);
            t->SetBranchAddress("mt_1",&mt);
            t->SetBranchAddress("m_vis",&mvis);
            t->SetBranchAddress("iso_1",&iso);
            t->SetBranchAddress("vbfMass",&vbfMass);
            t->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
            t->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
            t->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
            t->SetBranchAddress("againstElectronTightMVA6_2",&againstElectronTightMVA6_2);
            t->SetBranchAddress("againstMuonLoose3_2",&againstMuonLoose3_2);
            t->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
            t->SetBranchAddress("charge",&charge);
*/
            //function_pt = new StringObjectFunction<T>("leg1.pt");
            //function_eta = new StringObjectFunction<T>("leg1.eta");
            edm::Handle<std::vector<T>> handle;
            if( iEvent.getByToken(src_,handle)){
                taupt = handle->at(0).leg2()->pt();
                tauDM = handle->at(0).leg2()->tauDecayMode();
                tauDM = handle->at(0).njets();
            }

            //double efficiency_data = myScaleFactorIso->get_EfficiencyData(pt, eta);
            //double efficiency_MC = myScaleFactorIso->get_EfficiencyMC(pt,eta);
            double scaleFactorIso = myScaleFactorIso->get_ScaleFactor(pt,eta);
            double scaleFactorTrig = myScaleFactorTrig->get_ScaleFactor(pt,eta);
            double efficiencyTrig = myScaleFactorTrig->get_EfficiencyData(pt,eta);

            value[0]=scaleFactorIso;
            value[1]=scaleFactorTrig;
            value[2]=(scaleFactorTrig*scaleFactorIso);
            value[3]=efficiencyTrig;
            value[4]= myScaleFactorIsoAI->get_ScaleFactor(pt,eta)*myScaleFactorTrigAI->get_ScaleFactor(pt,eta);
        }


    protected:
        edm::EDGetTokenT<std::vector<T> > src_;
        std::string tag_;
        bool isMu_;
        float* value;
        ScaleFactor *myScaleFactorIso; 
        ScaleFactor *myScaleFactorIsoAI; 
        ScaleFactor *myScaleFactorTrig;
        ScaleFactor *myScaleFactorTrigAI;


};




#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateT1T2MEt.h"
#include "UWAnalysis/DataFormats/interface/CompositePtrCandidateTMEt.h"

typedef EventWeightFiller<PATMuTauPair> PATMuTauPairWeightFiller;
typedef EventWeightFiller<PATElecTauPair> PATEleTauPairWeightFiller;



