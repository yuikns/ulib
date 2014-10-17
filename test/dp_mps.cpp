#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ulib/dp_mps.h>

#define N 1000
#define T 10

int main()
{
	mps_job_t jobs[4] = {
		{0, 1, 10}, {5, 2, 1},
		{5, 4, 4}, {3, 2, 4} };

	int ns;
	const mps_job_t *sch[4];

	assert(dp_mps(jobs, 4, sch, &ns) == 5);
	assert(ns == 2);

	srand48(time(NULL));
	printf("%ld %ld\n", sch[0] - jobs, sch[1] - jobs);

	mps_job_t *rjobs = new mps_job_t[N];
	for (int i = 0; i < N; ++i) {
		rjobs[i].d = drand48() * N;
		rjobs[i].t = lrand48() % T;
		rjobs[i].p = drand48();
	}

	printf("%f\n", dp_mps(rjobs, N, NULL, &ns));
	printf("%d\n", ns);

	delete [] rjobs;

	printf("passed\n");

	return 0;
}
