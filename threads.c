#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>



void * funcaoC ();

pthread_mutex_t meuMutex = PTHREAD_MUTEX_INITIALIZER;

int contador = 0;

main ()

{

	int retorno1, retorno2;

	pthread_t threadUm, threadDois;



	/* Crie threads independentes. Cada uma delas executar� funcaoC. */



	if ((retorno1 = pthread_create (&threadUm, NULL, &funcaoC, NULL)))

	{

		printf ("Falha na cria��o do thread: %d \n", retorno1);

	}



	if ((retorno2 = pthread_create (&threadDois, NULL, &funcaoC, NULL)))

	{

		printf ("Falha na cria��o do thread: %d \n", retorno2);

	}



/* Aguarde at� que as threads sejam conclu�das antes de continuar com o main(). Caso n�o esperemos, corremos o risco de terminar o main() antes das threads. Com isso, elas seriam finalizadas antes de terminarem seu processamento/tarefa. */

	pthread_join (threadUm, NULL);

	pthread_join (threadDois, NULL);



	exit(0); /* Finaliza o processo e todas as threads em execu��o.*/

}



void * funcaoC ()

{

	pthread_mutex_lock (&meuMutex);

	contador++;

	printf ("Valor do contador: %d \n", contador);

		pthread_mutex_unlock (&meuMutex);
	
}
