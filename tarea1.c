#include <stdbool.h>
#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct  
{
  int ID;
  char problema[256];
  char prioridad[10];
  time_t horaRegistro;
  int prioridadNum;
} tipoTicket;


void mostrarMenuPrincipal() 
{
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_ticket(List* tickets) 
{
  tipoTicket *nuevoTicket = (tipoTicket*)malloc(sizeof(tipoTicket));
  if (!nuevoTicket) return;

  printf("\n--- Registrar Nuevo paciente ---\n");
  
  printf("ID: ");
  scanf("%d", &nuevoTicket->ID);
  getchar();
  
  printf("Describa el problema:");
  scanf("%255[^\n]", nuevoTicket->problema);
  getchar();
  
  
  strcpy(nuevoTicket->prioridad, "Bajo");
  nuevoTicket->prioridadNum = 0;
  time(&nuevoTicket->horaRegistro);
  
  list_pushBack(tickets, nuevoTicket);
  
  printf("Paciente registrado con éxito.\n");
}


void asignar_prioridad(List* tickets) 
{
  if (list_size(tickets) == 0) 
  {
      printf("No hay pacientes registrados.\n");
      return;
  }

  int id;
  printf("\nID del paciente a modificar: ");
  scanf("%d", &id);
  getchar();


  tipoTicket *ticketTemp = (tipoTicket *)list_first(tickets);
  bool encontrado = false;
  
  while (ticketTemp != NULL)
  {
      if (ticketTemp->ID == id) 
      {
          encontrado = true;
          break;
      }
      ticketTemp = (tipoTicket*)list_next(tickets);
  }

  if (!encontrado) 
  {
      printf("Ticket no encontrado.\n");
      return;
  }

  
  char nuevaPrioridad[10];
  printf("Asigne una nueva prioridad al ticket (Bajo / Medio / Alto): ");
  scanf("%9s", nuevaPrioridad);
  getchar();

  
 
  if (strcmp(nuevaPrioridad, "Bajo") == 0)
  {
    strcpy(ticketTemp->prioridad, nuevaPrioridad);
    time(&ticketTemp->horaRegistro);
    ticketTemp->prioridadNum = 0;
    printf("\n¡Prioridad ACTUALIZADA a %s! ¡Con éxito!\n", nuevaPrioridad);
  } 
  
  else if (strcmp(nuevaPrioridad, "Medio") == 0)
  {
    strcpy(ticketTemp->prioridad, nuevaPrioridad);
    time(&ticketTemp->horaRegistro); 
    ticketTemp->prioridadNum = 1;
    printf("\n¡Prioridad ACTUALIZADA a %s! ¡Con éxito!\n", nuevaPrioridad);
  }
  
  else if (strcmp(nuevaPrioridad, "Alto") == 0)
  {
    strcpy(ticketTemp->prioridad, nuevaPrioridad);
    time(&ticketTemp->horaRegistro); 
    ticketTemp->prioridadNum = 2;
    printf("\n¡Prioridad ACTUALIZADA a %s! ¡Con éxito!\n", nuevaPrioridad);
  }

  else 
  {
    printf("Prioridad no válida. El ticket se mantiene con prioridad \"%s\". Intente nuevamente.\n", ticketTemp->prioridad);
    return;
  }
}

int lower_than(void *ptrA, void *ptrB)
{
  tipoTicket *ticketA = (tipoTicket *)ptrA;
  tipoTicket *ticketB = (tipoTicket *)ptrB;

    
  if (ticketA->prioridadNum > ticketB->prioridadNum) return 1;

  if (ticketA->prioridadNum == ticketB->prioridadNum && ticketA->horaRegistro < ticketB->horaRegistro) return 1;
    

  return 0; 
}


void ordenarListaPorPrioridad(List *listaOriginal) 
{
  List *listaOrdenada = list_create(); 

  tipoTicket *ticketActual = (tipoTicket*)list_first(listaOriginal);
  while (ticketActual != NULL) 
  {
      
    list_sortedInsert(listaOrdenada, (void *)ticketActual, lower_than);
    ticketActual = (tipoTicket*)list_next(listaOriginal);
  }

  list_clean(listaOriginal);
  void *data;

  while ((data = list_popFront(listaOrdenada)) != NULL) 
  {
    list_pushBack(listaOriginal, data);
  }
  
}

void mostrar_lista_pacientes(List *tickets) 
{
  printf("Pacientes en espera: \n");
  
  if (list_size(tickets) == 0) 
  {
      printf("No hay tickets registrados.\n");
      return;
  }

  printf("\n=== Listado de Tickets ===\n");
  
  
  ordenarListaPorPrioridad(tickets);
  tipoTicket *ticket = (tipoTicket*)list_first(tickets);
  int cont = 1;
  
  while (ticket!= NULL) 
  {
      printf("\nTicket #%d\n", cont );
      printf("ID: %d\n", ticket->ID);
      printf("Problema: %s\n", ticket->problema);
      printf("Prioridad: %s\n", ticket->prioridad);
      printf("Hora Registro: %s", ctime(&ticket->horaRegistro));

      ticket = list_next(tickets);
      cont++;
  }
}

void siguiente_paciente(List *tickets)
{
  if (list_size(tickets) == 0) 
  {
    printf("No hay tickets pendientes\n");
    return;
  }

  ordenarListaPorPrioridad(tickets);
  tipoTicket *masPrioridad = list_popFront(tickets);

  if (masPrioridad == NULL)
  {
    printf("No hay tickets pendientes\n");
    return;
  }

  printf("\n===Ticket con mayor prioridad===\n");
  printf("ID: %d\n", masPrioridad->ID);
  printf("Problema: %s\n", masPrioridad->problema);
  printf("Prioridad: %s\n", masPrioridad->prioridad);
  printf("Hora Registro: %s", ctime(&masPrioridad->horaRegistro));

  free(masPrioridad); 
}

void buscar_ticket(List *tickets)
{
  int IdAux;
  printf("Ingresar ID a buscar:");
  scanf("%d" , &IdAux);
  getchar();

  tipoTicket * ticketAux = (tipoTicket*)list_first(tickets);
  bool encontrado = false;
  while(ticketAux != NULL)
  {
    if (ticketAux->ID == IdAux)
    {
      encontrado = true;
      break;
    }
    ticketAux = (tipoTicket*)list_next(tickets);
  }

  if(!encontrado)
  {
    printf("No se encontró ningún ticket con ese ID. Por favor, verifique e intente nuevamente.\n");
    return;
  }
  printf("\n=== Detalles del Ticket ===\n");
  printf("Descripción del problema: %s\n", ticketAux->problema);
  printf("Prioridad: %s\n", ticketAux->prioridad);
  printf("Hora de registro: %s", ctime(&ticketAux->horaRegistro));
}

int main() 
{
  char opcion;
  List *tickets = list_create();
  
  do 
  {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); 
    switch (opcion) {
    case '1':
      registrar_ticket(tickets);
      break;
    case '2':
      asignar_prioridad(tickets);
      break;
    case '3':
      mostrar_lista_pacientes(tickets);
      break;
    case '4':
      siguiente_paciente(tickets);
      break;
    case '5':
      buscar_ticket(tickets);
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  list_clean(tickets);
  return 0;
}
