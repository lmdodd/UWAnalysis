#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TMath.h"
#include "TFileMerger.h"



void readdir(TDirectory *dir,optutl::CommandLineParser parser); 



int main (int argc, char* argv[]) 
{
    optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");

    parser.parseArguments (argc, argv);

    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   

    readdir(f,parser );


} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser) 
{
    TDirectory *dirsav = gDirectory;
    TIter next(dir->GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)next())) {
        printf("Found key=%s \n",key->GetName());
        TObject *obj = key->ReadObj();

        if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
            dir->cd(key->GetName());
            TDirectory *subdir = gDirectory;
            readdir(subdir,parser);
            dirsav->cd();
        }
        else if(obj->IsA()->InheritsFrom(TTree::Class())) {
            TTree *t = (TTree*)obj;
            float weight_tauidUp;
            float weight_tauidDown;


            TBranch *newBranch = t->Branch("tauDM_weight",&weight_tauidUp,"tauDM_weight/F");
            TBranch *newBranch1 = t->Branch("tauDM_weightDown",&weight_tauidDown,"tauDM_weightDown/F");
            float tauDM=0;
            t->SetBranchAddress("tauDecayMode",&tauDM); //genPy


            printf("Found tree -> weight_tauiding\n");
            for(Int_t i=0;i<t->GetEntries();++i){
                t->GetEntry(i);
                weight_tauidUp=1.0;
                weight_tauidDown=1.0;

                if (tauDM==0){
                    weight_tauidUp=1.8;        
                    weight_tauidDown=0.2;        
                }

                newBranch->Fill();
                newBranch1->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }



    }

}
