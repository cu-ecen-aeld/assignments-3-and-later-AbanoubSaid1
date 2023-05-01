#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
     usleep(thread_func_args->wait_to_obtain_ms*1000);
    int res = pthread_mutex_lock(thread_func_args->mutex);
    if(res != 0){
		thread_func_args->thread_complete_success = false;
	}else {
		usleep(thread_func_args->wait_to_release_ms*1000);
		res = pthread_mutex_unlock(thread_func_args->mutex);
		if(res != 0){
			thread_func_args->thread_complete_success = false;
		}
		thread_func_args->thread_complete_success = true;
	}
    pthread_exit(thread_param);
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    struct thread_data *thread_param = (struct thread_data *) malloc(sizeof(struct thread_data));
    thread_param->mutex = mutex;
	thread_param->wait_to_obtain_ms = wait_to_obtain_ms; 
	thread_param->wait_to_release_ms = wait_to_release_ms;

    int res = pthread_create(thread, NULL, threadfunc, (void*) thread_param);
    if(res != 0){
		printf("pthread created failed: %d\n", res);
		return false;
	}
    else{
    return true;
    }
}

