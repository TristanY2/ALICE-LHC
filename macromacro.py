import subprocess
import os

try:
    dir_archivos_sin_filtro = os.listdir("/home/tristany/Documentos/Tesis/DATOS/")
    dir_archivos = [f for f in dir_archivos_sin_filtro
                    if f.endswith(".root") and not f.startswith(".")]
except:
    print("No se pudo")
    exit()

#print(dir_archivos, len(dir_archivos))

for i,archivo in enumerate(dir_archivos, start=1):
    macro = f'macro_rangopcov.cpp("{archivo}", {i})'
    cmd = ["root", "-b", "-l", "-q", macro]

    print(f"\n{i}/{len(dir_archivos)}: {archivo}")
    subprocess.run(cmd)