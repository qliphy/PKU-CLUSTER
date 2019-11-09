#include "TFile.h"
#include "math.h"
#include "TTree.h"
#include "TH1D.h"
#include <iostream>
#include "TCanvas.h"
#include "TPad.h"
#include "TLorentzVector.h"
#include "TGraph.h"

using namespace std;

Int_t find(double* ar, double sieie){
	Int_t iii=-1;
	for(int i=0;i<6;i++){
		if(ar[i]==sieie) {iii=i;break;}
	}
	return iii;
}

TH1D* trans(TTree* treename, std::string filename, TGraph* g1){

	char buffer1[256];
        sprintf(buffer1, "%s",filename.c_str());
        TTree* t1=treename;
//	TH1D*h=new TH1D(buffer1,buffer1,150,0.004,0.034);
	TH1D*h=new TH1D(buffer1,buffer1,150,0.01,0.065);

	treename->SetBranchStatus("*",0);
	treename->SetBranchStatus("ptVlep",1);
	treename->SetBranchStatus("yVlep",1);
	treename->SetBranchStatus("phiVlep",1);
	treename->SetBranchStatus("massVlep",1);
	treename->SetBranchStatus("ptlep1",1);
	treename->SetBranchStatus("etalep1",1);
	treename->SetBranchStatus("philep1",1);
	treename->SetBranchStatus("ptlep2",1);
	treename->SetBranchStatus("etalep2",1);
	treename->SetBranchStatus("philep2",1);
	treename->SetBranchStatus("lep",1);
	treename->SetBranchStatus("HLT_Ele1",1);
	treename->SetBranchStatus("HLT_Ele2",1);
	treename->SetBranchStatus("HLT_Ele3",1);
	treename->SetBranchStatus("HLT_Ele4",1);
	treename->SetBranchStatus("HLT_Ele5",1);
	treename->SetBranchStatus("HLT_Ele6",1);
	treename->SetBranchStatus("HLT_Ele7",1);
	treename->SetBranchStatus("pileupWeight",1);
	treename->SetBranchStatus("scalef",1);
	treename->SetBranchStatus("photon_pt",1);
	treename->SetBranchStatus("photon_eta",1);
	treename->SetBranchStatus("photon_phi",1);
	treename->SetBranchStatus("photon_e",1);
	treename->SetBranchStatus("photon_sieie",1);
	treename->SetBranchStatus("photon_chiso",1);
	treename->SetBranchStatus("photon_nhiso",1);
	treename->SetBranchStatus("photon_phoiso",1);
	treename->SetBranchStatus("photon_hoe",1);
	
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
	Double_t pileupWeight;
	Double_t scalef;
	Double_t photon_pt[6];
	Double_t photon_eta[6];
	Double_t photon_phi[6];
	Double_t photon_e[6];
	Double_t photon_sieie[6];
	Double_t photon_chiso[6];
	Double_t photon_nhiso[6];
	Double_t photon_phoiso[6];
	Double_t photon_hoe[6];
	Double_t weight;
	Double_t sieie;

	t1->SetBranchAddress("pileupWeight", &pileupWeight);
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
	t1->SetBranchAddress("photon_pt", photon_pt);
	t1->SetBranchAddress("photon_eta", photon_eta);
	t1->SetBranchAddress("photon_phi", photon_phi);
	t1->SetBranchAddress("photon_e", photon_e);
	t1->SetBranchAddress("photon_sieie", photon_sieie);
	t1->SetBranchAddress("photon_chiso", photon_chiso);
	t1->SetBranchAddress("photon_nhiso", photon_nhiso);
	t1->SetBranchAddress("photon_phoiso", photon_phoiso);
	t1->SetBranchAddress("photon_hoe", photon_hoe);
	t1->SetBranchAddress("scalef", &scalef );

	TLorentzVector leading_electron, subleading_electron, photon;
	Long64_t entries=t1->GetEntries();
	Int_t eta;
	for(Long64_t i=0;i<entries;i++){
		if(i%100000==0) std::cout<<i<<std::endl;
		t1->GetEntry(i);
		leading_electron.SetPtEtaPhiM(ptlep1, etalep1, philep1, 0.0005);
                subleading_electron.SetPtEtaPhiM(ptlep2, etalep2, philep2, 0.0005);
		double tm=(leading_electron+subleading_electron).M();
		if(ptlep1<25||ptlep2<25||fabs(etalep1) > 2.5 || fabs(etalep2) > 2.5||tm>80) continue;
                double pt_tmp=-99;
                int iii=-1;
                for(int j=0;j<6;j++){
                        if(photon_pt[j]<0) continue;
                        photon.SetPtEtaPhiE(photon_pt[j],photon_eta[j],photon_phi[j],photon_e[j]);
                        double tm1=(leading_electron+subleading_electron+photon).M();
			double drla=photon.DeltaR(leading_electron);
			double drla2=photon.DeltaR(subleading_electron);
                        if(photon_pt[j]>15/* && photon_hoe[j]<0.0396 && photon_nhiso[j]<(2.725+0.0148*photon_pt[j]+0.000017*photon_pt[j]*photon_pt[j]) && photon_phoiso[j]<(2.571+0.0047*photon_pt[j]) && photon_chiso[j]<0.441*/ &&tm1>70 &&tm1<110&&((drla>0.3&&drla<1.)||(drla2>0.3&&drla2<1.))) {
//                                if(i<100) std::cout<<"pass"<<std::endl;
                                if(j==0) {iii=j;pt_tmp=photon_pt[iii];}
                                if(j>0) {if(photon_pt[j]>pt_tmp){ iii=j; pt_tmp=photon_pt[iii];}}
                        }
                }
//              if(iii<0 || fabs(photon_eta[iii])<1.556 || fabs(photon_eta[iii])>2.5) continue;
              if(iii<0 || fabs(photon_eta[iii])>1.4442) continue;
		weight=1.;
		sieie = photon_sieie[iii];
		if(filename.find("ZJets") != std::string::npos){
			if(fabs(photon_eta[iii]) < 1.4442) sieie=g1->Eval(photon_sieie[iii]);
//			if(fabs(photon_eta[iii]) >1.566 && fabs(photon_eta[iii]) < 2.5)sieie=g1->Eval(photon_sieie[iii]);
			weight=pileupWeight;
		}
		h->Fill(sieie, weight);
	}
	return h;
}

