from WMCore.Configuration import Configuration
config = Configuration()
config.section_("General")
config.General.requestName   = 'Z-ZA-EWK-1'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.inputFiles = ['Summer16_23Sep2016V3_MC_L1FastJet_AK4PFchs.txt','Summer16_23Sep2016V3_MC_L2Relative_AK4PFchs.txt','Summer16_23Sep2016V3_MC_L3Absolute_AK4PFchs.txt','Summer16_23Sep2016V3_MC_L1FastJet_AK4PFpuppi.txt','Summer16_23Sep2016V3_MC_L2Relative_AK4PFpuppi.txt','Summer16_23Sep2016V3_MC_L3Absolute_AK4PFpuppi.txt']
# Name of the CMSSW configuration file
config.JobType.psetName    = 'Zanalysis_sig_JERS_nolepcorrection.py'
config.JobType.allowUndistributedCMSSW = True

config.section_("Data")
config.Data.inputDataset = '/LLAJJ_EWK_MLL-50_MJJ-120_13TeV-madgraph-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = -1
config.Data.publication = False
config.Data.outputDatasetTag = 'Z-ZA-EWK-1'

config.section_("Site")
#config.Site.storageSite = 'T2_CH_CERN'
config.Site.storageSite = 'T3_US_FNALLPC'


