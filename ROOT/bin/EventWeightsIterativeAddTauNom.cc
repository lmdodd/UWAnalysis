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

    char TreeToUse[80]="first" ;

    parser.parseArguments (argc, argv);

    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   

    readdir(f,parser, TreeToUse),

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

            float taupt=0.0;
            float tauDM=0.0;
            float newtaupt=0.0;
            float newtauptUP=0.0;
            float newtauptDOWN=0.0;
            TTree *t = (TTree*)obj;

            TBranch *newBranch1 = t->Branch("taupt",&newtaupt,"taupt/F");
            TBranch *newBranch2 = t->Branch("taupt_UP",&newtauptUP,"taupt_UP/F");
            TBranch *newBranch3 = t->Branch("taupt_DOWN",&newtauptDOWN,"taupt_DOWN/F");

            t->SetBranchAddress("pt_2",&taupt);
            t->SetBranchAddress("tauDecayMode",&tauDM);

            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);

                newtaupt=0;
                newtauptUP=0;
                newtauptDOWN=0;

                if (tauDM==0) newtaupt=taupt*0.982;
                else if (tauDM==1) newtaupt=taupt*1.01;
                else if (tauDM==10) newtaupt=taupt*1.004;             


                newtauptUP=newtaupt*1.006;
                newtauptDOWN=newtaupt*0.994;
                newBranch1->Fill();
                newBranch2->Fill();
                newBranch3->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }//end else if object A
    }//end while key
}//end read directory
