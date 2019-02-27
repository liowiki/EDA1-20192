#include <stdio.h>
#include <string.h>

struct productos{
    int codigoBarras;
    char nombre[30];
    float precio;
    int inventario;
};



struct productos agregaProducto();
struct productos agregaAInventario(struct productos agregaProducto);
void venderProducto(struct productos *sleccionProductos);
void muestraInventario(struct productos Productos);

int seleccionaProducto(struct productos *sleccionProductos);
void llenaProductos();

int elementos=0;

int main(){

    int select;
    int barras;
    int idProductos;
    //int elementos;


    struct productos misProductos[50];

    misProductos[0].codigoBarras = 111111;
    strcpy(misProductos[0].nombre, "coca de 600");
    misProductos[0].precio = 11.50;
    misProductos[0].inventario= 10;

    misProductos[1].codigoBarras = 222222;
    strcpy(misProductos[1].nombre, "nutrileche 1l");
    misProductos[1].precio = 11.50;
    misProductos[1].inventario = 10;

    misProductos[2].codigoBarras = 333333;
    strcpy(misProductos[2].nombre, "bonafont 1.5l");
    misProductos[2].precio = 11.50;
    misProductos[2].inventario = 10;

    misProductos[3].codigoBarras = 444444;
    strcpy(misProductos[3].nombre, "ariel 900g");
    misProductos[3].precio = 11.50;
    misProductos[3].inventario = 10;

    misProductos[4].codigoBarras = 555555;
    strcpy(misProductos[4].nombre, "sabritas 90g");
    misProductos[4].precio = 11.50;
    misProductos[4].inventario = 10;

    elementos=5;
    select = 0;

    while (select != 5){
        printf("-----------------------------------------------\n");
        printf("Bienvenidos a tienda XOOX\n");
        printf("Selecione del menu:\n"
           "1. Agregar productos\n"
           "2. Agregar a inventario\n"
           "3. Vender Producto\n"
           "4. Mostrar Inventarios\n"
           "5. Salir\n");
        scanf("%d", &select);

        switch(select){
        case 1:
            elementos ++;
            misProductos[elementos-1] = agregaProducto();
            printf("Elemento agregados\n");
            break;
        case 2:
            idProductos = seleccionaProducto(misProductos);
            misProductos[idProductos] = agregaAInventario(misProductos[idProductos]);
            printf("agregado\n");
            break;
        case 3:
            venderProducto(misProductos);
            break;
        case 4:
            printf("%d", misProductos[elementos].inventario);
            for (int i=0; i<elementos; i++){
                muestraInventario(misProductos[i]);
            }
            break;
        default:
            printf("selecciona uno de la lista\n");
            break;
        }

    }
    return 0;
}

struct productos agregaProducto(){

    struct productos addProductos;
    printf("cual es el codigo de barras\n");
    scanf("%d", &addProductos.codigoBarras);
    printf("nombre del producto\n");
    scanf("%s", &addProductos.nombre);
    printf("cuantos productos se agregan\n");
    scanf("%d", &addProductos.inventario);
    printf("cual sera el precio\n");
    scanf("%f", &addProductos.precio);
    return addProductos;

}

struct productos agregaAInventario(struct productos agregaProducto){
    int agregar;
    printf("cuantos articulos deseas agregar al inventario\n");
    scanf("%d", &agregar);
    agregaProducto.inventario+=agregar;
    return agregaProducto;
}




void muestraInventario(struct productos Productos){
    printf("Producto: %s\n", Productos.nombre);
    printf("Precio: %f\n", Productos.precio);
    printf("inventario: %d\n", Productos.inventario);
}





void venderProducto(struct productos *sleccionProductos){
    int idProductos;
    int cantidad=0;
    float total=0;
    idProductos = seleccionaProducto(sleccionProductos);
    printf("ingresa la cantiad de productos que se venderan\n");
    scanf("%d", &cantidad);
    sleccionProductos[idProductos].inventario-=cantidad;
    total += (sleccionProductos[idProductos].precio * cantidad);
    printf("el total serian %f\n", total);

}

int seleccionaProducto(struct productos *sleccionProductos){
    int codBarras;
    printf("selecciona Producto\n");
    printf("Ingresa el codigo de barras\n");
    scanf("%d", &codBarras);
    for (int i=0; i<elementos; i++){
        if (codBarras == sleccionProductos[i].codigoBarras){
            return i;
        }
    }
    return -1;
}

