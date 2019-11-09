#include "TFile.h"
#include "math.h"
#include "TTree.h"
#include <iostream>
#include "TCanvas.h"
#include "TLorentzVector.h"

using namespace std;

void sigmaieie(std::string filename){

	char buffer1[256];
	sprintf(buffer1, "%s",filename.c_str());
//	std::string pathToTrees = "../AddWeight_step2/";
	std::string pathToTrees = "/home/pku/anying/cms/file_in_cms/2017RunIIrootfiles/out";

        TFile* f1 = TFile::Open((pathToTrees + filename + ".root").c_str());
        TTree* t1;
//	if(filename.find("ZJets") != std::string::npos) t1=(TTree*)f1->Get("outZJets_FX");
//	else t1=(TTree*)f1->Get("outDEle");
	t1=(TTree*)f1->Get("demo");
	TFile *fout = new TFile(("small"+filename+".root").c_str(),"RECREATE");
	TTree *treename = new TTree(filename.c_str(), filename.c_str());

	Double_t ptVlep;
        Double_t yVlep;
        Double_t phiVlep;
        Double_t massVlep;
        Double_t ptlep1;
        Double_t etalep1;
        Double_t philep1;
        Double_t ptlep2;
        Double_t etalep2;
        Double_t philep2;
	Int_t lep;
        Int_t HLT_Ele1;
        Int_t HLT_Ele2;
        Int_t HLT_Ele3;
        Int_t HLT_Ele4;
        Int_t HLT_Ele5;
        Int_t HLT_Ele6;
        Int_t HLT_Ele7;
	Double_t ele1_sigmaieie;
	Double_t ele2_sigmaieie;
	Double_t lumiWeight;
	Double_t theWeight;
	Double_t pileupWeight;
	Double_t ele1_id_scale;
	Double_t ele2_id_scale;
	Double_t ele1_reco_scale;
	Double_t ele2_reco_scale;
	Double_t ele_hlt_scale;
	Double_t scalef;
	Double_t weight;
	Double_t photon_pt[6];
        Double_t photon_eta[6];
        Double_t photon_phi[6];
        Double_t photon_e[6];
        Double_t photon_sieie[6];
        Double_t photon_chiso[6];
        Double_t photon_nhiso[6];
        Double_t photon_phoiso[6];
        Double_t photon_hoe[6];
	Double_t sieie;

	treename->Branch("ptVlep", &ptVlep, "ptVlep/D");
	treename->Branch("sieie", &sieie, "sieie/D");
	treename->Branch("yVlep", &yVlep, "yVlep/D");
	treename->Branch("phiVlep", &phiVlep, "phiVlep/D");
	treename->Branch("massVlep", &massVlep, "massVlep/D");
	treename->Branch("ptlep1", &ptlep1, "ptlep1/D");
	treename->Branch("etalep1", &etalep1, "etalep1/D");
	treename->Branch("philep1", &philep1, "philep1/D");
	treename->Branch("etalep2", &etalep2, "etalep2/D");
	treename->Branch("philep2", &philep2, "philep2/D");
	treename->Branch("ptlep2", &ptlep2, "ptlep2/D");
	treename->Branch("lep", &lep, "lep/I");
	treename->Branch("HLT_Ele1", &HLT_Ele1, "HLT_Ele1/I");
	treename->Branch("HLT_Ele2", &HLT_Ele2, "HLT_Ele2/I");
	treename->Branch("HLT_Ele3", &HLT_Ele3, "HLT_Ele3/I");
	treename->Branch("HLT_Ele4", &HLT_Ele4, "HLT_Ele4/I");
	treename->Branch("HLT_Ele5", &HLT_Ele5, "HLT_Ele5/I");
	treename->Branch("HLT_Ele6", &HLT_Ele6, "HLT_Ele6/I");
	treename->Branch("HLT_Ele7", &HLT_Ele7, "HLT_Ele7/I");
	treename->Branch("ele1_sigmaieie", &ele1_sigmaieie, "ele1_sigmaieie/D");
	treename->Branch("ele2_sigmaieie", &ele2_sigmaieie, "ele2_sigmaieie/D");
	treename->Branch("lumiWeight", &lumiWeight, "lumiWeight/D");
	treename->Branch("theWeight", &theWeight, "theWeight/D");
	treename->Branch("pileupWeight", &pileupWeight, "pileupWeight/D");
	treename->Branch("ele1_id_scale", &ele1_id_scale, "ele1_id_scale/D");
	treename->Branch("ele2_id_scale", &ele2_id_scale, "ele2_id_scale/D");
	treename->Branch("ele1_reco_scale", &ele1_reco_scale, "ele1_reco_scale/D");
	treename->Branch("ele2_reco_scale", &ele2_reco_scale, "ele2_reco_scale/D");
	treename->Branch("ele_hlt_scale", &ele_hlt_scale, "ele_hlt_scale/D");
	treename->Branch("scalef", &scalef, "scalef/D");
	treename->Branch("weight", &weight, "weight/D");
	treename->Branch("photon_pt", photon_pt,"photon_pt[6]/D");
	treename->Branch("photon_eta", photon_eta,"photon_eta[6]/D");
        treename->Branch("photon_phi", photon_phi,"photon_phi[6]/D");
        treename->Branch("photon_e", photon_e,"photon_e[6]/D");
        treename->Branch("photon_sieie", photon_sieie,"photon_sieie[6]/D");
        treename->Branch("photon_chiso", photon_chiso,"photon_chiso[6]/D");
        treename->Branch("photon_nhiso", photon_nhiso,"photon_nhiso[6]/D");
        treename->Branch("photon_phoiso", photon_phoiso,"photon_phoiso[6]/D");
        treename->Branch("photon_hoe", photon_hoe,"photon_hoe[6]/D");

	t1->SetBranchAddress("lumiWeight", &lumiWeight);
	t1->SetBranchAddress("theWeight", &theWeight);
	t1->SetBranchAddress("pileupWeight", &pileupWeight);
	t1->SetBranchAddress("ele1_id_scale", &ele1_id_scale);
	t1->SetBranchAddress("ele2_id_scale", &ele2_id_scale);
	t1->SetBranchAddress("ele1_reco_scale", &ele1_reco_scale);
	t1->SetBranchAddress("ele2_reco_scale", &ele2_reco_scale);
	t1->SetBranchAddress("ele_hlt_scale", &ele_hlt_scale);
	t1->SetBranchAddress("ptVlep", &ptVlep);
        t1->SetBranchAddress("yVlep", &yVlep);
        t1->SetBranchAddress("phiVlep", &phiVlep);
        t1->SetBranchAddress("massVlep", &massVlep);
        t1->SetBranchAddress("ptlep1", &ptlep1);
        t1->SetBranchAddress("etalep1", &etalep1);
        t1->SetBranchAddress("philep1", &philep1);
        t1->SetBranchAddress("ptlep2", &ptlep2);
        t1->SetBranchAddress("etalep2", &etalep2);
        t1->SetBranchAddress("philep2", &philep2);
        t1->SetBranchAddress("HLT_Ele1", &HLT_Ele1);
        t1->SetBranchAddress("HLT_Ele2", &HLT_Ele2);
        t1->SetBranchAddress("HLT_Ele3", &HLT_Ele3);
        t1->SetBranchAddress("lep", &lep);
        t1->SetBranchAddress("ele1_sigmaieie", &ele1_sigmaieie);
        t1->SetBranchAddress("ele2_sigmaieie", &ele2_sigmaieie);
	t1->SetBranchAddress("photon_pt", photon_pt);
	t1->SetBranchAddress("photon_eta", photon_eta);
        t1->SetBranchAddress("photon_phi", photon_phi);
        t1->SetBranchAddress("photon_e", photon_e);
        t1->SetBranchAddress("photon_sieie", photon_sieie);
        t1->SetBranchAddress("photon_chiso", photon_chiso);
        t1->SetBranchAddress("photon_nhiso", photon_nhiso);
        t1->SetBranchAddress("photon_phoiso", photon_phoiso);
        t1->SetBranchAddress("photon_hoe", photon_hoe);
	
	TLorentzVector leading_electron, subleading_electron, photon;
	Long64_t entries=t1->GetEntries();
	for(Long64_t i=0;i<entries;i++){
		if(i%100000==0) std::cout<<i<<std::endl;
		t1->GetEntry(i);
		if(ptlep1<0 && ptlep2<0) continue;
		leading_electron.SetPtEtaPhiM(ptlep1, etalep1, philep1, 0.0005);
		subleading_electron.SetPtEtaPhiM(ptlep2, etalep2, philep2, 0.0005);
//		if(filename.find("ZJets") != std::string::npos){
//                      scalef=0.07487*fabs(theWeight)/theWeight;
//              }
		double pt_tmp=-99;
		int iii=-1;
		for(int j=0;j<6;j++){
			if(photon_pt[j]<0) continue;
                        photon.SetPtEtaPhiE(photon_pt[j],photon_eta[j],photon_phi[j],photon_e[j]);
			double tm1=(leading_electron+photon).M();
			double tm2=(subleading_electron+photon).M();
                        if(photon_pt[j]>15 && photon_hoe[j]<0.02197 && photon_nhiso[j]<(1.189 + 0.01512*photon_pt[j]+0.00002259*photon_pt[j]*photon_pt[j]) && photon_phoiso[j]<(2.08 + 0.004017*photon_pt[j]) && photon_chiso[j]<1.141 &&((tm1>70&&tm1<110&&!(tm2>70&&tm2<110))||(!(tm1>70&&tm1<110)&&tm2>70&&tm2<110))) {
				if(i<100) std::cout<<"pass"<<std::endl;
				if(j==0) {iii=j;pt_tmp=photon_pt[iii];}
				if(j>0) {if(photon_pt[j]>pt_tmp){ iii=j; pt_tmp=photon_pt[iii];}}
			}
		}
//		std::cout<<iii<<std::endl;
		if(iii!=-1) sieie=photon_sieie[iii];		
		treename->Fill();
	}
	fout->cd();
	treename->Write();
	fout->Close();

}

int main(){
	sigmaieie("DEle17");
	sigmaieie("ZJets_FX");
	return 1;
}
