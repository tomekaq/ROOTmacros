#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h> 
#include <TTree.h> 
#include <TBranch.h> 
#include <TClass.h> 

{
gROOT->Reset(); 
gStyle->SetPalette(1);
gROOT->ForceStyle();


auto c1  = new TCanvas("XY","XY",1200,800);
   
TFile *_file0 = TFile::Open("DAT000001_1.root");

TTree *tree;
_file0->GetObject("data_1",tree);

TBranch *xBranch;
Double_t xData; 
tree->SetBranchAddress("x",&xData,&xBranch);

TBranch *yBranch;
Double_t yData;
tree->SetBranchAddress("y",&yData,&yBranch);

int nentries = tree -> GetEntries();

auto *histogram1 = new TH2D("center"		, "" ,200, -1000,1000,200,-1000,1000);
auto *histogram2 = new TH2D("firstcircle"	, "" ,200, -1000,1000,200,-1000,1000);
auto *histogram3 = new TH2D("secondcircle"	, "" ,200, -1000,1000,200,-1000,1000);
auto *histogram4 = new TH2D("thirdcircle"	, "" ,200, -1000,1000,200,-1000,1000);

for(int i=1; i<=nentries; i=i+1)     
{
 tree->GetEntry(i);

if (sqrt(xData*xData + yData * yData) < 1000){
	histogram1-> SetFillColor( kBlue-2);
	histogram1->Fill(xData,yData);
}

if (1000<sqrt(xData*xData + yData * yData) && sqrt(xData*xData + yData * yData) < 2000){
	histogram2-> SetFillColor( kBlue-4);
	histogram2->Fill(xData,yData);}
if (2000<sqrt(xData*xData + yData * yData) && sqrt(xData*xData + yData * yData) < 3000){
	histogram3-> SetFillColor( kBlue-6);
	histogram3->Fill(xData,yData);
}
if (3000<sqrt(xData*xData + yData * yData) && sqrt(xData*xData + yData * yData) < 10000){
	histogram4-> SetFillColor( kBlue-9);
	histogram4->Fill(xData,yData);}
}

histogram1->Draw("box");
histogram2->Draw("boxsame");
histogram3->Draw("boxsame");
histogram4->Draw("boxsame");

auto *histogramEnergy = new TH1D("Energy histogram", "" ,300, 0.001,0.15);

TBranch *eBranch;
Double_t eData; 
tree->SetBranchAddress("e",&eData,&eBranch);
/*
for(int i=1; i<=nentries; i=i+1)   
{
 	tree->GetEntry(i);
	histogramEnergy->Fill(eData);
}



auto c2  = new TCanvas("Energy","Particle Energy",1200,800);
histogramEnergy ->GetXaxis()->SetTitle("Energy in GeV ");
histogramEnergy ->GetYaxis()->SetTitle("Amount");
histogramEnergy->Draw();

auto *histogramID = new TH1D("Type of particles by ID", "" ,20, 0,10.5);

TBranch *idBranch;
Double_t idData; 
tree->SetBranchAddress("id",&idData,&idBranch);
histogramID->GetXaxis()->SetTitle("ID");
histogramID->GetYaxis()->SetTitle("Amount");

for(int i=1; i<=nentries; i=i+1)   
{
 	tree->GetEntry(i);
	histogramID->Fill(idData);
}

auto c3  = new TCanvas("ID","Type particles",1200,800);
histogramID->Draw();
*/
                                                 
}
