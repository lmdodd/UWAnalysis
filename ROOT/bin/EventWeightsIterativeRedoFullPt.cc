#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include <iostream>

#include "HTT-utilities/RecoilCorrections/interface/RecoilCorrector.h"

using std::cout;
using std::endl;


void readdir(TDirectory *dir,optutl::CommandLineParser parser,  char TreeToUse[], int isWJets);


int main (int argc, char* argv[]) 
{
    optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");

    char TreeToUse[80]="first" ;

    parser.addOption("isWJets",optutl::CommandLineParser::kDouble,"isWJets",0.0);
    parser.parseArguments (argc, argv);

    std::cout << "EXTRA COMMANDS:"
        << "\n --- isWJets: " << parser.doubleValue("isWJets")
        << std::endl;


    TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   

    readdir(f,parser, TreeToUse, parser.doubleValue("isWJets"));

    f->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,char TreeToUse[], int isWJets)
{

    std::string recoilFileName = "HTT-utilities/RecoilCorrections/data/TypeI-PFMet_Run2016BtoH.root";

    RecoilCorrector* recoilCorrector = new RecoilCorrector(recoilFileName);

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
            readdir(subdir,parser, TreeToUse, parser.doubleValue("isWJets"));
            dirsav->cd();
        }
        else if(obj->IsA()->InheritsFrom(TTree::Class())) {

            float pttot=0.0;
            float pttotUP=0.0;
            float pttotDOWN=0.0;
            float pttotCESUP=0.0;
            float pttotCESDOWN=0.0;
            float pttotUESUP=0.0;
            float pttotUESDOWN=0.0;

            float pdgid=0.0;
            float lpt=0.0;
            float leta=0.0;
            float lphi=0.0;
            float lM=0.0;

            float taupt=0.0;
            float tauptUP=0.0;
            float tauptDOWN=0.0;
            float tauptCorr=0.0;
            float taueta=0.0;
            float tauphi=0.0;

            float pfmet;
            float pfmetphi;
            float pfmetEnUp;
            float pfmetphiEnUp;
            float pfmetEnDown;
            float pfmetphiEnDown;
            float pfmetJetUp;
            float pfmetphiJetUp;
            float pfmetJetDown;
            float pfmetphiJetDown;

            float tauDM=0.0;
            float tauM=0.0;
            float gen_match=0;


            int njets;
            float  genPx=-999.    , // generator Z/W/Higgs px (float)
                   genPy =-999.   , // generator Z/W/Higgs py (float)
                   visPx =-999.   , // generator visible Z/W/Higgs px (float)
                   visPy =-999.   ;

            double measuredMETx = 0.;
            double measuredMETy = 0.;
            double measuredMETEnUpx = 0.;
            double measuredMETEnDownx = 0.;
            double measuredMETJetUpx = 0.;
            double measuredMETJetDownx = 0.;
            double measuredMETEnUpy = 0.;
            double measuredMETEnDowny = 0.;
            double measuredMETJetUpy = 0.;
            double measuredMETJetDowny = 0.;

            float metcorr_ex = -10; // corrected met px (float)
            float metcorr_ey = -10;  // corrected met py (float)

            float metcorr_ex_UESUP = -10; // corrected met px (float)
            float metcorr_ey_UESUP = -10;  // corrected met py (float)

            float metcorr_ex_UESDOWN = -10; // corrected met px (float)
            float metcorr_ey_UESDOWN = -10;  // corrected met py (float)

            float metcorr_ex_CESUP = -10; // corrected met px (float)
            float metcorr_ey_CESUP = -10;  // corrected met py (float)

            float metcorr_ex_CESDOWN = -10; // corrected met px (float)
            float metcorr_ey_CESDOWN = -10;  // corrected met py (float)

            float fullPt=0.0;

            TLorentzVector tauold; 
            TLorentzVector tau; 
            TLorentzVector tauUp; 
            TLorentzVector tauDown; 
            TLorentzVector deltatau; 
            TLorentzVector deltatauUp; 
            TLorentzVector deltatauDown; 
            TLorentzVector l; 

            TLorentzVector met; 
            TLorentzVector mettauup; 
            TLorentzVector mettaudown; 
            TLorentzVector metuesup; 
            TLorentzVector metuesdown; 
            TLorentzVector metcesup; 
            TLorentzVector metcesdown; 

            TTree *t = (TTree*)obj;

            TBranch *newBranch1 = t->Branch("pttot_REDO",&pttot,"pttot_REDO/F");
            TBranch *newBranch2 = t->Branch("pttot_UP",&pttotUP,"pttot_UP/F");
            TBranch *newBranch3 = t->Branch("pttot_DOWN",&pttotDOWN,"pttot_DOWN/F");
            TBranch *newBranch4 = t->Branch("pttot_CES_UP",&pttotCESUP,"pttot_CES_UP/F");
            TBranch *newBranch5 = t->Branch("pttot_CES_DOWN",&pttotCESDOWN,"pttot_CES_DOWN/F");
            TBranch *newBranch6 = t->Branch("pttot_UES_UP",&pttotUESUP,"pttot_UES_UP/F");
            TBranch *newBranch7 = t->Branch("pttot_UES_DOWN",&pttotUESDOWN,"pttot_UES_DOWN/F");

            t->SetBranchAddress("fullPt",&fullPt);
            t->SetBranchAddress("pt_2",&taupt);
            t->SetBranchAddress("taupt",&tauptCorr);
            t->SetBranchAddress("taupt_UP",&tauptUP);
            t->SetBranchAddress("taupt_DOWN",&tauptDOWN);
            t->SetBranchAddress("eta_2",&taueta);
            t->SetBranchAddress("phi_2",&tauphi);
            t->SetBranchAddress("m_2",&tauM);

            t->SetBranchAddress("pt_1",&lpt);
            t->SetBranchAddress("eta_1",&leta);
            t->SetBranchAddress("phi_1",&lphi);
            t->SetBranchAddress("pdg1",&pdgid);

            t->SetBranchAddress("tauDecayMode",&tauDM);
            t->SetBranchAddress("gen_match_2",&gen_match);

            t->SetBranchAddress("njets", &njets);

            t->SetBranchAddress("genpX",&genPx);
            t->SetBranchAddress("genpY",&genPy);
            t->SetBranchAddress("vispX",&visPx);
            t->SetBranchAddress("vispY",&visPy);


            t->SetBranchAddress("pfmet",&pfmet);
            t->SetBranchAddress("pfmetphi",&pfmetphi);
            t->SetBranchAddress("pfmetEnUp",&pfmetEnUp);
            t->SetBranchAddress("pfmetphiEnUp",&pfmetphiEnUp);
            t->SetBranchAddress("pfmetEnDown",&pfmetEnDown);
            t->SetBranchAddress("pfmetphiEnDown",&pfmetphiEnDown);
            t->SetBranchAddress("pfmetJetUp",&pfmetJetUp);
            t->SetBranchAddress("pfmetphiJetUp",&pfmetphiJetUp);
            t->SetBranchAddress("pfmetJetDown",&pfmetJetDown);
            t->SetBranchAddress("pfmetphiJetDown",&pfmetphiJetDown);

            printf("Found tree -> weighting\n");
            std::cout<<"KeyName "<<keyname<<" or key->GetName() "<<key->GetName()<<std::endl;


            for(Int_t i=0;i<t->GetEntries();++i)
            {
                t->GetEntry(i);

                int recoilNJets;
                if(isWJets) {
                    recoilNJets = njets + 1;
                    //std::cout << " - njets: " << njets << " recoilNJets: " << recoilNJets << std::endl;
                }
                else recoilNJets = njets;

                measuredMETx = pfmet*TMath::Cos(pfmetphi);
                measuredMETy = pfmet*TMath::Sin(pfmetphi);
                measuredMETEnUpx = pfmetEnUp*TMath::Cos(pfmetphiEnUp);
                measuredMETEnUpy = pfmetEnUp*TMath::Sin(pfmetphiEnUp);
                measuredMETEnDownx = pfmetEnDown*TMath::Cos(pfmetphiEnDown);
                measuredMETEnDowny = pfmetEnDown*TMath::Sin(pfmetphiEnDown);
                measuredMETJetUpx = pfmetJetUp*TMath::Cos(pfmetphiJetUp);
                measuredMETJetUpy = pfmetJetUp*TMath::Sin(pfmetphiJetUp);
                measuredMETJetDownx = pfmetJetDown*TMath::Cos(pfmetphiJetDown);
                measuredMETJetDowny = pfmetJetDown*TMath::Sin(pfmetphiJetDown);

                recoilCorrector->CorrectByMeanResolution( // This method is faster (Alexei)
                        measuredMETx, // uncorrected mva met px (float)
                        measuredMETy, // uncorrected mva met py (float)
                        genPx, // generator Z/W/Higgs px (float)
                        genPy, // generator Z/W/Higgs py (float)
                        visPx, // generator visible Z/W/Higgs px (float)
                        visPy, // generator visible Z/W/Higgs py (float)
                        recoilNJets,  // number of jets (hadronic jet multiplicity) (int)
                        metcorr_ex, // corrected met px (float)
                        metcorr_ey  // corrected met py (float)
                        );
                //UES UP
                recoilCorrector->CorrectByMeanResolution( // This method is faster (Alexei)
                        measuredMETEnUpx, // uncorrected mva met px (float)
                        measuredMETEnUpy, // uncorrected mva met py (float)
                        genPx, // generator Z/W/Higgs px (float)
                        genPy, // generator Z/W/Higgs py (float)
                        visPx, // generator visible Z/W/Higgs px (float)
                        visPy, // generator visible Z/W/Higgs py (float)
                        recoilNJets,  // number of jets (hadronic jet multiplicity) (int)
                        metcorr_ex_UESUP, // corrected met px (float)
                        metcorr_ey_UESUP  // corrected met py (float)
                        );
                recoilCorrector->CorrectByMeanResolution( // This method is faster (Alexei)
                        measuredMETEnDownx, // uncorrected mva met px (float)
                        measuredMETEnDowny, // uncorrected mva met py (float)
                        genPx, // generator Z/W/Higgs px (float)
                        genPy, // generator Z/W/Higgs py (float)
                        visPx, // generator visible Z/W/Higgs px (float)
                        visPy, // generator visible Z/W/Higgs py (float)
                        recoilNJets,  // number of jets (hadronic jet multiplicity) (int)
                        metcorr_ex_UESDOWN, // corrected met px (float)
                        metcorr_ey_UESDOWN  // corrected met py (float)
                        );
                //CES UP
                recoilCorrector->CorrectByMeanResolution( // This method is faster (Alexei)
                        measuredMETJetUpx, // uncorrected mva met px (float)
                        measuredMETJetUpy, // uncorrected mva met py (float)
                        genPx, // generator Z/W/Higgs px (float)
                        genPy, // generator Z/W/Higgs py (float)
                        visPx, // generator visible Z/W/Higgs px (float)
                        visPy, // generator visible Z/W/Higgs py (float)
                        recoilNJets,  // number of jets (hadronic jet multiplicity) (int)
                        metcorr_ex_CESUP, // corrected met px (float)
                        metcorr_ey_CESUP  // corrected met py (float)
                        );
                recoilCorrector->CorrectByMeanResolution( // This method is faster (Alexei)
                        measuredMETJetDownx, // uncorrected mva met px (float)
                        measuredMETJetDowny, // uncorrected mva met py (float)
                        genPx, // generator Z/W/Higgs px (float)
                        genPy, // generator Z/W/Higgs py (float)
                        visPx, // generator visible Z/W/Higgs px (float)
                        visPy, // generator visible Z/W/Higgs py (float)
                        recoilNJets,  // number of jets (hadronic jet multiplicity) (int)
                        metcorr_ex_CESDOWN, // corrected met px (float)
                        metcorr_ey_CESDOWN  // corrected met py (float)
                        );



                pttot=0;
                pttotUP=0;
                pttotDOWN=0;
                pttotUESUP=0;
                pttotUESDOWN=0;
                pttotCESUP=0;
                pttotCESDOWN=0;
                lM=0;

                if (abs(pdgid)==11){
                    lM=0.00051100;
                }
                else{ 
                    //std::cout<<"muon mass"<<std::endl;
                    lM=0.105658;
                }

                //std::cout<<"L 4 vector: "<<lpt<<","<<leta<<","<<lphi<<","<<lM <<std::endl;
                l.SetPtEtaPhiM(lpt,leta,lphi,lM); 
                tauold.SetPtEtaPhiM(taupt,taueta,tauphi,tauM);
                tau.SetPtEtaPhiM(tauptCorr,taueta,tauphi,tauM);
                tauUp.SetPtEtaPhiM(tauptUP,taueta,tauphi,tauM);
                tauDown.SetPtEtaPhiM(tauptDOWN,taueta,tauphi,tauM);
                deltatau = tau -tauold;
                deltatauUp = tauUp -tau;
                deltatauDown = tauDown -tau;

                float dx= deltatau.Px();
                float dy= deltatau.Py();


                metcorr_ex = metcorr_ex-dx;
                metcorr_ey = metcorr_ey-dx;
                metcorr_ex_UESUP = metcorr_ex_UESUP-dx;
                metcorr_ex_UESDOWN = metcorr_ex_UESDOWN-dx;
                metcorr_ex_CESUP = metcorr_ex_CESUP-dx;
                metcorr_ex_CESDOWN = metcorr_ex_CESDOWN-dx;
                metcorr_ey_UESUP = metcorr_ey_UESUP-dy;
                metcorr_ey_UESDOWN = metcorr_ey_UESDOWN-dy;
                metcorr_ey_CESUP = metcorr_ey_CESUP-dy;
                metcorr_ey_CESDOWN = metcorr_ey_CESDOWN-dy;

                float metcor = TMath::Sqrt( metcorr_ex*metcorr_ex + metcorr_ey*metcorr_ey);

                float metcorUESUP = TMath::Sqrt( metcorr_ex_UESUP*metcorr_ex_UESUP + metcorr_ey_UESUP*metcorr_ey_UESUP);
                float metcorUESDOWN = TMath::Sqrt( metcorr_ex_UESDOWN*metcorr_ex_UESDOWN + metcorr_ey_UESDOWN*metcorr_ey_UESDOWN);
                float metcorCESUP = TMath::Sqrt( metcorr_ex_CESUP*metcorr_ex_CESUP + metcorr_ey_CESUP*metcorr_ey_CESUP);
                float metcorCESDOWN = TMath::Sqrt( metcorr_ex_CESDOWN*metcorr_ex_CESDOWN + metcorr_ey_CESDOWN*metcorr_ey_CESDOWN);

                float metcorphi = TMath::ATan2(metcorr_ey,metcorr_ex);

                float metcorUESUPphi = TMath::ATan2(metcorr_ey_UESUP,metcorr_ex_UESUP);
                float metcorUESDOWNphi =TMath::ATan2(metcorr_ey_UESDOWN,metcorr_ex_UESDOWN);; 
                float metcorCESUPphi = TMath::ATan2(metcorr_ey_CESUP,metcorr_ex_CESUP);
                float metcorCESDOWNphi = TMath::ATan2(metcorr_ey_CESDOWN,metcorr_ex_CESDOWN);

                met.SetPtEtaPhiM(metcor,0,metcorphi,0);
                mettauup = met - deltatauUp;
                mettaudown = met - deltatauDown;

                metuesup.SetPtEtaPhiM(metcorUESUP,0,metcorUESUPphi,0);
                metuesdown.SetPtEtaPhiM(metcorUESDOWN,0,metcorUESDOWNphi,0);

                metcesup.SetPtEtaPhiM(metcorCESUP,0,metcorCESUPphi,0);
                metcesdown.SetPtEtaPhiM(metcorCESDOWN,0,metcorCESDOWNphi,0);


                pttot=(tau+l+met).Pt();
                pttotUP=(tau+l+mettauup).Pt();
                pttotDOWN=(tau+l+mettaudown).Pt();
                pttotUESUP=(tau+l+metuesup).Pt();
                pttotUESDOWN=(tau+l+metuesdown).Pt();
                pttotCESUP=(tau+l+metcesup).Pt();
                pttotCESDOWN=(tau+l+metcesdown).Pt();

                //std::cout<<" FullPt: "<<fullPt<<"\t PtRedo: "<<pttot<<" \t pttotUESUp: "<<pttotUESUP<<" \t pttotUESDown: "<<pttotUESDOWN
                //   <<" \t pttotCESUP: "<<pttotCESUP<<" \t pttotCESDOWN: "<<pttotCESDOWN<<std::endl;

                newBranch1->Fill();
                newBranch2->Fill();
                newBranch3->Fill();
                newBranch4->Fill();
                newBranch5->Fill();
                newBranch6->Fill();
                newBranch7->Fill();
            }
            dir->cd();
            t->Write("",TObject::kOverwrite);

        }//end else if object A
    }//end while key
}//end read directory
