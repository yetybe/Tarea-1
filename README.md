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
✅ Funcionalidades implementadas correctamente:
Registrar ticket (Opción 1): Registra un nuevo ticket con prioridad "Bajo" por defecto.

Asignar prioridad (Opción 2): Cambia la prioridad del ticket (Alto, Medio o Bajo) y actualiza la hora.

Mostrar lista de espera (Opción 3): Muestra todos los tickets ordenados por prioridad y hora.

Atender al siguiente ticket (Opción 4): Atiende y elimina el ticket más urgente.

Buscar ticket por ID (Opción 5): Muestra los detalles de un ticket dado su ID.

⚠️ Funcionalidades no implementadas o limitadas:
Exportación e importación de tickets desde archivos (CSV o TXT): No implementado.

Validación de duplicados en el ID de tickets: No incluida, se debe ingresar manualmente un ID único.




