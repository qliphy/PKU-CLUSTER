#include <string>
#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "RooRealVar.h"
#include "RooAddPdf.h"
using namespace RooFit;
using namespace std;
TString dir1 = "../eleendcap/root/";
TString dir = "./fractionfitResult_za/"; 
ofstream file3( dir + "info_fit1.txt");
ofstream file2( dir + "info_number.txt");
Double_t fr,fr_Error;
void fitf(float lowpt, float highpt, float lowchiso, float highchiso){
//TString b="chiso5-12_";

	TFile* fdata = TFile::Open(dir1+"ptotal.root");
	cout<<"OK"<<endl;
	TH1F* hdata = (TH1F*)fdata->Get(Form("h11_pt%0.f_%0.f",lowpt,highpt));
        TH1F* hfake = (TH1F*)fdata->Get(Form("h12_pt%0.f_%0.f_chiso%0.f_%0.f",lowpt,highpt,lowchiso,highchiso));
        TH1F* htrue = (TH1F*)fdata->Get(Form("h13_pt%0.f_%0.f",lowpt,highpt));
        TH1F* hist  = (TH1F*) fdata->Get(Form("hfake_pt%0.f_%0.f",lowpt,highpt));
        TH1F* hmc    = (TH1F*)fdata->Get(Form("htrue_pt%0.f_%0.f",lowpt,highpt));
        TH1F* hsieie = (TH1F*)fdata->Get(Form("hsieie_pt%0.f_%0.f",lowpt,highpt));
        hdata->Sumw2();hfake->Sumw2();htrue->Sumw2(); 

	cout<<"OK"<<endl;
	Int_t nBins = hdata->GetNbinsX();
/*        Int_t nBins = 4;
        Int_t sieie_bin=1;
        Double_t bins[5];
        for (Int_t i=0;i<(nBins+1);i++){
                bins[i] = 0.0172 + 0.01*i;
	}*/
//        TH1* hdata = hdata_->Rebin(nBins, "", bins);
//        TH1* htrue = htrue_->Rebin(nBins, "", bins);
//        TH1* hfake = hfake_->Rebin(nBins, "", bins);
	cout<<"OK1"<<endl;
        for (Int_t i=0; i<nBins; i++){
                if (hdata->GetBinContent(i+1)<=0) hdata->SetBinContent(i+1,0.000000);
                if (htrue->GetBinContent(i+1)<=0) htrue->SetBinContent(i+1,0.000000);
                if (hfake->GetBinContent(i+1)<=0) hfake->SetBinContent(i+1,0.000000);
        }
        Double_t nFake=hfake->Integral();      
        Double_t nTrue=htrue->Integral();      
        Double_t nMax = hdata->GetSumOfWeights();
        Double_t nTrueStart = hmc->GetSumOfWeights();
        Double_t nFakeStart = nMax - nTrueStart;
//	Double_t nReal=hsieie->Integral();
//        std::cout<<"nMax = "<<nMax<<"; nTrueStart = "<<nTrueStart<<"; nFakeStart = "<<nFakeStart<<std::endl;
//        hfake->Scale((nMax-nReal)/nFake);
//        htrue->Scale(nTrueStart/nTrue);
    
        TObjArray *mc = new TObjArray(2);    
        mc->Add(hfake);
        mc->Add(htrue);
        TFractionFitter* fit = new TFractionFitter(hdata, mc,"V");

        fit->Constrain(1,0,1);
//        fit->Constrain(0,0,1);
        fit->SetRangeX(1,nBins); // use only the first 15 bins in the fit
        Int_t status = fit->Fit();// perform the fit
        std::cout << "fit status: " << status << std::endl;
        if (status == 0) {                       // check on fit status
            TH1F* result = (TH1F*) fit->GetPlot();
	    TCanvas *c1 = new TCanvas("c1","c1",500,400);
	    gStyle->SetOptStat(0);
	    c1->SetGrid();
	    hdata->SetTitle(Form("Barrel region %0.f < pt < %0.f, %0.f < chiso < %0.f",lowpt,highpt,lowchiso,highchiso)); 
            hdata->SetMarkerColor(1);
            hdata->SetLineColor(1);
            hdata->SetMarkerStyle(20);
            result->SetLineColor(kRed);
            hdata->Draw("Ep");
            result->Draw("same");
            auto mcp0 = (TH1F*)fit->GetMCPrediction(0);
            mcp0->SetLineColor(kBlue);
            mcp0->SetLineWidth(2);
            mcp0->SetLineStyle(1);
            auto mcp1 = (TH1F*)fit->GetMCPrediction(1);
            mcp1->SetLineColor(kGreen);
            mcp1->SetLineWidth(2);
            mcp1->SetLineStyle(2);

            mcp0->Draw("same hist");
            mcp1->Draw("same hist");
	    hist->SetLineColor(kOrange);
	    hist->SetLineStyle(2);
	    hist->SetLineWidth(3);
	    hist->Draw("same hist");
	    hmc->SetLineColor(kMagenta);
	    hmc->SetLineStyle(2);
	    hmc->SetLineWidth(3);
	    hmc->Draw("same hist");
 
           /*Double_t fakeError, trueError, dataError, dataActualError;
            Double_t eff = hsieie->GetSumOfWeights()/htrue->GetSumOfWeights();
            Double_t trueValue = mcp1->IntegralAndError(0,nBins,trueError)*eff;
            Double_t dataValue = result->IntegralAndError(0,2,dataError);
            Double_t dataActualValue  = hdata->IntegralAndError(0,2,dataError);
            Double_t fakeValue = dataActualValue-trueValue;
                     fakeError = sqrt(dataError * dataError + trueError * trueError);
            Double_t rate = fakeValue/hdata->Integral(0,2);
            Double_t rateError = fakeError/dataActualValue+fakeValue*dataActualError/(dataActualValue*dataActualValue);*/
            
            Double_t p0, p1, errP0, errP1,fakeValue,fakeError,fake_window,fake_window_Error,data_window,data_window_Error;
	    Double_t chi2=fit->GetChisquare();
	    Int_t Ndf=fit->GetNDF();
            double chi2ToNdf = chi2;//double chi2ToNdf = chi2/Ndf;
            cout<<"chi2 = "<<chi2<<"; chi2/Ndf = "<<chi2ToNdf<<endl;
            fit->GetResult( 0, p0, errP0);
            printf("total fake fraction %.3f +/- %.3f\n",  p0, errP0);
            fit->GetResult( 1, p1, errP1);
            printf("total true fraction %.3f +/- %.3f\n",  p1, errP1);
            fakeValue = mcp0->IntegralAndError(0,nBins,fakeError); 
            fake_window = mcp0->IntegralAndError(0,mcp0->FindFixBin(0.0272),fake_window_Error);
            data_window = result->IntegralAndError(0,result->FindFixBin(0.0272),data_window_Error);
//            fr = p0* (hfake->Integral(1,hfake->GetXaxis()->FindFixBin(0.0272)-1)/hfake->Integral())/(hdata->Integral(1,hdata->GetXaxis()->FindFixBin(0.0272)-1)/hdata->Integral());
            fr = p0* (hfake->Integral(1,hfake->FindFixBin(0.0272)-1)/hfake->Integral())/(hdata->Integral(1,hdata->FindFixBin(0.0272)-1)/hdata->Integral());
            fr_Error =sqrt(fake_window_Error*fake_window_Error/(data_window*data_window)
                             + fake_window*fake_window*data_window_Error*data_window_Error/(data_window
                              *data_window*data_window*data_window));;
            cout<<"window fake fraction = "<<fr<<endl;
            cout<<"window fake fraction error = "<<fr_Error<<endl;
 
            ofstream myfile(dir + Form("txt/fakerate_photon_pt%0.f_%0.f_chiso_%0.f_%0.f.txt",lowpt,highpt,lowchiso,highchiso),ios::out);
 
            /*myfile <<"Fake Yields"<<fakeValue<<"+-"<<fakeError<<endl;
            myfile <<"Ture yields"<<trueValue<<"+-"<<trueError<<endl;
            myfile <<"Data yields"<<dataValue<<"+-"<<dataError<<endl;*/
            myfile <<fr<<"\t"<<fr_Error<<"\t"<<hfake->Integral(1,hfake->FindFixBin(0.0272)-1)<<"\t"<<fakeValue<<"\t"<<fake_window<<endl;
	    file3<<Form("%0.f <pt<%0.f",lowpt,highpt)<<"\t"<<Form("%0.f<chiso<%0.f",lowchiso,highchiso)<<"\t"<<fixed<<setprecision(2)<<fr<<"\t"<<fixed<<setprecision(2)<<fr_Error<<endl;
	    file2<<Form("%0.f <pt<%0.f ",lowpt,highpt)<<"\t"<<Form("%0.f <chiso<%0.f ",lowchiso,highchiso)<<fixed<<setprecision(2)<< hist->Integral(1,hfake->FindFixBin(0.0272)) <<"\t"<<fixed<<setprecision(2)<<fake_window<<"\t"<<fixed<<setprecision(2)<<fake_window_Error<<fixed<<setprecision(2)<<"\t"<<fabs(hist->Integral(1,hfake->FindFixBin(0.0272))-fake_window)/fake_window_Error<<endl;
            myfile.close();
	    char c[200],c2[200],c3[200];
	    sprintf(c,"%f",chi2ToNdf);
	    sprintf(c2,"%f",fr);
	    sprintf(c3,"%f",fr_Error);
	    TString s="#chi^{2}/ndf = ";
	    TString s2="value = ";
	    TString s3="error = ";
	    TString chisquare=s + c;
	    TString v=s2 + c2;
	    TString e=s3 + c3;

	    TLatex *textchi2 = new TLatex(0.6, 0.7, chisquare);
	    textchi2->SetNDC();
	    textchi2->SetTextSize(0.05);
	    textchi2->SetLineWidth(1);
	    textchi2->Draw();
	    TLatex *textvalue = new TLatex(0.6, 0.6, v);
	    textvalue->SetNDC();
	    textvalue->SetTextSize(0.05);
	    textvalue->SetLineWidth(1);
	    textvalue->Draw();
	    TLatex *texterror = new TLatex(0.6, 0.5, e);
	    texterror->SetNDC();
	    texterror->SetTextSize(0.05);
	    texterror->SetLineWidth(1);
	    texterror->Draw();
            gPad->SetLogy(0);
	    TLegend *leg = new TLegend(0.7, 0.8, 0.88, 0.88, NULL, "brNDC");
	    leg->SetFillColor(10);
	    leg->AddEntry(hdata, "Fit result", "L");
	    leg->AddEntry(mcp1, "Ture photons", "L");
	    leg->AddEntry(mcp0, "Fake photons", "L");
	    leg->AddEntry(hist, "mc truth of fake #gamma", "L");
	    leg->AddEntry(hmc, "mc truth of true #gamma", "L");
	    leg->Draw("same");

            c1->Print(dir + Form("eps/pt%0.f_%0.f_chiso_%0.f_%0.f.eps",lowpt,highpt,lowchiso,highchiso));

     }
	fdata->Close();
}
