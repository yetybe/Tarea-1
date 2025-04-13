# Sistema de Gestión de Tickets de Soporte Técnico

## Descripción

Este programa implementa un sistema de gestión de tickets de soporte técnico. Permite registrar solicitudes, asignar prioridades, atender casos urgentes y mantener un orden eficiente en la atención. Cada ticket contiene un **ID**, una **descripción del problema**, una **prioridad** (Bajo, Medio, Alto) y la **hora de registro**.

---

## 1. ¿Cómo compilar y ejecutar la tarea?

Este sistema ha sido desarrollado en C y se ejecuta mediante la terminal de **Visual Studio Code**.

### Pasos para compilar y ejecutar

1. Abrir Visual Studio Code y copiar el repositorio git.
2. Abrir una terminal integrada (`Terminal > Nueva Terminal`).
3. Compila el programa con el siguiente comando:

```bash
gcc tdas/*.c tarea1.c -Wno-unused-result -o tarea

```
Este comando compila los archivos .c de la carpeta tdas junto con tarea1.c (archivo principal), generando un ejecutable llamado tarea1.
Luego, para ejecutar el código en consola:

```bash
./tarea1
