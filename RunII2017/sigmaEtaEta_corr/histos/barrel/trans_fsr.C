#include "TFile.h"
#include "math.h"
#include "TTree.h"
#include "TH1D.h"
#include <iostream>
#include "TCanvas.h"
#include "TLorentzVector.h"

using namespace std;


TH1D* trans_fsr(TTree* treename, std::string filename){

	char buffer1[256];
        sprintf(buffer1, "%s",filename.c_str());
        TTree* t1=treename;
	TH1D*h=new TH1D(buffer1,buffer1,1000,0,0.07);

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
	t1->SetBranchAddress("HLT_Ele4", &HLT_Ele4);
	t1->SetBranchAddress("HLT_Ele5", &HLT_Ele5);
	t1->SetBranchAddress("HLT_Ele6", &HLT_Ele6);
	t1->SetBranchAddress("HLT_Ele7", &HLT_Ele7);
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
	t1->SetBranchAddress("sieie", &sieie);
	t1->SetBranchAddress("scalef", &scalef );
	t1->SetBranchAddress("weight",&weight );

	TLorentzVector leading_electron, subleading_electron, photon;
	Long64_t entries=t1->GetEntries();
	Int_t eta;
	for(Long64_t i=0;i<entries;i++){
		if(i%100000==0) std::cout<<i<<std::endl;
		t1->GetEntry(i);
		leading_electron.SetPtEtaPhiM(ptlep1, etalep1, philep1, 0.0005);
                subleading_electron.SetPtEtaPhiM(ptlep2, etalep2, philep2, 0.0005);
		double pt_tmp=-99;
                int iii=-1;
                for(int j=0;j<6;j++){
                        if(photon_pt[j]<0) continue;
                        photon.SetPtEtaPhiE(photon_pt[j],photon_eta[j],photon_phi[j],photon_e[j]);
                        double tm1=(leading_electron+subleading_electron+photon).M();
                        if(photon_pt[j]>15 && photon_hoe[j]<0.02197 && photon_nhiso[j]<(1.189 + 0.01512*photon_pt[j]+0.00002259*photon_pt[j]*photon_pt[j]) && photon_phoiso[j]<(2.08 + 0.004017*photon_pt[j]) && photon_chiso[j]<1.141 && tm1>70 &&tm1<110) {
                                if(i<100) std::cout<<"pass"<<std::endl;
                                if(j==0) {iii=j;pt_tmp=photon_pt[iii];}
                                if(j>0) {if(photon_pt[j]>pt_tmp){ iii=j; pt_tmp=photon_pt[iii];}}
                        }
                }
		if(iii<0 || fabs(photon_eta[iii])<1.556 || fabs(photon_eta[iii])>2.5) continue;
//		if(iii<0 || fabs(photon_eta[iii])>1.4442) continue;
		weight=1.;
		if(filename.find("ZJets") != std::string::npos){
			weight=lumiWeight*pileupWeight*scalef*ele1_id_scale*ele2_id_scale*ele1_reco_scale*ele2_reco_scale;
		}
		h->Fill(sieie, weight);
	}
	return h;
}

int main(){
	TFile* f= new TFile("trans_barrel.root","RECREATE");
//	TFile* f= new TFile("trans_endcap.root","RECREATE");
	TFile* fdata=TFile::Open("../../samples/barrel/smallDEle16.root");
	TTree*tdata=(TTree*)fdata->Get("DEle16");
	TFile* fmc=TFile::Open("../../samples/barrel/smallZJets_FX.root");
	TTree*tmc=(TTree*)fmc->Get("ZJets_FX");
	TH1D* hdata = trans_fsr(tdata,"DEle16");
	TH1D* hmc = trans_fsr(tmc,"ZJets");
	f->cd();
	hdata->Write();
	hmc->Write();
	f->Close();
	return 1;
}
