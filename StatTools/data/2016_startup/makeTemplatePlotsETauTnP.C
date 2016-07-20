{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/2016/ETau/tnp/eleTau/MSSM8TeV/X/eleTau_highestJetEta","eleTauPlotsTnP/MSSM/eleTau_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
      makeLTauStack("~/www/ztt/2016/ETau/tnp/eleTau_m_vis","eleTauPlotsTnP/eleTau_m_vis.root","et_inclusive",0,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/ETau/tnp/eleTau_pt_1","eleTauPlotsTnP/eleTau_pt_1.root","et_inclusive",0,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/ETau/tnp/eleTau_eta_1","eleTauPlotsTnP/eleTau_eta_1.root","et_inclusive",0,"#eta_{e}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);

makeLTauStack("~/www/ztt/2016/ETau/tnp/eleTau_m_vis_before","eleTauPlotsTnP/eleTau_m_vis_beforeTnP.root","et_inclusive",0,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/ETau/tnp/eleTau_pt_1_before","eleTauPlotsTnP/eleTau_pt_1_beforeTnP.root","et_inclusive",0,"e P_{T} ","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/ETau/tnp/eleTau_eta_1_before","eleTauPlotsTnP/eleTau_eta_1_beforeTnP.root","et_inclusive",0,"#eta_{e}","",false,"#tau_{e}#tau_{h}","Golden",false,false,true);





}


