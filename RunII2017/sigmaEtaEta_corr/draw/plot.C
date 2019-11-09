void plot(){
	TCanvas*c=new TCanvas("aa","aa",800,600);
	c->SetLogy();
	c->cd();
	TFile* f=TFile::Open("../medium_id_cut/fsr_70110/trans_barrel.root");
//	TFile* f=TFile::Open("../medium_id_cut/fsr_70110/trans_endcap.root");
        TH1D* hdata;
        TH1D* hmc;
        f->GetObject("DEle",hdata);
        f->GetObject("ZJets",hmc);


        hmc->Scale(hdata->Integral()/hmc->Integral());

	hdata->SetLineColor(kBlack);
	hdata->Rebin(5);
	hdata->Draw();
	hmc->SetLineColor(kRed);
	hmc->Rebin(5);
	hmc->Draw("SAME");

	c->SaveAs("aa_barrel.png");
//	c->SaveAs("aa_endcap.png");
}
