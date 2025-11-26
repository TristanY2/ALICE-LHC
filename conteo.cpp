#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TGraphErrors.h"
#include <iostream>
#include <vector>
#include <string>

void conteo(std::string archivo) {
    /*TFile* file = new TFile("LHC15a_Bminus_oct18.root");
    TTree* tree = (TTree*)file->Get("fDatree;1");
    TApplication app("App", 0, 0);

    Double_t Promedios_mal[15] = {};
    Double_t Promedios[15] = {20.9, 50.94, 52.49, 65.33, 52.1, 60.48, 57.48, 42.61, 50.53, 74.34, 51.81, 47.26, 90.52, 51.05, 71.37};
    Double_t valores[15] = {2.5, 7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5, 47.5, 57.5, 62.5, 82.5, 97.5, 107.5};
    Double_t errx[15] = {0.006, 0.878, 1.701, 3.341, 3.874, 5.253, 6.249, 4.676, 7.169, 10.577, 12.078, 4.572, 9.734, 7.226, 9.005};

    //TH1F *hist = new TH1F("Prueba", "Pcov promedio", bines, min, max);

    TCanvas *canva = new TCanvas("c1", "Canva", 800, 600);
    //hist->Draw();
    TGraphErrors *gr = new TGraphErrors(15, valores, Promedios, nullptr, errx);
    gr->SetMarkerStyle(20);
    gr->Draw("ALP");
    canva->Update();
    
    std::cout << "Enter para finalizar" <<std::endl;
    std::cin.get();
    return 0;*/

    std::string ruta = "/home/tristany//Documentos/Tesis/datos_pcov/0-Merged/" + archivo;
    TFile* f = TFile::Open(ruta.c_str());
    //std::string pref[2] = {"h", "m"};
    std::string pref[1] = {"h"};
    Float_t mean[19];
    Float_t err[19];
    Float_t vals[19];
    int j = 0;
    TCanvas *c1 = new TCanvas("c1", "si", 800,600);
    for (std::string p : pref) {
        for (size_t i = 1; i <= 32; i++) {
            std::string histname = p + std::to_string(i);
            TH1F* hist = (TH1F*) f->Get(histname.c_str());
            Float_t prom = hist->GetMean();
            if (prom == 0) {continue;}
            Float_t error = hist->GetMeanError();
            std::cout << histname << "-> Promedio: " << prom << "     " << "Error: " << error << std::endl;
            mean[j] = prom;
            err[j] = error;
            if (i <=4) {vals[j] = i*5-2.5;}
            else {vals[j] = (i-2)*10-5;}
            j+=1;
        }
    }
    TGraphErrors *gr = new TGraphErrors(19, vals, mean, nullptr, err);
    gr->SetMarkerStyle(20);
    gr->Draw("ALP");
    std::string nombre = "error.png";
    c1->SaveAs(nombre.c_str());
    f->Close();
}