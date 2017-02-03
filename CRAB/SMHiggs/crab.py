from WMCore.Configuration import Configuration
from CRABClient.UserUtilities import config, getUsernameFromSiteDB


name = 'test_jan26_v3'
projectName = 'SM-HTT'


config = Configuration()
#General                                                                                                                                                                           
config.section_('General')
config.General.requestName = 'job_Embedded_rereco_2016B_v4'
config.General.workArea = '/cms/laura/crab_projects_emb_2016'
config.General.transferLogs = True
#JobType                                                                                                                                                                           
config.section_('JobType')
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'SUB-EMB.py'
#config.JobType.outputFiles = ['embedded.root']

# From Yuri
#use?
config.JobType.sendPythonFolder = True
config.JobType.maxMemoryMB = 4500

# Specify vo group
#config.User.voGroup = 'uscms'

#Data                                                                                                                                                                              
config.section_('Data')
config.Data.inputDataset = '/EmbeddingRun2016B/MuTauFinalState-imputSep16DoubleMu_mirror_miniAOD-v1/USER'
config.Data.inputDBS = 'phys03'                                                                                                                                                   
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 15
config.Data.publication = False
config.Data.totalUnits =  3
#config.Data.totalUnits =  -1
#config.Data.ignoreLocality = True                                                                                                                                                 
#config.Data.outLFNDirBase  ='/store/user/laura/2016_embedded/Embedded2016B'
config.Data.outLFNDirBase = '/store/user/%s/crab_%s/%s/' % (getUsernameFromSiteDB(), projectName, name)
#User                                                                                                                                                                              
config.section_('User')
#Site                                                                                                                     
config.section_('Site')
config.Site.storageSite = 'T2_US_Wisconsin'
