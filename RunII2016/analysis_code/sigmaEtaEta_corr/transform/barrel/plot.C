void plot(){
	TCanvas*c=new TCanvas("aa","aa",800,600);
	c->SetLogy();
	c->cd();
	TFile* f=TFile::Open("../../histos/barrel/trans_barrel.root");
//	TFile* f=TFile::Open("../medium_id_cut/fsr_70110/trans_endcap.root");
        TH1D* hdata;
        TH1D* hmc;
        f->GetObject("DEle16",hdata);
        f->GetObject("ZJets",hmc);


        hmc->Scale(hdata->Integral()/hmc->Integral());

	TLegend* l1 = new TLegend(0.7,0.7,0.9,0.9);
	l1->AddEntry(hdata,"DEle16");
	l1->AddEntry(hmc,"ZJets");
	hdata->SetLineWidth(2);
	hmc->SetLineWidth(2);

	hdata->SetLineColor(kBlack);
	hdata->Rebin(5);
	hdata->Draw();
	hmc->SetLineColor(kRed);
	hmc->Rebin(5);
	hmc->Draw("SAME");
        l1->Draw();

	c->SaveAs("aa_barrel.png");
//	c->SaveAs("aa_endcap.png");
}
