#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "HTTutilities/Jet2TauFakes/interface/FakeFactor.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include <iostream>

using std::cout;
using std::endl;


void readdir(TDirectory *dir,optutl::CommandLineParser parser,  char TreeToUse[], FakeFactor* ff_mt_0jet, FakeFactor* ff_mt_boosted, FakeFactor* ff_mt_vbf ,FakeFactor* ff_et_0jet ,FakeFactor* ff_et_boosted,FakeFactor* ff_et_vbf); 


int main (int argc, char* argv[]) 
{
    optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
    parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__FakeFactorWeight4__");

    char TreeToUse[80]="first" ;

    parser.parseArguments (argc, argv);


    TFile* ff_mt_file_0jet = TFile::Open("../HTTutilities/Jet2TauFakes/data/mt/0Jet/fakeFactors_20170111.root");
    FakeFactor* ff_mt_0jet = (FakeFactor*)ff_mt_file_0jet->Get("ff_mt_comb");
    const std::vector<std::string>& inputNames_mt_0jet = ff_mt_0jet->inputs();


    TFile* ff_mt_file_boosted = TFile::Open("../HTTutilities/Jet2TauFakes/data/mt/boosted/fakeFactors_20170111.root");
    FakeFactor* ff_mt_boosted = (FakeFactor*)ff_mt_file_boosted->Get("ff_mt_comb");
    const std::vector<std::string>& inputNames_mt_boosted = ff_mt_boosted->inputs();

    TFile* ff_mt_file_vbf = TFile::Open("../HTTutilities/Jet2TauFakes/data/mt/vbf/fakeFactors_20170111.root");
    FakeFactor* ff_mt_vbf = (FakeFactor*)ff_mt_file_vbf->Get("ff_mt_comb");
    const std::vector<std::string>& inputNames_mt_vbf = ff_mt_vbf->inputs();


    TFile* ff_et_file_0jet = TFile::Open("../HTTutilities/Jet2TauFakes/data/et/0Jet/fakeFactors_20170111.root");
    FakeFactor* ff_et_0jet = (FakeFactor*)ff_et_file_0jet->Get("ff_et_comb");
    const std::vector<std::string>& inputNames_et_0jet = ff_et_0jet->inputs();

    TFile* ff_et_file_boosted = TFile::Open("../HTTutilities/Jet2TauFakes/data/et/boosted/fakeFactors_20170111.root");
    FakeFactor* ff_et_boosted = (FakeFactor*)ff_et_file_boosted->Get("ff_et_comb");
    const std::vector<std::string>& inputNames_et_boosted = ff_et_boosted->inputs();

    TFile* ff_et_file_vbf = TFile::Open("../HTTutilities/Jet2TauFakes/data/et/vbf/fakeFactors_20170111.root");
    FakeFactor* ff_et_vbf = (FakeFactor*)ff_et_file_vbf->Get("ff_et_comb");
    const std::vector<std::string>& inputNames_et_vbf = ff_et_vbf->inputs();


    std::string FFsys[31]={"","ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
    TString postfix_mt_FF[31]={"","_norm_ff_qcd_mt_systUp","_norm_ff_qcd_mt_systDown","_norm_ff_qcd_dm0_njet0_mt_statUp","_norm_ff_qcd_dm0_njet0_mt_statDown","_norm_ff_qcd_dm0_njet1_mt_statUp","_norm_ff_qcd_dm0_njet1_mt_statDown","_norm_ff_qcd_dm1_njet0_mt_statUp","_norm_ff_qcd_dm1_njet0_mt_statDown","_norm_ff_qcd_dm1_njet1_mt_statUp","_norm_ff_qcd_dm1_njet1_mt_statDown","_norm_ff_w_mt_systUp","_norm_ff_w_mt_systDown","_norm_ff_w_dm0_njet0_mt_statUp","_norm_ff_w_dm0_njet0_mt_statDown","_norm_ff_w_dm0_njet1_mt_statUp","_norm_ff_w_dm0_njet1_mt_statDown","_norm_ff_w_dm1_njet0_mt_statUp","_norm_ff_w_dm1_njet0_mt_statDown","_norm_ff_w_dm1_njet1_mt_statUp","_norm_ff_w_dm1_njet1_mt_statDown","_norm_ff_tt_mt_systUp","_norm_ff_tt_mt_systDown","_norm_ff_tt_dm0_njet0_mt_statUp","_norm_ff_tt_dm0_njet0_mt_statDown","_norm_ff_tt_dm0_njet1_mt_statUp","_norm_ff_tt_dm0_njet1_mt_statDown","_norm_ff_tt_dm1_njet0_mt_statUp","_norm_ff_tt_dm1_njet0_mt_statDown","_norm_ff_tt_dm1_njet1_mt_statUp","_norm_ff_tt_dm1_njet1_mt_statDown"};
    TString postfix_et_FF[31]={"","_norm_ff_qcd_et_systUp","_norm_ff_qcd_et_systDown","_norm_ff_qcd_dm0_njet0_et_statUp","_norm_ff_qcd_dm0_njet0_et_statDown","_norm_ff_qcd_dm0_njet1_et_statUp","_norm_ff_qcd_dm0_njet1_et_statDown","_norm_ff_qcd_dm1_njet0_et_statUp","_norm_ff_qcd_dm1_njet0_et_statDown","_norm_ff_qcd_dm1_njet1_et_statUp","_norm_ff_qcd_dm1_njet1_et_statDown","_norm_ff_w_et_systUp","_norm_ff_w_et_systDown","_norm_ff_w_dm0_njet0_et_statUp","_norm_ff_w_dm0_njet0_et_statDown","_norm_ff_w_dm0_njet1_et_statUp","_norm_ff_w_dm0_njet1_et_statDown","_norm_ff_w_dm1_njet0_et_statUp","_norm_ff_w_dm1_njet0_et_statDown","_norm_ff_w_dm1_njet1_et_statUp","_norm_ff_w_dm1_njet1_et_statDown","_norm_ff_tt_et_systUp","_norm_ff_tt_et_systDown","_norm_ff_tt_dm0_njet0_et_statUp","_norm_ff_tt_dm0_njet0_et_statDown","_norm_ff_tt_dm0_njet1_et_statUp","_norm_ff_tt_dm0_njet1_et_statDown","_norm_ff_tt_dm1_njet0_et_statUp","_norm_ff_tt_dm1_njet0_et_statDown","_norm_ff_tt_dm1_njet1_et_statUp","_norm_ff_tt_dm1_njet1_et_statDown"};

    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   

    readdir(f,parser, TreeToUse, ff_mt_0jet, ff_mt_boosted, ff_mt_vbf, ff_et_0jet, ff_et_boosted, ff_et_vbf);

    f->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,char TreeToUse[], FakeFactor* ff_mt_0jet, FakeFactor* ff_mt_boosted, FakeFactor* ff_mt_vbf ,FakeFactor* ff_et_0jet ,FakeFactor* ff_et_boosted,FakeFactor* ff_et_vbf) 
{
    TDirectory *dirsav = gDirectory;
    TIter next(dir->GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)next())) {
        printf("Found key=%s \n",key->GetName());
        TString keyname = key->GetName();
        if (keyname=="CircJetID_puv2"||keyname=="sumweights"){
            printf("Skipping key %s . Not weighting. \n",key->GetName());
            continue;
        }

        TObject *obj = key->ReadObj();

        if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
            dir->cd(key->GetName());
            TDirectory *subdir = gDirectory;
            readdir(subdir,parser, TreeToUse, ff_mt_0jet, ff_mt_boosted, ff_mt_vbf, ff_et_0jet, ff_et_boosted, ff_et_vbf);
            dirsav->cd();
        }
        else if(obj->IsA()->InheritsFrom(TTree::Class())) {
            std::vector<double> inputs(6);

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
            TTree *t = (TTree*)obj;
            TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
            t->SetBranchAddress("pt_2",&taupt);
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

            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);

                weight=0;
                inputs[0] = taupt;
                inputs[1] = tauDM;
                inputs[2] = njets;
                inputs[3] = mvis;
                inputs[4] = mt;
                inputs[5] = iso;
                if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                    std::cout<<"Using muTau!"<<std::endl;
                    float antiisoRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2<0.5 && iso<0.15 && againstElectronVLooseMVA6_2 && againstMuonTight3_2);
                    //float antiisoRegion=(byVLooseIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && iso<0.15 && againstElectronVLooseMVA6_2 && againstMuonTight3_2);
                    if (antiisoRegion && charge==0) {

                        if (njets==0 && mt<50 && taupt>30){
                            weight=ff_mt_0jet->value(inputs);
                            //for (int k=0;k<31;++k){ weight=ff_mt_0jet->value(inputs,FFsys[k]);}
                        }
                        if ((njets==1 or (njets==2 && vbfMass<300) or njets>2) && mt<50 && taupt>30){
                            weight=ff_mt_boosted->value(inputs);
                            //for (int k=0;k<31;++k){ weight=ff_mt_boosted->value(inputs,FFsys[k]); }
                        }
                        if (njets==2 && vbfMass>300 && mt<50 && taupt>30){
                            weight=ff_mt_vbf->value(inputs);
                            //for (int k=0;k<31;++k){ weight=ff_mt_vbf->value(inputs,FFsys[k]); }
                        }
                    }
                } //End MuTau

                else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                    std::cout<<"Using eleTau!"<<std::endl;
                    float antiisoRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2<0.5 && iso<0.1 && againstElectronTightMVA6_2 && againstMuonLoose3_2);
                    //float antiisoRegion=(byVLooseIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && iso<0.1 && againstElectronTightMVA6_2 && againstMuonLoose3_2);
                    if (antiisoRegion && charge==0) {
                        if (njets==0 && mt<50 && taupt>30 ){
                            weight=ff_et_0jet->value(inputs);
                            //for (int k=0;k<31;++k){ weight=ff_et_0jet->value(inputs,FFsys[k]); }
                        }
                        if ((njets==1 or (njets==2 && vbfMass<300) or njets>2) && mt<50 && taupt>30){
                            weight=ff_et_boosted->value(inputs);
                            //for (int k=0;k<31;++k){ weight=ff_et_boosted->value(inputs,FFsys[k]); }
                        }
                        if (njets==2 && vbfMass>300 && mt<50 && taupt>30 && antiisoRegion){
                            weight=ff_et_vbf->value(inputs);
                            //for (int k=0;k<31;++k){ weight=ff_et_vbf->value(inputs,FFsys[k]); }
                        }
                    }
                } //E Tau


                newBranch->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }//end else if object A
    }//end while key
}//end read directory