int main(){
	TFile*fin = TFile::Open("../../transform/barrel/transformation_barrel.root");
//	TFile*fin = TFile::Open("../histos/trans_endcap.root");
	TGraph* gbarrel;
//	TGraph* gendcap;
	fin->GetObject("barrel",gbarrel);
//	fin->GetObject("endcap",gendcap);
	TFile* fdata=TFile::Open("../../samples/barrel/smallDEle16.root");
	TTree*tdata=(TTree*)fdata->Get("DEle16");
	TFile* fmc=TFile::Open("../../samples/barrel/smallZJets_FX.root");
	TTree*tmc=(TTree*)fmc->Get("ZJets_FX");
	TH1D* hdata = trans(tdata,"DEle",gbarrel);
	TH1D* hmc = trans(tmc,"ZJets",gbarrel);
//	TH1D* hdata = trans(tdata,"DEle16",gendcap);
//	TH1D* hmc = trans(tmc,"ZJets",gendcap);
	TH1D*hclone=(TH1D*)hdata->Clone();
	
	TCanvas*c1=new TCanvas("","",800,600);
	TPad*fPads1 = new TPad("pad1", "", 0.00, 0.40, 0.99, 0.99);
        TPad*fPads2 = new TPad("pad2", "", 0.00, 0.00, 0.99, 0.40);
        fPads1->SetFillColor(0);
        fPads1->SetLineColor(0);
        fPads2->SetFillColor(0);
        fPads2->SetLineColor(0);
        fPads1->SetBottomMargin(0);
        fPads2->SetTopMargin(0);
        fPads2->SetBottomMargin(0.3);

        fPads1->Draw();
        fPads2->Draw();
	
	fPads1->SetLogy();
	fPads1->cd();
	hdata->SetLineColor(kBlack);
	hdata->Draw();
	hmc->Scale(hdata->Integral()/hmc->Integral());
	hclone->Divide(hmc);
	hmc->SetLineColor(kRed);
	hmc->Draw("SAME");

	fPads2->cd();
	hclone->Draw();
//	c1->SaveAs("fsr70110_endcap.png");
	c1->SaveAs("fsr70110_barrel.png");
	return 1;
}
