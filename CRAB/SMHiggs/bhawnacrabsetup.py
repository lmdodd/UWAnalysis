from WMCore.Configuration import Configuration
config = Configuration()
#General                                                                                                                                                                           
config.section_('General')
config.General.requestName = 'job_jetht_rereo_2016G_v1'
config.General.workArea = 'crab_projects_ntuples_2016'
config.General.transferLogs = True
#JobType                                                                                                                                                                           
config.section_('JobType')
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'run_data_80X.py'
config.JobType.outputFiles = ['ggtree_data.root']
config.JobType.inputFiles = ['Spring16_25nsV6_DATA.db','Spring16_25nsV6_DATA_L2Relative_AK8PFchs.txt','Spring16_25nsV6_DATA_L3Absolute_AK8PFchs.txt','Spring16_25nsV6_DATA_L2L3Residual_AK8PFchs.txt'] 
#Data                                                                                                                                                                              
config.section_('Data')
config.Data.inputDataset = '/JetHT/Run2016G-23Sep2016-v1/MINIAOD'
#config.Data.inputDataset = '/DoubleMuon/Run2016D-PromptReco-v2/MINIAOD'
#config.Data.inputDataset = '/SingleElectron/Run2016G-PromptReco-v1/MINIAOD'
#config.Data.inputDataset = '/DoubleEG/Run2016B-PromptReco-v2/MINIAOD'
#config.Data.inputDataset = '/JetHT/Run2016G-PromptReco-v1/MINIAOD'
#config.Data.inputDBS = 'global'                                                                                                                                                   
#config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-275783_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt'
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 15
config.Data.publication = False
config.Data.totalUnits =  -1
#config.Data.ignoreLocality = True                                                                                                                                                 
config.Data.outLFNDirBase  ='/store/user/gomber/2016rereconutples/JetHt_Rereco_2016G_v1'
#User                                                                                                                                                                              
config.section_('User')
#Site                                                                                                                                                                              
config.section_('Site')
config.Site.storageSite = 'T2_US_Wisconsin'
