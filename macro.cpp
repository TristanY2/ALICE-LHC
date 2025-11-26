#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

// root 'macro.cpp("/home/Documentos/Tesis/Datos/Documento")'
// How to run it

void macro(const std::string archivo, int i) {

    std::string ruta_datos = "/home/tristany/Documentos/Tesis/qgsjet_fullMonteCarlo_62days/proton_todos/";
    std::string ruta_resultados = "/home/tristany//Documentos/Tesis/qgsjet_fullMonteCarlo_62days/proton_analizados//";

    std::string abrir = ruta_datos + archivo;
    
    TFile* file = TFile::Open(abrir.c_str());
    TTree* tree = (TTree*)file->Get("fDatree;1");
    TH1F *h1 = new TH1F("h1", "Multiplicidad", 100, 0, 3000);
    TH1F *h2 = new TH1F("h2", "Multiplicidad", 100, 0, 3000);
    TH1F *h3 = new TH1F("h3", "Multiplicidad", 100, 0, 3000);
    TH1F *h4 = new TH1F("h4", "Multiplicidad", 100, 0, 3000);
    TH1F *h5 = new TH1F("h5", "Multiplicidad", 100, 0, 3000);
    TH1F *h6 = new TH1F("h6", "Multiplicidad", 100, 0, 3000);
    TH1F *h7 = new TH1F("h7", "Multiplicidad", 100, 0, 3000);
    TH1F *h8 = new TH1F("h8", "Multiplicidad", 100, 0, 3000);
    TH1F *h9 = new TH1F("h9", "Multiplicidad", 100, 0, 3000);
    TH1F *h10 = new TH1F("h10", "Multiplicidad", 100, 0, 3000);
    TH1F *h11 = new TH1F("h11", "Multiplicidad", 100, 0, 3000);
    TH1F *h12 = new TH1F("h12", "Multiplicidad", 100, 0, 3000);
    TH1F *h13 = new TH1F("h13", "Multiplicidad", 100, 0, 3000);
    TH1F *h14 = new TH1F("h14", "Multiplicidad", 100, 0, 3000);
    TH1F *h15 = new TH1F("h15", "Multiplicidad", 100, 0, 3000);
    TH1F *h16 = new TH1F("h16", "Multiplicidad", 100, 0, 3000);
    TH1F *h17 = new TH1F("h17", "Multiplicidad", 100, 0, 3000);
    TH1F *h18 = new TH1F("h18", "Multiplicidad", 100, 0, 3000);
    TH1F *h19 = new TH1F("h19", "Multiplicidad", 100, 0, 3000);
    TH1F *h20 = new TH1F("h20", "Multiplicidad", 100, 0, 3000);
    TH1F *h21 = new TH1F("h21", "Multiplicidad", 100, 0, 3000);
    TH1F *h22 = new TH1F("h22", "Multiplicidad", 100, 0, 3000);
    TH1F *h23 = new TH1F("h23", "Multiplicidad", 100, 0, 3000);
    TH1F *h24 = new TH1F("h24", "Multiplicidad", 100, 0, 3000);
    TH1F *h25 = new TH1F("h25", "Multiplicidad", 100, 0, 3000);
    TH1F *h26 = new TH1F("h26", "Multiplicidad", 100, 0, 3000);
    TH1F *h27 = new TH1F("h27", "Multiplicidad", 100, 0, 3000);
    TH1F *h28 = new TH1F("h28", "Multiplicidad", 100, 0, 3000);
    TH1F *h29 = new TH1F("h29", "Multiplicidad", 100, 0, 3000);
    TH1F *h30 = new TH1F("h30", "Multiplicidad", 100, 0, 3000);
    TH1F *h31 = new TH1F("h31", "Multiplicidad", 100, 0, 3000);
    TH1F *h32 = new TH1F("h32", "Multiplicidad", 100, 0, 3000);
    
    tree->Draw("Pcov>>h1", "nMuons>0 && nMuons<=5");
    tree->Draw("Pcov>>h2", "nMuons>5 && nMuons<=10");
    tree->Draw("Pcov>>h3", "nMuons>10 && nMuons<=15");
    tree->Draw("Pcov>>h4", "nMuons>15 && nMuons<=20");
    tree->Draw("Pcov>>h5", "nMuons>20 && nMuons<=30");
    tree->Draw("Pcov>>h6", "nMuons>30 && nMuons<=40");
    tree->Draw("Pcov>>h7", "nMuons>40 && nMuons<=50");
    tree->Draw("Pcov>>h8", "nMuons>50 && nMuons<=60");
    tree->Draw("Pcov>>h9", "nMuons>60 && nMuons<=70");
    tree->Draw("Pcov>>h10", "nMuons>70 && nMuons<=80");
    tree->Draw("Pcov>>h11", "nMuons>80 && nMuons<=90");
    tree->Draw("Pcov>>h12", "nMuons>90 && nMuons<=100");
    tree->Draw("Pcov>>h13", "nMuons>100 && nMuons<=110");
    tree->Draw("Pcov>>h14", "nMuons>110 && nMuons<=120");
    tree->Draw("Pcov>>h15", "nMuons>120 && nMuons<=130");
    tree->Draw("Pcov>>h16", "nMuons>130 && nMuons<=140");
    tree->Draw("Pcov>>h17", "nMuons>140 && nMuons<=150");
    tree->Draw("Pcov>>h18", "nMuons>150 && nMuons<=160");
    tree->Draw("Pcov>>h19", "nMuons>160 && nMuons<=170");
    tree->Draw("Pcov>>h20", "nMuons>170 && nMuons<=180");
    tree->Draw("Pcov>>h21", "nMuons>180 && nMuons<=190");
    tree->Draw("Pcov>>h22", "nMuons>190 && nMuons<=200");
    tree->Draw("Pcov>>h23", "nMuons>200 && nMuons<=210");
    tree->Draw("Pcov>>h24", "nMuons>210 && nMuons<=220");
    tree->Draw("Pcov>>h25", "nMuons>220 && nMuons<=230");
    tree->Draw("Pcov>>h26", "nMuons>230 && nMuons<=240");
    tree->Draw("Pcov>>h27", "nMuons>240 && nMuons<=250");
    tree->Draw("Pcov>>h28", "nMuons>250 && nMuons<=260");
    tree->Draw("Pcov>>h29", "nMuons>260 && nMuons<=270");
    tree->Draw("Pcov>>h30", "nMuons>270 && nMuons<=280");
    tree->Draw("Pcov>>h31", "nMuons>280 && nMuons<=290");
    tree->Draw("Pcov>>h32", "nMuons>290 && nMuons<=300");

    TH1F *f1 = new TH1F("f1", "Multiplicidad", 100, 0, 3000);
    TH1F *f2 = new TH1F("f2", "Multiplicidad", 100, 0, 3000);
    TH1F *f3 = new TH1F("f3", "Multiplicidad", 100, 0, 3000);
    TH1F *f4 = new TH1F("f4", "Multiplicidad", 100, 0, 3000);
    TH1F *f5 = new TH1F("f5", "Multiplicidad", 100, 0, 3000);
    TH1F *f6 = new TH1F("f6", "Multiplicidad", 100, 0, 3000);
    TH1F *f7 = new TH1F("f7", "Multiplicidad", 100, 0, 3000);
    TH1F *f8 = new TH1F("f8", "Multiplicidad", 100, 0, 3000);
    TH1F *f9 = new TH1F("f9", "Multiplicidad", 100, 0, 3000);
    TH1F *f10 = new TH1F("f10", "Multiplicidad", 100, 0, 3000);
    TH1F *f11 = new TH1F("f11", "Multiplicidad", 100, 0, 3000);
    TH1F *f12 = new TH1F("f12", "Multiplicidad", 100, 0, 3000);
    TH1F *f13 = new TH1F("f13", "Multiplicidad", 100, 0, 3000);
    TH1F *f14 = new TH1F("f14", "Multiplicidad", 100, 0, 3000);
    TH1F *f15 = new TH1F("f15", "Multiplicidad", 100, 0, 3000);
    TH1F *f16 = new TH1F("f16", "Multiplicidad", 100, 0, 3000);
    TH1F *f17 = new TH1F("f17", "Multiplicidad", 100, 0, 3000);
    TH1F *f18 = new TH1F("f18", "Multiplicidad", 100, 0, 3000);
    TH1F *f19 = new TH1F("f19", "Multiplicidad", 100, 0, 3000);
    TH1F *f20 = new TH1F("f20", "Multiplicidad", 100, 0, 3000);
    TH1F *f21 = new TH1F("f21", "Multiplicidad", 100, 0, 3000);
    TH1F *f22 = new TH1F("f22", "Multiplicidad", 100, 0, 3000);
    TH1F *f23 = new TH1F("f23", "Multiplicidad", 100, 0, 3000);
    TH1F *f24 = new TH1F("f24", "Multiplicidad", 100, 0, 3000);
    TH1F *f25 = new TH1F("f25", "Multiplicidad", 100, 0, 3000);
    TH1F *f26 = new TH1F("f26", "Multiplicidad", 100, 0, 3000);
    TH1F *f27 = new TH1F("f27", "Multiplicidad", 100, 0, 3000);
    TH1F *f28 = new TH1F("f28", "Multiplicidad", 100, 0, 3000);
    TH1F *f29 = new TH1F("f29", "Multiplicidad", 100, 0, 3000);
    TH1F *f30 = new TH1F("f30", "Multiplicidad", 100, 0, 3000);
    TH1F *f31 = new TH1F("f31", "Multiplicidad", 100, 0, 3000);
    TH1F *f32 = new TH1F("f32", "Multiplicidad", 100, 0, 3000);
    
    tree->Draw("Pcov>>f1", "nMuons>0 && nMuons<=5 && Pcov <= 220");
    tree->Draw("Pcov>>f2", "nMuons>5 && nMuons<=10 && Pcov <= 220");
    tree->Draw("Pcov>>f3", "nMuons>10 && nMuons<=15 && Pcov <= 220");
    tree->Draw("Pcov>>f4", "nMuons>15 && nMuons<=20 && Pcov <= 220");
    tree->Draw("Pcov>>f5", "nMuons>20 && nMuons<=30 && Pcov <= 220");
    tree->Draw("Pcov>>f6", "nMuons>30 && nMuons<=40 && Pcov <= 220");
    tree->Draw("Pcov>>f7", "nMuons>40 && nMuons<=50 && Pcov <= 220");
    tree->Draw("Pcov>>f8", "nMuons>50 && nMuons<=60 && Pcov <= 220");
    tree->Draw("Pcov>>f9", "nMuons>60 && nMuons<=70 && Pcov <= 220");
    tree->Draw("Pcov>>f10", "nMuons>70 && nMuons<=80 && Pcov <= 220");
    tree->Draw("Pcov>>f11", "nMuons>80 && nMuons<=90 && Pcov <= 220");
    tree->Draw("Pcov>>f12", "nMuons>90 && nMuons<=100 && Pcov <= 220");
    tree->Draw("Pcov>>f13", "nMuons>100 && nMuons<=110 && Pcov <= 220");
    tree->Draw("Pcov>>f14", "nMuons>110 && nMuons<=120 && Pcov <= 220");
    tree->Draw("Pcov>>f15", "nMuons>120 && nMuons<=130 && Pcov <= 220");
    tree->Draw("Pcov>>f16", "nMuons>130 && nMuons<=140 && Pcov <= 220");
    tree->Draw("Pcov>>f17", "nMuons>140 && nMuons<=150 && Pcov <= 220");
    tree->Draw("Pcov>>f18", "nMuons>150 && nMuons<=160 && Pcov <= 220");
    tree->Draw("Pcov>>f19", "nMuons>160 && nMuons<=170 && Pcov <= 220");
    tree->Draw("Pcov>>f20", "nMuons>170 && nMuons<=180 && Pcov <= 220");
    tree->Draw("Pcov>>f21", "nMuons>180 && nMuons<=190 && Pcov <= 220");
    tree->Draw("Pcov>>f22", "nMuons>190 && nMuons<=200 && Pcov <= 220");
    tree->Draw("Pcov>>f23", "nMuons>200 && nMuons<=210 && Pcov <= 220");
    tree->Draw("Pcov>>f24", "nMuons>210 && nMuons<=220 && Pcov <= 220");
    tree->Draw("Pcov>>f25", "nMuons>220 && nMuons<=230 && Pcov <= 220");
    tree->Draw("Pcov>>f26", "nMuons>230 && nMuons<=240 && Pcov <= 220");
    tree->Draw("Pcov>>f27", "nMuons>240 && nMuons<=250 && Pcov <= 220");
    tree->Draw("Pcov>>f28", "nMuons>250 && nMuons<=260 && Pcov <= 220");
    tree->Draw("Pcov>>f29", "nMuons>260 && nMuons<=270 && Pcov <= 220");
    tree->Draw("Pcov>>f30", "nMuons>270 && nMuons<=280 && Pcov <= 220");
    tree->Draw("Pcov>>f31", "nMuons>280 && nMuons<=290 && Pcov <= 220");
    tree->Draw("Pcov>>f32", "nMuons>290 && nMuons<=300 && Pcov <= 220");

    std::string nombre = "mult_";
    std::string nombre_arch = archivo.substr(0, archivo.size() - 5);
    std::string root = ".root";
    std::string archivo_salida = ruta_resultados + nombre + nombre_arch + root;

    TFile *filtrado = new TFile(archivo_salida.c_str(), "RECREATE");
    h1->Write();
    h2->Write();
    h3->Write();
    h4->Write();
    h5->Write();
    h6->Write();
    h7->Write();
    h8->Write();
    h9->Write();
    h10->Write();
    h11->Write();
    h12->Write();
    h13->Write();
    h14->Write();
    h15->Write();
    h16->Write();
    h17->Write();
    h18->Write();
    h19->Write();
    h20->Write();
    h21->Write();
    h22->Write();
    h23->Write();
    h24->Write();
    h25->Write();
    h26->Write();
    h27->Write();
    h28->Write();
    h29->Write();
    h30->Write();
    h31->Write();
    h32->Write();

    f1->Write();
    f2->Write();
    f3->Write();
    f4->Write();
    f5->Write();
    f6->Write();
    f7->Write();
    f8->Write();
    f9->Write();
    f10->Write();
    f11->Write();
    f12->Write();
    f13->Write();
    f14->Write();
    f15->Write();
    f16->Write();
    f17->Write();
    f18->Write();
    f19->Write();
    f20->Write();
    f21->Write();
    f22->Write();
    f23->Write();
    f24->Write();
    f25->Write();
    f26->Write();
    f27->Write();
    f28->Write();
    f29->Write();
    f30->Write();
    f31->Write();
    f32->Write();

    filtrado->Close();
    file->Close();
    std::cout << archivo << std::endl;
}