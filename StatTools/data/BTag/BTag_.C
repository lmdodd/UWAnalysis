{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_m_vis_datacard_btagSF","datacards/htt_et.inputs-mssm-13TeV-btagSF.root","et_btag",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_m_vis_datacard_nobtagSF","datacards/htt_et.inputs-mssm-13TeV-btagSF.root","et_nobtag",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_m_vis_datacard_btagSF","datacards/htt_mt.inputs-mssm-13TeV-btagSF.root","mt_btag",3,"visible m_vis","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_m_vis_datacard_nobtagSF","datacards/htt_mt.inputs-mssm-13TeV-btagSF.root","mt_nobtag",3,"visible m_vis","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);

 makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_m_vis_datacard_btagPD","datacards/htt_et.inputs-mssm-13TeV-btag.root","et_btag",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/eleTau_m_vis_datacard_nobtagPD","datacards/htt_et.inputs-mssm-13TeV-btag.root","et_nobtag",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_m_vis_datacard_btagPD","datacards/htt_mt.inputs-mssm-13TeV-btag.root","mt_btag",3,"visible m_vis","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/muTau_m_vis_datacard_nobtagPD","datacards/htt_mt.inputs-mssm-13TeV-btag.root","mt_nobtag",3,"visible m_vis","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);



}


