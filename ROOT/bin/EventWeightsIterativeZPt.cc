#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TMath.h"
#include "TFileMerger.h"



void readdir(TDirectory *dir,optutl::CommandLineParser parser,TH2D* hist); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);

   
   parser.parseArguments (argc, argv);
   
   
 
   TFile *fZpt    = new TFile("zpt_weights_2016_BtoH.root","UPDATE");
   TH2D* hZpt = 0;
   if(fZpt!=0 && fZpt->IsOpen()) {
     hZpt = (TH2D*)fZpt->Get("zptmass_histo");;
     printf("ENABLING Z WEIGHTING USING HISTOGRAM\n");
   }
   else{
     printf("ERROR!!! WEIGHT FILE NOT FOUND!!! EXITING!!!\n");
     return 0;
   }

   TFile *f0 = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");
   readdir(f0,parser,hZpt);
   f0->Close();

   if(fZpt!=0 && fZpt->IsOpen())
     fZpt->Close();


} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser, TH2D* hist) 
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
			readdir(subdir,parser,hist);
			dirsav->cd();
		}
		else if(obj->IsA()->InheritsFrom(TTree::Class())) {
			TTree *t = (TTree*)obj;
			float weight;
			float weightU;
			float weightD;
			float weight2;


			TBranch *newBranch = t->Branch("ZWEIGHT",&weight,"ZWEIGHT/F");
			TBranch *newBranchU = t->Branch("ZWEIGHTUp",&weightU,"ZWEIGHTUp/F");
			TBranch *newBranchD = t->Branch("ZWEIGHTDown",&weightD,"ZWEIGHTDown/F");
			TBranch *newBranch2 = t->Branch("highTauEffi",&weight2,"highTauEffi/F");
			float mLL=0;
			float genPx=0;
			float genPy=0;
			float genTauPt=0;
			float TauEta=0;
			t->SetBranchAddress("genMass",&mLL); //InvMass
			t->SetBranchAddress("genpX",&genPx); //genPx
			t->SetBranchAddress("genpY",&genPy); //genPy
			t->SetBranchAddress("genPt2",&genTauPt); //genPy
			t->SetBranchAddress("eta_2",&TauEta); //genPy


			printf("Found tree -> weighting\n");
			for(Int_t i=0;i<t->GetEntries();++i){
				t->GetEntry(i);
				float genPt = TMath::Sqrt(genPx*genPx+genPy*genPy);
				//printf("Found genPt -> %f,\n",genPt);
                weight =  1.0;
                weight = hist->GetBinContent(hist->GetXaxis()->FindBin(mLL),hist->GetYaxis()->FindBin(genPt));
                weightU= 1+1.10*(weight-1);
                weightD= 1+0.90*(weight-1);
				//printf("Found Zweight -> %f,\n",weight);
				weight2 = 0.2 * genTauPt/1000.; 

				newBranch->Fill();
				newBranchU->Fill();
				newBranchD->Fill();
				newBranch2->Fill();
			}
			t->Write("",TObject::kOverwrite);
		}



	}

}
