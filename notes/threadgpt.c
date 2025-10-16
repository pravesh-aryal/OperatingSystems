#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

// Thread function: receives pointer to an int (thread id), computes something,
// and returns a malloc'ed int pointer (so main can read it after join).
void *worker(void *arg) {
    int thread_id = *(int *)arg;

    // Example work: compute double the id
    int *result = malloc(sizeof(int));
    if (!result) {
        perror("malloc");
        pthread_exit(NULL);
    }
    *result = thread_id * 2;

    // Optional: print from thread
    printf("Thread %d: computed %d\n", thread_id, *result);

    // Return pointer to result (caller must free)
    return result;
}

int main(void) {
    pthread_t threads[NTHREADS];
    int *ids = malloc(sizeof(int) * NTHREADS);
    if (!ids) {
        perror("malloc");
        return 1;
    }

    // Create threads
    for (int i = 0; i < NTHREADS; ++i) {
        ids[i] = i; // store id in an array so each thread has stable memory
        int rc = pthread_create(&threads[i], NULL, worker, &ids[i]);
        if (rc != 0) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, rc);
            // Attempt to join already-created threads before exit
            for (int j = 0; j < i; ++j) pthread_join(threads[j], NULL);
            free(ids);
            return 1;
        }
    }

    // Join threads and collect results
    for (int i = 0; i < NTHREADS; ++i) {
        void *ret;
        int rc = pthread_join(threads[i], &ret);
	printf("Joining threads\n");
        if (rc != 0) {
            fprintf(stderr, "Error joining thread %d: %d\n", i, rc);
            continue;
        }

        if (ret != NULL) {
            int *res = (int *)ret;
            printf("Main: thread %d returned %d\n", i, *res);
            free(res); // free memory allocated by thread
        } else {
            printf("Main: thread %d returned NULL\n", i);
        }
    }

    free(ids);
    return 0;
}

