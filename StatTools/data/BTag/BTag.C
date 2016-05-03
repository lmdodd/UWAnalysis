{
   gROOT->ProcessLine(".L ../../../../UWAnalysis/ROOT/macros/plotScripts/templatePlots/makePlot2015.C");

   makeLTauStack("~/www/ztt/25ns_BSystematics/btag_eleTau_m_vis_PDUp","eleTauPlots_BTag/eleTau_m_vis_Up.root","et_btag",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/btag_eleTau_m_vis_PDDown","eleTauPlots_BTag/eleTau_m_vis_Down.root","et_btag",3,"visible m_vis","GeV",false,"#tau_{e}#tau_{h}","Golden",false,false,true);


   makeLTauStack("~/www/ztt/25ns_BSystematics/btag_muTau_m_vis_PDUp","muTauPlots_BTag/muTau_m_vis_Up.root","mt_btag",3,"visible m_vis","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);
   makeLTauStack("~/www/ztt/25ns_BSystematics/btag_muTau_m_vis_PDDown","muTauPlots_BTag/muTau_m_vis_Down.root","mt_btag",3,"visible m_vis","GeV",false,"#tau_{#mu}#tau_{h}","Golden",false,false,true);



}


