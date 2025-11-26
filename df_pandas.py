import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import pandas as pd
import io
import re

full_df = pd.read_csv("/home/tristany/Documentos/ROOT/mult_vs_theta.csv")

alice = full_df[["angulo", "<N_m> ALICE"]]

def graficar(gr, gr2):
    ax = alice.plot(x="angulo", y="<N_m> ALICE", label="ALICE", marker="o", color="red")
    ax.set_ylabel(r"$<N_\mu>$", fontsize=28)
    gr.plot(x="angulo", ax=ax, marker="o", color="orange")
    gr2.plot(x="angulo", ax=ax, marker="o", color="blue")
    ax.set_xlabel(r"$Cos\theta$", fontsize=28)
    #titulo = "EPOSLHC" if gr.columns[1].startswith("EPOS") else "Sibyll"
    #ax.set_title("ALICE vs " + titulo + " " + muestra)
    ax.invert_xaxis()
    ax.tick_params(axis='both', which='major', labelsize=20)
    plt.legend(fontsize=20)
    plt.show()


promedios_df = pd.read_csv("/home/tristany/Documentos/ROOT/mult_vs_theta_promedios.csv")
#promedios_df.info()

epos_fe = promedios_df[["angulo", "<N_m> EPOSLHC fe"]]
epos_pr = promedios_df[["angulo", "<N_m> EPOSLHC pr"]]
epos_fe.columns = ["angulo", "Fe"]
epos_pr.columns = ["angulo", "Protón"]

sibyll_fe = promedios_df[["angulo", "<N_m> SIBYLL fe"]]
sibyll_pr = promedios_df[["angulo", "<N_m> SIBYLL pr"]]
sibyll_fe.columns = ["angulo", "Fe"]
sibyll_pr.columns = ["angulo", "Protón"]

qgsjet= pd.read_excel("/home/tristany/Documentos/ROOT/qgsjet.xlsx")
#qgsjet.info()

qgsjet_fe = qgsjet[["angulo","QGSJET FE P"]]
qgsjet_pr = qgsjet[["angulo","QGSJET PR P"]]
qgsjet_fe.columns = ["angulo", "Fe"]
qgsjet_pr.columns = ["angulo", "Protón"]


#graficar(epos_fe, epos_pr)
#graficar(sibyll_fe, sibyll_pr)
#graficar(qgsjet_fe, qgsjet_pr)

lista = [l for l in full_df.columns if l.startswith("<N_m> EPOSLHC pr")]
epos_pr = full_df[["angulo"] + lista]
rename = [col.replace("<N_m> EPOSLHC pr ","") for col in epos_pr.columns]
rename = ["angulo", r"$10^{14}-10^{15}$", 
          r"$10^{15}-3 \times 10^{15}$", 
          r"$3 \times 10^{15}-10^{16}$", 
          r"$10^{16}-3 \times 10^{16}$", 
          r"$3 \times 10^{16}-10^{17}$", 
          r"$10^{17}-3 \times 10^{17}$",
          r"$3 \times 10^{17}-10^{18}$"]
epos_pr.columns = rename

lista = [l for l in full_df.columns if l.startswith("<N_m> EPOSLHC fe")]
epos_fe = full_df[["angulo"] + lista]
rename = [col.replace("<N_m> EPOSLHC fe ", "") for col in epos_fe.columns]
rename = ["angulo", r"$10^{14}-10^{15}$", 
          r"$10^{15}-3 \times 10^{15}$", 
          r"$3 \times 10^{15}-10^{16}$", 
          r"$10^{16}-3 \times 10^{16}$", 
          r"$3 \times 10^{16}-10^{17}$", 
          r"$10^{17}-3 \times 10^{17}$",
          r"$3 \times 10^{17}-10^{18}$"]
epos_fe.columns = rename

lista = [l for l in full_df.columns if l.startswith("<N_m> Sibyll pr")]
sibyll_pr = full_df[["angulo"] + lista]
rename = [col.replace("<N_m> Sibyll pr", "") for col in sibyll_pr.columns]
rename = ["angulo", r"$10^{14}-10^{15}$", 
          r"$10^{15}-3 \times 10^{15}$", 
          r"$3 \times 10^{15}-10^{16}$", 
          r"$10^{16}-3 \times 10^{16}$", 
          r"$3 \times 10^{16}-10^{17}$", 
          r"$10^{17}-3 \times 10^{17}$",
          r"$3 \times 10^{17}-10^{18}$"]
sibyll_pr.columns = rename

