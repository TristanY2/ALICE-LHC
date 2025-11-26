#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include <iostream>
#include <vector>
#include <string>

void graficar(){
    /*Float_t vals[19] = {2.5,7.5,12.5,17.5,25,35,45,55,65,75,85,95,105,125,155,165,205,245,285};
    Float_t mean_crudo[19] = {27.6079, 93.667, 102.671, 115.707, 117.004, 106.396, 103.858, 111.619, 84.4484, 93.419, 153.995, 78.4209, 95.1282, 155.796, 187.512, 99.1356, 76.5394, 47.3424, 39.6661};
    Float_t mean_filtrado[19] = {21.2875, 48.6823, 50.7046, 55.2981, 55.0093, 55.0703, 54.7953, 61.0277, 51.2614, 50.5304, 76.3611, 52.9214, 50.5243, 69.243, 84.4211, 64.0016, 50.8783, 36.6146, 34.209};

    Float_t err_crudo[19] = {0.0054716, 0.790393, 1.71485, 2.85125, 2.97938, 4.29955, 5.4239, 9.9, 7.02021, 8.31898, 11.1555, 11.9243, 8.95366, 10.9538, 21.57, 20.8365, 10.3023, 6.77107, 3.61094};
    Float_t err_filtrado[19] = {0.00264839, 0.293783, 0.599086, 0.976104, 0.981752, 1.52601, 1.94928, 3.86129, 2.97321, 3.0664, 4.06129, 5.38515, 3.11572, 3.81904, 8.53675, 8.04056, 4.57243, 3.42913, 2.34918};

    TCanvas *c1 = new TCanvas("c1", "si", 1200, 900);
    TGraphErrors *gr1 = new TGraphErrors(19, vals, mean_crudo, nullptr, err_crudo);
    gr1->SetTitle("Promedio de Pcov vs Multiplicidad");
    gr1->GetXaxis()->SetTitle("Multiplicidad");
    gr1->GetYaxis()->SetTitle("Promedio Pcov");
    gr1->SetMarkerStyle(20);
    gr1->SetMarkerColor(kBlue);
    gr1->SetLineColor(kBlue);

    TGraphErrors *gr2 = new TGraphErrors(19, vals, mean_filtrado, nullptr, err_filtrado);
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed);
    gr2->SetLineColor(kBlue);

    gr1->Draw("ALP");
    gr2->Draw("LP SAME");

    auto leyenda = new TLegend(0.6, 0.7, 0.88, 0.88);
    leyenda->SetHeader("Datos", "C");
    leyenda->AddEntry(gr1, "sin filtrar", "lp");
    leyenda->AddEntry(gr2, "filtrada(Pcov<220)", "lp");

    leyenda->Draw();
    c1->SaveAs("Comparacion.png");*/

    std::string ruta_c = "/home/tristany/Documentos/Tesis/datos_pcov/0-Merged/mult_cruda_merged.root";
    std::string ruta_f = "/home/tristany/Documentos/Tesis/datos_pcov/0-Merged/mult_filtrada_merged.root";
    TFile* c = TFile::Open(ruta_c.c_str());
    TFile* f = TFile::Open(ruta_f.c_str());
    TCanvas *c1 = new TCanvas ("c1", "guardar", 800, 600);
    
    std::vector<Float_t> promedios_c;
    std::vector<Float_t> errores_c;
    std::vector<Float_t> promedios_f;
    std::vector<Float_t> errores_f;
    std::vector<Float_t> multiplicidad;

    //std::string pref = "h";
    for (size_t i = 1; i <= 32; i++) {
        std::string histname = "h" + std::to_string(i);

        TH1F* hist_c = (TH1F*) c->Get(histname.c_str());
        TH1F* hist_f = (TH1F*) f->Get(histname.c_str());
        int entradas = hist_c->GetEntries();
        if (entradas == 0) {continue;}

        float prom_c = hist_c->GetMean();
        float err_c = hist_c->GetMeanError();

        float prom_f = hist_f->GetMean();
        float err_f = hist_f->GetMeanError();

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


    TGraphErrors *gr1 = new TGraphErrors(multiplicidad.size(), multiplicidad.data(), promedios_c.data(), nullptr, errores_c.data());
    gr1->SetTitle("Promedio de Pcov vs Multiplicidad");
    gr1->GetXaxis()->SetTitle("Multiplicidad");
    gr1->GetYaxis()->SetTitle("Promedio Pcov");
    gr1->SetMarkerStyle(20);
    gr1->SetMarkerColor(kBlue);
    gr1->SetLineColor(kBlue);

    TGraphErrors *gr2 = new TGraphErrors(multiplicidad.size(), multiplicidad.data(), promedios_f.data(), nullptr, errores_f.data());
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed);
    gr2->SetLineColor(kRed);

    gr1->Draw("ALP");
    Float_t m1 = gr1->GetMaximum(); 
    gr1->GetYaxis()->SetRangeUser(0, m1);
    gr2->Draw("LP SAME");

    auto leyenda = new TLegend(0.6, 0.7, 0.88, 0.88);
    leyenda->SetHeader("Datos", "C");
    leyenda->AddEntry(gr1, "sin filtrar", "lp");
    leyenda->AddEntry(gr2, "filtrada(Pcov<220)", "lp");

    leyenda->Draw();
    
    std::cout << "---Promedios crudos---" << std::endl;
    for (Float_t i: promedios_c) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    std::cout << "---Errores crudos---" << std::endl;
    for (Float_t i: errores_c) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    std::cout << "---Promedios filtrados---" << std::endl;
    for (Float_t i: promedios_f) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    std::cout << "---Promedios crudos---" << std::endl;
    for (Float_t i: errores_f) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    std::cout << "---Multiplicidad---" << std::endl;
    for (Float_t i: multiplicidad) {
        std::cout << i << ",";
    }
    std::cout << std::endl;

    std::string ruta_completa = "/home/tristany/Documentos/Tesis/imagenes/multi_monte_carlo/ALICE_error.png";
    c1->SaveAs(ruta_completa.c_str());
    f->Close();
}