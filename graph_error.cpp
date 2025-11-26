#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TLatex.h"

void graph_error(std::string archivo, int contador) {
    std::string ruta = "/home/tristany/Documentos/Tesis/datos_pcov/0-Merged/";
    std::string ruta_doc = "/home/tristany/Documentos/Tesis/datos_pov/0-Merged/";
    std::string doc = ruta_doc + archivo;
    std::string arch = archivo.substr(0, archivo.size()-5);
    //std::string modelo = archivo.substr(0,10);
    //TFile* f = TFile::Open(doc.c_str());
    TCanvas *c1 = new TCanvas ("c1", "guardar", 800, 600);
    //c1->SetLogy(1);
    std::vector<Float_t> promedios_c;
    std::vector<Float_t> errores_c;
    std::vector<Float_t> promedios_f;
    std::vector<Float_t> errores_f;
    std::vector<Float_t> multiplicidad;

    //Valores de ALICE
    //std::vector<Float_t> ALICE_promedios_c = {27.6079,93.667,102.671,115.707,117.004,106.396,103.858,111.619,84.4484,93.417,153.995,78.4209,95.1282,155.796,187.512,99.1365,54.5159};
    //std::vector<Float_t> ALICE_errores_c = {0.0054716,0.790393,1.71485,2.85125,2.97938,4.29955,5.4239,9.9,7.02021,8.31898,11.1555,11.9243,8.95366,10.9538,21.57,20.8365,6.89759};
    std::vector<Float_t> ALICE_promedios_c = {27.6079,93.667,102.671,115.707,117.004,106.396,103.858,111.619,84.4484,93.417,153.995,78.4209,95.1282,155.796,187.512,99.1365,54.5159};
    std::vector<Float_t> ALICE_errores_c = {0.0054716,0.790393,1.71485,2.85125,2.97938,4.29955,5.4239,9.9,7.02021,8.31898,11.1555,11.9243,8.95366,10.9538,21.57,20.8365,6.89759};

    // Promediar 9-10-11, luego a los posteriores 10-11-12
    //std::vector<Float_t> ALICE_promedios_f = {21.2875,48.6823,50.7046,55.2981,55.0093,55.0703,54.7953,62.0277,51.2614,50.5304,76.3611,52.9214,50.5243,69.243,84.4211,64.0016,50.8783,36.6146,34.209};
    //std::vector<Float_t> ALICE_errores_f = {0.00264839,0.293783,0.599086,0.976104,0.981752,1.52601,1.94928,3.86219,2.97321,3.0664,4.06129,5.38515,3.11572,3.81904,8.53675,8.04056,4.57243,3.42913,2.34918};
    std::vector<Float_t> ALICE_promedios_f = {21.2875,48.6823,50.7046,55.2981,55.0093,55.0703,54.7953,62.0277,59.3843,57.5629,84.4211,64.0016,40.5673};
    std::vector<Float_t> ALICE_errores_f = {0.00264839,0.293783,0.599086,0.976104,0.981752,1.52601,1.94928,3.86219,3.367,4.1066,8.53675,8.04056,3.4502};
    //std::vector<Float_t> ALICE_multiplicidad = {2.5,7.5,12.5,17.5,25,35,45,55,65,75,85,95,105,125,155,165,205,245,285};
    std::vector<Float_t> ALICE_multiplicidad = {2.5,7.5,12.5,17.5,25,35,45,55,75,108,155,165,245};

    //std::string pref = "h";
    /*
    for (size_t i = 1; i <= 32; i++) {
        std::string histname_c = "h" + std::to_string(i);
        std::string histname_f = "f" + std::to_string(i);

        TH1F* hist_c = (TH1F*) f->Get(histname_c.c_str());
        TH1F* hist_f = (TH1F*) f->Get(histname_f.c_str());
        int entradas = hist_c->GetEntries();
        if (entradas == 0) {continue;}

        float prom_c = hist_c->GetMean();
        float err_c = hist_c->GetMeanError();

        float prom_f = hist_f->GetMean();
        float err_f = hist_f->GetMeanError();

        if (prom_f <10 || prom_c < 10) {continue;}

        promedios_c.push_back(prom_c);
        errores_c.push_back(err_c);

        promedios_f.push_back(prom_f);
        errores_f.push_back(err_f);

        if (i == 1) {multiplicidad.push_back(2.5);}
        if (i == 2) {multiplicidad.push_back(7.5);}
        if (i == 3) {multiplicidad.push_back(12.5);}
        if (i == 4) {multiplicidad.push_back(17.5);}
        if (i >= 5) {multiplicidad.push_back((i-3)*10+5);}
    }
    */

    //TGraphErrors *gr1 = new TGraphErrors(multiplicidad.size(), multiplicidad.data(), promedios_c.data(), nullptr, errores_c.data());
    //gr1->SetTitle("Promedio de Pcov vs Multiplicidad");
    //gr1->GetXaxis()->SetTitle("Multiplicidad");
    //gr1->GetYaxis()->SetTitle("Promedio Pcov");
    //gr1->SetMarkerStyle(20);
    //gr1->SetMarkerColor(kGreen + 2);
    //gr1->SetLineColor(kGreen + 2);

    //TGraphErrors *gr2 = new TGraphErrors(multiplicidad.size(), multiplicidad.data(), promedios_f.data(), nullptr, errores_f.data());
    //gr2->SetMarkerStyle(21);
    //gr2->SetMarkerColor(kBlue);
    //gr2->SetLineColor(kBlue);

    TGraphErrors *gr3 = new TGraphErrors(ALICE_multiplicidad.size(), ALICE_multiplicidad.data(), ALICE_promedios_c.data(), nullptr, ALICE_errores_c.data());
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kBlue);
    gr3->SetLineColor(kBlue);

    TGraphErrors *gr4 = new TGraphErrors(ALICE_multiplicidad.size(), ALICE_multiplicidad.data(), ALICE_promedios_f.data(), nullptr, ALICE_errores_f.data());
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(kRed);
    gr4->SetLineColor(kRed);

    Float_t M = ALICE_promedios_c[0];
    /*for (Float_t m: promedios_c) {
        if (M < m) {M = m;}
    }
    for (Float_t m: promedios_f) {
        if (M < m) {M = m;}
    }*/
    for (Float_t m: ALICE_promedios_c) {
        if (M < m) {M = m;}
    }
    for (Float_t m: ALICE_promedios_f) {
        if (M < m) {M = m;}
    }

    TMultiGraph *mg = new TMultiGraph();
    //mg->SetTitle("En esta tesis");
    //mg->Add(gr1);
    //mg->Add(gr2);
    mg->Add(gr3);
    mg->Add(gr4);
    mg->Draw("APL");
    mg->GetXaxis()->SetRangeUser(0, 300);
    mg->GetYaxis()->SetRangeUser(0, M*1.1); 
    mg->GetXaxis()->SetTitle("N_{#mu}");
    mg->GetYaxis()->SetTitle("#LT p #GT");
    mg->GetXaxis()->CenterTitle(true);
    mg->GetYaxis()->CenterTitle(true);

    std::string leyenda_c = "Muestra completa";
    std::string leyenda_f = "Muestra filtrada";

    auto leyenda = new TLegend(0.6, 0.7, 0.88, 0.88);
    //leyenda->SetHeader("En esta tesis", "C");
    //leyenda->AddEntry(gr1, leyenda_c.c_str(), "lp");
    //leyenda->AddEntry(gr2, leyenda_f.c_str(), "lp");
    leyenda->AddEntry(gr3, "Muestra completa", "lp");
    leyenda->AddEntry(gr4, "Muestra filtrada", "lp");

    leyenda->Draw();
    //std::cout << m1 << "\n";
    std::string ruta_completa = ruta + arch + "vs_ALICE_error.png";
    c1->SaveAs(ruta_completa.c_str());
    //f->Close();
}