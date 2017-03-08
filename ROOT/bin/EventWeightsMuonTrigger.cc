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
            float weight_redo2 = 1.0;
            TBranch *newBranch7 = t->Branch("trigweight_MuTau",&weight_redo2,"trigweight_MuTau/F");

            float pt1;
            float tauPt;
            float eta1;
            float eta2;
            float tauDM;

            t->SetBranchAddress("pt_1",&pt1);
            t->SetBranchAddress("pt_2",&tauPt);
            t->SetBranchAddress("eta_1",&eta1);
            t->SetBranchAddress("eta_2",&eta2);
            t->SetBranchAddress("tauDecayMode",&tauDM);


            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;

            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);
                weight_redo2=1.0;
                //printf("Wvar: pt:%f, eta:%f, iso:%f \n",pt1,eta1,iso1);
                if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                    w->var("m_pt")->setVal(pt1);
                    w->var("m_eta")->setVal(eta1);
                    w->var("t_pt")->setVal(tauPt);
                    w->var("t_eta")->setVal(eta2);
                    w->var("t_dm")->setVal(tauDM);

                    if (pt1>23){
                        weight_redo2 = w->function("m_trgMu22OR_eta2p1_desy_ratio")->getVal();
                    }
                    else{
                        weight_redo2 = w->function("t_genuine_TightIso_mt_ratio")->getVal()*w->function("m_trgMu19leg_eta2p1_desy_ratio")->getVal();
                    }

                }
                else{
                    //std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent... Skipping!!"<<std::endl;
                    continue;
                }

                newBranch7->Fill();


            }

            t->Write("",TObject::kOverwrite);
        }
    }
}
