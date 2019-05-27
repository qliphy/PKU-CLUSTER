#! /bin/bash

exit_on_error() {
    result=$1
    code=$2
    message=$3

    if [ $1 != 0 ]; then
        echo $3
        exit $2
    fi
}

#### FRAMEWORK SANDBOX SETUP ####
# Load cmssw_setup function
source cmssw_setup.sh

# Setup CMSSW Base
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
source $VO_CMS_SW_DIR/cmsset_default.sh

# Download sandbox
sandbox_name="sandbox-CMSSW_7_1_30-fb41af7.tar.bz2"
wget --no-check-certificate --progress=bar "http://stash.osgconnect.net/+anying/${sandbox_name}" || exit_on_error $? 150 "Could not download sandbox."

# Setup framework from sandbox
cmssw_setup $sandbox_name || exit_on_error $? 151 "Could not unpack sandbox"
#### END OF FRAMEWORK SANDBOX SETUP ####

# Name my input channel
#channel_rootpath="$1"
#channel_name="$(basename $channel_rootpath)"

# Enter script directory
cd $CMSSW_BASE/src/myproject/python
export RIVET_REF_PATH=$PWD
#Download ROOTLogon to define plotting styles and load some libraries
#wget --no-check-certificate --progress=bar "http://stash.osgconnect.net/+khurtado/rootlogon.C" || exit_on_error $? 150 "Could not download rootlogon."

# Execute ROOT script
cmsenv
cmsRun SMP-RunIISummer15wmLHEGS-00183_1_cfg.py 
# Stage-out to FNAL EOS
# mydate=$(date +%Y_%m_%d_%k_%M)
# xrdcp -f "$channel_name.root" "root://cmseos.fnal.gov:1094//eos/uscms/store/user/kenai/xrootd_test/${channel_name}_${mydate}.root" 2>&1

# Clean up
cd -
mv $CMSSW_BASE/src/myproject/python/*.root .
rm $sandbox_name
