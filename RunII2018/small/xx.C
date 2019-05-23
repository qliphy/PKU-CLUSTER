#define xx_cxx
#include "L1_weight.C"
#include "xx.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "ele_channel_scale.C"
#include "muon_channel_scale.C"

using namespace std;
void xx::Loop(TString name)
{
//   In a ROOT session, you can do:
//      root> .L xx.C
//      root> xx t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();


   double lep1_phi_station2_tmp = 0;
   double lep2_phi_station2_tmp = 0;
     TFile * input13 = new TFile ("./puweight.root");//puweight.root
     TH1D* h13 = NULL;
     input13->GetObject("h2",h13);
     cout<<"open the file: puweight.root"<<endl;
   // for lep and photon scales
   // muon ID
   TFile * f_BF= TFile::Open("./SF/EfficienciesStudies_2018_rootfiles_RunABCD_SF_ID.root");
   TH2D* ID_BF=0;
   f_BF->GetObject("NUM_TightID_DEN_TrackerMuons_pt_abseta", ID_BF);
   cout<<"open the muon ID file: EfficienciesStudies_2018_rootfiles_RunABCD_SF_ID.root"<<endl;

   // muon iso
   TFile * f_iso_BF= TFile::Open("./SF/EfficienciesStudies_2018_rootfiles_RunABCD_SF_ISO.root");
   TH2D* iso_BF=0;
   f_iso_BF->GetObject("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta", iso_BF);
   cout<<"open the muon ISO file: EfficienciesStudies_2018_rootfiles_RunABCD_SF_ISO.root"<<endl;
   // ele id
   TFile * f= TFile::Open("./SF/2018_ElectronMedium.root");
   TH2F* ID=0;
   f->GetObject("EGamma_SF2D", ID);
   cout<<"open the ele ID file: 2018_ElectronMedium.root"<<endl;

   //ele reco
   TFile* Reco_egamma= TFile::Open("./SF/egammaEffi.txt_EGM2D_updatedAll.root");
   TH2F* Reco=0;
   Reco_egamma->GetObject("EGamma_SF2D", Reco);
   cout<<"open the ele RECO file: egammaEffi.txt_EGM2D_updatedAll.root"<<endl;

   //photon id
   TFile* ID_photon_file = TFile::Open("./SF/2018_PhotonsMedium.root");
   TH2F* ID_photon=0;
   ID_photon_file->GetObject("EGamma_SF2D", ID_photon);
   cout<<"open the photon ID file: 2018_PhotonsMedium.root"<<endl;
   // for lep and photon scales

      /*ele1_id_scale=-1;
      ele2_id_scale=-1;
      ele1_reco_scale=-1;
      ele2_reco_scale=-1;
      muon1_id_scale=-1;
      muon2_id_scale=-1;
      muon1_iso_scale=-1;
      muon2_iso_scale=-1;
      photon_id_scale=-1;*/

   cut0=0,cut1=0;
   bool LEPele,LEPmu,JET,PHOTON,SignalRegion,DR;
//  nentries=1000;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      lep1_phi_station2_tmp = lep1_phi_station2;
      lep2_phi_station2_tmp = lep2_phi_station2;      
      //scalef =   
      cut0++;//total events, cut0=t1->GetEntries()
       
      if(name.Contains("Muon")) scalef=1;
      if(name.Contains("Ele"))  scalef=1;
      if(lep1_phi_station2<0) lep1_phi_station2_tmp = lep1_phi_station2+6.28319;
      if(lep2_phi_station2<0) lep2_phi_station2_tmp = lep2_phi_station2+6.28319;

      l1_weight = L1_weight(lep1_phi_station2_tmp, lep2_phi_station2_tmp, lep1_eta_station2, lep2_eta_station2);      
      if( ! (name.Contains("Muon")||name.Contains("Ele"))  )
	      pileupWeight_tmp=h13->GetBinContent(h13->GetXaxis()->FindBin(npT));
      else    pileupWeight_tmp =1;
      if(drla==10) drla=-1;
      if(drla2==10) drla2=-1; 
      if(drj1a==10) drj1a=-1;
      if(drj2a==10) drj2a=-1;
//      if(m_dataset.Contains("plj")){scalef=1.0;run_period=6;}

//      if(lep==11){cout<<"YES"<<endl;}

      if(photonet>0) photon_id_scale_tmp=get_photon_ID(photoneta,photonet,ID_photon); 
//      ele1_id_scale_tmp = ID->GetBinContent(ID->FindBin(etalep1,ptlep1));
//      ele2_id_scale_tmp = ID->GetBinContent(ID->FindBin(etalep2,ptlep2));
      if(lep==11){
	      ele1_id_scale_tmp=get_ele_ID(etalep1, ptlep1, ID);
	      ele2_id_scale_tmp=get_ele_ID(etalep2, ptlep2, ID);
	      ele1_reco_scale_tmp=get_ele_Reco(etalep1, ptlep1,Reco);
	      ele2_reco_scale_tmp=get_ele_Reco(etalep2, ptlep2,Reco);
      }
      if(lep==13){
	      muon1_id_scale_tmp=get_muon_ID(etalep1,ptlep1,ID_BF);
	      muon2_id_scale_tmp=get_muon_ID(etalep2,ptlep2,ID_BF);
	      muon1_iso_scale_tmp=get_muon_iso(etalep1,ptlep1,iso_BF);
	      muon2_iso_scale_tmp=get_muon_iso(etalep2,ptlep2,iso_BF);
      }

      LEPele = lep==11 && HLT_Ele1>0 && ptlep1 > 20. && ptlep2 > 20.&& fabs(etalep1) < 2.5 &&abs(etalep2) < 2.5 && nlooseeles < 3 && nloosemus == 0  && massVlep >70.;
      LEPmu = lep==13 && (HLT_Mu1>0||HLT_Mu2>0) && ptlep1 > 20. && ptlep2 > 20.&& fabs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles==0 && nloosemus <3  && massVlep >70. ;
      SignalRegion= Mjj>500 && deltaetajj>2.5;// && zepp<1.8;
      PHOTON= photonet>20 &&( (fabs(photoneta)<2.5&&fabs(photoneta)>1.566) || (fabs(photoneta)<1.4442) );
      JET=jet1pt> 30 && jet2pt > 30 && fabs(jet1eta)< 4.7 && fabs(jet2eta)<4.7;
      DR =drla>0.7 && drla2>0.7 && drj1a>0.5 && drj2a>0.5;
      if(jentry%1000000==0)   cout<<jentry<<"; "<<nentries<<"; cut1 = "<<cut1<<endl;
      if( ! ( (LEPmu || LEPele) && PHOTON && JET   ) )
	      continue;
      if(m_dataset.Contains("contamination")){
	      if(isprompt!=1 ) continue;
      }
      cut1++;//how many events passing the selection 
      newtree->Fill(); //fill the brach when this entry pass the both selection
//                 cout<<"jentry = "<<jentry<<"; cut1 = "<<cut1<<endl;

    }
        f_BF->Close();
        f_iso_BF->Close();
 //       f->Close();
        Reco_egamma->Close();
        ID_photon_file->Close();
}
