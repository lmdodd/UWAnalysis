#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include <iostream>

using std::cout;
using std::endl;


void readdir(TDirectory *dir,optutl::CommandLineParser parser,  char TreeToUse[]);


int main (int argc, char* argv[]) 
{
    optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
    //parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__BranchName__");

    char TreeToUse[80]="first" ;

    parser.parseArguments (argc, argv);

    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   

    readdir(f,parser, TreeToUse);

    f->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,char TreeToUse[])
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
            readdir(subdir,parser, TreeToUse);
            dirsav->cd();
        }
        else if(obj->IsA()->InheritsFrom(TTree::Class())) {

            float m_vis=0.0;
            float m_visUP=0.0;
            float m_visDOWN=0.0;

            float mvisN=0.0;
            float tauDM=0.0;
            float gen_match=0;



            TTree *t = (TTree*)obj;

            TBranch *newBranch0 = t->Branch("m_vis_ZL",&m_vis,"m_vis_ZL/F");
            TBranch *newBranch1 = t->Branch("m_vis_ZL_UP",&m_visUP,"m_vis_ZL_UP/F");
            TBranch *newBranch2 = t->Branch("m_vis_ZL_DOWN",&m_visDOWN,"m_vis_ZL_DOWN/F");

            t->SetBranchAddress("m_vis_REDO",&mvisN);

            t->SetBranchAddress("tauDecayMode",&tauDM);
            t->SetBranchAddress("gen_match_2",&gen_match);

            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);
                m_vis=mvisN;
                m_visUP=mvisN;
                m_visDOWN=mvisN;

                if (gen_match<5) {

                    if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                        if (tauDM==0){ m_vis=m_vis*1.01; }
                    }
                    else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                        if (tauDM==0) m_vis=m_vis*1.017;
                        else if (tauDM==1) m_vis=m_vis*1.03;

                    }
                    m_visUP=m_vis*1.03;
                    m_visDOWN=m_vis*0.97;

                }
                newBranch0->Fill();
                newBranch1->Fill();
                newBranch2->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }//end else if object A
    }//end while key
}//end read directory
