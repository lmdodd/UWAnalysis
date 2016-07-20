{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_m_vis","muTauPlotsTest20/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_m_vis_NR","muTauPlotsTest20/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_muonEta","muTauPlotsTest20/muTau_eta_1.root","mt_inclusive",0,"#mu #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_muonEta_NR","muTauPlotsTest20/muTau_eta_1.root","mt_inclusive",0,"#mu #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauMass","muTauPlotsTest20/muTau_m_2.root","mt_inclusive",0,"#tau mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauMAss_NR","muTauPlotsTest20/muTau_m_2.root","mt_inclusive",0,"#tau mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauDecayMode","muTauPlotsTest20/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauDecayMode_NR","muTauPlotsTest20/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);

   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauIso","muTauPlotsTest20/muTau_tauIso.root","mt_inclusive",0,"#tau Raw Cut-Based Iso","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauIso_LOG","muTauPlotsTest20/muTau_tauIso.root","mt_inclusive",0,"#tau Raw Cut-Based Iso","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauIso_NR","muTauPlotsTest20/muTau_tauIso.root","mt_inclusive",0,"#tau Raw Cut-Based Iso","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_tauIso_NR_LOG","muTauPlotsTest20/muTau_tauIso.root","mt_inclusive",0,"#tau Raw Cut-Based Iso","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_njetspt20","muTauPlotsTest20/muTau_njetspt20.root","mt_inclusive",0,"Number of Jets P_T>20","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_njetspt20_NR","muTauPlotsTest20/muTau_njetspt20.root","mt_inclusive",0,"Number of Jets P_T>20","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);


   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_OldMVAIso","muTauPlotsTest20/muTau_OldMVAIso.root","mt_inclusive",0,"#tau Raw MVA Iso","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_OldMVAIso_NR","muTauPlotsTest20/muTau_OldMVAIso.root","mt_inclusive",0,"#tau Raw MVA Iso","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);


   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_NPV","muTauPlotsTest20/muTau_npv.root","mt_inclusive",0,"npvs","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_NPV_NR","muTauPlotsTest20/muTau_npv.root","mt_inclusive",0,"npvs","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_mt_1","muTauPlotsTest20/muTau_mt_1.root","mt_inclusive",0,"M_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_mt_1_NR","muTauPlotsTest20/muTau_mt_1.root","mt_inclusive",0,"M_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_pt_1","muTauPlotsTest20/muTau_pt_1.root","mt_inclusive",0,"#mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_pt_1_NR","muTauPlotsTest20/muTau_pt_1.root","mt_inclusive",0,"#mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_pt_2","muTauPlotsTest20/muTau_pt_2.root","mt_inclusive",0,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_pt_2_NR","muTauPlotsTest20/muTau_pt_2.root","mt_inclusive",0,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_eta_2","muTauPlotsTest20/muTau_eta_2.root","mt_inclusive",0,"#tau #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_eta_2_NR","muTauPlotsTest20/muTau_eta_2.root","mt_inclusive",0,"#tau #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_phi_2","muTauPlotsTest20/muTau_phi_2.root","mt_inclusive",0,"#tau #phi","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_phi_2_NR","muTauPlotsTest20/muTau_phi_2.root","mt_inclusive",0,"#tau #phi","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_phi_1","muTauPlotsTest20/muTau_phi_1.root","mt_inclusive",0,"#mu #phi","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_phi_1_NR","muTauPlotsTest20/muTau_phi_1.root","mt_inclusive",0,"#mu #phi","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
 
   //makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_m_vis","muTauPlotsTest20/muTau_m_vis_notrigger.root","mt_inclusive",0,"visible mass(notrigger)","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/test/muTau_mLL","muTauPlotsTest20/muTau_LL_notrigger.root","mt_inclusive",0,"di Muon mass(notrigger)","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

}
