/*
 * sc_cycle_runner.h
 *
 *  Created on: 28.09.2018
 *      Author: herrmann
 */

#ifndef SC_CYCLE_RUNNER_H_
#define SC_CYCLE_RUNNER_H_

#include <pthread.h>
#include <unistd.h>
#include "sc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \file Defines the cycle runner interface for YAKINDU state machines.
 *  A cycle runner performs a cyclic execution of the state machines runCycle function
 *  with a fixed time interval. The implementation is based on  POSIX threads and makes
 *  use of a mutex for thread synchronization.
 */

/*! Function pointer type for state machines runCycle function. */
typedef void (*sc_run_cycle_fp)(void *handle);

/*! The type definition contains all properties a cycle runner instance requires.
 * Each cycle runner requires its own instance.
 */
typedef struct sc_cr_connection {
	void *cr_handle;

	void *sm_handle;
	sc_run_cycle_fp sm_runCycle;
} sc_cr_connection_t;

typedef struct {
	int interval_ms;
	sc_run_cycle_fp runCycle;
	pthread_t thread;
	sc_cr_connection_t *connection;
	struct sc_cycle_runner_service *service;
} sc_cycle_runner_t;

typedef struct sc_cycle_runner_service {
	sc_integer runner_count;
	sc_cycle_runner_t *runners;
	pthread_mutex_t runner_mutex;
	pthread_mutex_t *event_mutex;
} sc_cycle_runner_service_t;

typedef void (*sc_start_cycle_runner_fp)(struct sc_cr_connection *connection,
		int cycle_interval_ms);

typedef void (*sc_stop_cycle_runner_fp)(struct sc_cr_connection* connection);

typedef struct sc_cycle_runner_methods_t {
	sc_start_cycle_runner_fp start;
	sc_stop_cycle_runner_fp stop;
} sc_cycle_runner_methods_t;

/*! Start the cycle runner in an new thread. */
void sc_cycle_runner(struct sc_cr_connection *connection, int cycle_interval_ms);
void sc_cycle_runner_stop(struct sc_cr_connection *connection);
void sc_cycle_runner_init(sc_cycle_runner_service_t* this,
		sc_cycle_runner_t *runners, sc_integer count,
		pthread_mutex_t *event_mutex);

#ifdef __cplusplus
}
#endif

#endif /* SC_CYCLE_RUNNER_H_ */