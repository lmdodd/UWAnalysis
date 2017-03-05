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

            float pdgid=0.0;
            float lpt=0.0;
            float leta=0.0;
            float lphi=0.0;
            float lM=0.0;

            float taupt=0.0;
            float taueta=0.0;
            float tauphi=0.0;

            float tauDM=0.0;
            float tauM=0.0;
            float gen_match=0;

            float newtaupt=0.0;
            float newtauptUP=0.0;
            float newtauptDOWN=0.0;

            TLorentzVector tau; 
            TLorentzVector tauUp; 
            TLorentzVector tauDown; 
            TLorentzVector l; 


            TTree *t = (TTree*)obj;

            TBranch *newBranch1 = t->Branch("m_vis_REDO",&m_vis,"m_vis_REDO/F");
            TBranch *newBranch2 = t->Branch("m_vis_UP",&m_visUP,"m_vis_UP/F");
            TBranch *newBranch3 = t->Branch("m_vis_DOWN",&m_visDOWN,"m_vis_DOWN/F");
            TBranch *newBranch4 = t->Branch("taupt",&newtaupt,"taupt/F");
            TBranch *newBranch5 = t->Branch("taupt_UP",&newtauptUP,"taupt_UP/F");
            TBranch *newBranch6 = t->Branch("taupt_DOWN",&newtauptDOWN,"taupt_DOWN/F");


            t->SetBranchAddress("pt_2",&taupt);
            t->SetBranchAddress("eta_2",&taueta);
            t->SetBranchAddress("phi_2",&tauphi);
            t->SetBranchAddress("m_2",&tauM);

            t->SetBranchAddress("pt_1",&lpt);
            t->SetBranchAddress("eta_1",&leta);
            t->SetBranchAddress("phi_1",&lphi);
            t->SetBranchAddress("pdg1",&pdgid);

            t->SetBranchAddress("tauDecayMode",&tauDM);
            t->SetBranchAddress("gen_match_2",&gen_match);

            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);


                m_vis=0;
                m_visUP=0;
                m_visDOWN=0;
                lM=0;

                if (abs(pdgid)==11){
                    lM=0.00051100;
                }
                else{ 
                    std::cout<<"muon mass"<<std::endl;
                    lM=0.105658;
                }

                std::cout<<"L 4 vector: "<<lpt<<","<<leta<<","<<lphi<<","<<lM <<std::endl;
                l.SetPtEtaPhiM(lpt,leta,lphi,lM); 

                if (tauDM==0){ 
                    tauM=0.13957;
                    taupt=taupt*0.982;
                    newtaupt=taupt;
                    tau.SetPtEtaPhiM(taupt,taueta,tauphi,tauM);
                }
                else if (tauDM==1){ 
                    tauM=tauM*1.01;
                    taupt=taupt*1.01;
                    newtaupt=taupt;
                    tau.SetPtEtaPhiM(taupt,taueta,tauphi,tauM);
                }
                else { 
                    tauM=tauM*1.004;
                    taupt=taupt*1.004;
                    newtaupt=taupt;
                    tau.SetPtEtaPhiM(taupt,taueta,tauphi,tauM);
                }

                m_vis=(tau+l).M();

                if (gen_match==5){
                    if (tauDM!=0){
                        tauUp.SetPtEtaPhiM(taupt*1.006,taueta,tauphi,tauM*1.006);
                        tauDown.SetPtEtaPhiM(taupt*0.994,taueta,tauphi,tauM*0.994);
                    }
                    else {
                        tauUp.SetPtEtaPhiM(taupt*1.006,taueta,tauphi,0.13957);
                        tauDown.SetPtEtaPhiM(taupt*0.994,taueta,tauphi,0.13957);
                    } 
                    newtauptUP=taupt*1.006;
                    newtauptDOWN=taupt*0.994;
                }
                else {
                    if (tauDM!=0){
                        tauUp.SetPtEtaPhiM(taupt*1.01,taueta,tauphi,tauM*1.01);
                        tauDown.SetPtEtaPhiM(taupt*0.990,taueta,tauphi,tauM*0.990);
                    }
                    else {
                        tauUp.SetPtEtaPhiM(taupt*1.01,taueta,tauphi,0.13957);
                        tauDown.SetPtEtaPhiM(taupt*0.990,taueta,tauphi,0.13957);
                    } 
                    newtauptUP=taupt*1.010;
                    newtauptDOWN=taupt*0.990;
                }

                m_visUP=(tauUp+l).M();
                m_visDOWN=(tauDown+l).M();

                //std::cout<<" M_vis: "<<m_vis<<" m_visUp: "<<m_visUP<<" m_visDown: "<<m_visDOWN<<std::endl;

                newBranch1->Fill();
                newBranch2->Fill();
                newBranch3->Fill();
                newBranch4->Fill();
                newBranch5->Fill();
                newBranch6->Fill();
            }
            t->Write("",TObject::kOverwrite);
        }//end else if object A
    }//end while key
}//end read directory
