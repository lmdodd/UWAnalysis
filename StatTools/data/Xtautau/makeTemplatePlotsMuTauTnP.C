{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //WSideband Method
   //2016BKGD Method
   makeLTauStack("~/www/ztt/2016/MuTau/tnp/muTau_muonEta_afterTnP","muTauPlotsTnP/muTau_eta_1.root","mt_inclusive",0,"#mu #eta","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/tnp/muTau_muonEta_beforeTnP","muTauPlotsTnP/muTau_eta_1_before.root","mt_inclusive",0,"#mu #eta","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/tnp/muTau_pt_1_afterTnP","muTauPlotsTnP/muTau_pt_1.root","mt_inclusive",0,"#mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/tnp/muTau_pt_1_beforeTnP","muTauPlotsTnP/muTau_pt_1_before.root","mt_inclusive",0,"#mu P_{T}","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/tnp/muTau_m_vis_afterTnP","muTauPlotsTnP/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/tnp/muTau_m_vis_beforeTnP","muTauPlotsTnP/muTau_m_vis_before.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);


}

