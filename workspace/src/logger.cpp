#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
//#include <iostream.h>


int main(int argc, char **argv) {
    int fd;
    char buffer[1024];

    // X1: Borrar FIFO por si existiera previamente
    unlink("/tmp/FIFO_tenis");

    /* X2: Crear el FIFO con permisos de lectura y escritura (0666) */
    if (mkfifo("/tmp/FIFO_tenis", 0666) < 0) {
        perror("No puede crearse el FIFO");
        return(1);
    }

    /* X3: Abrir el FIFO en modo solo lectura */
    if ((fd = open("/tmp/FIFO_tenis", O_RDONLY)) < 0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }

    /* X4 y X5: Leer de la FIFO e imprimir en pantalla */
    // Cuando el juego 'tenis' cierre la tubería al terminar, read() devolverá 0 y el bucle finalizará solo.
    int n;
    while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0'; // Aseguramos el final de cadena
        printf("%s", buffer);
        fflush(stdout);
    }

    /* X5 y X6: Cerrar descriptor y eliminar el archivo FIFO */
    close(fd);
    unlink("/tmp/FIFO_tenis");
    return(0);
}
