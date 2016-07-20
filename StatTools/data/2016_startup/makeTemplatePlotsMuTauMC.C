{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_m_vis","muTauPlotsMC/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_mt_1","muTauPlotsMC/muTau_mt_1.root","mt_inclusive",0,"m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_eta_1","muTauPlotsMC/muTau_eta_1.root","mt_inclusive",0,"#eta_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_npv","muTauPlotsMC/muTau_npv.root","mt_inclusive",0,"npv","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_OldMVAIso","muTauPlotsMC/muTau_OldMVAIso.root","mt_inclusive",0,"Raw MVAIsolation","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_tauIso","muTauPlotsMC/muTau_tauIso.root","mt_inclusive",0,"Raw Tau Isolation","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_phi_1","muTauPlotsMC/muTau_phi_1.root","mt_inclusive",0,"#mu #phi","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_phi_2","muTauPlotsMC/muTau_phi_2.root","mt_inclusive",0,"#tau #phi","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_mt_2","muTauPlotsMC/muTau_mt_2.root","mt_inclusive",0,"#mu +MET m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_mt","muTauPlotsMC/muTau_mt.root","mt_inclusive",0,"Total m_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_m_vis","muTauPlotsMC/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_m_vis_nocut","muTauPlotsMC/muTau_m_vis_nocut.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_iso_1","muTauPlotsMC/muTau_iso_1.root","mt_inclusive",0,"Isolation #mu DR=0.3","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_met","muTauPlotsMC/muTau_met.root","mt_inclusive",0,"ME_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_pt_1","muTauPlotsMC/muTau_pt_1.root","mt_inclusive",0,"#mu P_{T} ","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_genVisPt1","muTauPlotsMC/muTau_genVisPt1.root","mt_inclusive",0,"Gen Visible #mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_pt_2","muTauPlotsMC/muTau_pt_2.root","mt_inclusive",0,"#tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_genVisPt2","muTauPlotsMC/muTau_genVisPt2.root","mt_inclusive",0,"Gen Visible #tau P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_eta_2","muTauPlotsMC/muTau_eta_2.root","mt_inclusive",0,"#eta_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_m_vis","muTauPlotsMC/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_pt","muTauPlotsMC/muTau_pt.root","mt_inclusive",0,"di-tau Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_q_1","muTauPlotsMC/muTau_q_1.root","mt_inclusive",0,"q_{#mu}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_q_2","muTauPlotsMC/muTau_q_2.root","mt_inclusive",0,"q_{#tau}","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_nCands","muTauPlotsMC/muTau_nCands.root","mt_inclusive",0,"nCands","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_tauDecayMode","muTauPlotsMC/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_m_2","muTauPlotsMC/muTau_m_2.root","mt_inclusive",0,"M_{#tau}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_mjj","muTauPlotsMC/muTau_mjj.root","mt_inclusive",0,"M_{JJ}","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_njetspt20","muTauPlotsMC/muTau_njetspt20.root","mt_inclusive",0,"Number Jets Pt>20","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_njets","muTauPlotsMC/muTau_njets.root","mt_inclusive",0,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   //makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_nbtag","muTauPlotsMC/muTau_nbtag.root","mt_inclusive",0,"Number Jets Pt>30","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_jeta_1","muTauPlotsMC/muTau_jeta_1.root","mt_inclusive",0,"Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_jeta_2","muTauPlotsMC/muTau_jeta_2.root","mt_inclusive",0,"Sub-Leading jet #eta","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_tauNIsoTracks","muTauPlotsMC/muTau_tauNIsoTracks.root","mt_inclusive",0,"Number Isolated Tracks","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_jpt_1","muTauPlotsMC/muTau_jpt_1.root","mt_inclusive",0,"Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/StraightMCYields/muTau_jpt_2","muTauPlotsMC/muTau_jpt_2.root","mt_inclusive",0,"Sub-Leading jet Pt","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

}
