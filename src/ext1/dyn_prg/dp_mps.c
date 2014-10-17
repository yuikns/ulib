/* The MIT License

   Copyright (C) 2014 Zilong Tan (eric.zltan@gmail.com)

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#include <stdlib.h>
#include "dp_mps.h"

#define OPT(ptr, i, t, d) ((ptr)[i][(t) > (d)? (d): (t)])

static inline int __dl_cmp(const void *a, const void *b)
{
	const mps_job_t *x = *(const mps_job_t **)a;
	const mps_job_t *y = *(const mps_job_t **)b;

	return x->d < y->d? -1: x->d == y->d? 0: 1;
}

float dp_mps(const mps_job_t *jobs, int n, const mps_job_t **sc, int *sn)
{
	float tp = -1;
	int   sp = 0;
	int i, t;
	int m = 0;
	float **opt = NULL;
	const mps_job_t **jp = NULL;
	float *buf = NULL;

	if (n <= 0) {
		*sn = 0;
		return 0;
	}

	if ((jp = (const mps_job_t **)malloc(sizeof(mps_job_t *) * n)) == NULL)
		return -1;
	for (i = 0; i < n; ++i) {
		jp[i] = jobs + i;
		m += jobs[i].d;
	}
	qsort(jp, n, sizeof(jp[0]), __dl_cmp);

	if ((buf = (float *)malloc(sizeof(float) * (m + n))) == NULL)
		goto done;
	if ((opt = (float **)malloc(sizeof(float *) * n)) == NULL)
		goto done;

	for (i = 0, t = 0; i < n; ++i) {
		opt[i] = buf + t;
		t += jp[i]->d + 1;
	}
	for (t = 0; t <= jp[0]->d; ++t)
		opt[0][t] = 0;

	for (tp = 0, i = 1; i < n; ++i) {
		mps_job_t cur = *jp[i];
		int d = jp[i - 1]->d;
		for (t = 0; t <= cur.d; ++t) {
			int    end = t - cur.t;
			float drop = OPT(opt, i - 1, t, d);
			if (end >= 0) {
				float add = cur.p + OPT(opt, i - 1, end, d);
				opt[i][t] = add > drop? add: drop;
			} else
				opt[i][t] = drop;
		}
		if (opt[i][cur.d] > opt[i - 1][d]) {
			if (sc)
				sc[sp] = jp[i];
			++sp;
			tp += cur.p;
		}
	}

done:	
	free(opt);
	free(buf);
	free(jp);

	if (sn)
		*sn = sp;

	return tp;
}
