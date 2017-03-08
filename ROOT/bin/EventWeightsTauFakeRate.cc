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
            float weight_tauid;


            TBranch *newBranch = t->Branch("TAUID",&weight_tauid,"TAUID/F");
            float TauEta=0;
            float GenMatch=0;
            t->SetBranchAddress("eta_2",&TauEta); //genPy
            t->SetBranchAddress("gen_match_2",&GenMatch); //genPy


            printf("Found tree -> weight_tauiding\n");
            for(Int_t i=0;i<t->GetEntries();++i){
                t->GetEntry(i);
                weight_tauid=1.0;

                if (GenMatch==1||GenMatch==3){
                    if (std::abs(TauEta)<1.460)  weight_tauid=1.867;
                    else  weight_tauid=1.456;
                }
                else if (GenMatch==2||GenMatch==4){
                    if (std::abs(TauEta)<0.4)  weight_tauid=1.263;
                    else if (std::abs(TauEta)<0.8)  weight_tauid=1.364;
                    else if (std::abs(TauEta)<1.2)  weight_tauid=0.854;
                    else if (std::abs(TauEta)<1.7)  weight_tauid=1.712;
                    else if (std::abs(TauEta)<2.3)  weight_tauid=2.324;
                }
                else if(GenMatch==5){
                    weight_tauid=0.95;
                }

                newBranch->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }



    }

}
