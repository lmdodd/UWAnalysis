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
    parser.addOption("IsoFile",optutl::CommandLineParser::kString,"Iso Hist","scalefactors_2016_v5.root");
    parser.parseArguments (argc, argv);


    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

    char TreeToUse[80]="first" ;


    TFile fIso("htt_scalefactors_v5.root");
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
            TBranch *newBranch  = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
            TBranch *newBranch1  = t->Branch(parser.stringValue("branch1").c_str(),&weight1,(parser.stringValue("branch1")+"/F").c_str());
            TBranch *newBranch2 = t->Branch("fakeTauEffiUp",&weightUp,"fakeTauEffiUp/F");
            TBranch *newBranch3 = t->Branch("fakeTauEffiDown",&weightDown,"fakeTauEffiDown/F");
            TBranch *newBranch4 = t->Branch("zmumu_pth",&weightpth,"zmumu_pth/F");
            TBranch *newBranch5 = t->Branch("zmumu_mjj",&weightmjj,"zmumu_mjj/F");



            float pt1;
            float tauPt;
            float eta1;
            float iso1;
            float pth;
            float mjj;

            t->SetBranchAddress("pt_1",&pt1);
            t->SetBranchAddress("pt_2",&tauPt);
            t->SetBranchAddress("eta_1",&eta1);
            t->SetBranchAddress("iso_1",&iso1);
            t->SetBranchAddress("vbfMass",&mjj);
            t->SetBranchAddress("p_sv",&pth);

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
                //printf("Wvar: pt:%f, eta:%f, iso:%f \n",pt1,eta1,iso1);
                if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                    w->var("m_pt")->setVal(pt1);
                    w->var("m_eta")->setVal(eta1);
                    w->var("m_iso")->setVal(iso1);

                    double muon_id_scalefactor = w->function("m_id_ratio")->getVal();
                    double muon_iso_scalefactor = w->function("m_iso_binned_ratio")->getVal();
                    weight1 = w->function("m_trgOR_binned_data")->getVal();
                    //printf("Muon function: id:%f, iso:%f, trig:%f \n", muon_id_scalefactor, muon_iso_scalefactor, weight1);

                    weight=muon_id_scalefactor*muon_iso_scalefactor;
                }
                else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                    w->var("e_pt")->setVal(pt1);
                    w->var("e_eta")->setVal(eta1);
                    w->var("e_iso")->setVal(iso1);


                    double ele_id_scalefactor = w->function("e_id_ratio")->getVal();
                    double ele_iso_scalefactor = w->function("e_iso_binned_ratio")->getVal();
                    weight1 = w->function("e_trg_binned_data")->getVal();
                    //printf("Ele function: id:%f, iso:%f, trig:%f \n", ele_id_scalefactor, ele_iso_scalefactor, weight1);

                    weight=ele_id_scalefactor*ele_iso_scalefactor;
                }
                else{
                    std::cout<<"TreeToUse "<< std::string(TreeToUse)<<" does not match muTauEvent or eleTauEvent... Skipping!!"<<std::endl;
                    continue;
                }
                if (tauPt>200)tauPt=200.;

                weightUp = 1-(0.2*(tauPt/100.0));
                weightDown = 1+ (0.2*(tauPt/100.0));

                if (pth <100) weightpth = 0.971;
                else if (pth <150) weightpth = 0.975;
                else if (pth <200) weightpth = 0.960;
                else if (pth <250) weightpth = 0.964;
                else if (pth <300) weightpth = 0.934;
                else  weightpth = 0.942;

                if (300<mjj && mjj<700) weightmjj= 1.043;
                else if (700<mjj && mjj<1100) weightmjj= 0.965;
                else if (1100<mjj && mjj<1500) weightmjj= 0.901;
                else if (1500<mjj) weightmjj= 0.888;

                newBranch->Fill();
                newBranch1->Fill();
                newBranch2->Fill();
                newBranch3->Fill();
                newBranch4->Fill();
                newBranch5->Fill();


            }

            t->Write("",TObject::kOverwrite);
        }
    }
}
