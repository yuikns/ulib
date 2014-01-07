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

#ifndef _ULIB_DP_LIS_H
#define _ULIB_DP_LIS_H

namespace ulib {

/**
 * dp_lis - find the longest increasing subsequence and return its
 * length
 * @seq: sequence to process
 * @res: resulting longest increasing subsequence.
 * @num: number of elements in the sequence
 * NOTE: this function returns 0 if seq is NULL or empty. @res can be
 * NULL if the subsequence is not desired. This function throws
 * bad_alloc exception in case of lacking memory.
 * Complexity: O(num*log(num)) time and O(num) space.
 */
template<typename T>
int dp_lis(const T seq[], T res[], int num)
{
	T   *opt;
	int *pos;
	int *sub;
	int *pred;
	int max_len;

	if (seq == NULL || num <= 0)
		return 0;

	opt = new T[num];
	pos = new int[num];
	sub = new int[num];
	pred = new int[num];

	opt[0] = seq[0];
	pos[0] = 0;
	sub[0] = 1;
	max_len = 1;

	for (int i = 1; i < num; ++i) {
		int m, j, k;
		for (j = 0, k = max_len; j < k;) {
			m = (j + k) / 2;
			if (seq[i] == opt[m]) {
				j = m;
				break;
			}
			if (seq[i] < opt[m])
				k = m;
			else
				j = m + 1;
		}
		opt[j] = seq[i];
		pos[j] = i;
		sub[i] = j + 1;
		if (j > 0) {
			pred[i] = pos[j - 1];
			if (j == max_len)
				++max_len;
		}
	}

	if (res) {
		int p = pos[max_len - 1];
		for (int i = max_len - 1; i >= 0; --i) {
			res[i] = seq[p];
			p = pred[p];
		}
	}

	delete [] opt;
	delete [] pos;
	delete [] sub;
	delete [] pred;

	return max_len;
}

}  // namespace ulib

#endif  /* _ULIB_DP_LIS_H */
