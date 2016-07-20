{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");

//makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString json = "FuckMuons",bool log = false,bool dndm=false,bool doRatio = false)

   //makeLTauStack("~/www/Research/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_npv","muTauPlots/muTau_npv.root","mt_inclusive",0,"npv","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_OldMVAIso","muTauPlots/muTau_OldMVAIso.root","mt_inclusive",0,"Raw MVAIsolation","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_tauIso","muTauPlots/muTau_tauIso.root","mt_inclusive",0,"Raw Tau Isolation","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);

   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_mt_1","muTauPlots/muTau_mt_1.root","mt_inclusive",0,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_phi_1","muTauPlots/muTau_phi_1.root","mt_inclusive",0,"#mu #phi","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_phi_2","muTauPlots/muTau_phi_2.root","mt_inclusive",0,"#tau #phi","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_mt_2","muTauPlots/muTau_mt_2.root","mt_inclusive",0,"#mu +MET m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_mt","muTauPlots/muTau_mt.root","mt_inclusive",0,"Total m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_m_vis_nocut","muTauPlots/muTau_m_vis_nocut.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_iso_1","muTauPlots/muTau_iso_1.root","mt_inclusive",0,"Isolation #mu DR=0.3","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_met","muTauPlots/muTau_met.root","mt_inclusive",0,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_pt_1","muTauPlots/muTau_pt_1.root","mt_inclusive",0,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_genVisPt1","muTauPlots/muTau_genVisPt1.root","mt_inclusive",0,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_pt_2","muTauPlots/muTau_pt_2.root","mt_inclusive",0,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_genVisPt2","muTauPlots/muTau_genVisPt2.root","mt_inclusive",0,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_eta_1","muTauPlots/muTau_eta_1.root","mt_inclusive",0,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_eta_2","muTauPlots/muTau_eta_2.root","mt_inclusive",0,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_m_vis","muTauPlots/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_pt","muTauPlots/muTau_pt.root","mt_inclusive",0,"di-tau Pt","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_q_1","muTauPlots/muTau_q_1.root","mt_inclusive",0,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_q_2","muTauPlots/muTau_q_2.root","mt_inclusive",0,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);

   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_nCands","muTauPlots/muTau_nCands.root","mt_inclusive",0,"nCands","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_tauDecayMode","muTauPlots/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_m_2","muTauPlots/muTau_m_2.root","mt_inclusive",0,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_mjj","muTauPlots/muTau_mjj.root","mt_inclusive",0,"M_{JJ}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_njetspt20","muTauPlots/muTau_njetspt20.root","mt_inclusive",0,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_njets","muTauPlots/muTau_njets.root","mt_inclusive",0,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_nbtag","muTauPlots/muTau_nbtag.root","mt_inclusive",0,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_jeta_1","muTauPlots/muTau_jeta_1.root","mt_inclusive",0,"Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_jeta_2","muTauPlots/muTau_jeta_2.root","mt_inclusive",0,"Sub-Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_tauNIsoTracks","muTauPlots/muTau_tauNIsoTracks.root","mt_inclusive",0,"Number Isolated Tracks","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);

   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_jpt_1","muTauPlots/muTau_jpt_1.root","mt_inclusive",0,"Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/HTT_BkgdMethod4/muTau_jpt_2","muTauPlots/muTau_jpt_2.root","mt_inclusive",0,"Sub-Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);

}
