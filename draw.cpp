#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"

void draw(std::string archivo) {
    std::string ruta = "/home/tristany/Documentos/Tesis/eposlhc_fullMonteCarlo_62days/proton_img/";
    std::string ruta_doc = "/home/tristany/Documentos/Tesis/eposlhc_fullMonteCarlo_62days/proton_analizados/";
    std::string doc = ruta_doc + archivo;
    std::string arch = archivo.substr(0, archivo.size()-5);
    TFile* f = TFile::Open(doc.c_str());
    TCanvas *c1 = new TCanvas ("c1", "guardar", 800, 600);
    c1->SetLogy(1);

    std::string pref = "h";
    for (size_t i = 1; i <= 32; i++) {
        std::string histname = pref + std::to_string(i);
        //std::string imgname = "mult_f_";
        TH1F* hist = (TH1F*) f->Get(histname.c_str());
        hist->Draw();
        std::string multiplicidad;
        if (i == 1) {multiplicidad = "1-5";}
        if (i == 2) {multiplicidad = "5-10";}
        if (i == 3) {multiplicidad = "10-15";}
        if (i == 4) {multiplicidad = "15-20";}
        if (i >= 5) {multiplicidad = std::to_string((i-3)*10) + "-" + std::to_string((i-2)*10);}

        std::string ruta_completa = ruta + arch + "_" + multiplicidad + ".png";
        c1->SaveAs(ruta_completa.c_str());
    }
    f->Close();
}