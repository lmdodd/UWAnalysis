#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TF1.h"
#include <math.h> 
#include "TMath.h" 
#include <limits>
#include "RooWorkspace.h"
#include "RooRealVar.h"


void readdir(TDirectory *dir,optutl::CommandLineParser parser,RooWorkspace *w, char TreeToUse[]); 




int main (int argc, char* argv[]) 
{
    optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
    parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__QCDIDISO__");
    parser.addOption("branch1",optutl::CommandLineParser::kString,"Branch","__QCDTRIG__");
    parser.addOption("IsoFile",optutl::CommandLineParser::kString,"Iso Hist","htt_scalefactors_sm_moriond_v1.root");
    parser.parseArguments (argc, argv);


    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

    char TreeToUse[80]="first" ;


    TFile fIso("htt_scalefactors_sm_moriond_v1.root");
    RooWorkspace *w = (RooWorkspace*)fIso.Get("w");
    fIso.Close();


    readdir(f,parser,w,TreeToUse);
    f->Close();

} 


void readdir(TDirectory *dir, optutl::CommandLineParser parser,RooWorkspace *w, char TreeToUse[]) 
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
            sprintf(TreeToUse,"%s",key->GetName());
            TDirectory *subdir = gDirectory;
            readdir(subdir,parser,w,TreeToUse);
            dirsav->cd();
        }
        else if(obj->IsA()->InheritsFrom(TTree::Class())) {
            TTree *t = (TTree*)obj;
            float weight = 1.0;
            float weight1 = 1.0;
            float weightUp = 1.0;
            float weightDown = 1.0;
            float weightpth = 1.0;
            float weightmjj = 1.0;
            float weight_redo1 = 1.0;
            float weight_redo2 = 1.0;
            float weight_tauid = 1.0;
            //TBranch *newBranch  = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
            //TBranch *newBranch1  = t->Branch(parser.stringValue("branch1").c_str(),&weight1,(parser.stringValue("branch1")+"/F").c_str());
            TBranch *newBranch2 = t->Branch("fakeTauEffiUp_REDO",&weightUp,"fakeTauEffiUp_REDO/F");
            TBranch *newBranch3 = t->Branch("fakeTauEffiDown_REDO",&weightDown,"fakeTauEffiDown_REDO/F");
            //TBranch *newBranch4 = t->Branch("zmumu_pth",&weightpth,"zmumu_pth/F");
            TBranch *newBranch5 = t->Branch("zmumu_mjj_REDO",&weightmjj,"zmumu_mjj_REDO/F");
            //TBranch *newBranch6 = t->Branch("idisoweight_REDO",&weight_redo1,"idisoweight_REDO/F");
            //TBranch *newBranch7 = t->Branch("trigweight_REDO",&weight_redo2,"trigweight_REDO/F");
            //TBranch *newBranch8 = t->Branch("TAUID",&weight_tauid,"TAUID/F");


            std::cout<<"here1"<<std::endl;

            float pt1;
            float tauPt;
            float eta1;
            float eta2;
            float iso1;
            float pth;
            float mjj;
            float gen_match;
            float tauDM;

            t->SetBranchAddress("pt_1",&pt1);
            t->SetBranchAddress("pt_2",&tauPt);
            t->SetBranchAddress("eta_1",&eta1);
            t->SetBranchAddress("eta_2",&eta2);
            t->SetBranchAddress("iso_1",&iso1);
            t->SetBranchAddress("vbfMass",&mjj);
            t->SetBranchAddress("pt_sv",&pth);
            t->SetBranchAddress("tauDecayMode",&tauDM);
            t->SetBranchAddress("gen_match_2",&gen_match);

            std::cout<<"here2"<<std::endl;

            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;
            if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                std::cout<<"Using muTau!"<<std::endl;
            }
            else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                std::cout<<"Using eleTau!"<<std::endl;
            }


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);
                weight=1.0;
                weight1=1.0;
                weightUp =1.0;
                weightDown=1.0;
                weightpth=1.0;
                weightmjj=1.0;
                weight_redo1=1.0;
                weight_redo2=1.0;
                weight_tauid=1.0;
                //printf("Wvar: pt:%f, eta:%f, iso:%f \n",pt1,eta1,iso1);
                if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                    w->var("m_pt")->setVal(pt1);
                    w->var("m_eta")->setVal(eta1);
                    w->var("t_pt")->setVal(tauPt);
                    w->var("t_eta")->setVal(eta2);
                    w->var("t_dm")->setVal(tauDM);

                    double muon_id_scalefactor = w->function("m_idiso_aiso0p15to0p3_desy_ratio")->getVal();
                    weight=muon_id_scalefactor;
                    weight1 = w->function("m_trgMu19leg_eta2p1_aiso0p15to0p3_desy_ratio")->getVal();
                    weight_redo1 = w->function("m_idiso0p15_desy_ratio")->getVal();

                    if (pt1>23){
                        weight_redo2 = w->function("m_trgMu22OR_eta2p1_desy_ratio")->getVal();
                    }
                    else{
                        weight_redo2 = w->function("t_genuine_TightIso_mt_ratio")->getVal()*w->function("m_trgMu19leg_eta2p1_desy_ratio")->getVal();
                    }
                }
                else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                    w->var("e_pt")->setVal(pt1);
                    w->var("e_eta")->setVal(eta1);


                    double ele_id_scalefactor = w->function("e_idiso_aiso0p1to0p3_desy_ratio")->getVal();
                    weight=ele_id_scalefactor;
                    weight1 = w->function("e_trgEle24_aiso0p1to0p3_desy_ratio")->getVal();
                    //printf("Ele function: id:%f,  trig:%f \n", ele_id_scalefactor, weight1);

                    weight_redo1 = w->function("e_idiso0p1_desy_ratio")->getVal();
                    weight_redo2 = w->function("e_trgEle25eta2p1WPTight_desy_ratio")->getVal();
                    //printf("Ele function: id:%f,  trig:%f \n", weight_redo1, weight_redo2);


                }
                else{
                    std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent... Skipping!!"<<std::endl;
                    continue;
                }

                if (gen_match==1||gen_match==3){
                    if (std::abs(eta2)<1.460)  weight_tauid=1.867;
                    else  weight_tauid=1.456;
                }
                else if (gen_match==2||gen_match==4){
                    if (std::abs(eta2)<0.4)  weight_tauid=1.263;
                    else if (std::abs(eta2)<0.8)  weight_tauid=1.364;
                    else if (std::abs(eta2)<1.2)  weight_tauid=0.854;
                    else if (std::abs(eta2)<1.7)  weight_tauid=1.712;
                    else if (std::abs(eta2)<2.3)  weight_tauid=2.324;
                }
                else if(gen_match==5){
                    weight_tauid=0.95;
                }
                else if(gen_match==6){
                    if (tauPt>150)tauPt=150.;

                    weightUp = 1-(0.2*(tauPt/100.0));
                    weightDown = 1+ (0.2*(tauPt/100.0));
                }

                if (pth <100) weightpth = 0.971;
                else if (pth <150) weightpth = 0.975;
                else if (pth <200) weightpth = 0.960;
                else if (pth <250) weightpth = 0.964;
                else if (pth <300) weightpth = 0.934;
                else  weightpth = 0.942;

                if (300<mjj && mjj<700) weightmjj= 1.070;
                else if (700<mjj && mjj<1100) weightmjj= 1.090;
                else if (1100<mjj && mjj<1500) weightmjj= 1.055;
                else if (1500<mjj) weightmjj= 1.015;

                //newBranch->Fill();
                //newBranch1->Fill();
                newBranch2->Fill();
                newBranch3->Fill();
                //newBranch4->Fill();
                newBranch5->Fill();
                //newBranch6->Fill();
                //newBranch7->Fill();
                //newBranch8->Fill();


            }

            t->Write("",TObject::kOverwrite);
        }
    }
}
