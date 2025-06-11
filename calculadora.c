#include <stdio.h>
#include <string.h>

//Definicion de estructura para mascota-----------------------------------------
struct Mascota{
    int id;
    char Nombre[30];
    char Tipo[30];
    int Edad;
    char Propietario[30];
    int activa;
    };

//Definicion de funciones

//Funcion para menu-------------------------------------------------------------
void mostrarMenu () {
    printf("Menu: \n");
    printf("1. Registrar mascota: \n");
    printf("2. Mostrar lista de mascotas: \n");
    printf("3. Buscar mascota: \n");
    printf("4. Eliminar mascota: \n");
    printf("5. Salir. \n");
    }

//Funcion para registrar una mascota--------------------------------------------

void regMascota(struct Mascota mascotas[], int *contador){
    if(*contador >=5){
        printf("Error, no se pueden registrar mas mascotas. \n");
        return;
    }
    printf("--------------------------------------------------------\n");
    printf("Registrar una mascota: \n");
    printf("Ingrese el ID de la mascota: \n");
    scanf("%d", &mascotas[*contador].id);
    getchar();
    
    printf("Nombre de la mascota: \n");
    fgets(mascotas[*contador].Nombre, 30, stdin);
    mascotas[*contador].Nombre[strcspn(mascotas[*contador].Nombre, "\n")] =0;
    
    printf("Tipo de mascota (perro, gato, tortuga, etc.): \n");
    fgets(mascotas[*contador].Tipo, 30, stdin);
    mascotas[*contador].Tipo[strcspn(mascotas[*contador].Tipo, "\n")];
    
    printf("Edad en meses: \n");
    scanf("%d", &mascotas[*contador].Edad);
    getchar();
    
    printf("Nombre del propietario: \n");
    fgets(mascotas[*contador].Propietario, 30, stdin);
    mascotas[*contador].Propietario[strcspn(mascotas[*contador].Propietario, "\n")];
    
    mascotas[*contador].activa=1;
    (*contador)++;
    printf("Mascota registrada! \n");
    printf("--------------------------------------------------------\n");
}

//funcion para mostrar lista de mascotas----------------------------------------
void listMascotas(struct Mascota mascotas[], int contador){
    int i;
    printf("--------------------------------------------------------\n");
    printf("Lista de mascotas: \n");
    for(int i= 0; i< contador; i++){
        if(mascotas[i].activa==1){
            printf(" -ID: %d\n -Nombre: %s\n -Tipo: %s -Edad en meses: %d\n -Propietario: %s\n", mascotas[i].id, mascotas[i].Nombre, mascotas[i].Tipo, mascotas[i].Edad, mascotas[i].Propietario);
            
        }
    }
    printf("\n");
    
}

//funcion para buscar una mascota-----------------------------------------------
void buscarMascota(struct Mascota mascotas[], int contador){
    int buscarID;
    int i;
    printf("--------------------------------------------------------\n");
    printf("Ingresa el ID de la mascota: ");
    scanf("%d", &buscarID);
    int encontrada = 0;
    
    for(int i = 0; i < contador; i++){
    if(mascotas[i].id == buscarID){
        if(mascotas[i].activa == 1){
            printf("Mascota encontrada!\n");
            printf(" -ID: %d\n -Nombre: %s\n -Tipo: %s -Edad en meses: %d\n -Propietario: %s\n", mascotas[i].id, mascotas[i].Nombre, mascotas[i].Tipo, mascotas[i].Edad, mascotas[i].Propietario);
        }
    }else{
        printf("Mascota no encontrada.\n");
    }};
    encontrada = 1;
    
    
    
    if(!encontrada){
        printf("Mascota no encontrada.\n");
    }
    printf("\n");
        
    
}
//funcion para eliminar mascota-------------------------------------------------     
void elimMascota(struct Mascota mascotas[], int contador){
    int eliminarID;
    printf("--------------------------------------------------------\n");
    printf("Ingrese el ID de la mascota a eliminar: \n");
    scanf("%d", &eliminarID);
    
    int encontrada = 0; //flag para indicar si el ID fue encontrado 
    
    for(int i = 0; i < contador; i++){
        if(mascotas[i].id == eliminarID){
            if(mascotas[i].activa == 1){
                mascotas[i].activa=0;
                printf("Mascota eliminada.\n");
                
            }else {
                printf("Mascota no encontrada o ya eliminada. \n");
                
            }
            encontrada = 1;
            break;
        }
    }
    if(!encontrada){
        printf("Mascota no encontrada o ya eliminada.\n");
        
    }
    printf("\n");
    
}    

    

int main(){
    
    struct Mascota mascotas[5];
    int contador = 0;
    int opcion;
    
    while(1){
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion){
            
            case 1: 
            
            regMascota(mascotas, &contador);
            break;
            
            case 2:
            
            listMascotas(mascotas, contador);
            break;
            
            case 3:
            
            buscarMascota(mascotas, contador);
            break;
            
            case 4:
            
            elimMascota(mascotas, contador);
            break;
            
            case 5:
            printf("Gracias por utilizar el programa!");
            return 0;
            
            default: 
            printf("Opcion no valida \n");
            
            
            
        }
    }
    
    
    return 0;
