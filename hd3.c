#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void guardarEnTxt(const char *NombreDeArchivo, const char *texto){
    FILE *archivo = fopen(NombreDeArchivo, "w");
    if (archivo == NULL) {
        printf("Error :( %s\n", NombreDeArchivo);
    }
    fprintf(archivo, "%s", texto);
    fclose(archivo);
    printf("Texto guardado en el archivo :)");
}

void guardarEnBinario(const char *filename, const char *texto) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return;
    }
    fwrite(texto, sizeof(char), strlen(texto), file);
    fclose(file);
    printf("Texto guardado en el archivo binario %s\n", filename);
}

void mostrarMenu() {
    printf("1. Ingresar texto y guardarlo en un txt\n");
    printf("2. Crear un archivo binario con el texto ingresado\n");
    printf("3. Crear un archivo .txt con el texto ingresado\n");
    printf("4. Salir\n");
}

int main() {
    char texto[100];
    int opcion;

    while(opcion == 4){
        mostrarMenu();
        printf("Ingrese una accion - ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion){
            case 1:
                printf("Ingrese el texto - ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0';
                guardarEnTxt("texto.txt", texto);
                break;
            case 2:
                guardarEnBinario("archivo.bin", texto);
                break;
            case 3:
                guardarEnTxt("archivo_nuevo.txt", texto);
                break;
            case 4:
                printf("Salir \n");
                break;
            default:
                printf("Opción no válida\n");
        }
    }
}
