/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:08:06 by marvin            #+#    #+#             */
/*   Updated: 2024/12/03 14:08:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>   // Para open()
#include <stdio.h>   // Para printf()
#include <stdlib.h>  // Para free()
#include "get_next_line.h"  // Tu archivo de cabecera

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    // Comprobación de argumentos
    if (argc != 2)
    {
        printf("Uso: %s ejemplo.txt\n", argv[0]);
        return (1);
    }

    // Abrir el archivo en modo solo lectura
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Leer cada línea usando get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // Mostrar la línea en la terminal
        free(line);          // Liberar la memoria de la línea
    }
    // Cerrar el archivo
    close(fd);

    return (0);
}
