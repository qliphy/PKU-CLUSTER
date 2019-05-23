#include "TEfficiency.h"
//TCanvas* c1[4];
//TCanvas* c2[4];
void open(int i,TFile*file,TFile*f2){
	TH1D*hsN;TH1D*husN;
	TH1D*hsD;TH1D*husD;
	TEfficiency* hseed;
	TEfficiency* hunseed;
	TString name = file->GetName();
	hsN = (TH1D*)file->Get(Form("hsN_%i",i+1));
	hsD = (TH1D*)file->Get(Form("hsD_%i",i+1));
	husN = (TH1D*)file->Get(Form("hunsN_%i",i+1));
	husD = (TH1D*)file->Get(Form("hunsD_%i",i+1));
cout<<"OK1"<<endl;
//        hsN->Sumw2();husN->Sumw2();
//        hsD->Sumw2();husD->Sumw2();
	if(TEfficiency::CheckConsistency(*hsN,*hsD))
        	{hseed = new TEfficiency(*hsN,*hsD);cout<<"OK2"<<endl;}
	if(TEfficiency::CheckConsistency(*husN,*husD))
        	{hunseed = new TEfficiency(*husN,*husD);}
	TString title1 = hsN->GetTitle();
	TString title2 = husN->GetTitle();
cout<<"OK3"<<endl;
         hseed->SetTitle(/*"Seed_"+*/title1);
         hunseed->SetTitle(/*"unSeed_"+*/title1);
	hseed->Draw("ape");
	hunseed->Draw("ape");

      /*TGraphErrors* grS;
	TGraphErrors* grUS;
        const int count = hsN->GetNbinsX();
        double grXS[count],grYS[count],grXSe[count],grYSe[count];
        double grXUS[count],grYUS[count],grXUSe[count],grYUSe[count];
	for(int i=0;i<husN->GetNbinsX();i++){          
            grYS[i]  = hsN->GetBinContent(i+1);
            grXS[i]  = hsN->GetBinCenter(i+1);
            grXSe[i] = hsN->GetBinWidth(i+1)/2;
            grYSe[i] = hsN->GetBinError(i+1); 

            grYUS[i]  = husN->GetBinContent(i+1);
            grXUS[i]  = husN->GetBinCenter(i+1);
            grXUSe[i] = husN->GetBinWidth(i+1)/2;
            grYUSe[i] = husN->GetBinError(i+1); 
	}
        grS = new TGraphErrors(count,grXS,grYS,grXSe,grYSe);
        grUS = new TGraphErrors(count,grXUS,grYUS,grXUSe,grYUSe);
	grS->SetMarkerSize(1.5);                  
	grS->SetMarkerStyle(22);                
	grS->SetMarkerColor(kAzure+7);
	grS->Draw("ap");
        grS->SetTitle("seed/gen efficiency vs "+title1);
        grS->GetYaxis()->SetTitle("efficiency hlt/gen");
        grS->GetXaxis()->SetTitle(title1);
        grUS->SetTitle("unseed/gen efficiency vs "+title2);
        grUS->GetYaxis()->SetTitle("efficiency hlt/gen");
        grUS->GetXaxis()->SetTitle(title2);
	grUS->SetMarkerColor(kAzure+7);grUS->SetMarkerStyle(22);
	grUS->SetMarkerSize(1.5);
	grUS->Draw("ap");*/
	f2->cd();
	hseed->Write();hunseed->Write();hsN->Write();
	delete hsN;delete hsD;delete husN;delete husD;delete hseed;delete hunseed;
//	delete c1;
}
int draw(){
//	TFile* f1 = new TFile("50_120_barrel.root");
//	TFile* f2 = new TFile("120_200_barrel.root");
	TFile* f1 = new TFile("50_120_endcap.root");
	TFile* f2 = new TFile("120_200_endcap.root");
        TString filename1 = f1->GetName();
        TString filename2 = f2->GetName();
        TString name1 = "eff_"+ filename1 ;
        TString name2 = "eff_"+ filename2;
	TFile* eff2 = new TFile(name1,"recreate");
	TFile* eff1 = new TFile(name2,"recreate");
	f1->cd();
	for(int i=0;i<4;i++){
		open(i,f1,eff1);
	}
	f1->Close();
        eff1->Close();
	f2->cd();
	for(int i=0;i<4;i++){
		open(i,f2,eff2);
	}
	f2->Close();
return 1;
}
