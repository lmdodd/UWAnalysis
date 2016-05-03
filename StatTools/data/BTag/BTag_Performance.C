{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

//makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString json = "Golden",bool log = false,bool dndm=false,bool doRatio = false)
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_njets","eleTauPlots_BTag/eleTau_njets.root","et_inclusive",3," njets","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_nbtag","eleTauPlots_BTag/eleTau_nbtag.root","et_inclusive",3," nbtag","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_NBtagPD","eleTauPlots_BTag/eleTau_NBtagPD.root","et_inclusive",3," NBtagPD","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_NBtagPDUp","eleTauPlots_BTag/eleTau_NBtagPDUp.root","et_inclusive",3," NBtagPDUp","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_NBtagPDDown","eleTauPlots_BTag/eleTau_NBtagPDDown.root","et_inclusive",3," NBtagPDDown","GeV",false,"#tau_{e}#tau_{h}","Golden",true,false,true);

   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_njets","muTauPlots_BTag/muTau_njets.root","mt_inclusive",3," njets","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_nbtag","muTauPlots_BTag/muTau_nbtag.root","mt_inclusive",3," nbtag","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_NBtagPD","muTauPlots_BTag/muTau_NBtagPD.root","mt_inclusive",3," NBtagPD","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_NBtagPDUp","muTauPlots_BTag/muTau_NBtagPDUp.root","mt_inclusive",3," NBtagPDUp","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_NBtagPDDown","muTauPlots_BTag/muTau_NBtagPDDown.root","mt_inclusive",3," NBtagPDDown","GeV",false,"#tau_{#mu}#tau_{h}","Golden",true,false,true);



}


