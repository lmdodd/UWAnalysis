{
   gROOT->ProcessLine(".L ../ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   //makeLTauStack(TString name,TString file,TString dir,int s,TString labelX,TString units = "GeV",bool left=false,TString channel = "",TString year = "2012",bool log = false,bool dndm=false,bool doRatio = false,true)
   //makeLTauStackPF("~/www/ztt/ETau/25ns_FullSelection/eleTau/MSSM8TeV/X/eleTau_highestJetEta","eleTauPlots/MSSM/eleTau_highestJetEta.root","eleTau_X",1,"Jet_{1} #eta","",true,"#tau_{#ele}#tau_{h}","2012",false,true,1,1,1,1,1,1,1,1,false,true);

//}
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt_sv","datacards/htt_et.inputs-mssm-13TeV-m_vis.root","et_inclusive",3,"mt_sv","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt_sv_nbt","datacards/htt_et.inputs-mssm-13TeV-m_vis.root","et_nobtag",3,"mt_sv","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/ETau/25ns_FullSelection/eleTau_mt_sv_bt","datacards/htt_et.inputs-mssm-13TeV-m_vis.root","et_btag",3,"mt_sv","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
}


