{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2016.C");
   //gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makeTauMassPlot.C");

//makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString json = "FuckMuons",bool log = false,bool dndm=false,bool doRatio = false)

   makeLTauStack("~/www/ztt/2016/MuTau/JanNPVCheck/muTau_tauDecayMode","muTauPlotsDM/muTau_tauDecayMode.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,false);
   makeLTauStack("~/www/ztt/2016/MuTau/JanNPVCheck/muTau_tauDecayMode_10","muTauPlotsDM/muTau_tauDecayMode_10.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/JanNPVCheck/muTau_tauDecayMode_15","muTauPlotsDM/muTau_tauDecayMode_15.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/JanNPVCheck/muTau_tauDecayMode_20","muTauPlotsDM/muTau_tauDecayMode_20.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/JanNPVCheck/muTau_tauDecayMode_25","muTauPlotsDM/muTau_tauDecayMode_25.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);
   makeLTauStack("~/www/ztt/2016/MuTau/JanNPVCheck/muTau_tauDecayMode_30","muTauPlotsDM/muTau_tauDecayMode_30.root","mt_inclusive",0,"#tau decay mode","",false,"#tau_{#mu}#tau_{h}","FuckMuons",false,false,true);

}
