from WMCore.Configuration import Configuration
config = Configuration()
config.section_("General")
config.General.requestName   = 'Z-ST-tbarw-1'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.inputFiles = ['Autumn18_V8_MC_L1FastJet_AK4PFchs.txt','Autumn18_V8_MC_L2Relative_AK4PFchs.txt','Autumn18_V8_MC_L3Absolute_AK4PFchs.txt','Autumn18_V8_MC_L1FastJet_AK4PFPuppi.txt','Autumn18_V8_MC_L2Relative_AK4PFPuppi.txt','Autumn18_V8_MC_L3Absolute_AK4PFPuppi.txt']
# Name of the CMSSW configuration file
config.JobType.psetName    = 'Zanalysis.py'
config.JobType.allowUndistributedCMSSW = True

config.section_("Data")
config.Data.inputDataset ='/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = -1
config.Data.publication = False
config.Data.outputDatasetTag = 'Z-ST-tbarw-1'

config.section_("Site")
#config.Site.storageSite = 'T2_CN_Beijing'
config.Site.storageSite = 'T3_US_FNALLPC'


