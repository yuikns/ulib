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

#ifndef _ULIB_DP_MPS_H
#define _ULIB_DP_MPS_H

typedef struct {
	int   d;  // processing time
	int   t;  // deadline
	float p;  // profit
} mps_job_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * dp_mps - find the schedule with maximum profit
 * @jobs: an array of jobs
 * @n:    number of jobs in the array
 * @sc:   output schedule, only pointers to the @jobs array are stored
 * @sn:   number of jobs in the schedule
 * Returns an negative number if an error has occurred
 */
float dp_mps(const mps_job_t *jobs, int n, const mps_job_t **sc, int *sn);

#ifdef __cplusplus
}
#endif

#endif  /* _ULIB_DP_MPS_H */
