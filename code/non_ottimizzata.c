// inclusione librerie
#include <omp.h>
#include <stdio.h>
#include <math.h>

int num_threads = 4; 
long long num_steps = 10000000;     

int main()
{
    // set del numero di thread
    omp_set_num_threads(num_threads);
    
    // inizializzazione timer globale
    double start_time = omp_get_wtime();
	
    // dichiarazione variabili
    double step = 1.0/((double) num_steps);
    double sum[num_threads];
    double full_sum = 0.0;
    double pi;
    int j;  // indice in piu per il for finale
    
    // inizializzazione timer parallelo, con solo overhead di creazione thread
    double start_parallel_time = omp_get_wtime();
	    
    #pragma omp parallel num_threads(num_threads)
    {
        long long i; // long long per fare test con numero di step elevati  
        int id = omp_get_thread_num();
        // printf("thread id: %d\n", id);
        int numthreads = omp_get_num_threads();
        double x;
        sum[id] = 0.0;

        for (i=id; i<num_steps; i+=numthreads){
            x = (i+0.5)*step;
            sum[id] = sum[id] + 4.0/(1.0+x*x);
        }
    }

    for(j=0; j<num_threads; j++)
        full_sum += sum[j];

    pi=step*full_sum;

    // calcolo tempo totale e tempo parallelo
    double total_time = omp_get_wtime() - start_time;
    double total_parallel_time = omp_get_wtime() - start_parallel_time;

    // stampe finali
    printf("Approssimazione di pi: %.16f\nNumero di threads: %d\nNumero di passi: %lld\nTempo totale di esecuzione: %.6f \nTempo totale calcolo parallelo: %.6f\n", pi, num_threads, num_steps, total_time, total_parallel_time);

    return 0;
}