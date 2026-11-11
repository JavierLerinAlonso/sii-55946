#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "DatosMemCompartida.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	DatosMemCompartida* dat;
	char *direccion;
	int fd;
	// X1: Abrir el fichero proyectado creado por tenis
	fd = open("/tmp/mem_tenis", O_RDWR);
	if (fd == -1)
	{
		perror("Error al abrir el archivo (ejecuta ./tenis antes que ./bot)"); 
		return 1;
	}

	// X2: Proyectar el fichero en memoria
	direccion = (char*)mmap(NULL, sizeof(DatosMemCompartida), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (direccion == MAP_FAILED)
	{
		perror("Error en la proyeccion mmap"); 
		return 1;
	}
	close(fd);
	dat = (DatosMemCompartida*)direccion;
        dat->fin_juego=0;
	while(1)
	{
		usleep(25000);
		if(dat->fin_juego==1){
		printf("El juego ha finalizado y el bot ha terminado.\n");
		break;
	      
		}
		// X3: Lógica del bot comparando la altura (Y) de la esfera y el centro de raqueta1
		float centro_raqueta = (dat->raqueta1.y1 + dat->raqueta1.y2) / 2.0f;

		if (dat->esfera.centro.y > centro_raqueta + 0.2f) {
			dat->accion = 1;  // Mover arriba
		} else if (dat->esfera.centro.y < centro_raqueta - 0.2f) {
			dat->accion = -1; // Mover abajo
		} else {
			dat->accion = 0;  // Nada
		}
	}
	return 0;
}