lista = [l for l in full_df.columns if l.startswith("<N_m> Sibyll fe")]
sibyll_fe = full_df[["angulo"] + lista]
rename = [col.replace("<N_m> Sibyll fe", "") for col in sibyll_fe.columns]
rename = ["angulo", r"$10^{14}-10^{15}$", 
          r"$10^{15}-3 \times 10^{15}$", 
          r"$3 \times 10^{15}-10^{16}$", 
          r"$10^{16}-3 \times 10^{16}$", 
          r"$3 \times 10^{16}-10^{17}$", 
          r"$10^{17}-3 \times 10^{17}$",
          r"$3 \times 10^{17}-10^{18}$"]
sibyll_fe.columns = rename

lista = [l for l in qgsjet.columns if l.startswith("QGSJET FE") and not l.endswith("P")]
qgsjet_fe = qgsjet[["angulo"] + lista]
rename = [col.replace("QGSJET FE ", "") for col in qgsjet_fe.columns]
rename = ["angulo", r"$10^{14}-10^{15}$", 
          r"$10^{15}-3 \times 10^{15}$", 
          r"$3 \times 10^{15}-10^{16}$", 
          r"$10^{16}-3 \times 10^{16}$", 
          r"$3 \times 10^{16}-10^{17}$", 
          r"$10^{17}-3 \times 10^{17}$",
          r"$3 \times 10^{17}-10^{18}$"]
qgsjet_fe.columns = rename

lista = [l for l in qgsjet.columns if l.startswith("QGSJET PR") and not l.endswith("P")]
qgsjet_pr = qgsjet[["angulo"] + lista]
rename = [col.replace("QGSJET PR ", "") for col in qgsjet_pr.columns]
rename = ["angulo", r"$10^{14}-10^{15}$", 
          r"$10^{15}-3 \times 10^{15}$", 
          r"$3 \times 10^{15}-10^{16}$", 
          r"$10^{16}-3 \times 10^{16}$", 
          r"$3 \times 10^{16}-10^{17}$", 
          r"$10^{17}-3 \times 10^{17}$",
          r"$3 \times 10^{17}-10^{18}$"]
qgsjet_pr.columns = rename

def graficar_detallado(gr):
    ax = alice.plot(x="angulo", y="<N_m> ALICE", label="ALICE", marker="o", color="red")
    ax.set_ylabel(r"$<N_\mu>$", fontsize=28)
    gr.plot(x="angulo", ax=ax, marker="o")
    ax.set_xlabel(r"$Cos\theta$", fontsize=28)
    #titulo = "EPOSLHC" if gr.columns[1].startswith("EPOS") else "Sibyll"
    #ax.set_title("ALICE vs " + titulo + " " + muestra)
    ax.invert_xaxis()
    ax.tick_params(axis='both', which='major', labelsize=20)
    plt.legend(fontsize=20)
    plt.show()


#graficar_detallado(epos_pr)
#graficar_detallado(epos_fe)
#graficar_detallado(sibyll_pr)
#graficar_detallado(sibyll_fe)
#graficar_detallado(qgsjet_pr)
#graficar_detallado(qgsjet_fe)

full_alice = pd.read_excel("/home/tristany/Documentos/ROOT/FULL_ALICE.xlsx")

def graficar_alice():
    cols = ["P", "A"]
    angs = ["1.000", "0.975", "0.938", "0.900", "0.825", "0.750", "0.675", "0.600", "0.525"]
    desfase = 0.05
    ax = full_alice.plot(x="P1", y="A1", label=f"{angs[1]} - {angs[0]}")
    ax.set_ylabel(r"$\Phi \langle p \rangle^{3}$", fontsize=28)
    ax.set_xlabel(r"$\langle p \rangle$", fontsize=28)
    for i in range(7):
        pe = cols[0]+str(i+2)
        aa = cols[1]+str(i+2)
        des = desfase*(i+1)
        aa = full_alice[aa]+des
        ax.plot(full_alice[pe], aa, label=f"{angs[i+2]} - {angs[i+1]}   $\pm${des:.2f}" )
    plt.xscale("log")
    handels, labels = ax.get_legend_handles_labels()
    plt.legend(handels[::-1], labels[::-1], title=r"                        $Cos \theta $              desfase",
               loc="upper left",
               bbox_to_anchor=(1.02,1.0),
               frameon=False,
               fontsize=14,
               ncol=1)
    plt.subplots_adjust(right=0.60)
    plt.grid(True)
    plt.show()

graficar_alice()