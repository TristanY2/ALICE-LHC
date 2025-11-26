#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

// root 'macro.cpp("/home/Documentos/Tesis/Datos/Documento")'
// How to run it

void macro_rangopcov(const std::string archivo, int i) {

    std::string ruta_datos = "/home/tristany/Documentos/Tesis/DATOS/";
    std::string ruta_resultados = "/home/tristany/Documentos/Tesis/datos_pcov/remake/";

    std::string abrir = ruta_datos + archivo;
    
    TFile* file = TFile::Open(abrir.c_str());
    TTree* tree = (TTree*)file->Get("fDatree;1");

    std::string nombre = "Pcov_";
    std::string nombre_arch = archivo.substr(0, archivo.size() - 5);
    std::string root = ".root";
    std::string archivo_salida = ruta_resultados + nombre + nombre_arch + root;

    TFile *filtrado = new TFile(archivo_salida.c_str(), "RECREATE");

    std::string R1 = "Pcov>20 && Pcov<=27";
    std::string R2 = "Pcov>27 && Pcov<=34.5";
    std::string R3 = "Pcov>34.5 && Pcov<=42";
    std::string R4 = "Pcov>42 && Pcov<=50";
    std::string R5 = "Pcov>50 && Pcov<=58.5";
    std::string R6 = "Pcov>58.5 && Pcov<=68.5";
    std::string R7 = "Pcov>68.5 && Pcov<=81.5";
    std::string R8 = "Pcov>81.5 && Pcov<=100";
    std::string R9 = "Pcov>100 && Pcov<=132";
    std::string R10 = "Pcov>132 && Pcov<=200";
    std::string R11 = "Pcov>200 && Pcov<=300";
    std::string R12 = "Pcov>300 && Pcov<=500";
    std::string R13 = "Pcov>500 && Pcov<=1000";
    std::string R14 = "Pcov>1000 && Pcov<=3000";
    std::string rangos[14] = {R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14};

    std::string theta_1 = " && upthetaCos<=12.8385";
    std::string theta_2 = " && upthetaCos>12.8385 && upthetaCos<=20.2816";
    std::string theta_3 = " && upthetaCos>20.2816 && upthetaCos<=25.8419";
    std::string theta_4 = " && upthetaCos>25.8419 && upthetaCos<=34.4115";
    std::string theta_5 = " && upthetaCos>34.4115 && upthetaCos<=41.4096";
    std::string theta_6 = " && upthetaCos>41.4096 && upthetaCos<=47.5458";
    std::string theta_7 = " && upthetaCos>47.5458 && upthetaCos<=53.1301";
    std::string theta_8 = " && upthetaCos>53.1301 && upthetaCos<=58.3317";
    std::string thethas[8] = {theta_1, theta_2, theta_3, theta_4, theta_5, theta_6, theta_7, theta_8};

    for (size_t i = 1; i <= 14; i++) {
        for (size_t j = 1; j <= 8; j++) {
            std::string h_din = std::to_string(i) + "_theta_" + std::to_string(j);
            std::string p_nombre = "p_" + h_din;
            std::string m_nombre = "m_" + h_din;

            TH1F *histp = new TH1F(p_nombre.c_str(), "Rango de Pcov", 3000, 0, 3000);
            TH1F *histm = new TH1F(m_nombre.c_str(), "Promedio de nMuons", 1000, 0, 1000);
            std::string h_p = "Pcov>>" + p_nombre;
            std::string h_m = "nMuons>>" + m_nombre;

            std::string filtro = rangos[i-1] + thethas[j-1];
            tree->Draw(h_p.c_str(), filtro.c_str());
            tree->Draw(h_m.c_str(), filtro.c_str());

            histp->Write();
            histm->Write();
        }
    }

    filtrado->Close();
    file->Close();
    std::cout << archivo << std::endl;
}