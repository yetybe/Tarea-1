# Sistema de Gestión de Tickets de Soporte Técnico

## Descripción

Este programa implementa un sistema de gestión de tickets de soporte técnico. Permite registrar solicitudes, asignar prioridades, atender casos urgentes y mantener un orden eficiente en la atención. Cada ticket contiene un **ID**, una **descripción del problema**, una **prioridad** (Bajo, Medio, Alto) y la **hora de registro**.

---

## 1. ¿Cómo compilar y ejecutar la tarea?

Este sistema ha sido desarrollado en C y se ejecuta mediante la terminal de **Visual Studio Code**.

### Pasos para compilar y ejecutar

1. Abrir Visual Studio Code y copiar el repositorio git.
2. Abrir una terminal integrada (`Terminal > Nueva Terminal`).
3. Compilar el programa con el siguiente comando:

```bash
gcc tdas/*.c tarea1.c -Wno-unused-result -o tarea

```
Este comando compila los archivos .c de la carpeta tdas junto con tarea1.c (archivo principal), generando un ejecutable llamado tarea1.
Luego, para ejecutar el código en consola:

```bash
./tarea1

```
# Funcionalidades implementadas correctamente:

Registrar ticket (Opción 1): Registra un nuevo ticket con prioridad "Bajo" por defecto.

Asignar prioridad (Opción 2): Cambia la prioridad del ticket (Alto, Medio o Bajo) y actualiza la hora.

Mostrar lista de espera (Opción 3): Muestra todos los tickets ordenados por prioridad y hora.

Atender al siguiente ticket (Opción 4): Atiende y elimina el ticket más urgente.

Buscar ticket por ID (Opción 5): Muestra los detalles de un ticket dado su ID.

# Funcionalidades no implementadas o limitadas:

Exportación e importación de tickets desde archivos (CSV o TXT): No implementado.

Validación de duplicados en el ID de tickets: No incluida, se debe ingresar manualmente un ID único.


# Ejemplo de interacción

# Paso 1: Registrar un ticket

Ingrese su opción: 1
ID: 1001
Describa el problema: No hay conexión a Internet
Paciente registrado con éxito.

# Paso 2: Asignar una prioridad
Ingrese su opción: 2
ID del paciente a modificar: 1001
Asigne una nueva prioridad al ticket (Bajo / Medio / Alto): Alto
¡Prioridad ACTUALIZADA a Alto! ¡Con éxito!

# Paso 3: Ver la lista de espera

Ingrese su opción: 3

=== Listado de Tickets ===
Ticket #1
ID: 1001
Problema: No hay conexión a Internet
Prioridad: Alto
Hora Registro: Sun Apr 13 10:05:32 2025


# Paso 4: Atender al siguiente ticket

Ingrese su opción: 4

===Ticket con mayor prioridad===
ID: 1001
Problema: No hay conexión a Internet
Prioridad: Alto
Hora Registro: Sun Apr 13 10:05:32 2025

# Paso 5: Buscar ticket por ID

Ingrese su opción: 4

Ingresar ID a buscar: 1001
=== Detalles del Ticket ===  
Descripción del problema: No hay conexión a Internet  
Prioridad: Alto  
Hora de registro: Sun Apr 13 10:05:32 2025





# Paso 6: Salir del sistema

Ingrese su opción: 6 
Saliendo del sistema de gestión hospitalaria...



