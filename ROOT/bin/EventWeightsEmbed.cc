#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"
#include <iostream>

using std::cout;
using std::endl;

void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev); 


int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("sumHistoName",optutl::CommandLineParser::kString,"Sum Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);

   
   parser.parseArguments (argc, argv);
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   
   
   readdir(f,parser,evGen);

   f->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev) 
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
		  readdir(subdir,parser,ev);
		  dirsav->cd();
	  }
	  else if(obj->IsA()->InheritsFrom(TTree::Class())) {
		  float weight1; 
		  float weight2; 

		  TTree *t = (TTree*)obj;
		  TBranch *newBranch2 = t->Branch("m_vis_up",&weight1,"m_vis_up/F");
		  TBranch *newBranch3 = t->Branch("m_vis_down",&weight2,"m_vis_down/F");

		  float tauPt=0;
		  t->SetBranchAddress("pt_2",&tauPt); //genPy



		  printf("Found tree -> weighting\n");
		  for(Int_t i=0;i<t->GetEntries();++i)
		  {
			  t->GetEntry(i);
			  weight = parser.doubleValue("weight")/(ev);
              weighttau = 0.929+0.0001702*tauPt;
              weightpth = 0.919+0.0010055*ptH;
              weightmjj = 1.026+0.000066*JJ;
			  newBranch->Fill();
			  newBranch2->Fill();
			  newBranch3->Fill();
			  newBranch4->Fill();
		  }
		  t->Write("",TObject::kOverwrite);
	  }//end else if object A
  }//end while key
}//end read directory
