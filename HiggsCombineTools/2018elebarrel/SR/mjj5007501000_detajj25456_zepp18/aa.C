void aa()
{
//=========Macro generated from canvas: /
//=========  (Wed Sep 11 20:17:03 2019) by ROOT version6.06/09
   TCanvas * = new TCanvas("", "",0,0,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.15);
   c1->SetRightMargin(0.05);
   c1->SetBottomMargin(0.13);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "",0,0,0.99,0.99);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-1.5,-11.79864,8.5,78.96016);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.15);
   pad1->SetRightMargin(0.05);
   pad1->SetBottomMargin(0.13);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",8,0,8);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(70.79187);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);
   hs_stack_1->SetLineStyle(0);
   hs_stack_1->SetLineWidth(2);
   hs_stack_1->SetMarkerStyle(20);
   hs_stack_1->GetXaxis()->SetBinLabel(1,"Mjj 500~800");
   hs_stack_1->GetXaxis()->SetBinLabel(2,"Mjj 800~1200");
   hs_stack_1->GetXaxis()->SetBinLabel(3,"Mjj 1200~2000");
   hs_stack_1->GetXaxis()->SetBinLabel(4,"Mjj 500~800");
   hs_stack_1->GetXaxis()->SetBinLabel(5,"Mjj 800~1200");
   hs_stack_1->GetXaxis()->SetBinLabel(6,"Mjj 1200~2000");
   hs_stack_1->GetXaxis()->SetBinLabel(7,"Mjj 500~1200");
   hs_stack_1->GetXaxis()->SetBinLabel(8,"Mjj 1200~2000");
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetXaxis()->SetTitleSize(0.06);
   hs_stack_1->GetXaxis()->SetTitleOffset(0.9);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetTitle("Events /bin");
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetYaxis()->SetTitleSize(0.06);
   hs_stack_1->GetYaxis()->SetTitleOffset(0.8);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetZaxis()->SetTitleSize(0.06);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *ST__1 = new TH1D("ST__1","",8,0,8);
   ST__1->SetBinContent(1,0.617403);
   ST__1->SetBinContent(4,0.3655605);
   ST__1->SetBinError(1,0.5019872);
   ST__1->SetBinError(4,0.3655605);
   ST__1->SetEntries(8);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   ST__1->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   ST__1->SetLineColor(ci);
   ST__1->SetLineStyle(0);
   ST__1->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   ST__1->SetMarkerColor(ci);
   ST__1->SetMarkerStyle(20);
   ST__1->GetXaxis()->SetBinLabel(1,"Mjj 500~800");
   ST__1->GetXaxis()->SetBinLabel(2,"Mjj 800~1200");
   ST__1->GetXaxis()->SetBinLabel(3,"Mjj 1200~2000");
   ST__1->GetXaxis()->SetBinLabel(4,"Mjj 500~800");
   ST__1->GetXaxis()->SetBinLabel(5,"Mjj 800~1200");
   ST__1->GetXaxis()->SetBinLabel(6,"Mjj 1200~2000");
   ST__1->GetXaxis()->SetBinLabel(7,"Mjj 500~1200");
   ST__1->GetXaxis()->SetBinLabel(8,"Mjj 1200~2000");
   ST__1->GetXaxis()->SetLabelFont(42);
   ST__1->GetXaxis()->SetLabelOffset(0.007);
   ST__1->GetXaxis()->SetTitleSize(0.06);
   ST__1->GetXaxis()->SetTitleOffset(0.9);
   ST__1->GetXaxis()->SetTitleFont(42);
   ST__1->GetYaxis()->SetLabelFont(42);
   ST__1->GetYaxis()->SetLabelOffset(0.007);
   ST__1->GetYaxis()->SetTitleSize(0.06);
   ST__1->GetYaxis()->SetTitleOffset(1.1);
   ST__1->GetYaxis()->SetTitleFont(42);
   ST__1->GetZaxis()->SetLabelFont(42);
   ST__1->GetZaxis()->SetLabelOffset(0.007);
   ST__1->GetZaxis()->SetTitleSize(0.06);
   ST__1->GetZaxis()->SetTitleFont(42);
   hs->Add(ST,"");
   
   TH1D *TTA__2 = new TH1D("TTA__2","",8,0,8);
   TTA__2->SetBinContent(1,0.09022869);
   TTA__2->SetBinContent(2,1.07566);
   TTA__2->SetBinContent(3,0.2992949);
   TTA__2->SetBinContent(4,-0.1135263);
   TTA__2->SetBinContent(5,0.02484615);
   TTA__2->SetBinContent(6,0.3720589);
   TTA__2->SetBinContent(7,0.1287624);
   TTA__2->SetBinContent(8,0.07525705);
   TTA__2->SetBinError(1,0.574958);
   TTA__2->SetBinError(2,0.527934);
   TTA__2->SetBinError(3,0.1844011);
   TTA__2->SetBinError(4,0.481351);
   TTA__2->SetBinError(5,0.2335973);
   TTA__2->SetBinError(6,0.2699734);
   TTA__2->SetBinError(7,0.1287624);
   TTA__2->SetEntries(8);

   ci = TColor::GetColor("#00ffff");
   TTA__2->SetFillColor(ci);

   ci = TColor::GetColor("#00ffff");
   TTA__2->SetLineColor(ci);
   TTA__2->SetLineStyle(0);
   TTA__2->SetLineWidth(2);

   ci = TColor::GetColor("#00ffff");
   TTA__2->SetMarkerColor(ci);
   TTA__2->SetMarkerStyle(20);
   TTA__2->GetXaxis()->SetLabelFont(42);
   TTA__2->GetXaxis()->SetLabelOffset(0.007);
   TTA__2->GetXaxis()->SetTitleSize(0.06);
   TTA__2->GetXaxis()->SetTitleOffset(0.9);
   TTA__2->GetXaxis()->SetTitleFont(42);
   TTA__2->GetYaxis()->SetLabelFont(42);
   TTA__2->GetYaxis()->SetLabelOffset(0.007);
   TTA__2->GetYaxis()->SetTitleSize(0.06);
   TTA__2->GetYaxis()->SetTitleOffset(1.1);
   TTA__2->GetYaxis()->SetTitleFont(42);
   TTA__2->GetZaxis()->SetLabelFont(42);
   TTA__2->GetZaxis()->SetLabelOffset(0.007);
   TTA__2->GetZaxis()->SetTitleSize(0.06);
   TTA__2->GetZaxis()->SetTitleFont(42);
   hs->Add(TTA,"");
   
   TH1D *VV__3 = new TH1D("VV__3","",8,0,8);
   VV__3->SetBinContent(1,9.020622);
   VV__3->SetBinContent(3,0.207013);
   VV__3->SetBinContent(4,1.510172);
   VV__3->SetBinError(1,8.410138);
   VV__3->SetBinError(3,0.207013);
   VV__3->SetBinError(4,0.8464458);
   VV__3->SetEntries(8);

   ci = TColor::GetColor("#6666cc");
   VV__3->SetFillColor(ci);

   ci = TColor::GetColor("#6666cc");
   VV__3->SetLineColor(ci);
   VV__3->SetLineStyle(0);
   VV__3->SetLineWidth(2);

   ci = TColor::GetColor("#6666cc");
   VV__3->SetMarkerColor(ci);
   VV__3->SetMarkerStyle(20);
   VV__3->GetXaxis()->SetLabelFont(42);
   VV__3->GetXaxis()->SetLabelOffset(0.007);
   VV__3->GetXaxis()->SetTitleSize(0.06);
   VV__3->GetXaxis()->SetTitleOffset(0.9);
   VV__3->GetXaxis()->SetTitleFont(42);
   VV__3->GetYaxis()->SetLabelFont(42);
   VV__3->GetYaxis()->SetLabelOffset(0.007);
   VV__3->GetYaxis()->SetTitleSize(0.06);
   VV__3->GetYaxis()->SetTitleOffset(1.1);
   VV__3->GetYaxis()->SetTitleFont(42);
   VV__3->GetZaxis()->SetLabelFont(42);
   VV__3->GetZaxis()->SetLabelOffset(0.007);
   VV__3->GetZaxis()->SetTitleSize(0.06);
   VV__3->GetZaxis()->SetTitleFont(42);
   hs->Add(VV,"");
   
   TH1D *WA__4 = new TH1D("WA__4","",8,0,8);
   WA__4->SetEntries(8);

   ci = TColor::GetColor("#000099");
   WA__4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   WA__4->SetLineColor(ci);
   WA__4->SetLineStyle(0);
   WA__4->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   WA__4->SetMarkerColor(ci);
   WA__4->SetMarkerStyle(20);
   WA__4->GetXaxis()->SetLabelFont(42);
   WA__4->GetXaxis()->SetLabelOffset(0.007);
   WA__4->GetXaxis()->SetTitleSize(0.06);
   WA__4->GetXaxis()->SetTitleOffset(0.9);
   WA__4->GetXaxis()->SetTitleFont(42);
   WA__4->GetYaxis()->SetLabelFont(42);
   WA__4->GetYaxis()->SetLabelOffset(0.007);
   WA__4->GetYaxis()->SetTitleSize(0.06);
   WA__4->GetYaxis()->SetTitleOffset(1.1);
   WA__4->GetYaxis()->SetTitleFont(42);
   WA__4->GetZaxis()->SetLabelFont(42);
   WA__4->GetZaxis()->SetLabelOffset(0.007);
   WA__4->GetZaxis()->SetTitleSize(0.06);
   WA__4->GetZaxis()->SetTitleFont(42);
   hs->Add(WA,"");
   
   TH1D *plj__5 = new TH1D("plj__5","",8,0,8);
   plj__5->SetBinContent(1,11.63923);
   plj__5->SetBinContent(2,0.6611368);
   plj__5->SetBinContent(4,18.64748);
   plj__5->SetBinContent(5,6.230174);
   plj__5->SetBinContent(6,1.234943);
   plj__5->SetBinContent(7,5.826248);
   plj__5->SetBinContent(8,5.563707);
   plj__5->SetBinError(1,1.989016);
   plj__5->SetBinError(2,0.4599336);
   plj__5->SetBinError(4,2.624399);
   plj__5->SetBinError(5,1.502694);
   plj__5->SetBinError(6,0.5763129);
   plj__5->SetBinError(7,1.451488);
   plj__5->SetEntries(8);

   ci = TColor::GetColor("#ffff00");
   plj__5->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   plj__5->SetLineColor(ci);
   plj__5->SetLineStyle(0);
   plj__5->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   plj__5->SetMarkerColor(ci);
   plj__5->SetMarkerStyle(20);
   plj__5->GetXaxis()->SetLabelFont(42);
   plj__5->GetXaxis()->SetLabelOffset(0.007);
   plj__5->GetXaxis()->SetTitleSize(0.06);
   plj__5->GetXaxis()->SetTitleOffset(0.9);
   plj__5->GetXaxis()->SetTitleFont(42);
   plj__5->GetYaxis()->SetLabelFont(42);
   plj__5->GetYaxis()->SetLabelOffset(0.007);
   plj__5->GetYaxis()->SetTitleSize(0.06);
   plj__5->GetYaxis()->SetTitleOffset(1.1);
   plj__5->GetYaxis()->SetTitleFont(42);
   plj__5->GetZaxis()->SetLabelFont(42);
   plj__5->GetZaxis()->SetLabelOffset(0.007);
   plj__5->GetZaxis()->SetTitleSize(0.06);
   plj__5->GetZaxis()->SetTitleFont(42);
   hs->Add(plj,"");
   
   TH1D *t_ZA__6 = new TH1D("t_ZA__6","",8,0,8);
   t_ZA__6->SetBinContent(1,36.88034);
   t_ZA__6->SetBinContent(2,5.086841);
   t_ZA__6->SetBinContent(3,1.385151);
   t_ZA__6->SetBinContent(4,30.05165);
   t_ZA__6->SetBinContent(5,13.7055);
   t_ZA__6->SetBinContent(6,2.393915);
   t_ZA__6->SetBinContent(7,12.15066);
   t_ZA__6->SetBinContent(8,4.582542);
   t_ZA__6->SetBinError(1,9.315369);
   t_ZA__6->SetBinError(2,2.019714);
   t_ZA__6->SetBinError(3,1.128486);
   t_ZA__6->SetBinError(4,5.235741);
   t_ZA__6->SetBinError(5,3.135466);
   t_ZA__6->SetBinError(6,1.016365);
   t_ZA__6->SetBinError(7,2.547177);
   t_ZA__6->SetEntries(8);

   ci = TColor::GetColor("#ff00ff");
   t_ZA__6->SetFillColor(ci);

   ci = TColor::GetColor("#ff00ff");
   t_ZA__6->SetLineColor(ci);
   t_ZA__6->SetLineStyle(0);
   t_ZA__6->SetLineWidth(2);

   ci = TColor::GetColor("#ff00ff");
   t_ZA__6->SetMarkerColor(ci);
   t_ZA__6->SetMarkerStyle(20);
   t_ZA__6->GetXaxis()->SetLabelFont(42);
   t_ZA__6->GetXaxis()->SetLabelOffset(0.007);
   t_ZA__6->GetXaxis()->SetTitleSize(0.06);
   t_ZA__6->GetXaxis()->SetTitleOffset(0.9);
   t_ZA__6->GetXaxis()->SetTitleFont(42);
   t_ZA__6->GetYaxis()->SetLabelFont(42);
   t_ZA__6->GetYaxis()->SetLabelOffset(0.007);
   t_ZA__6->GetYaxis()->SetTitleSize(0.06);
   t_ZA__6->GetYaxis()->SetTitleOffset(1.1);
   t_ZA__6->GetYaxis()->SetTitleFont(42);
   t_ZA__6->GetZaxis()->SetLabelFont(42);
   t_ZA__6->GetZaxis()->SetLabelOffset(0.007);
   t_ZA__6->GetZaxis()->SetTitleSize(0.06);
   t_ZA__6->GetZaxis()->SetTitleFont(42);
   hs->Add(t_ZA,"");
   
   TH1D *ZA_sig__7 = new TH1D("ZA_sig__7","",8,0,8);
   ZA_sig__7->SetBinContent(1,9.173001);
   ZA_sig__7->SetBinContent(2,7.900606);
   ZA_sig__7->SetBinContent(3,5.87862);
   ZA_sig__7->SetBinContent(4,1.720542);
   ZA_sig__7->SetBinContent(5,3.961347);
   ZA_sig__7->SetBinContent(6,6.936967);
   ZA_sig__7->SetBinContent(7,0.2978239);
   ZA_sig__7->SetBinContent(8,3.3645);
   ZA_sig__7->SetBinError(1,0.5280247);
   ZA_sig__7->SetBinError(2,0.500354);
   ZA_sig__7->SetBinError(3,0.621096);
   ZA_sig__7->SetBinError(4,0.2308392);
   ZA_sig__7->SetBinError(5,0.3495992);
   ZA_sig__7->SetBinError(6,0.4622478);
   ZA_sig__7->SetBinError(7,0.08842891);
   ZA_sig__7->SetEntries(8);

   ci = TColor::GetColor("#ff3333");
   ZA_sig__7->SetFillColor(ci);

   ci = TColor::GetColor("#ff3333");
   ZA_sig__7->SetLineColor(ci);
   ZA_sig__7->SetLineStyle(0);
   ZA_sig__7->SetLineWidth(2);

   ci = TColor::GetColor("#ff3333");
   ZA_sig__7->SetMarkerColor(ci);
   ZA_sig__7->SetMarkerStyle(21);
   ZA_sig__7->GetXaxis()->SetLabelFont(42);
   ZA_sig__7->GetXaxis()->SetLabelOffset(0.007);
   ZA_sig__7->GetXaxis()->SetTitleSize(0.06);
   ZA_sig__7->GetXaxis()->SetTitleOffset(0.9);
   ZA_sig__7->GetXaxis()->SetTitleFont(42);
   ZA_sig__7->GetYaxis()->SetLabelFont(42);
   ZA_sig__7->GetYaxis()->SetLabelOffset(0.007);
   ZA_sig__7->GetYaxis()->SetTitleSize(0.06);
   ZA_sig__7->GetYaxis()->SetTitleOffset(1.1);
   ZA_sig__7->GetYaxis()->SetTitleFont(42);
   ZA_sig__7->GetZaxis()->SetLabelFont(42);
   ZA_sig__7->GetZaxis()->SetLabelOffset(0.007);
   ZA_sig__7->GetZaxis()->SetTitleSize(0.06);
   ZA_sig__7->GetZaxis()->SetTitleFont(42);
   hs->Add(ZA_sig,"");
   hs->Draw("hist");
   
   TLegend *leg = new TLegend(0.82,0.7,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("ZA_sig","ZA_sig","lpf");

   ci = TColor::GetColor("#ff3333");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff3333");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff3333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("t_ZA","ZA","lpf");

   ci = TColor::GetColor("#ff00ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff00ff");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff00ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("plj","non-prompt","lpf");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ffff00");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("WA","WA","lpf");

   ci = TColor::GetColor("#000099");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("VV","VV","lpf");

   ci = TColor::GetColor("#6666cc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#6666cc");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#6666cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("TTA","TTA","lpf");

   ci = TColor::GetColor("#00ffff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ffff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("ST","ST","lpf");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.18,0.82,"Preliminary");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.18,0.86,"CMS");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.76,0.92,"57.1 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
   pad1->Modified();
   ->cd();
   c1->Modified();
   ->cd();
   ->SetSelected();
}
