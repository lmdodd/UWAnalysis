{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLphi_1","diMuonMC/muTau_LLphi_1.root","mt_inclusive",0,"#mu #phi","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLphi_2","diMuonMC/muTau_LLphi_2.root","mt_inclusive",0,"#mu #phi","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLeta_1","diMuonMC/muTau_LLeta_1.root","mt_inclusive",0,"#mu #eta","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLeta_2","diMuonMC/muTau_LLeta_2.root","mt_inclusive",0,"#mu #eta","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLpt_1","diMuonMC/muTau_LLpt_1.root","mt_inclusive",0,"#mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLpt_2","diMuonMC/muTau_LLpt_2.root","mt_inclusive",0,"#mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DiMuons/muTau_LLmass","diMuonMC/muTau_LLmass.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

}
