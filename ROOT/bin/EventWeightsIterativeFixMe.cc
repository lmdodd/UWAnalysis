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
    parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__FakeFactorWeight7__");

    char TreeToUse[80]="first" ;

    parser.parseArguments (argc, argv);


    TFile* ff_mt_file_0jet = TFile::Open("../HTTutilities/Jet2TauFakes/data/mt/0Jet/fakeFactors_20170111.root");
    FakeFactor* ff_mt_0jet = (FakeFactor*)ff_mt_file_0jet->Get("ff_comb");
   //const std::vector<std::string>& inputNames_mt_0jet = ff_mt_0jet->inputs();


    TFile* ff_mt_file_boosted = TFile::Open("../HTTutilities/Jet2TauFakes/data/mt/boosted/fakeFactors_20170111.root");
    FakeFactor* ff_mt_boosted = (FakeFactor*)ff_mt_file_boosted->Get("ff_comb");
    //const std::vector<std::string>& inputNames_mt_boosted = ff_mt_boosted->inputs();

    TFile* ff_mt_file_vbf = TFile::Open("../HTTutilities/Jet2TauFakes/data/mt/vbf/fakeFactors_20170111.root");
    FakeFactor* ff_mt_vbf = (FakeFactor*)ff_mt_file_vbf->Get("ff_comb");
    //const std::vector<std::string>& inputNames_mt_vbf = ff_mt_vbf->inputs();


    TFile* ff_et_file_0jet = TFile::Open("../HTTutilities/Jet2TauFakes/data/et/0Jet/fakeFactors_20170111.root");
    FakeFactor* ff_et_0jet = (FakeFactor*)ff_et_file_0jet->Get("ff_comb");
    //const std::vector<std::string>& inputNames_et_0jet = ff_et_0jet->inputs();

    TFile* ff_et_file_boosted = TFile::Open("../HTTutilities/Jet2TauFakes/data/et/boosted/fakeFactors_20170111.root");
    FakeFactor* ff_et_boosted = (FakeFactor*)ff_et_file_boosted->Get("ff_comb");
    //const std::vector<std::string>& inputNames_et_boosted = ff_et_boosted->inputs();

    TFile* ff_et_file_vbf = TFile::Open("../HTTutilities/Jet2TauFakes/data/et/vbf/fakeFactors_20170111.root");
    FakeFactor* ff_et_vbf = (FakeFactor*)ff_et_file_vbf->Get("ff_comb");
    //const std::vector<std::string>& inputNames_et_vbf = ff_et_vbf->inputs();


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
            sprintf(TreeToUse,"%s",key->GetName());
            readdir(subdir,parser, TreeToUse, ff_mt_0jet, ff_mt_boosted, ff_mt_vbf, ff_et_0jet, ff_et_boosted, ff_et_vbf);
            dirsav->cd();
        }
        else if(obj->IsA()->InheritsFrom(TTree::Class())) {
            std::vector<double> inputs(6);

            float taupt=0.0;
            float tauDM=0.0;
            int njets=0.0;
            float mvis=0.0;
            float mt=1.0;
            float iso=1.0;
            float vbfMass=1.0;
            float charge=1.0;
            float byTightIsolationMVArun2v1DBoldDMwLT_2,byVLooseIsolationMVArun2v1DBoldDMwLT_2,againstElectronVLooseMVA6_2,againstElectronTightMVA6_2,againstMuonLoose3_2,againstMuonTight3_2;


            float weight=0.0;
            TTree *t = (TTree*)obj;
            std::vector<float> weightSys;

            std::string FFsys[31]={"","ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};




            //std::vector<TBranch> myBranches;

            TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());

            for (int k=0;k<31;++k){
                weightSys.push_back(0);
                //TBranch temp = t->Branch((FFsys[k]).c_str(),&weightSys[k],(FFsys[k]).c_str());
                //myBranches.push_back(temp);
            }

            TBranch *nBranch0 =  t->Branch((FFsys[0]+"ff_comb").c_str(),&weightSys[0],(FFsys[0]+"ff_comb").c_str());
            TBranch *nBranch1 =  t->Branch((FFsys[1]).c_str(),&weightSys[1],(FFsys[1]).c_str());
            TBranch *nBranch2 =  t->Branch((FFsys[2]).c_str(),&weightSys[2],(FFsys[2]).c_str());
            TBranch *nBranch3 =  t->Branch((FFsys[3]).c_str(),&weightSys[3],(FFsys[3]).c_str());
            TBranch *nBranch4 =  t->Branch((FFsys[4]).c_str(),&weightSys[4],(FFsys[4]).c_str());
            TBranch *nBranch5 =  t->Branch((FFsys[5]).c_str(),&weightSys[5],(FFsys[5]).c_str());
            TBranch *nBranch6 =  t->Branch((FFsys[6]).c_str(),&weightSys[6],(FFsys[6]).c_str());
            TBranch *nBranch7 =  t->Branch((FFsys[7]).c_str(),&weightSys[7],(FFsys[7]).c_str());
            TBranch *nBranch8 =  t->Branch((FFsys[8]).c_str(),&weightSys[8],(FFsys[8]).c_str());
            TBranch *nBranch9 =  t->Branch((FFsys[9]).c_str(),&weightSys[9],(FFsys[9]).c_str());
            TBranch *nBranch10 =  t->Branch((FFsys[10]).c_str(),&weightSys[10],(FFsys[10]).c_str());
            TBranch *nBranch11 =  t->Branch((FFsys[11]).c_str(),&weightSys[11],(FFsys[11]).c_str());
            TBranch *nBranch12 =  t->Branch((FFsys[12]).c_str(),&weightSys[12],(FFsys[12]).c_str());
            TBranch *nBranch13 =  t->Branch((FFsys[13]).c_str(),&weightSys[13],(FFsys[13]).c_str());
            TBranch *nBranch14 =  t->Branch((FFsys[14]).c_str(),&weightSys[14],(FFsys[14]).c_str());
            TBranch *nBranch15 =  t->Branch((FFsys[15]).c_str(),&weightSys[15],(FFsys[15]).c_str());
            TBranch *nBranch16 =  t->Branch((FFsys[16]).c_str(),&weightSys[16],(FFsys[16]).c_str());
            TBranch *nBranch17 =  t->Branch((FFsys[17]).c_str(),&weightSys[17],(FFsys[17]).c_str());
            TBranch *nBranch18 =  t->Branch((FFsys[18]).c_str(),&weightSys[18],(FFsys[18]).c_str());
            TBranch *nBranch19 =  t->Branch((FFsys[19]).c_str(),&weightSys[19],(FFsys[19]).c_str());
            TBranch *nBranch20 =  t->Branch((FFsys[20]).c_str(),&weightSys[20],(FFsys[20]).c_str());
            TBranch *nBranch21 =  t->Branch((FFsys[21]).c_str(),&weightSys[21],(FFsys[21]).c_str());
            TBranch *nBranch22 =  t->Branch((FFsys[22]).c_str(),&weightSys[22],(FFsys[22]).c_str());
            TBranch *nBranch23 =  t->Branch((FFsys[23]).c_str(),&weightSys[23],(FFsys[23]).c_str());
            TBranch *nBranch24 =  t->Branch((FFsys[24]).c_str(),&weightSys[24],(FFsys[24]).c_str());
            TBranch *nBranch25 =  t->Branch((FFsys[25]).c_str(),&weightSys[25],(FFsys[25]).c_str());
            TBranch *nBranch26 =  t->Branch((FFsys[26]).c_str(),&weightSys[26],(FFsys[26]).c_str());
            TBranch *nBranch27 =  t->Branch((FFsys[27]).c_str(),&weightSys[27],(FFsys[27]).c_str());
            TBranch *nBranch28 =  t->Branch((FFsys[28]).c_str(),&weightSys[28],(FFsys[28]).c_str());
            TBranch *nBranch29 =  t->Branch((FFsys[29]).c_str(),&weightSys[29],(FFsys[29]).c_str());
            TBranch *nBranch30 =  t->Branch((FFsys[30]).c_str(),&weightSys[30],(FFsys[30]).c_str());

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

                //std::cout<<"GetEntry"<<std::endl;
                //std::cout<<"tauPt: "<<taupt<<"  tauDM: "<<tauDM<<"  njets: "<<njets<<"  mvis: "<<mvis<<"  mt: "<<mt<<"  iso: "<<iso<<std::endl;
                //std::cout<<" \t byTightIsolationMVArun2v1DBoldDMwLT_2 "<<byTightIsolationMVArun2v1DBoldDMwLT_2<<"  \tagainstElectronVLooseMVA6_2:"<<againstElectronVLooseMVA6_2<<" \t againstMuonTight3_2: "<<againstMuonTight3_2<<std::endl;
                weight=0;
                inputs[0] = taupt;
                inputs[1] = tauDM;
                inputs[2] = njets;
                inputs[3] = mvis;
                inputs[4] = mt;
                inputs[5] = iso;
                std::cout<<"TreeToUse: "<<std::string(TreeToUse)<<std::endl;
                if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                    std::cout<<"Using muTau!"<<std::endl;
                    bool antiisoRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2<0.5 && iso<0.15 && againstElectronVLooseMVA6_2>0.5 && againstMuonTight3_2>0.5);
                    //std::cout<<"passes bool: "<<antiisoRegion<<std::endl;
                    //float antiisoRegion=(byVLooseIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && iso<0.15 && againstElectronVLooseMVA6_2 && againstMuonTight3_2);
                    if (antiisoRegion && charge==0){ 
                        std::cout<<"Is Anti Isolated"<<std::endl;

                        if (njets==0 && mt<50 && taupt>30){
                            std::cout<<"Is 0 Jet"<<std::endl;
                            weight=ff_mt_0jet->value(inputs);
                            for (int k=0;k<31;++k){ weightSys[k]=ff_mt_0jet->value(inputs,FFsys[k]);}
                        }
                        if ((njets==1 or (njets==2 && vbfMass<300) or njets>2) && mt<50 && taupt>30){
                            weight=ff_mt_boosted->value(inputs);
                            std::cout<<"Is Boosted"<<std::endl;
                            for (int k=0;k<31;++k){ weightSys[k]=ff_mt_boosted->value(inputs,FFsys[k]); }
                        }
                        if (njets==2 && vbfMass>300 && mt<50 && taupt>30){
                            std::cout<<"Is VBF"<<std::endl;
                            weight=ff_mt_vbf->value(inputs);
                            for (int k=0;k<31;++k){ weightSys[k]=ff_mt_vbf->value(inputs,FFsys[k]); }
                        }
                    }
                } //End MuTau

                else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                    std::cout<<"Using eleTau!"<<std::endl;
                    float antiisoRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2<0.5 && iso<0.1 && againstElectronTightMVA6_2>0.5 && againstMuonLoose3_2>0.5);
                    //float antiisoRegion=(byVLooseIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && iso<0.1 && againstElectronTightMVA6_2 && againstMuonLoose3_2);
                    if (antiisoRegion && charge==0) {
                        if (njets==0 && mt<50 && taupt>30 ){
                            weight=ff_et_0jet->value(inputs);
                            for (int k=0;k<31;++k){ weightSys[k]=ff_et_0jet->value(inputs,FFsys[k]); }
                        }
                        if ((njets==1 or (njets==2 && vbfMass<300) or njets>2) && mt<50 && taupt>30){
                            weight=ff_et_boosted->value(inputs);
                            for (int k=0;k<31;++k){ weightSys[k]=ff_et_boosted->value(inputs,FFsys[k]); }
                        }
                        if (njets==2 && vbfMass>300 && mt<50 && taupt>30 && antiisoRegion){
                            weight=ff_et_vbf->value(inputs);
                            for (int k=0;k<31;++k){ weightSys[k]=ff_et_vbf->value(inputs,FFsys[k]); }
                        }
                    }
                } //E Tau


                newBranch->Fill();
                nBranch0->Fill();
                nBranch1->Fill();
                nBranch2->Fill();
                nBranch3->Fill();
                nBranch4->Fill();
                nBranch5->Fill();
                nBranch6->Fill();
                nBranch7->Fill();
                nBranch8->Fill();
                nBranch9->Fill();
                nBranch10->Fill();
                nBranch11->Fill();
                nBranch12->Fill();
                nBranch13->Fill();
                nBranch14->Fill();
                nBranch15->Fill();
                nBranch16->Fill();
                nBranch17->Fill();
                nBranch18->Fill();
                nBranch19->Fill();
                nBranch20->Fill();
                nBranch21->Fill();
                nBranch22->Fill();
                nBranch23->Fill();
                nBranch24->Fill();
                nBranch25->Fill();
                nBranch26->Fill();
                nBranch27->Fill();
                nBranch28->Fill();
                nBranch29->Fill();
                nBranch30->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }//end else if object A
    }//end while key
}//end read directory
