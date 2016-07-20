{
   //gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makeTauMassPlot.C");
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makeTauDecayModePlot.C");
   //makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauMass","muTauPlotsDPS/muTau_m_2.root","mt_inclusive",0,"#tau mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   //makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauDecayMode","muTauPlotsDPS/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauDecayMode_NR","muTauPlotsDPS/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);

}

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)

   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauMass","muTauPlotsDPS/muTau_m_2.root","mt_inclusive",0,"#tau mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_m_vis","muTauPlotsDPS/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_m_vis_NR","muTauPlotsDPS/muTau_m_vis.root","mt_inclusive",0,"visible mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauMass","muTauPlotsDPS/muTau_m_2.root","mt_inclusive",0,"#tau mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauMAss_NR","muTauPlotsDPS/muTau_m_2.root","mt_inclusive",0,"#tau mass","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauDecayMode","muTauPlotsDPS/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/DPS/muTau_tauDecayMode_NR","muTauPlotsDPS/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","Golden",false,false,false);


}
