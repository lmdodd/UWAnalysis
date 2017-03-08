#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
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

            //float taupt=0.0;
            int weight=0.0;
            TTree *t = (TTree*)obj;

         //   TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/I").c_str());
            TBranch *newBranch1 = t->Branch("HLT_IsoMu22_v_prescale",&weight,"HLT_IsoMu22_v_prescale/I");
            TBranch *newBranch2 = t->Branch("HLT_IsoMu22_v_fired",&weight,"HLT_IsoMu22_v_fired/I");
            TBranch *newBranch3 = t->Branch("HLT_IsoTkMu22_v_fired",&weight,"HLT_IsoTkMu22_v_fired/I");
            TBranch *newBranch4 = t->Branch("HLT_IsoTkMu22_v_prescale",&weight,"HLT_IsoTkMu22_v_prescale/I");

            //t->SetBranchAddress("pt_2",&taupt);
            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);

                weight=0;
                //std::cout<<"TreeToUse: "<<std::string(TreeToUse)<<std::endl;
                //if(std::string(TreeToUse).find("muTauEvent")!= std::string::npos){
                    //std::cout<<"Using muTau!"<<std::endl;
                //} //End MuTau

                //else if(std::string(TreeToUse).find("eleTauEvent")!= std::string::npos){
                //    std::cout<<"Using eleTau!"<<std::endl;
                //} //E Tau

                //newBranch->Fill();
                newBranch1->Fill();
                newBranch2->Fill();
                newBranch3->Fill();
                newBranch4->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }//end else if object A
    }//end while key
}//end read directory
