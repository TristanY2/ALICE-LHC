#include <iostream>
#include <fstream>
#include <string>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

// root 'macro.cpp("/home/Documentos/Tesis/Datos/Documento")'
// How to run it

void imprimir(const std::string archivo, int i) {

    std::string ruta_datos = "/home/tristany/Documentos/Tesis/qgsjet_fullMonteCarlo_62days/proton_analizados/";

    std::string abrir = ruta_datos + archivo;
    
    TFile* f = TFile::Open(abrir.c_str());

    for (size_t i = 1; i <= 8; i++) {
        std::cout << " " << std::endl;
        std::cout << "P_theta_" + std::to_string(i) << std::endl;
        for (size_t j = 1; j <= 14; j++) {
            std::string h_din = std::to_string(j) + "_theta_" + std::to_string(i);
            std::string p_nombre = "p_" + h_din;

            TH1F *hp = (TH1F*)f->Get(p_nombre.c_str());

            float meanp = hp->GetMean();
            std::cout << meanp << std::endl;
        }
        std::cout << " " << std::endl;
        std::cout << "M_theta_" + std::to_string(i) << std::endl;
        for (size_t j = 1; j <= 14; j++) {
            std::string h_din = std::to_string(j) + "_theta_" + std::to_string(i);
            std::string m_nombre = "m_" + h_din;

            TH1F *hm = (TH1F*)f->Get(m_nombre.c_str());

            float meanm = hm->GetMean();
            std::cout << meanm << std::endl;
        }
    }

    f->Close();
    std::cout << archivo << std::endl;
}